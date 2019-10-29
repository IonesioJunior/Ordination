#coding: utf-8
from Sort import Sort

__author__ = "Ionesio Junior"

class BubbleSort(Sort):
    ''' BubbleSort class implementation have many ways to sort using bubble sort idea '''

    def sort(self,lista,leftIndex = 0,rightIndex = None):
        ''' Generic Sort Method
            algorithm.sort(array) -> return  complete ordered array
            algorithm.sort(array,leftLimit,rightLimit) -> return partially ordered array
        '''        
        if rightIndex == None:
            rightIndex = len(lista) - 1
        
        if self.__validateParams(lista,leftIndex,rightIndex):
            #self.__simpleBubbleSort(lista,leftIndex,rightIndex)
            #self.__bidirectionalBubbleSort(lista,leftIndex,rightIndex)
            self.__recursiveBidirectionalBubbleSort(lista,leftIndex,rightIndex,True)
    

    def __simpleBubbleSort(self,lista,leftIndex,rightIndex):
        '''Simple Iterative Bubble Sort'''
        flag = True
        while(flag):
            flag = False
            for i in range(leftIndex,rightIndex):
                if(lista[i] > lista[i+1]):
                    lista[i] , lista[i +1] = lista[i+1] , lista[i]
                    flag = True
    
    def __bidirectionalBubbleSort(self,lista,leftIndex,rightIndex):
        ''' Iterative bidirectional bubble sort implementation in place'''
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
        ''' Recursive bidirectional bubble sort implementation in place'''
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
        '''' This method verify if parameters are valid if some parameter is not valid the method returns false '''        
        if(lista == None  or leftIndex < 0 or rightIndex > len(lista) - 1 or leftIndex >= rightIndex):
            return False
        else:
            return True
