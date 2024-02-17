#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites

#include "MyDataStructures.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( LinkedlistSuite )
BOOST_AUTO_TEST_CASE( linked_list_test ) {
    struct node<int> *head = MyDataStructures::LinkedList::LinkedListInit(10);
    for(int i = 1 ; i < 5 ; ++i) {
        MyDataStructures::LinkedList::AddNode(head,i*20);
    }
    BOOST_CHECK(MyDataStructures::LinkedList::Contains(head,10) == true);
}

BOOST_AUTO_TEST_SUITE_END()