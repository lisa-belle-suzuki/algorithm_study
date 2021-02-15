class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        originalColor = image[sr][sc]
        di_dj_list = ((-1,0),(1,0),(0,1),(0,-1))
        stack = [(sr,sc)]
        visited = [ [False] * len(image[0]) for _ in range(len(image)) ]
        while stack:
            i,j = stack.pop()
            if image[i][j]!=originalColor:
                continue
            image[i][j] = newColor
            visited[i][j] = True
            for di,dj in di_dj_list:
                new_i = i+di
                new_j = j+dj
                if not (0<=new_i<len(image)) or not (0<=new_j<len(image[0])):
                    continue
                if visited[new_i][new_j]:
                    continue
                stack.append((new_i,new_j))
        return image
