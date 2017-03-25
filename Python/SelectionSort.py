#coding: utf-8
from Sort import Sort
class SelectionSort(Sort):
	pass

	def sort(self,array,leftIndex = 0 , rightIndex = None):
		if(rightIndex == None):
			rightIndex = len(array) -1
		if self.__validateParams(array,leftIndex,rightIndex):
			#self.__simpleSelectionSort(array,leftIndex,rightIndex)
			#self.__bidirectionalSelectionSort(array,leftIndex,rightIndex)
			#self.__recursiveSimpleSelectionSort(array,leftIndex,rightIndex)
			self.__recursiveBidirectionalSelectionSort(array,leftIndex,rightIndex)
	

	def __simpleSelectionSort(self,array,leftIndex,rightIndex):
		while(leftIndex < rightIndex):
			minIndex = leftIndex;
			for i in range(leftIndex+1,rightIndex+1):
				if(array[minIndex]> array[i]):
					minIndex = i
			array[minIndex],array[leftIndex] = array[leftIndex] ,array[minIndex]
			leftIndex = leftIndex + 1


	def __bidirectionalSelectionSort(self,array,leftIndex,rightIndex):
		while(leftIndex < rightIndex):
			minIndex = leftIndex
			for i in range(leftIndex + 1 ,rightIndex +1):
				if(array[minIndex] > array[i]):
					minIndex = i		
			array[minIndex], array[leftIndex] = array[leftIndex],array[minIndex]
			leftIndex = leftIndex +1
			
			maxIndex = rightIndex
			for i in range(rightIndex-1 , leftIndex-1,-1):
				if(array[maxIndex] < array[i]):
					maxIndex = i
			array[maxIndex] , array[rightIndex] = array[rightIndex],array[maxIndex]
			rightIndex = rightIndex -1

	
	def __recursiveSimpleSelectionSort(self,array,leftIndex,rightIndex):
			if(leftIndex < rightIndex):
				self.__recursiveGetMin(array,leftIndex,rightIndex,leftIndex,rightIndex)
				self.__recursiveSimpleSelectionSort(array,leftIndex + 1,rightIndex)

	
	def __recursiveBidirectionalSelectionSort(self,array,leftIndex,rightIndex):
			if(leftIndex < rightIndex):
				self.__recursiveGetMax(array,leftIndex,rightIndex,rightIndex,rightIndex)
				self.__recursiveGetMin(array,leftIndex,rightIndex,leftIndex,leftIndex)
				self.__recursiveBidirectionalSelectionSort(array,leftIndex + 1,rightIndex-1)


	def __recursiveGetMax(self,array,leftIndex,rightIndex,maxValue,index):
		if(index >= leftIndex):
			if(array[maxValue] < array[index]):
				maxValue = index
			self.__recursiveGetMax(array,leftIndex,rightIndex,maxValue,index-1)
		else:
			array[maxValue],array[rightIndex] = array[rightIndex] , array[maxValue]


	def __recursiveGetMin(self,array,leftIndex,rightIndex,minValue,index):
		if(index <= rightIndex):
			if(array[minValue] > array[index]):
				minValue = index
			self.__recursiveGetMin(array,leftIndex,rightIndex,minValue,index +1)
		else:
			array[minValue] ,array[leftIndex] = array[leftIndex] , array[minValue]

					
	def __validateParams(self,array,leftIndex,rightIndex):
		if(array == None or leftIndex < 0 or rightIndex > len(lista) -1 or leftIndex >= rightIndex):
			return False
		else:
			return True;
