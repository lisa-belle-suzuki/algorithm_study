num_to_chars = {
    "2": [str('a'), str('b'), str('c')],
    "3": [str('d'), str('e'), str('f')],
    "4": [str('g'), str('h'), str('i')],
    "5": [str('j'), str('k'), str('l')],
    "6": [str('m'), str('n'), str('o')],
    "7": [str('p'), str('q'), str('r'), str('s')],
    "8": [str('t'), str('u'), str('v')],
    "9": [str('w'), str('x'), str('y'), str('z')]
}


def cur_string(digits: str, cur_list) -> str:
    if len(digits) == 0:
        return cur_list
    if len(cur_list) < 3:
        print("aaa")
        return cur_string(digits[1:], num_to_chars[digits[0]] )
    else:
        ret = []
        cur_chars = num_to_chars[digits[0]]
        for c_str in cur_chars:
            ret.extend([ele + c_str for ele in cur_list])

        print("cur_list = ", cur_list)
        return cur_string(digits[1:], ret)

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        return cur_string(digits, [])
