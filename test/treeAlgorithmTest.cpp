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

TEST_F(testTree, traversal_test_when_tree_is_empty)
{
    vector<shared_ptr<Node<int>>> data(treeAlgorithms::treeTraversal<int>(tr.getHead()));
    ASSERT_EQ(tr.size(), 0);
    ASSERT_EQ(data.size(), 0);
}

TEST_F(testTree, traversal_test_when_tree_have_given_five_elements)
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

TEST_F(testTree, traversal_test_after_clear_five_elements_tree)
{
    auto node1 = make_shared<Node<int>>(0);
    tr.push(node1);
    auto node2 = make_shared<Node<int>>(3);
    tr.push(node2);
    auto node3 = make_shared<Node<int>>(5);
    tr.push(node3);
    auto node4 = make_shared<Node<int>>(2);
    tr.push(node4);
    auto node5 = make_shared<Node<int>>(1);
    tr.push(node5);

    vector<shared_ptr<Node<int>>> data(treeAlgorithms::treeTraversal<int>(tr.getHead()));

    ASSERT_EQ(tr.size(), 5);
    ASSERT_EQ(5, data.size());

    tr.clear();
    data.clear();
    ASSERT_EQ(data.size(), 0);
    data = treeAlgorithms::treeTraversal<int>(tr.getHead());
    ASSERT_EQ(data.size(), 0);
    ASSERT_EQ(tr.size(), 0);
}

TEST_F(testTree, traversal_test_pure_binary_tree_with_seven_elements)
{
    auto node1 = make_shared<Node<int>>(5);
    tr.push(node1);
    auto node2 = make_shared<Node<int>>(3);
    tr.push(node2);
    auto node3 = make_shared<Node<int>>(7);
    tr.push(node3);
    auto node4 = make_shared<Node<int>>(2);
    tr.push(node4);
    auto node5 = make_shared<Node<int>>(4);
    tr.push(node5);
    auto node6 = make_shared<Node<int>>(6);
    tr.push(node6);
    auto node7 = make_shared<Node<int>>(8);
    tr.push(node7);

    vector<int> vec = {5, 3, 7, 2, 4, 6, 8};
    vector<shared_ptr<Node<int>>> data(treeAlgorithms::treeTraversal<int>(tr.getHead()));

    bool checker = true;
    for (int i = 0; i < 7; i++) {
        if (vec[i] != data[i]->value) checker = false;
    }
    ASSERT_TRUE(checker);
}
