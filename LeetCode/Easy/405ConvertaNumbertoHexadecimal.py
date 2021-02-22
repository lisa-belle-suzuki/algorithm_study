def int_to_reversed_hex(num: int):
    power_of_hex = 16
    while num > 0:
        yield num % power_of_hex
        num >>= 4

def hex_to_str(hex_int: int):
    if hex_int <= 9:
        return str(hex_int)
    return chr(hex_int - 10 + ord('a'))

class Solution:
    def toHex(self, num: int) -> str:
        if num==0: return "0"
        if num < 0:
            num += 2**32
        ans = ""
        for hex_ in int_to_reversed_hex(num):
            ans += hex_to_str(hex_)
        return ans[::-1]
