package MergeSort;

import java.util.Arrays;

import sorting.AbstractSort;

public class MergeSort<T extends Comparable<T>> extends AbstractSort<T> {

	@Override
	public void sort(T[] array, int leftIndex, int rightIndex) {
		if(validateParams(array,leftIndex,rightIndex)){
			int mid = (leftIndex + rightIndex) / 2;
			sort(array,leftIndex,mid);
			sort(array,mid + 1, rightIndex);
			merge(array,leftIndex,rightIndex);
		}else{
			//Do Nothing
		}
	}
	private void merge(T[] array,int leftIndex, int rightIndex){
		int mid = (leftIndex + rightIndex) / 2;
		T[] leftArray = Arrays.copyOfRange(array, leftIndex, mid +1);
		T[] rightArray = Arrays.copyOfRange(array, mid + 1, rightIndex + 1);
		
		int i = 0;
		int j = 0;
		while(i< leftArray.length && j < rightArray.length){
			if(leftArray[i].compareTo(rightArray[j]) < 0){
				array[leftIndex++] = leftArray[i++];
			}else{
				array[leftIndex++] = rightArray[j++];
			}
		}
		
		while(i < leftArray.length){
			array[leftIndex++] = leftArray[i++];
		}
		
		while(j < rightArray.length){
			array[leftIndex++] = rightArray[j++];
		}
	}
	
	private boolean validateParams(T[] array,int leftIndex,int rightIndex){
		if(array == null || leftIndex < 0 || rightIndex > array.length - 1 || leftIndex >= rightIndex){
			return false;
		}else{
			return true;
		}
	}
}
