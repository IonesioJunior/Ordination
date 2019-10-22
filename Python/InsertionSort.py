#coding: utf-8

from Sort import Sort

__author__ = "Ionesio Junior"

class InsertionSort(Sort):
    '''Insertion sort class have many ways to implement insertion sort idea '''
    
    def sort(self,array=None,leftIndex = 0,rightIndex = None):
        '''Generic sort method
                algorithm.sort(array) -> return complete ordered array
                algorithm.sort(array,leftLimit,rightLimit) -> return partially ordered array
        '''
        if(rightIndex == None):
            rightIndex = len(array) - 1
        if self.__validateParams(array,leftIndex,rightIndex):
            #self.__simpleInsertionSort(array,leftIndex,rightIndex)
             self.__recursiveInsertionSort(array,leftIndex,rightIndex,leftIndex +1)
    

    def __simpleInsertionSort(self,array,leftIndex,rightIndex):
        ''' Simple iteractive insertion sort '''
        for i in range(leftIndex,rightIndex+1):
            j = i
            while(j > leftIndex and array[j] < array[j-1]):
                array[j] , array[j -1] = array[j -1] , array[j]
                j = j - 1
    
    def __recursiveInsertionSort(self,array,leftIndex,rightIndex,pivot):
        ''' Simple recursive insertion sort '''
        if(pivot <= rightIndex):
            self.__recursiveSwitchBack(array,leftIndex,pivot)
            self.__recursiveInsertionSort(array,leftIndex,rightIndex,pivot+1)
    

    def __recursiveSwitchBack(self,array,leftIndex,pivot):
        ''' Recursive method to verify and switch previous elements if less than the pivot '''
        if(pivot > leftIndex  and array[pivot] < array[pivot -1]):
            array[pivot] , array[pivot - 1] = array[pivot -1] , array[pivot]
            self.__recursiveSwitchBack(array,leftIndex,pivot - 1)
    
        
    def __validateParams(self,array,leftIndex,rightIndex):
        ''' This method verify if parameters are valid if some parameter is not valid the method returns false   '''    
        if(array == None or leftIndex < 0 or rightIndex > len(array)-1 or leftIndex >= rightIndex):
            return False
        else:
            return True
