#!/usr/bin/python3
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
    wall_length = len(walls)
    left = [0] * wall_length
    right = [0] * wall_length

    left[0] = walls[0]
    for i in range(1, wall_length):
        left[i] = max(left[i - 1], walls[i])

    right[wall_length - 1] = walls[wall_length - 1]
    for i in range(wall_length - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    for i in range(0, wall_length):
        tot_rain += min(left[i], right[i]) - walls[i]

    return tot_rain
