# -*- coding: utf-8 -*-

def deencrypt(str, key):
    plaintext = ""

    for ch in list(str):
        if 'A' <= ch <= 'Z':
            plaintext += chr((ord(ch) - ord('A') + key) % 26 + ord('A'))
        elif 'a' <= ch <= 'z':
            plaintext += chr((ord(ch) - ord('a') + key) % 26 + ord('a'))
        else:
            plaintext += ch

    return plaintext

if __name__ == '__main__':
    ciphertext = input("PLEASE INPUT CIPHERTEXT : ")

    for i in range(1, 26):
        print('{0:2d}'.format(i) + " : " + deencrypt(ciphertext, i))

    input(input("PLEASE PRESS ANY"))