#pragma once

#include "Node.hpp"
#include <queue>

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

    unsigned int size() const noexcept;

    void push(shared_ptr<Node<T>> node);

    bool clear();


};

template<typename T>
shared_ptr<Node<T>> Tree<T>::getHead() const noexcept
{
    return head_;
}

template<typename T>
unsigned int Tree<T>::size() const noexcept
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
                current.lock()->left = node;
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

template<typename T>
bool Tree<T>::clear()
{
    shared_ptr<Node<T>> ptr = head_;
    queue<shared_ptr<Node<T>>> que;
    que.push(ptr);

    while (!que.empty()) {
        ptr = que.front();
        que.pop();

        if (ptr->left.lock() != nullptr) que.push(ptr->left.lock());
        if (ptr->right.lock() != nullptr) que.push(ptr->right.lock());
        if (ptr != nullptr) ptr.reset();
        --treeSize_;
    }
    head_ = nullptr;
    return true;
}
