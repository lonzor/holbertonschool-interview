#!/usr/bin/python3
"""
contains function minOperations(n)
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to complete task.
    """
    if n < 2 or type(n) is not int:
        return 0

    oper_list = []
    i = 1
    while n != 1:
        i += 1
        if n % i == 0:
            while (n % i == 0 and n != 1):
                n = n / i
                oper_list.append(i)
    return sum(oper_list)
