class Stack:
    def __init__(self, nums=[]):
        super().__init__()
        self.nums = nums


    def isEmpty(self):
        return len(self.nums) == 0


    def push(self, elem):
        self.nums.append(elem)
        return


    def pop(self):
        ret = self.nums[-1]
        self.nums = self.nums[:-1]
        return ret


    def peek(self):
        if self.isEmpty():
            return None
        return self.nums[-1]


def sort_stack(s1_array):
    s1 = Stack(s1_array)
    s2 = Stack()

    # 長さを知る
    length = 0
    while not s1.isEmpty():
        num = s1.pop()
        s2.push(num)
        length += 1
    while not s2.isEmpty():
        num = s2.pop()
        s1.push(num)

    cnt = 0 # ソート済の要素の数
    while cnt <= length:
        cur_max = -1000000
        # 最大値を探しながらs1をs2に移す(最初のcnt個数分は無視)
        i = 0
        while not s1.isEmpty():
            num = s1.pop()
            s2.push(num)
            if i >= cnt and num > cur_max:
                cur_max = num
            i += 1
        # その最大値以外の要素をs1に戻す（それより大きい値も含めて）
        isCurMaxFound = False
        while not s2.isEmpty():
            num = s2.pop()
            if not isCurMaxFound and num == cur_max:
                isCurMaxFound = True
            else:
                s1.push(num)
        # 最後にその最大値をs1にpush
        if cur_max != -1000000:
            s1.push(cur_max)
        cnt += 1
    return s1


if __name__ == '__main__':
    ans = sort_stack([8,2,4,6,3,8,5])
    print(ans.nums)
