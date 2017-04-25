#coding: utf-8
from Sort import Sort

class BubbleSort(Sort):
	pass

	'''
		Generic Sort Method
		algorithm.sort(array) -> return  complete ordered array
		algorithm.sort(array,leftLimit,rightLimit) -> return partially ordered array
	'''
	def sort(self,lista,leftIndex = 0,rightIndex = None):
		if rightIndex == None:
			rightIndex = len(lista) - 1
		
		if self.__validateParams(lista,leftIndex,rightIndex):
			#self.__simpleBubbleSort(lista,leftIndex,rightIndex)
			#self.__bidirectionalBubbleSort(lista,leftIndex,rightIndex)
			self.__recursiveBidirectionalBubbleSort(lista,leftIndex,rightIndex,True)
	
	'''
		Simple Iterative BubbleSort
	'''
	def __simpleBubbleSort(self,lista,leftIndex,rightIndex):
		flag = True
		while(flag):
			flag = False;
			for i in range(leftIndex,rightIndex):
				if(lista[i] > lista[i+1]):
					lista[i] , lista[i +1] = lista[i+1] , lista[i]
					flag = True
	'''
		Iterative Bidirectional BubbleSort in place
	'''
	def __bidirectionalBubbleSort(self,lista,leftIndex,rightIndex):
		flag = True
		while(flag  and leftIndex < rightIndex):
			flag = False;
			for i in range(leftIndex,rightIndex):
				if(lista[i] > lista[i+1]):
					lista[i],lista[i+1] = lista[i+1] , lista[i]
					flag = True
			flag = False
			rightIndex = rightIndex- 1
			for i in range(rightIndex,leftIndex +1,-1):
				if(lista[i] < lista[i - 1]):
					lista[i-1],lista[i] = lista[i] , lista[i-1]
					flag = True
			leftIndex = leftIndex +1
	'''
		Recursive Bididrectional BubbleSort in place
	'''
	def __recursiveBidirectionalBubbleSort(self,lista,leftIndex,rightIndex,flag):
		if(flag and leftIndex < rightIndex):
			flag = False
			for i in range(leftIndex,rightIndex):
				if(lista[i] > lista[i+1]):
					lista[i] ,lista[i + 1] = lista[i+1] ,lista[i]
					flag = True
			flag = False
			rightIndex = rightIndex -1
			for i in range(rightIndex,leftIndex,-1):
				if(lista[i] < lista[i-1]):
					lista[i] , lista[i - 1] = lista[i-1],lista[i]
					flag = True
			leftindex = leftIndex +1
			self.__recursiveBidirectionalBubbleSort(lista,leftIndex,rightIndex,flag)
	
	''''
		This method verify if parameters are valid if some parameter is not valid the method returns false
	'''
	def __validateParams(self,lista , leftIndex , rightIndex):
		if(lista == None  or leftIndex < 0 or rightIndex > len(lista) - 1 or leftIndex >= rightIndex):
			return False
		else:
			return True
