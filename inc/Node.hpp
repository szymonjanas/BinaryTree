#pragma once
#include <memory>

using namespace std;

template<typename T>
struct Node
{
    T value;
    weak_ptr<Node<T>> left;
    weak_ptr<Node<T>> right;
    
    Node() : 
        value(0) {}
    Node(T data) :
        value(data) {}
    ~Node(){}
};
