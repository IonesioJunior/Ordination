/*
* @author Ionésio Junior
*/

#include <iostream>

//SelectionSort.hpp
template<typename T> class SelectionSort{
	public:
		void sort(T array[],int leftIndex,int rightIndex,int size);	
		void sort(T array[],int size);
	private:
		void simpleSelectionSort(T array[],int leftIndex,int rightIndex);
		void bidirectionalSelectionSort(T array[],int leftIndex,int rightIndex);
		void recursiveSimpleSelectionSort(T array[],int leftIndex,int rightIndex);
		void recursiveBidirectionalSelectionSort(T array[],int leftIndex,int rightIndex);
		void recursiveGetMin(T array[],int leftIndex,int rightIndex,int min,int index);
		void recursiveGetMax(T array[],int leftIndex,int rightIndex,int max, int index);
		bool validateParams(T array[],int leftIndex,int rightIndex,int size);
		void swap(T array[],int i ,int j);	
		void showArray(T array[],int size);
};

//SelectionSort.cpp
/////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void SelectionSort<T>::sort(T array[],int leftIndex,int rightIndex,int size){
	if(validateParams(array,leftIndex,rightIndex,size)){
		//this->simpleSelectionSort(array,leftIndex,rightIndex);
		//this->bidirectionalSelectionSort(array,leftIndex,rightIndex);
		this->recursiveSimpleSelectionSort(array,leftIndex,rightIndex);
		//this->recursiveBidirectionalSelectionSort(array,leftIndex,rightIndex);
		this->showArray(array,size);
	}else{
		std::cout << "Entrou na area errada!!" << std::endl;
	}
}	

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void SelectionSort<T>::sort(T array[],int size){
	this->sort(array,0,size - 1 ,size);
}

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void SelectionSort<T>::simpleSelectionSort(T array[],int leftIndex,int rightIndex){
	while(leftIndex < rightIndex){
		int minIndex = leftIndex;
		for(int j = leftIndex + 1; j <= rightIndex;j++){
			if(array[minIndex] > array[j]){
				minIndex = j;
			}
		}
		swap(array,leftIndex++,minIndex);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////
		
template<typename T>
void SelectionSort<T>::bidirectionalSelectionSort(T array[],int leftIndex,int rightIndex){
	while(leftIndex < rightIndex){
		int minIndex = leftIndex;
		for(int j = leftIndex + 1;j <= rightIndex;j++){
			if(array[minIndex] > array[j]){
				minIndex = j;
			}
		}
		
		swap(array,leftIndex++,minIndex);
		
		int maxIndex = rightIndex;
		for(int i = rightIndex; i >= leftIndex;i--){
			if(array[maxIndex] < array[i]){
				maxIndex = i;
			}
		}
		swap(array,rightIndex--,maxIndex);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////
		
template<typename T>
void SelectionSort<T>::recursiveSimpleSelectionSort(T array[],int leftIndex,int rightIndex){
	if(leftIndex < rightIndex){
		this->recursiveGetMin(array,leftIndex,rightIndex,leftIndex,leftIndex);
		this->recursiveSimpleSelectionSort(array,leftIndex +1,rightIndex);
	}	
}

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void SelectionSort<T>::recursiveBidirectionalSelectionSort(T array[],int leftIndex,int rightIndex){
	if(leftIndex < rightIndex){
		this->recursiveGetMin(array,leftIndex,rightIndex,leftIndex,leftIndex);
		this->recursiveGetMax(array,leftIndex,rightIndex,rightIndex,rightIndex);
		this->recursiveBidirectionalSelectionSort(array,leftIndex + 1,rightIndex- 1);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void SelectionSort<T>::recursiveGetMin(T array[],int leftIndex,int rightIndex,int min,int index){
	if(index <= rightIndex){
		if(array[min] >array[index]){
			min = index;
		}
		this->recursiveGetMin(array,leftIndex,rightIndex,min,index + 1);
	}else{
		swap(array,leftIndex,min);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////
	
template<typename T>
void SelectionSort<T>::recursiveGetMax(T array[],int leftIndex,int rightIndex,int max, int index){
	if(index >= leftIndex){
		if(array[max] < array[index]){
			max = index;
		}
		this->recursiveGetMax(array,leftIndex,rightIndex,max,index -1);
	}else{
		swap(array,rightIndex,max);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
bool SelectionSort<T>::validateParams(T array[],int leftIndex,int rightIndex,int size){
	if(array == NULL || leftIndex < 0 || rightIndex > size - 1 || leftIndex >= rightIndex){
		return false;
	}else{
		return true;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////
		
template<typename T>
void SelectionSort<T>::swap(T array[],int i ,int j){
	T aux = array[i];
	array[i] = array[j];
	array[j] = aux;
}	

/////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////		

template<typename T>
void SelectionSort<T>::showArray(T array[],int size){
	std::cout << "Array:  [";
	for(int i = 0 ; i < size; i++){
		if(i != size - 1){
			std::cout << array[i] << ",";
		}else{
			std::cout << array[i] << "]";	
		}
	}
	std::cout << std::endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
