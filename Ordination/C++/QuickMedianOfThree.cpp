#include <iostream>

template<typename T> class QuickMedianOfThree{
	public:
		void sort(T array[],int leftIndex,int rightIndex,int size){
			if(validateParams(array,leftIndex,rightIndex,size)){
				this->medianOfThree(array,leftIndex,rightIndex);
				this->swap(array,(leftIndex + rightIndex)/2,rightIndex - 1);
				int partition = this->partition(array,leftIndex,rightIndex);
				this->sort(array,leftIndex,partition - 1,size);
				this->sort(array,partition + 1 ,rightIndex,size);		
			}else{
			
			}
		}
		
		void sort(T array[],int size){
			this->sort(array,0,size - 1 ,size);
			this->showArray(array,size);
		}
	private:
		int partition(T array[],int leftIndex,int rightIndex){
			T pivot = array[rightIndex];
			int pivot_index = rightIndex;
			for(int i = rightIndex - 1;i >= leftIndex;i--){
				if(pivot < array[i]){
					pivot_index--;
					swap(array,i,pivot_index);
				}
			}
			swap(array,rightIndex,pivot_index);
			return pivot_index;	
		}

		void medianOfThree(T array[],int leftIndex,int rightIndex){
			int mid = (leftIndex + rightIndex) / 2;
			int minIndex = leftIndex;
			if(array[minIndex] > array[rightIndex]){
				minIndex = rightIndex;
			}
			 if(array[minIndex] > array[mid]){
				minIndex = mid;
			}
			swap(array,leftIndex,minIndex);
			if(array[mid] > array[rightIndex]){
				swap(array,mid,rightIndex);
			}
		}
		
		bool validateParams(T array[],int leftIndex,int rightIndex,int size){
			if(array == NULL || leftIndex < 0 || rightIndex > size - 1 || leftIndex >= rightIndex){
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
		void showArray(T array[],int size){
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
};
