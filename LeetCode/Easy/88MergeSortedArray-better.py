class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        if m == 0 and n != 0:
            nums1[:] = nums2[:]
        elif m != 0 and n != 0:
            i = -(n+1) #num1のindex
            j = -1 # nums2のindex
            k = -1
            while k >= -(m + n):
                if i < -(m+n):
                    if j == -1:
                        nums1[:n] = nums2[:n]
                    else:
                        nums1[:k+1] = nums2[:j+1]
                    break
                if j < -n:
                    break
                if nums1[i] > nums2[j]:
                    nums1[k] = nums1[i]
                    i -= 1
                else:
                    nums1[k] = nums2[j]
                    j -= 1
                k -= 1
