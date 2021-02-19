# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.flatten_list = []
        self.flatten(nestedList)
        print("self.flatten_list = ", self.flatten_list)
        self.idx = -1
        self.list_size = len(self.flatten_list)

    def flatten(self, nested_list):
        for nested_int in nested_list:
            if nested_int.isInteger():
                self.flatten_list.append(nested_int.getInteger())
            else:
                self.flatten(nested_int.getList())

    def next(self) -> int:
        if self.hasNext():
            self.idx += 1
            return self.flatten_list[self.idx]
        return -1

    def hasNext(self) -> bool:
        return self.idx < self.list_size-1

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())