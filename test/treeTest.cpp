#include <gtest/gtest.h>

#include "Tree.hpp"

struct testTree : ::testing::TEST
{
    Tree<int> tr;
};

TEST_F(testTree, push_first_element_to_empty_list)
{
    shared_ptr<Tree<int>> node = make_shared<Tree<int>>(1001);
    
    ASSERT_EQ(tr.getTreeSize(), 0);

    tr.push(node);

    ASSERT_EQ(tr.getTreeSize(), 1);
    ASSERT_EQ(tr.getHead()->value, 1001);
}
