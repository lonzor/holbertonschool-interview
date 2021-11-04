#!/usr/bin/python3
"""
Contains the function canUnlockAll
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be unlocked
    Returns True if all boxes can be opened
    Returns False if they can't
    """
    if not boxes:
        return False

    size = len(boxes)

    for x in range(1, size - 1):
        matched = False

        for i in range(size):
            matched = x in boxes[i] and x != i
            if matched:
                break

        if matched is False:
            return matched

    return True
