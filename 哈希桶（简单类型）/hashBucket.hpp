#pragma once


// 键提取器：默认直接返回数据本身（适用于K=T的情况）
template<class K>
struct DirectKeyOfT
{
    using result_type = K;  // 添加result_type类型定义
    
    const K& operator()(const K& data) const
    {
        return data;    // 直接返回T自己作为Key的函数对象
    }
};


// 更多的键提取器……



// 前向声明
template <class T, class KeyOfT, class HashFunc>
class HashBucket;

template <class T, class KeyOfT, class HashFunc>
class HBIterator;


// 哈希桶迭代器相关类
// 参数1：节点类型，参数2：键提取器类型，参数3：使用的哈希函数
template <class T, class KeyOfT, class HashFunc>
class HBIterator
{
public:
    using Node = hashNode<T>*;
    using Self = HBIterator<T, KeyOfT, HashFunc>;
    
    Node _node;
    size_t _bucketIdx;
    const HashBucket<T, KeyOfT, HashFunc>* _hb;
    
    HBIterator(Node node = nullptr, size_t bucketIdx = 0, const HashBucket<T, KeyOfT, HashFunc>* hb = nullptr)
        :_node(node), _bucketIdx(bucketIdx), _hb(hb)
    {}
    
    T& operator*()
    {
        return _node->_data;
    }
    
    T* operator->()
    {
        return &_node->_data;
    }
    
    bool operator!=(const Self& it) const
    {
        return _node != it._node;
    }
    
    Self& operator++()
    {
        if (_node->_next)
        {
            // 当前桶还有下一个节点
            _node = _node->_next;
        }
        else
        {
            // 当前桶遍历完，找下一个非空桶
            ++_bucketIdx;
            while (_bucketIdx < _hb->_buckets.size())
            {
                if (_hb->_buckets[_bucketIdx])
                {
                    _node = _hb->_buckets[_bucketIdx]; // 友元
                    return *this;
                }
                ++_bucketIdx;
            }
            _node = nullptr;  // 遍历结束
        }
        return *this;
    }
};


// 哈希桶类（模板默认参数，类似于函数默认参数）
// 参数1：节点类型，参数2：键提取器类型，参数3：使用的哈希函数
template <class T, class KeyOfT = DirectKeyOfT<T>, class HashFunc = Hash<T>>
class HashBucket
{
    // 声明HBIterator为友元类，允许访问私有成员
    friend class HBIterator<T, KeyOfT, HashFunc>;
    
public:
    using Node = hashNode<T>*;   // 节点指针类型

    //迭代器需要（简单指针无法处理这种复杂结构）：
    //1. 知道当前在哪个节点
    //2. 知道当前在哪个桶
    //3. 知道整个哈希桶的结构（为了找到下一个非空桶）
    using Iterator = HBIterator<T, KeyOfT, HashFunc>;   // 当前节点指针、当前桶索引、哈希桶指针

    HashBucket(size_t bucketCount = 10, double maxLF = 0.7)
        :_buckets(bucketCount, nullptr),
        _size(0),
        _maxLF(maxLF)
    {}

    Iterator begin()
    {
        // 找第一个非空桶
        for (size_t i = 0; i < _buckets.size(); ++i)
        {
            if (_buckets[i])
            {
                // 参数1:第一个非空桶的第一个节点，参数2:桶索引，参数3:指向整个哈希桶
                return Iterator(_buckets[i], i, this);
            }
        }

        return end();
    }

    Iterator end()
    {
        // 参数1表示遍历结束，参数2：超出最后一个桶的索引，参数3:指向整个哈希桶
        return Iterator(nullptr, _buckets.size(), this);
    }

    void Clear()
    {
        for (size_t i = 0; i < _buckets.size(); i++)
        {
            Node curr = _buckets[i];
            while (curr)
            {
                Node next = curr->_next;    // 先保存下一个节点
                delete curr;                // 删除当前节点
                curr = next;                // 继续判断下一个节点
            }

            _buckets[i] = nullptr;          // 清空当前这个桶
        }

        _size = 0;
    }

    ~HashBucket()
    {
        Clear();
    }

    // 头插法插入元素
    void Insert(const T& data)
    {
        size_t idx = GetIndex(data);

        Node newNode = new hashNode<T>(data);

        if (_buckets[idx] == nullptr)
        {
            _buckets[idx] = newNode;
        }
        else
        {
            newNode->_next = _buckets[idx];
            _buckets[idx] = newNode;
        }

        _size++;

        if (loadFactor() > _maxLF)
        {
            ResizeHash();
        }
    }

    // 返回哈希桶的元素个数
    size_t Size() const
    {
        return _size;
    }

    // 返回桶的个数
    size_t BucketCount() const
    {
        return _buckets.size();
    }

    // 获取当前的负载因子大小
    double getLF() const
    {
        return loadFactor();
    }

    // 查找元素，返回指向节点的指针
    Node Find(const T& data) const
    {
        size_t idx = GetIndex(data);
        Node curr = _buckets[idx];
        
        while (curr)
        {
            if (KeyOfT()(curr->_data) == KeyOfT()(data))
            {
                return curr;  // 找到匹配的节点
            }
            curr = curr->_next;
        }
        
        return nullptr;  // 未找到
    }

    // 查找元素，返回bool表示是否存在
    bool Contains(const T& data) const
    {
        return Find(data) != nullptr;
    }

    // 删除元素，返回是否成功删除
    bool Erase(const T& data)
    {
        size_t idx = GetIndex(data);
        Node curr = _buckets[idx];
        Node prev = nullptr;
        
        while (curr)
        {
            if (KeyOfT()(curr->_data) == KeyOfT()(data))
            {
                // 找到要删除的节点
                if (prev == nullptr)
                {
                    // 删除的是头节点
                    _buckets[idx] = curr->_next;
                }
                else
                {
                    // 删除的是中间或尾节点
                    prev->_next = curr->_next;
                }
                
                delete curr;
                _size--;
                return true;  // 删除成功
            }
            
            prev = curr;
            curr = curr->_next;
        }
        
        return false;  // 未找到要删除的元素
    }

private:
    // 获取下一个素数大小
    size_t GetNextPrime(size_t n) const
    {
        static const size_t primeList[] = {
            53ul, 97ul, 193ul, 389ul, 769ul,
            1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
            49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
            1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
            50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
            1610612741ul, 3221225473ul, 4294967291ul
        };

        for (size_t p : primeList)
        {
            if (p >= n)
            {
                return p;
            }
        }

        // 若请求过大，返回表中最大素数
        return primeList[sizeof(primeList) / sizeof(primeList[0]) - 1];
    }

    // 计算哈希值
    size_t hashValue(const T& data) const
    {
        return HashFunc()(KeyOfT()(data));
    }

    // 计算索引值
    size_t GetIndex(const T& data) const
    {
        return hashValue(data) % _buckets.size();
    }

    // 计算当前的负载因子=元素个数/桶个数
    double loadFactor() const
    {
        return static_cast<double>(_size) / _buckets.size();
    }

    // 扩容哈希表
    void ResizeHash()
    {
        size_t newSize = GetNextPrime(_buckets.size());
        std::vector<Node> newBuckets(newSize, nullptr);
        
        // 重新哈希所有节点
        for (size_t i = 0; i < _buckets.size(); i++)
        {
            Node curr = _buckets[i];
            while (curr)
            {
                Node next = curr->_next;
                
                // 计算新的索引位置
                size_t newIndex = hashValue(curr->_data) % newSize;
                
                // 插入到新桶中
                curr->_next = newBuckets[newIndex];
                newBuckets[newIndex] = curr;
                
                curr = next;
            }
        }
        
        _buckets.swap(newBuckets);
    }

private:
    std::vector<Node> _buckets;    // 桶数组/链表头指针
    size_t _size;                  // 元素个数
    double _maxLF;                 // 负载因子
};