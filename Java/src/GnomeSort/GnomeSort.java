package GnomeSort;

import sorting.AbstractSort;

public class GnomeSort<T extends Comparable<T>> extends AbstractSort<T> {

	@Override
	public void sort(T[] array, int leftIndex, int rightIndex) {
		if(validateParams(array, leftIndex, rightIndex)){
			//simpleGnomeSort(array, leftIndex, rightIndex);
			recursiveGnomeSort(array, leftIndex, leftIndex +1, rightIndex);
		}else{
			//Do nothing
		}
	}
	private void simpleGnomeSort(T[] array,int leftIndex,int rightIndex){
		int pivot = leftIndex +1;
		while(pivot <= rightIndex){
			if(array[pivot].compareTo(array[pivot - 1]) >= 0){
				pivot++;
			}else{
				swap(array,pivot,pivot-1);
				if(pivot > leftIndex +1){
					pivot--;
				}else{
					pivot++;
				}
			}
		}
	}
	
	private void recursiveGnomeSort(T[] array,int leftIndex,int pivot,int rightIndex){
		if(pivot <= rightIndex){
			if(array[pivot].compareTo(array[pivot -1]) >= 0){
				recursiveGnomeSort(array, leftIndex, pivot +1, rightIndex);
			}else{
				swap(array,pivot,pivot -1);
				if(pivot > leftIndex +1){
					recursiveGnomeSort(array, leftIndex, pivot-1, rightIndex);
				}else{
					recursiveGnomeSort(array, leftIndex, pivot +1, rightIndex);
				}
			}
		}
	}
	
	private void swap(T[] array,int i , int j){
		T aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
	
	private boolean validateParams(T[] array,int leftIndex,int rightIndex){
		if(array == null || leftIndex < 0 || rightIndex > array.length - 1 || leftIndex >= rightIndex){
			return false;
		}else{
			return true;
		}
	}
}
