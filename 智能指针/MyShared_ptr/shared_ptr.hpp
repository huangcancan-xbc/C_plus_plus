#include <atomic>

namespace minbit
{
    template<typename T>
    class shared_ptr
    {
    public:
        // 默认构造函数
        shared_ptr()
            : _ptr(nullptr),
            _count(nullptr)
        {

        }

        // 构造函数
        // 这里使用 explicit 关键字，防止隐式类型转换
        // shared_ptr<int> ptr1 = new int(10);  不允许出现
        explicit shared_ptr(T* p)
            : _ptr(p),
            _count(p ? new std::atomic<std::size_t>(1) : nullptr)
        {

        }

        // 析构函数
        ~shared_ptr()
        {
            release();
        }

        // 拷贝构造函数
        shared_ptr(const shared_ptr& other)
            : _ptr(other._ptr),
            _count(other._count)
        {
            if (_count)
            {
                ++(*_count);
                //(*_count).fetch_add(1);
            }
        }

        // 拷贝赋值运算符
        shared_ptr<T>& operator=(const shared_ptr<T>& other)
        {
            if (this != &other)
            {
                release();
                _ptr = other._ptr;
                _count = other._count;

                if (_count)  // 如果原来有引用计数，则增加引用计数
                {
                    ++(*_count);
                    //(*_count).fetch_add(1);
                }
            }

            return *this;// 注意：拷贝赋值运算符必须返回 *this
        }

        // 移动构造函数
        // noexcept 关键字表示该函数不会抛出异常。
        // 标准库中的某些操作（如 std::swap）要求移动操作是 noexcept 的，以确保异常安全。
        // noexcept 可以帮助编译器生成更高效的代码，因为它不需要为异常处理生成额外的代码。
        shared_ptr(shared_ptr<T>&& other) noexcept
            : _ptr(other._ptr),
            _count(other._count)
        {
            other._ptr = nullptr;
            other._count = nullptr;
        }

        // 移动赋值运算符
        shared_ptr<T>& operator=(shared_ptr<T>&& other) noexcept
        {
            if (this != &other)
            {
                release();  // 释放当前资源
                _ptr = other._ptr;
                _count = other._count;
                other._ptr = nullptr;
                other._count = nullptr;
            }

            return *this;// 注意：移动赋值运算符必须返回 *this
        }

        // 解引用运算符
        T& operator*()
        {
            return *_ptr;
        }

        // 指针运算符
        T* operator->()
        {
            return _ptr;
        }

        // use_count():返回引用计数，即当前 shared_ptr 实例的引用数量（debug 用，避免依赖）
        size_t use_count() const
        {
            return _count ? _count->load() : 0;
            // load() 函数用于读取原子变量的值，返回其当前值。
        }

        // unique()：判断是否独占所有权（use_count () == 1）
        bool unique() const
        {
            return _count ? _count->load() == 1 : false;  // 注意：空指针检查
        }

        // get():返回原生指针，获取原生指针（不影响引用计数，谨慎使用）
        T* get() const
        {
            return _ptr;
        }

        // reset():释放当前持有对象的所有权（引用计数减1），当计数为0时自动释放资源。可选参数：新的原生指针(T*)或nullptr，不能传入另一个shared_ptr（类型要一致）
        void reset(T* p = nullptr)
        {
            if (p != _ptr)
            {
                release();
                _ptr = p;
                _count = p ? new std::atomic<std::size_t>(1) : nullptr;
            }
        }

        // swap():交换两个 shared_ptr 的所有权，类型要一样。
        void swap(shared_ptr<T>& other) noexcept
        {
            std::swap(_ptr, other._ptr);
            std::swap(_count, other._count);
        }

        // operator bool():判断是否指向有效内存（非 nullptr）
        explicit operator bool() const
        {
            return _ptr != nullptr;
        }

    private:
        T* _ptr;
        std::atomic<size_t>* _count;

        void release()
        {
            if (_count)
            {
                if (--(*_count) == 0)
                {
                    delete _ptr;
                    delete _count;
                }

                // 注意：这里不将 _ptr 和 _count 置为 nullptr
                // 因为其他拷贝可能还在使用它们
            }

            // 如果 _count 为 nullptr，什么都不做
        }
    };

    template <class T>
    void swap(shared_ptr<T>& a, shared_ptr<T>& b)
    {
        a.swap(b);
    }

    template <class T>
    bool operator==(const shared_ptr<T>& a, const shared_ptr<T>& b)
    {
        return a.get() == b.get();
    }

    template <class T>
    bool operator!=(const shared_ptr<T>& a, const shared_ptr<T>& b)
    {
        return !(a == b);
    }

    template<class T>
    bool operator==(const shared_ptr<T>& a, std::nullptr_t)
    {
        return a.get() == nullptr;
    }

    template<class T>
    bool operator!=(const shared_ptr<T>& a, std::nullptr_t)
    {
        return a.get() != nullptr;
    }
}


// make_shared() To be realized……