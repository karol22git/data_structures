#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites

#include "../source_code/MyAlgorithms.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( QuickSortSuite )

BOOST_AUTO_TEST_CASE(test1, *boost::unit_test::description(" testing array with one element")) {
    int array[1] = {1};
    MyAlgorithms::QuickSort(array,1,1);
    BOOST_CHECK(array[0] == 1);
}

BOOST_AUTO_TEST_CASE(test2, *boost::unit_test::description("testing array of size bigger than 1 ")) {
    int array[13] = {10,5,11,20,1,2,100, 50, 3, 15, 130, 99, 55};
    MyAlgorithms::QuickSort(array,0,13);
    BOOST_CHECK(array[0]==1);
    BOOST_CHECK(array[12] == 130);
    BOOST_CHECK(array[1]==2);
    BOOST_CHECK(array[11] == 100);
}

BOOST_AUTO_TEST_SUITE_END()