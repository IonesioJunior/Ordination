/*
* @author Ionésio Junior
*/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SortingTest
#include <boost/test/unit_test.hpp>
#include "src/BubbleSort.hpp"
#include "src/SelectionSort.hpp"
#include "src/InsertionSort.hpp"
#include "src/GnomeSort.hpp"
#include "src/MergeSort.hpp"
#include "src/QuickSort.hpp"
#include "src/QuickMedianOfThree.hpp"

struct SortingAlgorithms{
	//Algorithms
	BubbleSort<int>* bubble = new  BubbleSort<int>();;
	SelectionSort<int>* selection = new SelectionSort<int>();
	InsertionSort<int>* insertion = new InsertionSort<int>();
	GnomeSort<int>* gnome = new GnomeSort<int>();
	MergeSort<int>* merge = new MergeSort<int>();
	QuickSort<int>* quick = new QuickSort<int>();
	QuickMedianOfThree<int>* qMedian = new QuickMedianOfThree<int>();
	int even[10] = {9,8,7,6,5,4,3,2,1,0};
	int odd[9] = {9,8,7,6,5,4,3,2,1};
	int repeated[9] = {8,5,8,5,9,5,7,8,5};
	int equal[5] = {5,5,5,5,5};
	int evenOrdered[10] = {0,1,2,3,4,5,6,7,8,9};
	int oddOrdered[9] = {1,2,3,4,5,6,7,8,9};
};

BOOST_FIXTURE_TEST_SUITE(SortingTEST,SortingAlgorithms)

BOOST_AUTO_TEST_CASE(evenSortingTest)
{	
	int size = 10;
	int evenArray[10];
	
	//BubbleSort Test
	std::copy(even, even+10, evenArray);
	bubble->sort(evenArray,size);
	for(int i = 0 ; i < size;i++){
		BOOST_CHECK(evenOrdered[i] == evenArray[i]);	
	}
	
	//SelectionSort Test
        std::copy(even, even+10, evenArray);
        selection->sort(evenArray,size);
        for(int i = 0 ; i < size;i++){
                BOOST_CHECK(evenOrdered[i] == evenArray[i]);
        }
	
	//InsertionSort Test
        std::copy(even, even+10, evenArray);
        insertion->sort(evenArray,size);
        for(int i = 0 ; i < size;i++){
                BOOST_CHECK(evenOrdered[i] == evenArray[i]);
        }
	
	//GnomeSort Test
	std::copy(even, even+10, evenArray);
       	gnome->sort(evenArray,size);
        for(int i = 0 ; i < size;i++){
                BOOST_CHECK(evenOrdered[i] == evenArray[i]);
        }

	//QuickSort Test
        std::copy(even, even+10, evenArray);
        quick->sort(evenArray,size);
        for(int i = 0 ; i < size;i++){
                BOOST_CHECK(evenOrdered[i] == evenArray[i]);
        }

	//MergeSort Test
        std::copy(even, even+10, evenArray);
        merge->sort(evenArray,size);
        for(int i = 0 ; i < size;i++){
                BOOST_CHECK(evenOrdered[i] == evenArray[i]);
        }

	//QuickSort Median of Three
        std::copy(even, even+10, evenArray);
        qMedian->sort(evenArray,size);
        for(int i = 0 ; i < size;i++){
                BOOST_CHECK(evenOrdered[i] == evenArray[i]);
        }





}


BOOST_AUTO_TEST_CASE(oddSortingTest){
	int oddArray[9];

	//BubbleSort Test
	std::copy(odd,odd+9,oddArray);
	bubble->sort(oddArray,9);
	for(int i = 0 ; i < 9;i++){
		BOOST_CHECK(oddOrdered[i] == oddArray[i]);
	}

	//InsertionSort Test
        std::copy(odd,odd+9,oddArray);
        insertion->sort(oddArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(oddOrdered[i] == oddArray[i]);
        }


	//SelectionSort Test
        std::copy(odd,odd+9,oddArray);
        selection->sort(oddArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(oddOrdered[i] == oddArray[i]);
        }


	//GnomeSort Test
        std::copy(odd,odd+9,oddArray);
        gnome->sort(oddArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(oddOrdered[i] == oddArray[i]);
        }

	//MergeSort Test
        std::copy(odd,odd+9,oddArray);
        merge->sort(oddArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(oddOrdered[i] == oddArray[i]);
        }


	//QuickSort Test
        std::copy(odd,odd+9,oddArray);
        quick->sort(oddArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(oddOrdered[i] == oddArray[i]);
        }

	//QuickSort with MedianOfThree  Test
        std::copy(odd,odd+9,oddArray);
       	qMedian->sort(oddArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(oddOrdered[i] == oddArray[i]);
        }
}
BOOST_AUTO_TEST_CASE(repeatedSortingTest){
	int repeatedArray[9];
	int repeatedOrdered[9] = {5,5,5,5,7,8,8,8,9};
	
	//BubbleSort Test
	std::copy(repeated,repeated+9,repeatedArray);
	bubble->sort(repeatedArray,9);
	for(int i = 0 ; i < 9;i++){
		BOOST_CHECK(repeatedArray[i] == repeatedOrdered[i]);
	}


	//InsertionSort Test
        std::copy(repeated,repeated+9,repeatedArray);
        insertion->sort(repeatedArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(repeatedArray[i] == repeatedOrdered[i]);
        }

	//SelectionSort Test
        std::copy(repeated,repeated+9,repeatedArray);
        selection->sort(repeatedArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(repeatedArray[i] == repeatedOrdered[i]);
        }

	//GnomeSort Test
        std::copy(repeated,repeated+9,repeatedArray);
        gnome->sort(repeatedArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(repeatedArray[i] == repeatedOrdered[i]);
        }

	//MergeSort Test
        std::copy(repeated,repeated+9,repeatedArray);
        merge->sort(repeatedArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(repeatedArray[i] == repeatedOrdered[i]);
        }

	//QuickSort Test
	std::copy(repeated,repeated+9,repeatedArray);
        quick->sort(repeatedArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(repeatedArray[i] == repeatedOrdered[i]);
        }

	//Quick with median of three Test
        std::copy(repeated,repeated+9,repeatedArray);
        qMedian->sort(repeatedArray,9);
        for(int i = 0 ; i < 9;i++){
                BOOST_CHECK(repeatedArray[i] == repeatedOrdered[i]);
        }

}

BOOST_AUTO_TEST_CASE(equalSortingTest){
	int equalArray[5];

	//BubbleSort Test
	std::copy(equal,equal+5,equalArray);
	bubble->sort(equalArray,5);
	for(int i = 0 ; i< 5 ;i++){
		BOOST_CHECK(equalArray[i] == equal[i]);
	}

	//InsertionSort Test
        std::copy(equal,equal+5,equalArray);
        insertion->sort(equalArray,5);
        for(int i = 0 ; i< 5 ;i++){
                BOOST_CHECK(equalArray[i] == equal[i]);
        }

	//SelectionSort Test
        std::copy(equal,equal+5,equalArray);
        selection->sort(equalArray,5);
        for(int i = 0 ; i< 5 ;i++){
                BOOST_CHECK(equalArray[i] == equal[i]);
        }

	//GnomeSort Test
        std::copy(equal,equal+5,equalArray);
        gnome->sort(equalArray,5);
        for(int i = 0 ; i< 5 ;i++){
                BOOST_CHECK(equalArray[i] == equal[i]);
        }

	//MergeSort test
        std::copy(equal,equal+5,equalArray);
        merge->sort(equalArray,5);
        for(int i = 0 ; i< 5 ;i++){
                BOOST_CHECK(equalArray[i] == equal[i]);
        }

	//QuickSort test
        std::copy(equal,equal+5,equalArray);
        quick->sort(equalArray,5);
        for(int i = 0 ; i< 5 ;i++){
                BOOST_CHECK(equalArray[i] == equal[i]);
        }

	//QuickSort  with median of three Test
        std::copy(equal,equal+5,equalArray);
        qMedian->sort(equalArray,5);
        for(int i = 0 ; i< 5 ;i++){
                BOOST_CHECK(equalArray[i] == equal[i]);
        }

}
BOOST_AUTO_TEST_SUITE_END()
