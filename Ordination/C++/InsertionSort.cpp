#include <iostream>

template<class T> class InsertionSort{
	public:
		void sort(T array[],int leftIndex,int rightIndex,int size){
			if(validateParams(array,leftIndex,rightIndex,size)){
				//this->simpleInsertionSort(array,leftIndex,rightIndex);
				this->recursiveInsertionSort(array,leftIndex,rightIndex,leftIndex);
				this->showArray(array,size);
			}else{
				std::cout << "Entrando aqui!!" << std::endl;
				//Do nothing
			}
		}
		void sort(T array[],int size){
			this->sort(array,0,size-1,size);	
		}
	private:
		bool validateParams(T array[],int leftIndex,int rightIndex,int size){
			if(array == NULL || leftIndex < 0 || rightIndex > size-  1 || leftIndex >= rightIndex){
				return false;
			}else{
				return true;
			}
		}
		
		void swap(T array[],int i,int j){
			T aux = array[i];
			array[i] = array[j];
			array[j] = aux;
		}
		void simpleInsertionSort(T array[],int leftIndex,int rightIndex){
			for(int i = leftIndex;i <= rightIndex;i++){
				int j = i;
				while(j > leftIndex && array[j] < array[j-1]){
					swap(array,j,j-1);
					j--;
				}
			}	
		}
		
		void recursiveInsertionSort(T array[],int leftIndex,int rightIndex,int pivot){
			if(pivot <= rightIndex){
				this->recursiveSwitchBack(array,leftIndex,pivot);
				this->recursiveInsertionSort(array,leftIndex,rightIndex,pivot + 1);
			}
		}
		
		void recursiveSwitchBack(T array[],int leftIndex,int pivot){
			if(pivot > leftIndex && array[pivot] < array[pivot - 1]){
				swap(array,pivot,pivot - 1);
				this->recursiveSwitchBack(array,leftIndex,pivot -1);
			}
		}
		void showArray(T array[],int size){
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
};
