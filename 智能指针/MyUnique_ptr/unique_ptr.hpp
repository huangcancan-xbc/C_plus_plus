#pragma once
#include <utility>

namespace minbit
{
    //template <typename T>
    template <class T>
    class unique_ptr
    {
    public:
        explicit unique_ptr(T* ptr = nullptr)
            : _ptr(ptr)
        {

        }

        ~unique_ptr()
        {
            delete _ptr;
        }

        // 禁用拷贝构造函数和拷贝赋值运算符
        unique_ptr(const unique_ptr&) = delete;
        unique_ptr& operator=(const unique_ptr&) = delete;

        // unique_ptr允许使用移动构造函数，但要求类型要一样。
        // 方法一：直接使用 std::exchange() 函数，其用法简单来说就是：
        // A = std::exchange(B, C);B是旧值，C是新值。输出结果：A的值等于B，B的值等于C。
        unique_ptr(unique_ptr&& other) noexcept
            :_ptr(std::exchange(other._ptr, nullptr))
        {

        }
        //// 方法二：手动交换
        //unique_ptr(unique_ptr&& other) noexcept
        //    :_ptr(other._ptr)
        //{
        //    other._ptr = ptr;
        //}
        //// 方法三：先保存在设置
        //unique_ptr(unique_ptr&& other) noexcept
        //{
        //    _ptr = other._ptr;
        //    other._ptr = ptr;
        //}
        //// ……


        unique_ptr& operator=(unique_ptr&& other) noexcept
        {
            if (this != &other)
            {
                delete _ptr;
                _ptr = std::exchange(other._ptr, nullptr);
            }

            return *this;
        }

        T* operator->() const
        {
            return _ptr;
        }

        T& operator*() const
        {
            return *_ptr;
        }


        // get() :返回原生指针，但不释放所有权（智能指针仍管着内存，会自动释放）
        T* get() const noexcept
        {
            return _ptr;
        }

        // reset():释放当前内存，重置为 nullptr（可选传新指针，要求类型要一样）
        void reset(T* ptr = nullptr)
        {
            if (_ptr != ptr)
            {
                delete _ptr;
                _ptr = ptr;
            }
        }
        //void reset()
        //{
        //    reset(nullptr);
        //}

        // release():返回原生指针，并且彻底释放所有权（智能指针不管了），必须手动delete，否则内存泄漏。
        T* release()
        {
            return std::exchange(_ptr, nullptr);
        }

        // swap():交换两个 unique_ptr 的所有权，类型要一样。
        void swap(unique_ptr& other)
        {
            std::swap(_ptr, other._ptr);
        }

        // operator bool():判断是否指向有效内存（非 nullptr）
        operator bool() const noexcept
        {
            return _ptr != nullptr;
        }
    private:
        T* _ptr;
    };

    // 数组版本的特化
    template<class T>
    class unique_ptr<T[]>
    {
    public:
        explicit unique_ptr<T[]>(T* ptr = nullptr)
            : _ptr(ptr)
        {
        }

        ~unique_ptr<T[]>()
        {
            delete[] _ptr;
        }

        unique_ptr(const unique_ptr<T[]>&) = delete;
        unique_ptr<T[]>& operator=(const unique_ptr<T[]>&) = delete;

        unique_ptr(unique_ptr<T[]>&& other) noexcept
            :_ptr(std::exchange(other._ptr, nullptr))
        {

        }

        unique_ptr<T[]>& operator=(unique_ptr<T[]>&& other) noexcept
        {
            if (this != &other)
            {
                delete[] _ptr;
                _ptr = std::exchange(other._ptr, nullptr);
            }

            return *this;
        }

        T& operator[](size_t index)
        {
            return _ptr[index];
        }

        T* get() const noexcept
        {
            return _ptr;
        }

        void reset(T* ptr = nullptr)
        {
            if (_ptr != ptr)
            {
                delete[] _ptr;
                _ptr = ptr;
            }
        }

        //void reset()
        //{
        //    reset(nullptr);
        //}

        T* release()
        {
            return std::exchange(_ptr, nullptr);
        }

        void swap(unique_ptr<T[]>& other)
        {
            std::swap(_ptr, other._ptr);
        }

        operator bool() const noexcept
        {
            return _ptr != nullptr;
        }
    private:
        T* _ptr;
    };

    template<class T>
    void swap(unique_ptr<T>& a, unique_ptr<T>& b)
    {
        a.swap(b);
    }

    template<class T>
    void swap(unique_ptr<T[]>& a, unique_ptr<T[]>& b)
    {
        a.swap(b);
    }


    template<class T>
    bool operator==(const unique_ptr<T>& a, const unique_ptr<T>& b)
    {
        return a.get() == b.get();
    }

    template<class T>
    bool operator!=(const unique_ptr<T>& a, const unique_ptr<T>& b)
    {
        return a.get() != b.get();
    }

    template<class T>
    bool operator==(const unique_ptr<T>& a, std::nullptr_t)
    {
        return a.get() == nullptr;
    }

    template<class T>
    bool operator!=(const unique_ptr<T>& a, std::nullptr_t)
    {
        return a.get() != nullptr;
    }
}

// make_unique() To be realized……