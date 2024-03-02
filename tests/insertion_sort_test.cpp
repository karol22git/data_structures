#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites

#include "../source_code/MyAlgorithms.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( InsertionSortSuite )

BOOST_AUTO_TEST_CASE(test1, *boost::unit_test::description("testing one element array")) {
    int array[1] = {1};
    MyAlgorithms::InsertionSort(array,1);
    BOOST_CHECK(array[0]==1);
}

BOOST_AUTO_TEST_CASE(test2, *boost::unit_test::description("testing array of size bigger than 1")){
    int array[10] = {10, 9, 8, 7, 6, 1, 2, 3, 4, 5,};
    MyAlgorithms::InsertionSort(array,10);
    BOOST_CHECK(array[0] == 1);
    BOOST_CHECK(array[9] == 10);
    BOOST_CHECK(array[5] == 6);
}

BOOST_AUTO_TEST_SUITE_END()