package BubbleSort;

import sorting.AbstractSort;

public class BubbleSort<T extends Comparable<T>> extends AbstractSort<T> {

	@Override
	public void sort(T[] array, int leftIndex, int rightIndex) {
		if(validateParams(array,leftIndex,rightIndex)){
			//simpleBubbleSort(array,leftIndex,rightIndex);
			//bidirectionalBubbleSort(array, leftIndex, rightIndex);
			recursiveBubbleSort(array, leftIndex, rightIndex, true);
		}else{
			//Do nothing
		}
	}
	
	private void simpleBubbleSort(T[] array,int leftIndex,int rightIndex){
		for(int i = leftIndex ; i < rightIndex;i++){
			boolean flag = false;
			for(int j =  leftIndex; j < rightIndex - i ;j++){
				if(array[j].compareTo(array[j+1]) > 0){
					swap(array,j,j+1);
					flag = true;
				}
			}
			if(flag == false){
				break;
			}
		}
	}
	
	private void bidirectionalBubbleSort(T[] array,int leftIndex,int rightIndex){
		boolean flag = true;
		while(leftIndex < rightIndex && flag == true){
			flag = false;
			for(int i = leftIndex; i < rightIndex ; i++){
				if(array[i].compareTo(array[i +1]) > 0){
					swap(array,i,i+1);
					flag = true;
				}
			}
			rightIndex--;
			flag = false;
			for(int i = rightIndex;i > leftIndex;i--){
				if(array[i].compareTo(array[i-1]) < 0){
					swap(array,i,i-1);
					flag = true;
				}
			}
			leftIndex++;
		}
	}
	
	private void recursiveBubbleSort(T[] array,int leftIndex,int rightIndex,boolean flag){
		if(flag == true && leftIndex < rightIndex){
			for(int i = leftIndex; i < rightIndex;i++){
				if(array[i].compareTo(array[i+1]) > 0){
					swap(array,i,i+1);
					flag = true;
				}
			}
			rightIndex --;
			flag = false;
			for(int i = rightIndex;i > leftIndex;i--){
				if(array[i].compareTo(array[i-1]) < 0){
					swap(array,i,i-1);
					flag = true;
				}
			}
			leftIndex++;
			recursiveBubbleSort(array, leftIndex, rightIndex, flag);
		}
	}
	
	private void swap(T[] array, int i , int j){
		T aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
	private boolean validateParams(T[] array, int leftIndex,int rightIndex){
		if(array == null || leftIndex >= rightIndex || rightIndex > array.length -1 || leftIndex < 0 ){
			return false;
		}else{
			return true;
		}
	}
}
