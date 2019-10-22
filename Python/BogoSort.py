#coding: utf-8
from Sort import Sort
from random import shuffle

__author__ = "Rodolfo Marinho"


class BogoSort(Sort):
    ''' BogoSort class provides an implementation of a sorting algorithm based on a "pure luck" strategy.'''

    def sort(self, unnorderedList, leftIndex=0, rightIndex=None):
        ''' Generic Sort Method
        algorithm.sort(array) -> return  complete ordered array
        '''

        if(rightIndex == None):
            rightIndex = len(unnorderedList) - 1
        if self.__validateParams(unnorderedList, leftIndex, rightIndex):
            self.__bogoSort(unnorderedList)

    def __bogoSort(self, unnorderedList):
        '''Simple Iterative Bogo Sort'''
        flag = True
        while(flag):
            flag = False
            shuffle(unnorderedList)
            for i in range(len(unnorderedList) - 1):
                if(unnorderedList[i] > unnorderedList[i+1]):
                    flag = True
                    break

    def __validateParams(self, array, leftIndex, rightIndex):
        ''' This method verify if parameters are valid,if some parameter isn't valid the method returns false '''
        if(array == None or leftIndex < 0 or rightIndex > len(array) - 1 or leftIndex >= rightIndex):
            return False
        else:
            return True
