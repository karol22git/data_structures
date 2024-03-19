#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites

#include "../source_code/MyAlgorithms.hpp"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE( HeapSortSuite )

BOOST_AUTO_TEST_CASE(test1, *boost::unit_test::description("testing array of size bigger than 1")) {
    int array[10] = {10,5,11,20,1,2,100, 50, 3, 15};
    MyAlgorithms::HeapSort(array,10);
    BOOST_CHECK(array[0] == 1);
    BOOST_CHECK(array[9] == 100);
    BOOST_CHECK(array[4] == 10);
}

BOOST_AUTO_TEST_CASE(test2, *boost::unit_test::description("testing array of size 1")) {
    int array[1] = {1};
    MyAlgorithms::HeapSort(array,1);
    BOOST_CHECK(array[0] == 1);
}

BOOST_AUTO_TEST_SUITE_END()