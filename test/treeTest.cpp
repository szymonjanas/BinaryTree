#include <gtest/gtest.h>
#include <memory>
#include "Tree.hpp"

using namespace std;

struct testTree: public ::testing::Test
{
    Tree<int> tr;
};

TEST_F(testTree, push_first_element_to_empty_list)
{
    auto node = make_shared<Node<int>>(1001);

    ASSERT_EQ(tr.size(), 0);

    tr.push(node);

    ASSERT_EQ(tr.size(), 1);
    ASSERT_EQ(tr.getHead()->value, 1001);
}

TEST_F(testTree, push_second_right_element_to_empty_list)
{
    auto node1 = make_shared<Node<int>>(1);
    auto node2 = make_shared<Node<int>>(2);

    ASSERT_EQ(tr.size(), 0);
    tr.push(node1);
    tr.push(node2);

    ASSERT_EQ(tr.size(), 2);

    ASSERT_EQ(tr.getHead()->value, 1);
    ASSERT_EQ(tr.getHead()->right.lock()->value, 2);
}

TEST_F(testTree, push_thrid_left_element_to_empty_list)
{
    auto node1 = make_shared<Node<int>>(2);
    auto node2 = make_shared<Node<int>>(3);
    auto node3 = make_shared<Node<int>>(1);
    ASSERT_EQ(tr.size(), 0);
    tr.push(node1);
    tr.push(node2);
    tr.push(node3);

    ASSERT_EQ(tr.size(), 3);

    ASSERT_EQ(tr.getHead()->value, 2);
    ASSERT_EQ(tr.getHead()->left.lock()->value, 1);
}

TEST_F(testTree, clear_five_elements_tree)
{
    auto node1 = make_shared<Node<int>>(1);
    auto node2 = make_shared<Node<int>>(2);
    auto node3 = make_shared<Node<int>>(3);
    auto node4 = make_shared<Node<int>>(4);
    auto node5 = make_shared<Node<int>>(5);
    ASSERT_EQ(tr.size(), 0);
    tr.push(node1);
    tr.push(node2);
    tr.push(node3);
    tr.push(node4);
    tr.push(node5);
    ASSERT_EQ(tr.size(), 5);
    tr.clear();
    ASSERT_EQ(tr.size(), 0);
}
