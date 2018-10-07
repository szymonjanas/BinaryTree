#pragma once

#include "Node.hpp"

using namespace std;

template<typename T>
class Tree
{
    shared_ptr<Node<T>> head_;

    unsigned int treeSize_;

    public:
    Tree() :
        head_(nullptr), treeSize_(0) {}
    ~Tree(){}

    shared_ptr<Node<T>> getHead() const noexcept;
    unsigned int getTreeSize() const noexcept;

    void push(shared_ptr<Node<T>>&);

};

template<typename T>
shared_ptr<Node<T>> Tree<T>::getHead() const noexcept
{
    return head_;
}

template<typename T>
unsigned int Tree<T>::getTreeSize() const noexcept
{
    return treeSize_;
}

template<typename T>
void Tree<T>::push(shared_ptr<Node<T>>& node)
{
    if (head_ == nullptr)
    {
        head_ = node;
        treeSize_++;
    }
}
