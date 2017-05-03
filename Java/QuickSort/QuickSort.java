package QuickSort;

import sorting.AbstractSort;

public class QuickSort<T extends Comparable<T>> extends AbstractSort<T> {

	@Override
	public void sort(T[] array, int leftIndex, int rightIndex) {
		if(validateParams(array, leftIndex, rightIndex)){
			//int pivot_partition = partition(array,leftIndex,rightIndex);
			int pivot_partition = recursivePartition(array,leftIndex,rightIndex);
			sort(array,leftIndex,pivot_partition -1);
			sort(array,pivot_partition + 1,rightIndex);
		}else{
			//Return nothing
		}
	}
	
	private int partition(T[] array,int leftIndex,int rightIndex){
		int pivot_index = leftIndex;
		T pivot = array[leftIndex];
		for(int i = pivot_index + 1; i  <=rightIndex;i++){
			if(pivot.compareTo(array[i]) > 0){
				pivot_index++;
				swap(array,pivot_index,i);
			}
		}
		swap(array,leftIndex,pivot_index);
		return pivot_index;
	}
	
	//Recursive Partition
	private int recursivePartition(T[] array,int leftIndex,int rightIndex){
		int pivot_index = leftIndex;
		T pivot = array[leftIndex];
		pivot_index = recursiveLoopPartition(array, pivot, rightIndex, pivot_index + 1, pivot_index);
		swap(array,leftIndex,pivot_index);
		return pivot_index;
	}
	private int recursiveLoopPartition(T[] array,T pivot,int rightIndex,int index,int pivot_index){
		if(index <= rightIndex){
			if(pivot.compareTo(array[index]) > 0){
				pivot_index++;
				swap(array,pivot_index,index);
			}
			return recursiveLoopPartition(array,pivot,rightIndex,index +1,pivot_index);
		}else{
			return pivot_index;
		}
	}
	
	
	private void swap(T[] array, int i , int j){
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
