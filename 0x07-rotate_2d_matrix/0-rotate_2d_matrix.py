#!/usr/bin/python3
"""
contains method rotate_2d_matrix()
"""


def rotate_2d_matrix(matrix):
    """
    rotates a 2d matrix 90 degrees clockwise
    """
    if len(matrix) < 2:
        return

    lng = len(matrix)

    for i in range(0, int(lng / 2)):
        for x in range(i, lng - i - 1):
            temp = matrix[i][x]
            matrix[i][x] = matrix[lng - x - 1][i]
            matrix[lng - x - 1][i] = matrix[lng - i - 1][lng - x - 1]
            matrix[lng - i - 1][lng - x - 1] = matrix[x][lng - i - 1]
            matrix[x][lng - i - 1] = temp
    return
