'''
	Author: Ionésio Junior
'''
#coding: utf-8

from Sort import Sort
'''
	InsertionSort implementation
'''
class InsertionSort(Sort):
	pass
	'''
		Generic sort method
		algorithm.sort(array) -> return complete ordered array
		algorithm.sort(array,leftLimit,rightLimit) -> return partially ordered array
	'''
	def sort(self,array=None,leftIndex = 0,rightIndex = None):
		if(rightIndex == None):
			rightIndex = len(array) - 1
		if self.__validateParams(array,leftIndex,rightIndex):
			#self.__simpleInsertionSort(array,leftIndex,rightIndex)
			 self.__recursiveInsertionSort(array,leftIndex,rightIndex,leftIndex +1)
	'''
		Simple iteractive insertion sort
	'''
	def __simpleInsertionSort(self,array,leftIndex,rightIndex):
		for i in range(leftIndex,rightIndex+1):
			j = i
			while(j > leftIndex and array[j] < array[j-1]):
				array[j] , array[j -1] = array[j -1] , array[j]
				j = j - 1
	'''
		Simple recursive insertion sort
	'''
	def __recursiveInsertionSort(self,array,leftIndex,rightIndex,pivot):
		if(pivot <= rightIndex):
			self.__recursiveSwitchBack(array,leftIndex,pivot)
			self.__recursiveInsertionSort(array,leftIndex,rightIndex,pivot+1)
	'''
		recursive method to verify and switch previous elements if less than the pivot
	'''
	def __recursiveSwitchBack(self,array,leftIndex,pivot):
		if(pivot > leftIndex  and array[pivot] < array[pivot -1]):
			array[pivot] , array[pivot - 1] = array[pivot -1] , array[pivot]
			self.__recursiveSwitchBack(array,leftIndex,pivot - 1)
	'''
		This method verify if parameters are valid if some parameter is not valid the method returns false	
	'''			
	def __validateParams(self,array,leftIndex,rightIndex):
		if(array == None or leftIndex < 0 or rightIndex > len(array)-1 or leftIndex >= rightIndex):
			return False
		else:
			return True
