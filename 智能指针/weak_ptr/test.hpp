#pragma once

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    Node(int val) : value(val)
    {
        cout << "Node " << value << " 构造" << endl;
    }

    ~Node()
    {
        cout << "Node " << value << " 析构" << endl;
    }

    int value;                    // 节点存储的值
    shared_ptr<Node> next;        // 强引用指针，指向下一个节点
    weak_ptr<Node> parent;        // 弱引用指针，指向上一个节点（避免循环引用）
};