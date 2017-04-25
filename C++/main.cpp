#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include "BubbleSort.hpp"
int add(int i , int j ){return i  + j;}

BOOST_AUTO_TEST_CASE(addTest)
{
	BubbleSort<int> algorithm = BubbleSort<int>();
	int array[10] = {5,9,8,7,6,3,2,4,1,0};
	int size = sizeof(array) / sizeof(int);
	int orderedArray[10] = {0,1,2,3,4,5,6,7,8,9};
	algorithm.sort(array,size);
	for(int i = 0 ; i < size;i++){
		BOOST_CHECK(array[i] == orderedArray[i]);
	}
}
