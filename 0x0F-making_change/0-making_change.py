#!/usr/bin/python3
"""
Contains function makeChange(coins, total)
"""


def makeChange(coins, total):
    """
    Gives the number of coins needed in order to meet the given amount
    Gives the least amount of coins, too
    """
    num = 0
    if total <= 0:
        return num

    coins.sort(reverse=True)
    while (total > 0 and coins):
        n = int(total / coins[0])
        total = total - (coins[0] * n)
        num = num + n
        coins.remove(coins[0])

    if total != 0:
        return -1

    return num
