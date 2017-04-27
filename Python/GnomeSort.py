'''
	Author: Ionésio Junior
'''
#coding: utf-8

from Sort import Sort
'''
	GnomeSort implementation
'''
class GnomeSort(Sort):
	pass
	'''
		Generic Sort
		algorithm.sort(array) -> return complete ordered array
		algorithm.sort(array,leftLimit,rightLimit) -> return partially ordered array
	'''	
	def sort(self,array ,leftIndex = 0,rightIndex = None):
		if(rightIndex == None):
			rightIndex = len(array) - 1
		if self.__validateParams(array,leftIndex,rightIndex):
			self.__simpleGnomeSort(array,leftIndex,rightIndex)		
			#self.__recursiveGnomeSort(array,leftIndex,leftIndex + 1 ,rightIndex)
	
	
	'''
		Simple iteractive Gnome Sort implementation
	'''
	def __simpleGnomeSort(self,array,leftIndex,rightIndex):
		pivot = leftIndex +1
		while(pivot <= rightIndex):
			if(array[pivot] >= array[pivot -1]):
				pivot = pivot +1
			else:
				array[pivot] , array[pivot -1] = array[pivot -1] , array[pivot]
				if(pivot > leftIndex + 1):
					pivot = pivot -1
				else:
					pivot = pivot + 1
	
	
	
	'''
		Recursive Gnome Sort implementation
	'''
	def __recursiveGnomeSort(self,array,leftIndex,pivot,rightIndex):
		if(pivot <= rightIndex):
			if(array[pivot] >= array[pivot - 1]):
				self.__recursiveGnomeSort(array,leftIndex,pivot + 1 , rightIndex)
			else:
				array[pivot] , array[pivot - 1] = array[pivot - 1] ,array[pivot]
				if(pivot > leftIndex + 1):
					self.__recursiveGnomeSort(array,leftIndex,pivot - 1 ,rightIndex)
				else:
					self.__recursiveGnomeSort(array,leftIndex,pivot + 1 ,rightIndex)

	'''
		This method verify if parameters are valid if some parameter is not valid the method returns false		
	'''
	def __validateParams(self,array,leftIndex,rightIndex):
		if(array == None or leftIndex < 0 or rightIndex > len(array) - 1 or leftIndex > rightIndex):
			return False
		else:
			return True
