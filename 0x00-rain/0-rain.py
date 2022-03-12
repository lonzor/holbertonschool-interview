#!/usr/bin/env python3
"""
contains function rain()
"""


def rain(walls):
    """
    Calculates amount of rainfall walls can keep.
    """
    if walls is None or len(walls) < 2:
        return 0

    tot_rain = 0
    l = len(walls)
    left = [0] * l
    right = [0] * l

    left[0] = walls[0]
    for i in range(1, l):
        left[i] = max(left[i - 1], walls[i])

    right[l - 1] = walls[l - 1]
    for i in range(l - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    for i in range(0, l):
        tot_rain += min(left[i], right[i]) - walls[i]

    return tot_rain
