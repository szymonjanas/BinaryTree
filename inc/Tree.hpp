#pragma once

#include "Node.hpp"

using namespace std;

template<typename T>
class Tree
{
    shared_ptr<Node<T>> head_;

    unsigned int treeSize_;

public:
    Tree()
        :
        head_(nullptr), treeSize_(0)
    {}

    ~Tree()
    {}

    shared_ptr<Node<T>> getHead() const noexcept;

    unsigned int getTreeSize() const noexcept;

    void push(shared_ptr<Node<T>> node);

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
void Tree<T>::push(shared_ptr<Node<T>> node)
{
    weak_ptr<Node<T>> current (head_);

    if (head_ == nullptr) {
        head_ = node;
        treeSize_++;
        return;
    }

    while (current.lock() != nullptr) {
        if (current.lock()->value > node->value) {
            if (current.lock()->left.lock() == nullptr) {
                current.lock()->left;
                treeSize_++;
                return;
            }
            else current = current.lock()->left;
        }
        if (current.lock()->value < node->value) {
            if (current.lock()->right.lock() == nullptr) {
                current.lock()->right = node;
                treeSize_++;
                return;
            }
            else current = current.lock()->right;
        }
    }
}
