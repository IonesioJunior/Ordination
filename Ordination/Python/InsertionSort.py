#coding: utf-8

from Sort import Sort

class InsertionSort(Sort):
	pass

	def sort(self,array=None,leftIndex = 0,rightIndex = None):
		if(rightIndex == None):
			rightIndex = len(array) - 1
		if self.__validateParams(array,leftIndex,rightIndex):
			#self.__simpleInsertionSort(array,leftIndex,rightIndex)
			 self.__recursiveInsertionSort(array,leftIndex,rightIndex,leftIndex +1)

	def __simpleInsertionSort(self,array,leftIndex,rightIndex):
		for i in range(leftIndex,rightIndex+1):
			j = i
			while(j > leftIndex and array[j] < array[j-1]):
				array[j] , array[j -1] = array[j -1] , array[j]
				j = j - 1
	
	def __recursiveInsertionSort(self,array,leftIndex,rightIndex,pivot):
		if(pivot <= rightIndex):
			self.__recursiveSwitchBack(array,leftIndex,pivot)
			self.__recursiveInsertionSort(array,leftIndex,rightIndex,pivot+1)

	def __recursiveSwitchBack(self,array,leftIndex,pivot):
		if(pivot > leftIndex  and array[pivot] < array[pivot -1]):
			array[pivot] , array[pivot - 1] = array[pivot -1] , array[pivot]
			self.__recursiveSwitchBack(array,leftIndex,pivot - 1)
				
	def __validateParams(self,array,leftIndex,rightIndex):
		if(array == None or leftIndex < 0 or rightIndex > len(array)-1 or leftIndex >= rightIndex):
			return False
		else:
			return True
	


sort = InsertionSort()
array = [9,8,7,6,5,4,3,2,1]
sort.sort(array)
print array
