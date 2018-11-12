#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "Tree.hpp"
#include "TreeAlgorithm.hpp"

using namespace std;

struct testTree: public ::testing::Test
{
    Tree<int> tr;
};

TEST_F(testTree, traversalTest)
{
    auto node1 = make_shared<Node<int>>(0);
    tr.push(node1);
    auto node2 = make_shared<Node<int>>(1);
    tr.push(node2);
    auto node3 = make_shared<Node<int>>(2);
    tr.push(node3);
    auto node4 = make_shared<Node<int>>(3);
    tr.push(node4);
    auto node5 = make_shared<Node<int>>(4);
    tr.push(node5);

    vector<shared_ptr<Node<int>>> data(treeAlgorithms::treeTraversal<int>(tr.getHead()));

    ASSERT_EQ(tr.size(), 5);
    ASSERT_EQ(5, data.size());

    bool checker = true;
    for (int i = 0; i < 5; i++)
    {
        if (i != data[i]->value) checker = false;
    }
    ASSERT_TRUE(checker);
}
