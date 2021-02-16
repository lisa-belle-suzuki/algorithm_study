# class Stack:
#     def __init__(self, nums=[]):
#         super().__init__()
#         self.nums = nums


# s1 = Stack()
# s1.nums.append(1)
# s2 = Stack()

# from copy import deepcopy
# class MyList(list):
#     def is_empty(self):
#         if len(self)==0:
#             return True
#         else:
#             return False

# mylist = MyList()
# import pdb;pdb.set_trace()


l = ["a", "b", "c"]


from time import time
start_time = time()
for _ in range(100):
    s = ""
    for x in l: s += x
end_time = time()
diff1 = end_time - start_time

start_time = time()
for _ in range(100):
    s = "".join(l)
end_time = time()
diff2 = end_time - start_time

b = bytearray("", encoding="utf-8")
l = [bytearray(s, encoding="utf-8") for s in l]
print("id(b) = ", id(b))
start_time = time()
for _ in range(100):
    for s in l: b += s
end_time = time()
diff3 = end_time - start_time
print("id(b) = ", id(b))

print("diff1(str +=  ) = ", diff1)
print("diff2(join    ) = ", diff2)
print("diff3(bytes +=) = ", diff3)


start_time = time()
s = ""
a = "aaa"
for _ in range(100):
    s += a
end_time = time()
diff4 = end_time - start_time

s = ""
start_time = time()
for _ in range(100):
    s = "".join([s,a])
end_time = time()
diff5 = end_time - start_time

s = bytearray("", encoding="utf-8")
a = bytearray("aaa", encoding="utf-8")
print("id(b) = ", id(b))
start_time = time()
for _ in range(100):
    s += a
end_time = time()
diff6 = end_time - start_time
print("id(b) = ", id(b))

print("diff4(str +=  ) = ", diff4)
print("diff5(join    ) = ", diff5)
print("diff6(bytes +=) = ", diff6)

import pdb;pdb.set_trace()
