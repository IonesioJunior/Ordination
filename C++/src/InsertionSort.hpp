/*
* @author Ionésio Junior
*/
#include <iostream>


//InsertionSort.hpp

template<class T> class InsertionSort{
	public:
		void sort(T array[],int leftIndex,int rightIndex,int size);
		void sort(T array[],int size);
	private:
		bool validateParams(T array[],int leftIndex,int rightIndex,int size);
		void swap(T array[],int i,int j);
		void simpleInsertionSort(T array[],int leftIndex,int rightIndex);
		void recursiveInsertionSort(T array[],int leftIndex,int rightIndex,int pivot);
		void recursiveSwitchBack(T array[],int leftIndex,int pivot);
		void showArray(T array[],int size);
};

//InsertionSort.cpp
///////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void InsertionSort<T>::sort(T array[],int leftIndex,int rightIndex,int size){
	if(validateParams(array,leftIndex,rightIndex,size)){
		//this->simpleInsertionSort(array,leftIndex,rightIndex);
		this->recursiveInsertionSort(array,leftIndex,rightIndex,leftIndex);
	}else{
		std::cout << "Entrando aqui!!" << std::endl;
		//Do nothing
	}
}

///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void InsertionSort<T>::sort(T array[],int size){
	this->sort(array,0,size-1,size);	
}

///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
bool InsertionSort<T>::validateParams(T array[],int leftIndex,int rightIndex,int size){
	if(array == NULL || leftIndex < 0 || rightIndex > size-  1 || leftIndex >= rightIndex){
		return false;
	}else{
		return true;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void InsertionSort<T>::swap(T array[],int i,int j){
	T aux = array[i];
	array[i] = array[j];
	array[j] = aux;
}

///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void InsertionSort<T>::simpleInsertionSort(T array[],int leftIndex,int rightIndex){
	for(int i = leftIndex;i <= rightIndex;i++){
		int j = i;
		while(j > leftIndex && array[j] < array[j-1]){
			swap(array,j,j-1);
			j--;
		}
	}	
}

///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void InsertionSort<T>::recursiveInsertionSort(T array[],int leftIndex,int rightIndex,int pivot){
	if(pivot <= rightIndex){
		this->recursiveSwitchBack(array,leftIndex,pivot);
		this->recursiveInsertionSort(array,leftIndex,rightIndex,pivot + 1);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void InsertionSort<T>::recursiveSwitchBack(T array[],int leftIndex,int pivot){
	if(pivot > leftIndex && array[pivot] < array[pivot - 1]){
		swap(array,pivot,pivot - 1);
		this->recursiveSwitchBack(array,leftIndex,pivot -1);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void InsertionSort<T>::showArray(T array[],int size){
	std::cout << "Array : [";
	for(int i = 0 ; i < size; i++){
		if(i != size- 1){
			std::cout << array[i] << ",";
		}else{
			std::cout << array[i] << "]";
		}
	}
	std::cout << std::endl;
}
///////////////////////////////////////////////////////////////////////////////////////////
