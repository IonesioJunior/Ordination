/*
* @author Ionésio Junior
*/
#include <iostream>

//QuickSort.hpp
template<typename T> class QuickSort{
	public:
		void sort(T array[],int leftIndex,int rightIndex,int size);
		void sort(T array[],int size);
	private:
		int partition(T array[],int leftIndex,int rightIndex);
		int recursivePartition(T array[],int leftIndex,int rightIndex);
		int recursiveLoopPartition(T array[],T pivot,int rightIndex,int index,int pivot_index);
		bool validateParams(T array[],int leftIndex,int rightIndex,int size);
		void swap(T array[],int i,int j);
		void showArray(T array[],int size);
};

//QuickSort.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void QuickSort<T>::sort(T array[],int leftIndex,int rightIndex,int size){
	if(validateParams(array,leftIndex,rightIndex,size)){
		//int partition = this->partition(array,leftIndex,rightIndex);
		int partition = this->recursivePartition(array,leftIndex,rightIndex);
		this->sort(array,leftIndex,partition - 1,size);
		this->sort(array,partition + 1,rightIndex,size);
	}else{
		//Do nothing
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
		
template<typename T>
void QuickSort<T>::sort(T array[],int size){
	this->sort(array,0,size - 1 ,size);
}

///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
int QuickSort<T>::partition(T array[],int leftIndex,int rightIndex){
	T pivot = array[leftIndex];	
	int pivotIndex = leftIndex;
	for(int i = leftIndex +  1; i <= rightIndex;i++){
		if(pivot > array[i]){
			pivotIndex++;
			swap(array,pivotIndex,i);
		}
	}
	swap(array,leftIndex,pivotIndex);
	return pivotIndex;
}

///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
		
template<typename T>
int QuickSort<T>::recursivePartition(T array[],int leftIndex,int rightIndex){
	int pivot_index = leftIndex;
	T pivot = array[leftIndex];
	pivot_index = this->recursiveLoopPartition(array,pivot,rightIndex,pivot_index + 1,pivot_index);
	swap(array,leftIndex,pivot_index);
	return pivot_index;
}

///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
		
template<typename T>
int QuickSort<T>::recursiveLoopPartition(T array[],T pivot,int rightIndex,int index,int pivot_index){
	if(index <= rightIndex){
		if(pivot > array[index]){
			pivot_index++;
			swap(array,pivot_index,index);
		}
		return this->recursiveLoopPartition(array,pivot,rightIndex,index + 1,pivot_index);
	}else{
		return pivot_index;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
bool QuickSort<T>::validateParams(T array[],int leftIndex,int rightIndex,int size){
	if(array == NULL || leftIndex < 0 || rightIndex > size - 1 || leftIndex >= rightIndex){
		return false;
	}else{
		return true;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
		
template<typename T>
void QuickSort<T>::swap(T array[],int i,int j){
	T aux = array[i];
	array[i] = array[j];
	array[j] = aux;
}

///////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////
		
template<typename T>
void QuickSort<T>::showArray(T array[],int size){
	std::cout << "Array : [";
	for(int i = 0 ; i < size; i++){
		if(i != size - 1){
			std::cout << array[i] << ",";
		}else{
			std::cout << array[i] << "]";
		}
	}
	std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
