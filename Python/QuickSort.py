#coding : utf- 8

from Sort import Sort
__author__ = "Ionesio Junior"

class QuickSort(Sort):
	
	''' Quick Sort class implementation have different ways to implement quicksort algorithm idea '''
	'''
		Generic Sort
		algorithm.sort(array) -> return complete ordered array
		algorithm.sort(array,leftIndex,rightIndex) -> return partially ordered array
	'''
	def sort(self,array,leftIndex = 0 ,rightIndex = None):
        	''' Generic Sort
                algorithm.sort(array) -> return complete ordered array
                algorithm.sort(array,leftLimit,rightLimit) -> return partially ordered array
        	'''
		if(rightIndex == None):
			rightIndex = len(array) - 1
		#self.__simpleQuickSort(array,leftIndex,rightIndex)
		self.__quickSortMedianOfThree(array,leftIndex,rightIndex)
	
	
	def __quickSortMedianOfThree(self,array,leftIndex,rightIndex):
		''' This method implements quick sort using median of three optimization'''
		if(self.__validateParams(array,leftIndex,rightIndex)):
			self.__medianOfThree(array,leftIndex,rightIndex)
			mid = (leftIndex + rightIndex ) / 2
			array[mid] , array[rightIndex - 1]  = array[rightIndex - 1],array[mid]
			partition  = self.__reversePartition(array,leftIndex,rightIndex)
			self.__quickSortMedianOfThree(array,leftIndex,partition -1)
			self.__quickSortMedianOfThree(array,partition + 1 , rightIndex)
	
	
	def __reversePartition(self,array,leftIndex,rightIndex):
		''' This method put pivot in correct position and return this position '''
		pivot = array[rightIndex]
		pivot_index = rightIndex
		for i in range(rightIndex, leftIndex - 1 , -1):
			if(pivot < array[i]):
				pivot_index = pivot_index - 1
				array[pivot_index] , array[i] = array[i] , array[pivot_index]
		array[pivot_index],array[rightIndex] = array[rightIndex],array[pivot_index]
		return pivot_index

	
	def __medianOfThree(self,array,leftIndex,rightIndex):
		''' This method put in correct places left,mid and right elements '''
		mid = (leftIndex + rightIndex )  / 2
		minValue = leftIndex
		if(array[minValue] > array[rightIndex]):
			minValue = rightIndex
		if(array[mid] < array[minValue]):
			minValue = mid
		array[leftIndex],array[minValue] = array[minValue] , array[leftIndex]
		
		if(array[mid] > array[rightIndex]):
			array[mid] , array[rightIndex] = array[rightIndex] , array[mid]
		




	
	def __simpleQuickSort(self,array,leftIndex,rightIndex):
		''' This method implements quicksort without median of three (it's less efficient)'''
		if(self.__validateParams(array,leftIndex,rightIndex)):
			pivot = self.__simplePartition(array,leftIndex,rightIndex)
			self.__simpleQuickSort(array,leftIndex,pivot -1)
			self.__simpleQuickSort(array,pivot+1,rightIndex)
	

	def __simplePartition(self,array,leftIndex,rightIndex):
		''' This method put the pivot in a correct place and return index of this place '''
		pivot = array[leftIndex]
		pivot_index  = leftIndex
		for i in range(pivot_index + 1,rightIndex +1):
			if(pivot > array[i]):
				pivot_index = pivot_index + 1
				array[pivot_index] , array[i] = array[i] , array[pivot_index]
		array[leftIndex] ,array[pivot_index] = array[pivot_index],array[leftIndex]
		return pivot_index



	
	def __validateParams(self,array,leftIndex,rightIndex):
	        '''This method verify if parameters are valid if some parameter is not valid the method returns false '''
		if(array == None or leftIndex < 0 or rightIndex > len(array) - 1 or leftIndex >= rightIndex):
			return False
		else:
			return True

