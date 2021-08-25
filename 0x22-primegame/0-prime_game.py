#!/usr/bin/python3
"""Contains the isWinner function."""


def isWinner(x, nums):
    """Calculates the winner of the Prime Game."""
    mariaW = 0
    benW = 0
    pnums = {2, 3, 5, 7}
    largestp = 7

    if type(nums) is not list or x > len(nums):
        return None

    for i in range(0, x):
        primes = 0

        for num in range(2, nums[i] + 1):
            if num in pnums:
                primes += 1
                continue
            if num < largestp:
                continue

            for p in range(2, int(num/2) + 1):
                if num % p == 0:
                    break
            else:
                pnums.add(num)
                if num > largestp:
                    largestp = num
                primes += 1

        if primes % 2 == 1:
            mariaW += 1
        else:
            benW += 1

    if mariaW > benW:
        return "Maria"
    elif benW > mariaW:
        return "Ben"
    return None
