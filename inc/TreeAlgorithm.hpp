#pragma once

#include "Tree.hpp"
#include <memory>
#include <queue>
#include <vector>

using namespace std;

template<typename T>
using node_ptr = shared_ptr<Node<T>>;

namespace treeAlgorithms
{
template<typename T>
vector<node_ptr<T>> treeTraversal(node_ptr<T> head)
{
    vector<node_ptr<T>> vec;

    if (head == nullptr) return vec;

    node_ptr<T> ptr = head;
    queue<node_ptr<T>> que;
    que.push(ptr);

    while(!que.empty())
    {
        ptr = que.front();
        que.pop();

        if (ptr != nullptr) vec.push_back(ptr);
        if (ptr->left.lock() != nullptr) que.push(ptr->left.lock());
        if (ptr->right.lock() != nullptr) que.push(ptr->right.lock());
    }

    return vec;
}

}
