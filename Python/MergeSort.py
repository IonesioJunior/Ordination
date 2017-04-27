'''
	Author: Ionésio Junior
'''
#coding: utf-8

from Sort import Sort
'''
	MergeSort implementation
'''
class MergeSort(Sort):
	pass
	'''
		Generic Sort
		algorithm.sort(array) -> return complete ordered array
		algorithm.sort(array,leftLimit,rightLimit) -> return partially ordered array
	'''
	def sort(self,array,leftIndex = 0 , rightIndex= None):
		if(rightIndex == None):
			rightIndex = len(array) - 1
		if self.__validateParams(array,leftIndex,rightIndex):
			mid = (leftIndex + rightIndex) / 2
			self.sort(array,leftIndex,mid)
			self.sort(array,mid +1,rightIndex)
			self.__merge(array,leftIndex,rightIndex)
	'''
		This method will order and merge two parts of same array
	'''
	def __merge(self,array,leftIndex,rightIndex):
		mid = (leftIndex + rightIndex) / 2
		leftArray = array[leftIndex:mid +1]
		rightArray = array[mid +1: rightIndex + 1]
		i = 0
		j = 0
		while(i < len(leftArray) and j < len(rightArray)):
			if(leftArray[i] < rightArray[j]):
				array[leftIndex] = leftArray[i]
				i = i  +1
			else:
				array[leftIndex] = rightArray[j]
				j = j + 1
			leftIndex = leftIndex + 1
	
		while(i < len(leftArray)):
			array[leftIndex] = leftArray[i]
			i = i + 1
			leftIndex = leftIndex + 1
		while(j < len(rightArray)):
			array[leftIndex] = rightArray[j]
			j = j + 1
			leftIndex = leftIndex + 1

	'''
		This method verify if parameters are valid if some parameter is not valid the method returns false
	'''
	def __validateParams(self,array,leftIndex,rightIndex):
		if(array == None or leftIndex < 0 or rightIndex > len(array) - 1 or leftIndex >= rightIndex):
			return False
		else:
			return True
