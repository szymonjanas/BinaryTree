#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "Tree.hpp"
#include "TreeAlgorithm.hpp"

using namespace std;

struct testTree: public ::testing::Test
{
    Tree<int> tr;
    vector<shared_ptr<Node<int>>> data;
    vector<int> addElementsToTree(unsigned int howMany)
    {
        vector<int> vec;
        for (unsigned int i = 0; i < howMany; i++) {
            auto node = make_shared<Node<int>>(i);
            data.push_back(node);
            tr.push(node);
            vec.push_back(i);
        }
        return vec;
    }

};

TEST_F(testTree, traversalTest)
{
    vector<shared_ptr<Node<int>>> empty_data(treeAlgorithms::treeTraversal<int>(tr.getHead()));
    ASSERT_EQ(empty_data.size(), 0);

    unsigned int howMany = 20;
    vector<int> vec(addElementsToTree(howMany));
    vector<shared_ptr<Node<int>>> data(treeAlgorithms::treeTraversal<int>(tr.getHead()));

    ASSERT_EQ(tr.getTreeSize(), 20);
    ASSERT_EQ(vec[4], 4);
    ASSERT_EQ(20, data.size());
    ASSERT_EQ(vec[4], data[4]->value);

    bool checker = true;
    for (unsigned int i = 0; i < howMany-1; i++)
    {
        if (vec[i] != data[i]->value) checker = false;
    }
    ASSERT_TRUE(checker);
}
