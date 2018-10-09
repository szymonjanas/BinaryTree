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

    ASSERT_EQ(tr.getTreeSize(), 0);

    tr.push(node);

    ASSERT_EQ(tr.getTreeSize(), 1);
    ASSERT_EQ(tr.getHead()->value, 1001);
}

TEST_F(testTree, push_second_right_element_to_empty_list)
{
    auto node1 = make_shared<Node<int>>(1);
    auto node2 = make_shared<Node<int>>(2);

    ASSERT_EQ(tr.getTreeSize(), 0);
    tr.push(node1);
    tr.push(node2);

    ASSERT_EQ(tr.getTreeSize(), 2);

    ASSERT_EQ(tr.getHead()->value, 1);
    ASSERT_EQ(tr.getHead()->right.lock()->value, 2);
}
