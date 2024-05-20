#! /usr/bin/env python3

import random

import cffi

def main():
    ffi = cffi.FFI()
    clib = ffi.dlopen('../ctypes/libutils.so')
    ffi.cdef('int sum(int*, int);')

    l = list(range(10))
    random.shuffle(l)
    c_arr = ffi.new("int[]", l)

    res = clib.sum(c_arr, len(l))
    print(f"Sum of array {l} is {res}")

    ffi = cffi.FFI()
    clib = ffi.dlopen('./libutils.so')
    ffi.cdef('''
    struct Point {
        int x;
        int y;
    };

    int area(struct Point* p1, struct Point* p2);
    ''')

    p1 = ffi.new('struct Point*')
    p2 = ffi.new('struct Point*')
    p1.x = 10
    p1.y = 15
    p2.x = 23
    p2.y = 10

    res = clib.area(p1, p2)
    print(res)

if __name__ == "__main__":
    main()
