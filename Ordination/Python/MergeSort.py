#coding: utf-8

from Sort import Sort

class MergeSort(Sort):
	pass
	
	def sort(self,array,leftIndex = 0 , rightIndex= None):
		if(rightIndex == None):
			rightIndex = len(array) - 1
		if self.__validateParams(array,leftIndex,rightIndex):
			mid = (leftIndex + rightIndex) / 2
			self.sort(array,leftIndex,mid)
			self.sort(array,mid +1,rightIndex)
			self.__merge(array,leftIndex,rightIndex)
	
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

	def __validateParams(self,array,leftIndex,rightIndex):
		if(array == None or leftIndex < 0 or rightIndex > len(array) - 1 or leftIndex >= rightIndex):
			return False
		else:
			return True

sort = MergeSort()
lista = [9,8,7,6,5,4,3,2,1]
sort.sort(lista,5,8)
print lista
