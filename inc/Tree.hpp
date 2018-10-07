#pragma once

#include "Node.hpp"

template<typename T>
class Tree
{
    shared_ptr<Node<T>> head_;

    unsigned int treeSize_;

    public:
    Tree() :
        head(nullptr), treeSize(0) {}
    ~Tree(){}

    shared_ptr<Node<T>> getHead() const noexcept;
    unsigned int getTreeSize() const noexcept;

    void push();

};

template<typename T>
shared_ptr<Node<T>> Tree::getHead() const noexcept
{
    return head_;
}

template<typename T>
unsigned int Tree::getTreeSize() const noexcept
{
    return treeSize_;
}

template<typename T>
void Tree::push()
{

}
