#!/usr/bin/env python3
"""
contains function rain()
"""


def rain(walls):
    """
    Calculates amount of rainfall walls can keep.
    """
    if not walls:
        return 0

    tot_rain = 0

    for w1, w2 in enumerate(walls):
        left_max = max(walls[:w1 + 1])
        right_max = max(walls[w1:])
        wall_min = min(left_max, right_max)
        tot_rain = tot_rain + max(wall_min - w2, 0)

    return tot_rain
