#include <iostream>


template<typename T> class MergeSort{
	public:
		void sort(T array[],int leftIndex,int rightIndex,int size){
			if(validateParams(array,leftIndex,rightIndex,size)){
				int mid = (leftIndex + rightIndex)  / 2;
				this->sort(array,leftIndex,mid,size);
				this->sort(array,mid + 1,rightIndex,size);
				this->merge(array,leftIndex,rightIndex,size);
			}else{
				//Do nothing
			}
		}
		void sort(T array[],int size){
			this->sort(array,0,size-  1,size);
			this->showArray(array,size);
		}
	private:
		void merge(T array[],int leftIndex,int rightIndex,int size){
			int mid = (leftIndex + rightIndex) / 2;
			T newArray[size];
			int i = leftIndex;
			int pivot = leftIndex;
			int j = mid + 1;
		
			while(i <= mid && j <= rightIndex){
				if(array[i] < array[j]){
					newArray[pivot++] = array[i++];
				}else{
					newArray[pivot++] = array[j++];
				}
			}
			while(i <= mid){
				newArray[pivot++] = array[i++];
			}
			while(j <= rightIndex){
				newArray[pivot++] = array[j++];
			}
		
			for(int i = leftIndex; i <= rightIndex;i++){
				array[i] = newArray[i];
			}
		}
		
		T* fillArray(T array[],int leftIndex,int rightIndex){
			int size = (rightIndex - leftIndex) + 1;
			if(size > 0){
				T newArray[size];
				int index = 0;
				for(int i = leftIndex;i <= rightIndex;i++){
					newArray[index] = array[i];
					index++;
				}
				return newArray;
			}else{
				T newArray[0];
				return newArray;
			}
		}

		bool validateParams(T array[],int leftIndex,int rightIndex,int size){
			if(array == NULL || leftIndex < 0 || rightIndex > size - 1 || leftIndex >= rightIndex){
				return false;
			}else{
				return true;
			}
		}
		
		void swap(T array[], int i,int j){
			T aux = array[i];
			array[i] = array[j];
			array[j] = aux;
		}
	
		void showArray(T array[],int size){
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
	
};
