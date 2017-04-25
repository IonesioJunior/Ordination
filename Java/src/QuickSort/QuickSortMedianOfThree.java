package QuickSort;

import sorting.AbstractSort;

public class QuickSortMedianOfThree<T extends Comparable<T>> extends AbstractSort<T> {

	@Override
	public void sort(T[] array, int leftIndex, int rightIndex) {
		if(validateParams(array, leftIndex, rightIndex)){
			medianOfThree(array,leftIndex,rightIndex);
			swap(array,(leftIndex + rightIndex) / 2,rightIndex -1);
			//int partition = partition(array,leftIndex,rightIndex);
			int partition = recursivePartition(array, leftIndex, rightIndex);
			sort(array,leftIndex,partition -1);
			sort(array,partition +1,rightIndex);
		}
	}
	
	private int partition(T[] array, int leftIndex,int rightIndex){
		T pivot = array[rightIndex];
		int pivotIndex = rightIndex;
		for(int i = rightIndex -1;i >= leftIndex;i--){
			if(pivot.compareTo(array[i]) < 0){
				pivotIndex--;
				swap(array,i,pivotIndex);
			}
		}
		swap(array,pivotIndex,rightIndex);
		return pivotIndex;
	}
	
	
	
	//Recursive Method
	private int recursivePartition(T[] array, int leftIndex,int rightIndex){
		T pivot = array[rightIndex];
		int pivotIndex = rightIndex;
		pivotIndex = recursiveLoopPartition(array,pivot,leftIndex,rightIndex -1,pivotIndex);
		swap(array,pivotIndex,rightIndex);
		return pivotIndex;		
	}
	private int recursiveLoopPartition(T[] array,T pivot,int leftIndex,int index,int pivotIndex){
		if(index >= leftIndex){
			if(pivot.compareTo(array[index]) < 0){
				swap(array,index,pivotIndex -1);
				return recursiveLoopPartition(array,pivot,leftIndex,index -1,pivotIndex -1);
			}
			return recursiveLoopPartition(array,pivot,leftIndex,index -1,pivotIndex);
		}else{
			return pivotIndex;
		}
	}
	
	//Auxiliar Methods
	private void medianOfThree(T[] array,int leftIndex,int rightIndex){
		int mid = (leftIndex + rightIndex) / 2;
		int min = leftIndex;
		if(array[min].compareTo(array[rightIndex]) > 0){
			min = rightIndex;
		}
		if(array[mid].compareTo(array[min]) < 0){
			min = mid;
		}
		swap(array,leftIndex,min);
		if(array[mid].compareTo(array[rightIndex]) > 0){
			swap(array,mid,rightIndex);
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
