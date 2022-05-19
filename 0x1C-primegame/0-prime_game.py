#!/usr/bin/python3
"""
Contains function isWinner(x, nums)
"""


def isWinner(x, nums):
    """
    solves the prime number game
    """
    if not nums or x < 1:
        return None
    n = max(nums)
    filters = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not filters[i]:
            continue
        for j in range(i * i, n + 1, i):
            filters[j] = False

    filters[0] = filters[1] = False
    x = 0
    for i in range(len(filters)):
        if filters[i]:
            x += 1
        filters[i] = x

    y = 0
    for n in nums:
        y += filters[n] % 2 == 1
    if y * 2 == len(nums):
        return None
    if y * 2 > len(nums):
        return "Maria"
    return "Ben"
