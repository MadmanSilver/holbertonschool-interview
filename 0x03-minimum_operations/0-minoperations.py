#!/usr/bin/python3
""" Contains the minOperations function. """

def minOperations(n):
    """ Calculates the minimum copy all/paste operations to achieve n """
    if n < 1:
        return 0

    return operate(n, 1, n, 1, 1)

def operate(n, opps, lowest, copied, total):
    """ Recursively checks every possible path """
    if total == n:
        if opps < lowest:
            return opps
        return lowest

    if total > n:
        return lowest

    lowest = operate(n, opps + 1, lowest, copied, total + copied)

    lowest = operate(n, opps + 2, lowest, total, total * 2)

    return lowest