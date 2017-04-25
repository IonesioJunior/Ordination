package InsertionSort;

import sorting.AbstractSort;

public class InsertionSort<T extends Comparable<T>> extends AbstractSort<T> {

	@Override
	public void sort(T[] array, int leftIndex, int rightIndex) {
		if(validateParams(array, leftIndex, rightIndex)){
			//simpleInsertionSort(array, leftIndex, rightIndex);
			recursiveInsertionSort(array, leftIndex, rightIndex, leftIndex);
		}else{
			
		}
	}
	private void simpleInsertionSort(T[] array,int leftIndex,int rightIndex){
		for(int i = leftIndex; i<= rightIndex ;i++){
			int j = i;
			while(j > leftIndex && array[j].compareTo(array[j-1]) < 0){
				swap(array,j,j-1);
				j--;
			}
		}
	}
	
	
	private void recursiveInsertionSort(T[] array,int leftIndex,int rightIndex,int pivot){
		if(pivot <= rightIndex){
			recursiveSwitchBack(array,leftIndex,pivot);
			recursiveInsertionSort(array, leftIndex, rightIndex, pivot + 1);
		}
	}
	private void recursiveSwitchBack(T[] array,int leftIndex,int pivot){
		if(pivot > leftIndex && array[pivot].compareTo(array[pivot - 1]) < 0){
			swap(array,pivot,pivot - 1);
			recursiveSwitchBack(array,leftIndex,pivot -1);			
		}
	}
	
	private void swap(T[] array,int i,int j){
		T aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
	private boolean validateParams(T[] array,int leftIndex,int rightIndex){
		if(array == null || leftIndex >= rightIndex || rightIndex > array.length -1 || leftIndex < 0 ){
			return false;
		}else{
			return true;
		}
	}

}
