package Tests;

import static org.junit.Assert.*;

import java.util.Arrays;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import BubbleSort.BubbleSort;
import CoutingSort.CoutingSort;
import GnomeSort.GnomeSort;
import InsertionSort.InsertionSort;
import MergeSort.MergeSort;
import QuickSort.QuickSort;
import QuickSort.QuickSortMedianOfThree;
import SelectionSort.SelectionSort;
import sorting.AbstractSort;

public class OrdinationTests {
	public Integer[] evenSize = {3,5,6,8,9,7,4,2,1,0};
	public Integer[] oddSize = {3,9,7,8,5,4,6,2,1};
	public Integer[] empty = {};
	public Integer[] equals = {5,5,5,5,5,5};
	public Integer[] repeated = {6,8,7,6,5,4,2,6,5,8,6,9};
	public Integer[] ordered = {1,2,3,4,5,6,7,8,9};
	
	AbstractSort<Integer> implementation;
	@Before
	public void setUp(){
		this.implementation = new CoutingSort();
	}
	//Auxiliar Methods
	public void genericSort(Integer[] array){
		Integer[] copy = Arrays.copyOf(array, array.length);
		this.implementation.sort(array);
		Arrays.sort(copy);
		Assert.assertArrayEquals(array, copy);
	}
	public void invalidInput(Integer[] array,int leftIndex ,int rightIndex){
		Integer[] copy = Arrays.copyOf(array, array.length);
		this.implementation.sort(array,leftIndex,rightIndex);
		Assert.assertArrayEquals(array, copy);
	}
	@Test
	public void testevenSize(){
		genericSort(evenSize);
	}
	@Test
	public void tesoddSize(){
		genericSort(oddSize);
	}
	@Test
	public void testempty(){
		genericSort(empty);
	}
	@Test
	public void testEquals(){
		genericSort(equals);
	}
	@Test
	public void testRepetido(){
		genericSort(repeated);
	}
	@Test
	public void testOdernados(){
		genericSort(ordered);
	}
	
	@Test
	public void invalidLeftIndex(){
		invalidInput(evenSize,-1,evenSize.length);
		invalidInput(evenSize,evenSize.length +2,evenSize.length);
		
		invalidInput(oddSize,-1,oddSize.length);
		invalidInput(oddSize,oddSize.length +2,oddSize.length);
		
		invalidInput(empty,-1,empty.length);
		invalidInput(empty,empty.length +2,empty.length);
		
		invalidInput(repeated,-1,repeated.length);
		invalidInput(repeated,repeated.length +2,repeated.length);
		
		invalidInput(equals,-1,equals.length);
		invalidInput(equals,equals.length +2,equals.length);
		
		invalidInput(ordered,-1,ordered.length);
		invalidInput(ordered,ordered.length +2,ordered.length);
	}
	
	@Test
	public void invalidRightIndex(){
		invalidInput(evenSize,0,evenSize.length);
		invalidInput(evenSize,0,-5);
		
		invalidInput(oddSize,0,oddSize.length);
		invalidInput(oddSize,0,-5);
		
		invalidInput(empty,0,empty.length);
		invalidInput(empty,0,-5);
		
		invalidInput(repeated,0,repeated.length);
		invalidInput(repeated,0,-5);
		
		invalidInput(equals,0,equals.length);
		invalidInput(equals,0,-5);
		
		invalidInput(ordered,0,ordered.length);
		invalidInput(ordered,0,-5);
		
	}
}
