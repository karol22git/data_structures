#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites

#include "../source_code/BinaryTree.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( BinaryTreeTestSuite ) 

struct node<int> *head = MyDataStructures::BinaryTree::BinaryTreeInit(10);
BOOST_AUTO_TEST_CASE(test1,  *boost::unit_test::description("testing initialization")) {
    BOOST_CHECK(MyDataStructures::BinaryTree::Contains(head,10)==true);
    BOOST_CHECK(MyDataStructures::BinaryTree::Contains(head,19)==false);
}

BOOST_AUTO_TEST_CASE(test2, *boost::unit_test::description("testing adding")) {
    MyDataStructures::BinaryTree::AddNode(head,1);
    MyDataStructures::BinaryTree::AddNode(head,100);
    MyDataStructures::BinaryTree::AddNode(head,5);
    MyDataStructures::BinaryTree::AddNode(head,60);
    MyDataStructures::BinaryTree::AddNode(head,19);
    BOOST_CHECK(MyDataStructures::BinaryTree::Contains(head,100)==true);
    BOOST_CHECK(MyDataStructures::BinaryTree::Contains(head,19)==true);
    BOOST_CHECK(MyDataStructures::BinaryTree::Contains(head,1000)==false);
    BOOST_CHECK(MyDataStructures::BinaryTree::Contains(head,20)==false);

}

BOOST_AUTO_TEST_CASE(test3, *boost::unit_test::description("testing deletions")) {
    MyDataStructures::BinaryTree::DeleteNode(head,100);
    BOOST_TEST(MyDataStructures::BinaryTree::Contains(head,100) == false);
    MyDataStructures::BinaryTree::DeleteNode(head,5);
    BOOST_TEST(MyDataStructures::BinaryTree::Contains(head,5) == false);
}

BOOST_AUTO_TEST_SUITE_END()