/*
* @author Ionésio Junior
*/
#include <iostream>

//GnomeSort.hpp
template <typename T> class GnomeSort{
	public:
		void sort(T array[],int leftIndex,int rightIndex,int size);
		void sort(T array[],int size);
	private:
		void simpleGnomeSort(T array[],int leftIndex,int rightIndex);	
		void recursiveGnomeSort(T array[],int leftIndex,int rightIndex,int pivot);
		void swap(T array[],int i,int j);
		bool validateParams(T array[],int leftIndex,int rightIndex,int size);
		void showArray(T array[],int size);
};




//GnomeSort.cpp
/////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void GnomeSort<T>::sort(T array[],int leftIndex,int rightIndex,int size){
	if(validateParams(array,leftIndex,rightIndex,size)){
		//this->simpleGnomeSort(array,leftIndex,rightIndex);
		this->recursiveGnomeSort(array,leftIndex,rightIndex,leftIndex + 1);
	}else{
		std::cout << "Nao era para entrar aqui!!" <<std::endl;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////


template<typename T>
void GnomeSort<T>::sort(T array[],int size){
	this->sort(array,0,size -1,size);
}

/////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////
		
template<typename T>
void GnomeSort<T>::simpleGnomeSort(T array[],int leftIndex,int rightIndex){
	int pivot = leftIndex + 1;
	while(pivot <= rightIndex){
		if(array[pivot] >= array[pivot-1]){
			pivot++;
		}else{
			swap(array,pivot,pivot -1);
			if(pivot > leftIndex + 1){
				pivot--;	
			}else{
				pivot++;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////
	
template<typename T>
void GnomeSort<T>::recursiveGnomeSort(T array[],int leftIndex,int rightIndex,int pivot){
	if(pivot <= rightIndex){
		if(array[pivot] >= array[pivot - 1]){
			this->recursiveGnomeSort(array,leftIndex,rightIndex,pivot + 1);
		}else{
			this->swap(array,pivot,pivot - 1);
			if(pivot > leftIndex +1){
				this->recursiveGnomeSort(array,leftIndex,rightIndex,pivot- 1);
			}else{
				this->recursiveGnomeSort(array,leftIndex,rightIndex,pivot + 1);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void GnomeSort<T>::swap(T array[],int i,int j){
	T aux = array[i];
	array[i] = array[j];
	array[j] = aux;
}

//////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
bool GnomeSort<T>::validateParams(T array[],int leftIndex,int rightIndex,int size){
	if(array == NULL || leftIndex < 0 || rightIndex > size - 1 || leftIndex >= rightIndex){
		return false;
	}else{
		return true;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
void GnomeSort<T>::showArray(T array[],int size){
	std::cout << "Array: [";
	for(int i = 0 ; i < size;i++){
		if(i != size - 1){
			std::cout << array[i] << ",";
		}else{
			std::cout << array[i] << "]";
		}
	}
	std::cout << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
