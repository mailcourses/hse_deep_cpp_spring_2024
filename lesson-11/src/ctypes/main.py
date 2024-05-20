#! /usr/bin/env python3

import random
import ctypes

def main():
    clib = ctypes.cdll.LoadLibrary('./libutils.so')

    clib.fibonacci.argstype = [ctypes.c_int]
    clib.fibonacci.restype = ctypes.c_int

    clib.func1.argstype = [ctypes.c_int,]
    clib.func1.restype = ctypes.c_int

    clib.func2.argstype = [ctypes.c_char_p, ctypes.c_int]
    clib.func2.restype = ctypes.c_void_p

    clib.sum.argstype = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]
    clib.sum.restype = ctypes.c_int

    for num in range(5):
        print(f"func1.res = {clib.func1(num)}")

    s = b"hello kitty"
    clib.func2(s, len(s))

    l = list(range(10))
    random.shuffle(l)
    print(f"list = {l}, sum = {sum(l)}")

    list_type = ctypes.c_int * len(l)
    cres = clib.sum(list_type(*l), len(l))
    print(f"list = {l}, csum = {cres}")

    print(f"fibonacci res = {clib.fibonacci(10)}")

if __name__ == "__main__":
    main()
