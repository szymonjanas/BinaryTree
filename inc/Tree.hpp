#pragma once

#include "Node.hpp"

template<tyoename T>
class Tree
{
    shared_ptr<Node<T>> head;

    unsigned int treeSize;

    public:

    shared_ptr<Node<T>> getHead() const noexcept;
    unsigned int getTreeSize() const noexcept;

    void push();
    
};
