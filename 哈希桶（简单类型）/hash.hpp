#pragma once
#include "node.hpp"

// 直接使用std::hash
template <class K>
struct Hash
{
    size_t operator()(const K& key) const
    {
        return std::hash<K>()(key);
    }
};

// 对string进行特化（虽然std::hash<string>已经很好）
template<>
struct Hash<std::string>
{
    size_t operator()(const std::string& s) const
    {
        size_t hash = 0;

        for (char ch : s)
        {
            hash = hash * 131 + ch;  // 使用更优的BKDRHash算法（通常选131、13331等质数）
        }

        return hash;
    }
};



// 更多的自定义类型、复杂类型的特化，要对什么类型做哈希就写什么样的仿函数


#include "hashBucket.hpp"