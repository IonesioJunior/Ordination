#coding: utf-8

from Sort import Sort
class GnomeSort(Sort):
	pass
	
	def sort(self,array ,leftIndex = 0,rightIndex = None):
		if(rightIndex == None):
			rightIndex = len(array) - 1
		if self.__validateParams(array,leftIndex,rightIndex):
			#self.__simpleGnomeSort(array,leftIndex,rightIndex)		
			self.__recursiveGnomeSort(array,leftIndex,leftIndex + 1 ,rightIndex)
	
	
	
	def __simpleGnomeSort(self,array,leftIndex,rightIndex):
		pivot = leftIndex +1
		while(pivot <= rightIndex):
			if(array[pivot] > array[pivot -1]):
				pivot = pivot +1
			else:
				array[pivot] , array[pivot -1] = array[pivot -1] , array[pivot]
				if(pivot > leftIndex + 1):
					pivot = pivot -1
				else:
					pivot = pivot + 1
	
	
	
	
	def __recursiveGnomeSort(self,array,leftIndex,pivot,rightIndex):
		if(pivot <= rightIndex):
			if(array[pivot] > array[pivot - 1]):
				self.__recursiveGnomeSort(array,leftIndex,pivot + 1 , rightIndex)
			else:
				array[pivot] , array[pivot - 1] = array[pivot - 1] ,array[pivot]
				if(pivot > leftIndex + 1):
					self.__recursiveGnomeSort(array,leftIndex,pivot - 1 ,rightIndex)
				else:
					self.__recursiveGnomeSort(array,leftIndex,pivot + 1 ,rightIndex)

			
	def __validateParams(self,array,leftIndex,rightIndex):
		if(array == None or leftIndex < 0 or rightIndex > len(array) - 1 or leftIndex > rightIndex):
			return False
		else:
			return True


sort = GnomeSort()
lista = [9,8,7,6,5,4,3,2,1]
sort.sort(lista)
print lista
