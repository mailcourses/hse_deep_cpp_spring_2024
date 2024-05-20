#! /usr/bin/env python3

import random

import cutils

def main():
    l = list(range(10))
    d = {'a': 1, 'b': 2}
    random.shuffle(l)
    print(sum(l), cutils.sum(l, len(l)))

    print(cutils.fibonacci(10))

if __name__ == "__main__":
    main()
