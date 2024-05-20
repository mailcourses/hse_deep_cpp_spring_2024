#! /usr/bin/env python3

import ctypes
import time

import cffi

import cutils
import cyutils

MAX_N = 36

def fibonacci(n):
    if n < 2:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

def cython_fibonacci():
    start_ts = time.time()
    res = cyutils.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"[cython_fibonacci] Time of execution is {end_ts - start_ts} seconds")
    return res

def capi_fibonacci():
    start_ts = time.time()
    res = cutils.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"[capi_fibonacci] Time of execution is {end_ts - start_ts} seconds")
    return res

def ctypes_fibonacci():
    clib = ctypes.cdll.LoadLibrary('./ctypes/libutils.so')
    clib.fibonacci.argstype = [ctypes.c_int]
    clib.fibonacci.restype = ctypes.c_int
    start_ts = time.time()
    res = clib.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"[ctypes_fibonacci] Time of execution is {end_ts - start_ts} seconds")
    return res

def cffi_fibonacci():
    ffi = cffi.FFI()
    clib = ffi.dlopen('./cffi/libutils.so')
    ffi.cdef('int fibonacci(int);')
    start_ts = time.time()
    res = clib.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"[cffi_fibonacci] Time of execution is {end_ts - start_ts} seconds")
    return res

def py_fibonacci():
    start_ts = time.time()
    res = fibonacci(MAX_N)
    end_ts = time.time()
    print(f"[py_fibonacci] Time of execution is {end_ts - start_ts} seconds")
    return res

def main():
    py_res = py_fibonacci()
    ctypes_res = ctypes_fibonacci()
    cffi_res = cffi_fibonacci()
    capi_res = capi_fibonacci()
    cython_res = cython_fibonacci()
    print(py_res, ctypes_res, cffi_res, capi_res, cython_res)
    assert(py_res == ctypes_res == cffi_res == capi_res == cython_res)

if __name__ == "__main__":
    main()
