#!/usr/bin/python3
""" Contains the rotateMatrix function. """


def rotate_2d_matrix(matrix):
    """ Rotates a 2D matrix 90 degrees clockwise. """
    size = len(matrix)

    for i in range(3):
        for x in range(0, int(size / 2)):
            for y in range(x, size - x - 1):
                tmp = matrix[x][y]
                matrix[x][y] = matrix[y][size - 1 - x]
                matrix[y][size - 1 - x] = matrix[size - 1 - x][size - 1 - y]
                matrix[size - 1 - x][size - 1 - y] = matrix[size - 1 - y][x]
                matrix[size - 1 - y][x] = tmp
