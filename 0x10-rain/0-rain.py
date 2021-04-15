#!/usr/bin/python3
""" Contains rain method. """


def rain(walls):
    """ Calculates how much water is retained. """
    total = 0
    left = -1
    right = -1

    for i in range(len(walls)):
        if left == -1 and walls[i] > 0:
            left = i
        elif left != -1 and walls[i] >= walls[left]:
            total += (i - (left + 1)) * walls[left]
            left = i

    for i in range(len(walls) - 1, -1, -1):
        if right == -1 and walls[i] > 0:
            right = i
        elif right != -1 and walls[i] >= walls[right]:
            total += (right - (i + 1)) * walls[right]
            right = i
        if right == left:
            break

    return total
    