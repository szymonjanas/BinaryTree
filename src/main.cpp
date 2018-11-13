#include "Tree.hpp"
#include "TreeAlgorithm.hpp"
#include <iostream>

using namespace std;

int main()
{
    Tree<int> tr;
    auto node1 = make_shared<Node<int>>(0);
    tr.push(node1);
    auto node2 = make_shared<Node<int>>(3);
    tr.push(node2);
    auto node3 = make_shared<Node<int>>(2);
    tr.push(node3);
    auto node4 = make_shared<Node<int>>(5);
    tr.push(node4);
    auto node5 = make_shared<Node<int>>(1);
    tr.push(node5);

    vector<shared_ptr<Node<int>>> data(treeAlgorithms::treeTraversal<int>(tr.getHead()));

    for (int i = 0; i < 5; i++) {
        cout << data[i]->value << endl;
    }

    return 0;
}
