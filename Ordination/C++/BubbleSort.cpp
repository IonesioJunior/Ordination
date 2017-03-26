#include <iostream>

template <typename T> class BubbleSort{
	public:
		void sort(T array[],int leftIndex,int rightIndex,int size){
			if(validateParams(array,leftIndex,rightIndex,size)){
				//simpleBubbleSort(array,leftIndex,rightIndex);
				//bidirectionalBubbleSort(array,leftIndex,rightIndex);
				this->recursiveBidirectionalBubbleSort(array,leftIndex,rightIndex,true);
				this->showArray(array,size);
			}else{
				std::cout << "Nao esta entrando!!" << std::endl;
				
			}	
		}
		void sort(T array[],int size){
			this->sort(array,0,size-1,size);
		}
	private:
		bool validateParams(T array[],int leftIndex,int rightIndex,int size){
			if(array == NULL || leftIndex < 0 || rightIndex > size - 1 || leftIndex >= rightIndex){
				return false;
			}else{	
				return true;
			}
		}
	
		void simpleBubbleSort(T array[],int leftIndex,int rightIndex){
			int ordered  = 0;
			for(int i = leftIndex ; i < rightIndex;i++){
				bool flag = false;
				for(int j = leftIndex; j < rightIndex-ordered;j++){
					if(array[j] > array[j+1]){
						swap(array,j,j+1);
						flag = true;
					}
				}
				ordered++;
				if(!flag){
					break;
				}
			}
		}

		void bidirectionalBubbleSort(T array[],int leftIndex,int rightIndex){
			bool flag= true;
			while(flag){
				flag = false;
				for(int i = leftIndex;i < rightIndex;i++){
					if(array[i] > array[i+1]){
						swap(array,i,i+1);
					}
				}
				rightIndex--;
				flag = false;
				for(int i = rightIndex; i > leftIndex;i--){
					if(array[i] < array[i-1]){
						swap(array,i,i-1);
						flag = true;
					}
				}
				leftIndex++;
			}
		}
		
		void recursiveBidirectionalBubbleSort(T array[],int leftIndex,int rightIndex,bool flag){
			if(flag){
				flag = false;
				for(int i = 0 ; i < rightIndex; i++){
					if(array[i] > array[i+1]){
						swap(array,i,i+1);
						flag = true;
					}
				}
				rightIndex--;
				
				flag = false;
				for(int i = rightIndex; i > leftIndex;i--){
					if(array[i] < array[i-1]){
						swap(array,i,i-1);
						flag = true;
					}
				}
				leftIndex++;
				this->recursiveBidirectionalBubbleSort(array,leftIndex,rightIndex,flag);
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
				if(i != size- 1){
					std::cout << array[i] << ",";
				}else{
					std::cout << array[i] << "]";
				}
			}	
			std::cout << std::endl;
		}
};
