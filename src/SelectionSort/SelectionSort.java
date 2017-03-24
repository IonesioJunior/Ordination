package SelectionSort;

import sorting.AbstractSort;

public class SelectionSort<T extends Comparable<T>> extends AbstractSort<T> {

	@Override
	public void sort(T[] array, int leftIndex, int rightIndex) {
		if(validateParams(array, leftIndex, rightIndex)){
			//simpleSelectionSort(array, leftIndex, rightIndex);
			//bidirectionalSelectionSort(array, leftIndex, rightIndex);
			recursiveBidirectionalSelectionSort(array, leftIndex, rightIndex);
			//recursiveSimpleSelectionSort(array, leftIndex, rightIndex);
		}else{
			//Do nothing
		}
	}
	
	private void simpleSelectionSort(T[] array,int leftIndex,int rightIndex){
		while(leftIndex < rightIndex){
			int minIndex = leftIndex;
			for(int i = leftIndex+1;i <= rightIndex;i++){
				if(array[minIndex].compareTo(array[i]) > 0){
					minIndex = i;
				}
			}
			swap(array,minIndex,leftIndex++);
		}
	}
	
	private void bidirectionalSelectionSort(T[] array,int leftIndex,int rightIndex){
		while(leftIndex < rightIndex){
			int minIndex = leftIndex;
			for(int i = leftIndex  +1;i <= rightIndex;i++){
				if(array[minIndex].compareTo(array[i]) > 0){
					minIndex = i;
				}
			}
			swap(array,minIndex,leftIndex++);
			
			int maxIndex = rightIndex;
			for(int i = rightIndex;i >= leftIndex;i--){
				if(array[maxIndex].compareTo(array[i]) < 0){
					maxIndex = i;
				}
			}
			swap(array,maxIndex,rightIndex--);
		}
	}

	
	//Recursive Methods
	private void recursiveSimpleSelectionSort(T[] array,int leftIndex,int rightIndex){
		if(leftIndex < rightIndex){
			recursiveGetMin(array, leftIndex, rightIndex, leftIndex, leftIndex);
			recursiveSimpleSelectionSort(array, leftIndex +1, rightIndex);
		}
	}
	
	private void recursiveBidirectionalSelectionSort(T[] array,int leftIndex,int rightIndex){
		if(leftIndex < rightIndex){
			recursiveGetMax(array, leftIndex, rightIndex, rightIndex, rightIndex);
			recursiveGetMin(array, leftIndex, rightIndex, leftIndex, leftIndex);
			recursiveBidirectionalSelectionSort(array, leftIndex +1, rightIndex -1);
		}
	}
	
	
	
	//Recursive Auxiliar Methods
	private void recursiveGetMax(T[] array,int leftIndex,int rightIndex,int max,int index){
		if(index >= leftIndex){
			if(array[max].compareTo(array[index]) < 0){
				max = index;
			}
			recursiveGetMax(array,leftIndex,rightIndex,max,index-1);
		}else{
			swap(array,max,rightIndex);
		}
	}
	
	private void recursiveGetMin(T[] array,int leftIndex,int rightIndex,int min,int index){
		if(index <= rightIndex){
			if(array[min].compareTo(array[index]) > 0){
				min = index;
			}
			recursiveGetMin(array,leftIndex,rightIndex,min,index+1);
		}else{
			swap(array,min,leftIndex);
		}
	}

	
	//Auxiliar Methods
	private void swap(T[] array,int i,int j){
		T aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
	
	private boolean validateParams(T[] array,int leftIndex,int rightIndex){
		if(array == null || leftIndex < 0 || leftIndex >= rightIndex || rightIndex > array.length - 1){
			return false;
		}else{
			return true;
		}
	}

}
