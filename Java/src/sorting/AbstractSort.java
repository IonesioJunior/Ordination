package sorting;

public abstract class AbstractSort<T extends Comparable<T>> implements sort<T> {
	public void sort(T[] array){
		sort(array,0,array.length -1);
	}
	public abstract void sort(T[] array,int leftIndex,int rightIndex);
}
