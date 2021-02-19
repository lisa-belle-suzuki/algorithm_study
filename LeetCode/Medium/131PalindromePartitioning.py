def isPalindrome(s: str) -> bool:
    for i in range(len(s)//2):
        if s[i]!=s[len(s)-1-i]:
            return False
    return True

class Solution:
    def __init__(self):
        self.ans = []

    def partition(self, s: str) -> List[List[str]]:
        # 全探索
        def search(next_idx: int, str_list: tuple, cur_str: str):
            if next_idx >= len(s):
                if len(cur_str)==0:
                    self.ans.append(str_list)
                    return
                if not isPalindrome(cur_str):
                    return
                return

            # partitionを入れずにつなげる
            search(next_idx+1, str_list, cur_str+s[next_idx])
            # partition入れる
            cur_str += s[next_idx]
            if isPalindrome(cur_str):
                str_list += tuple([cur_str])
                search(next_idx+1, str_list, '')
            return

        search(0,tuple([]),"")
        return self.ans
