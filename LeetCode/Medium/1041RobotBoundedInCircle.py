class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        direction = 0
        dx_dy = [(0, 1), (-1, 0), (0, -1), (1, 0)]

        x = 0
        y = 0
        for instruction in instructions:
            if instruction == 'G':
                dx, dy = dx_dy[direction]
                x += dx
                y += dy
            elif instruction == 'L':
                direction += 1
                direction %= 4
            else:
                direction -= 1
                direction %= 4

        print("x:", x, "y:", y)
        if x == 0 and y == 0:
            return True

        if direction == 0:
            return False
        else:
            return True
