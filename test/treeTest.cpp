#include <gtest/gtest.h>
#include <memory>
#include "Tree.hpp"

using namespace std;

struct testTree : public ::testing::Test
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
