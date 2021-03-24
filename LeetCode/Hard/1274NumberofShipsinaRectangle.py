# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Sea(object):
#    def hasShips(self, topRight: 'Point', bottomLeft: 'Point') -> bool:
#
# class Point(object):
#	def __init__(self, x: int, y: int):
#		self.x = x
#		self.y = y

class Solution(object):
    def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point') -> int:
        cnt = 0

        stack = [(bottomLeft.x, topRight.x, bottomLeft.y, topRight.y)]
        while stack:
            x1, x2, y1, y2 = stack.pop()
            if x1 > x2 or y1 > y2:
                continue
            xc = (x1+x2)//2
            yc = (y1+y2)//2
            p = Point(x1, y1)
            q = Point(x2, y2)
            if sea.hasShips(q, p):
                if x1 == x2 and y1 == y2:  # point
                    cnt += 1
                else:
                    stack.append((x1, xc, y1, yc))
                    stack.append((x1, xc, yc+1, y2))
                    stack.append((xc+1, x2, y1, yc))
                    stack.append((xc+1, x2, yc+1, y2))

        return cnt
