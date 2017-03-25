#coding: utf-8
from Sort import Sort

class BubbleSort(Sort):
	pass
	
	def sort(self,lista,leftIndex = 0,rightIndex = None):
		if rightIndex == None:
			rightIndex = len(lista) - 1
		
		if self.__validateParams(lista,leftIndex,rightIndex):
			#self.__simpleBubbleSort(lista,leftIndex,rightIndex)
			#self.__bidirectionalBubbleSort(lista,leftIndex,rightIndex)
			self.__recursiveBidirectionalBubbleSort(lista,leftIndex,rightIndex,True)
	
	def __simpleBubbleSort(self,lista,leftIndex,rightIndex):
		flag = True
		while(flag):
			flag = False;
			for i in range(leftIndex,rightIndex):
				if(lista[i] > lista[i+1]):
					lista[i] , lista[i +1] = lista[i+1] , lista[i]
					flag = True
	
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

	def __validateParams(self,lista , leftIndex , rightIndex):
		if(lista == None  or leftIndex < 0 or rightIndex > len(lista) - 1 or leftIndex >= rightIndex):
			return False
		else:
			return True

bubble = BubbleSort()
lista = [9,8,7,6,5,4,3,2,1]
bubble.sort(lista,2,8)
print lista
