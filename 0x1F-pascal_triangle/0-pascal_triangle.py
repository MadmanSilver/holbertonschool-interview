#!/usr/bin/python3
""" Contains the pascal_triangle function. """


def pascal_triangle(n):
    """ Calculates a list of integers representing Pascal's triangle of n. """
    if n <= 0:
        return []

    tri = [[1]]
    for row in range(2, n + 1):
        new = []
        for col in range(row):
            res = 0
            if col != 0:
                res += tri[-1][col - 1]
            if col + 1 != row:
                res += tri[-1][col]
            new.append(res)
        tri.append(new)
    return tri
