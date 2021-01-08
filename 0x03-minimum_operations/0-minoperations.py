#!/usr/bin/python3
""" Contains the minOperations function. """


def minOperations(n):
    """ Calculates the minimum copy all/paste operations to achieve n """
    if n < 2:
        return 0

    opps = 0
    total = 1
    coppied = 0

    while total < n:
        if n % total == 0:
            coppied = total
            opps += 1

        total += coppied
        opps += 1

    if total == n:
        return opps

    return 0
