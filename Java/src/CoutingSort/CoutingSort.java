package CoutingSort;

import sorting.AbstractSort;

public class CoutingSort extends AbstractSort<Integer> {

  	@Override
  	public void sort(Integer[] array, int leftIndex, int rightIndex) {
  		if(validateParams(array, leftIndex, rightIndex)){
  			//simpleCoutingSort(array, leftIndex, rightIndex);
  			extentedCoutingSort(array, leftIndex, rightIndex);
  		}else{
  			//Do nothing
  		}
  	}
  	private void extentedCoutingSort(Integer[] array,int leftIndex,int rightIndex){
 		int max = getMaxElement(array);
  		int min = getMinElement(array);
 		int size = (max - min) + 1;
 		
 		int[] newArray = new int[size];
  		for (int i = leftIndex; i <= rightIndex; i++) {
  			newArray[array[i] - min]++;
  		}
  		for (int i = 0, j = leftIndex; i < newArray.length; i++) {
  			while (newArray[i] > 0) {
  				array[j++] = i + min;
  				newArray[i]--;
  			}
  		}
  	}
  	private void simpleCoutingSort(Integer[] array,int leftIndex,int rightIndex){
  		int max = getMaxElement(array);
  		int size = max + 1;
  
  		// array auxiliar
  		int[] count = new int[size];
 
  		// conta as ocorrencias dos numeros
  		for (int i = leftIndex; i <= rightIndex; i++) {
  			count[array[i]]++;
  		}
  
  		// substitui as ocorrencias no vetor original
  		for (int i = 0, j = leftIndex; i < count.length; i++) {
  
  			while (count[i] > 0) {
  				array[j++] = i;
  				count[i]--;
  			}
  		} 		
  	}
  	private int getMaxElement(Integer[] array) {
  		int max = array[0];
  
  		for (int i = 1; i < array.length; i++) {
  			if (array[i] > max)
  				max = array[i];
  		}
  
  		return max;
  	}
  	private int getMinElement(Integer[] array){
  		int min = array[0];
  		for(int i = 0 ; i < array.length;i++){
  			if(array[i] < min)
  				min = array[i];
  		}
  		return min;
  	}
  	private boolean validateParams(Integer[] array,int leftIndex,int rightIndex){
  		if (array == null || array.length == 0 || leftIndex < 0 || leftIndex > rightIndex || rightIndex > array.length-1)
  			return false;
  		else{
  			return true;
  		}
  	}
}
