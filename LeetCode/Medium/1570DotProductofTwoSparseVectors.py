class SparseVector:
    def __init__(self, nums: List[int]):
        self.vector = nums


    # Return the dotProduct of two sparse vectors
    def dotProduct(self, vec: 'SparseVector') -> int:
        product = 0
        for num1, num2 in zip(self.vector, vec.vector):
            if num1 == 0 or num2 == 0:
                continue
            product += num1 * num2
        return product


# Your SparseVector object will be instantiated and called as such:
# v1 = SparseVector(nums1)
# v2 = SparseVector(nums2)
# ans = v1.dotProduct(v2)