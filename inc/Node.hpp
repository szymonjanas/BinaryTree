#pragma once
#include <memory>

template<typename T>
struct Node
{
    T value;
    weak_ptr<Node> left;
    weak_ptr<Node> right;
    
    Node() : 
        value(0) {}
    Node(T data) :
        value(data) {}
    ~Node(){}
};
