import unittest

from BubbleSort import BubbleSort
from SelectionSort import SelectionSort
from InsertionSort import InsertionSort
from GnomeSort import GnomeSort
from MergeSort import MergeSort
from QuickSort import QuickSort
from BogoSort import BogoSort


class OrdinationTest(unittest.TestCase):
	
	def setUp(self):
		self.oddSize = [9,8,7,6,5,4,3,2,1,0]
		self.evenSize = [9,8,7,6,5,4,3,2,1]
		self.empty = []
		self.equal = [5,5,5,5,5,5]
		self.repeated = [5,9,8,7,6,8,6,8,5,4,3,2]
		self.ordered = [1,2,3,4,5,6,7,8,9]
		
		
		#self.algorithm = BubbleSort()
		#self.algorithm = SelectionSort()
		#self.algorithm = InsertionSort()
		#self.algorithm = GnomeSort()
		#self.algorithm = MergeSort()
		#self.algorithm = QuickSort()
		self.algorithm = BogoSort()
	
	def genericTest(self,array):
		copy = array[:]
		self.algorithm.sort(array)
		copy.sort()
		self.assertEqual(copy,array)

	def invalidParameters(self,array,leftIndex,rightIndex):
		copy = array[:]
		self.algorithm.sort(array,leftIndex,rightIndex)
		self.assertEqual(copy,array)

	def testOrdinationOdd(self):
		self.genericTest(self.oddSize)
	def testOrdinationEven(self):
		self.genericTest(self.evenSize)
	def testOrdinationEmpty(self):
		self.genericTest(self.empty)
	def testOrdinationEqual(self):
		self.genericTest(self.equal)
	def testOrdinationRepeated(self):
		self.genericTest(self.repeated)
	def testOrdinationOrdered(self):
		self.genericTest(self.ordered)

	def testInvalidLeftIndex(self):
		self.invalidParameters(self.oddSize,-5,3)
		self.invalidParameters(self.evenSize,-5,3)
		self.invalidParameters(self.empty,-5,3)
		self.invalidParameters(self.equal,-5,3)
		self.invalidParameters(self.repeated,-5,3)
		self.invalidParameters(self.ordered,-5,3)
	
	def testInvalidRightIndex(self):
		self.invalidParameters(self.oddSize,0,len(self.oddSize))
		self.invalidParameters(self.evenSize,0,len(self.evenSize))
		self.invalidParameters(self.empty,0,len(self.empty))
		self.invalidParameters(self.equal,0,len(self.equal))
		self.invalidParameters(self.repeated,0,len(self.repeated))
		self.invalidParameters(self.ordered,0,len(self.ordered))

	def testInvalidLeftRight(self):
		self.invalidParameters(self.oddSize,5,5)
		self.invalidParameters(self.evenSize,5,3)
if __name__ == "__main__":
	unittest.main()
