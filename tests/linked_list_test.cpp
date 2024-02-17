#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites

#include "../source_code/MyDataStructures.hpp"
#include <boost/test/unit_test.hpp>
void testing_initializing_list() {
    struct node<int> *head = MyDataStructures::LinkedList::LinkedListInit(10);
    BOOST_CHECK(MyDataStructures::LinkedList::Contains(head,10) == true);
    BOOST_CHECK(MyDataStructures::LinkedList::Size(head) == 1);
    BOOST_CHECK(MyDataStructures::LinkedList::GetLastNode(head) == head);

}
BOOST_AUTO_TEST_SUITE( LinkedlistSuite)
struct node<int> *head = MyDataStructures::LinkedList::LinkedListInit(10);
BOOST_AUTO_TEST_CASE(test1, *boost::unit_test::description("testing initialization of linked list") ) {
    BOOST_CHECK(MyDataStructures::LinkedList::Contains(head,10) == true);
}
BOOST_AUTO_TEST_CASE(test2,*boost::unit_test::description("checking list size")) {
    BOOST_CHECK(MyDataStructures::LinkedList::Size(head) == 1);
}
BOOST_AUTO_TEST_CASE(test3, *boost::unit_test::description("checking first node of list")){
    BOOST_CHECK(MyDataStructures::LinkedList::GetLastNode(head) == head);
}

BOOST_AUTO_TEST_CASE(test4, *boost::unit_test::description("cheking adding")){
    for(int i = 1 ; i < 5 ; ++i) {
        MyDataStructures::LinkedList::AddNode(head,i);
    }
    BOOST_CHECK(MyDataStructures::LinkedList::Size(head) == 5);
    BOOST_CHECK(MyDataStructures::LinkedList::Contains(head,1) == true);
    
}
BOOST_AUTO_TEST_SUITE_END()