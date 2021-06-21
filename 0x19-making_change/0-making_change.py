#!/usr/bin/python3
""" Contains the makeChange function. """

def makeChange(coins, total):
    """ Calculates the least number of coins required to reach total. """
    curTot = 0
    curCoin = 0
    totCoin = 0

    if total <= 0:
        return 0

    coins.sort(reverse=True)

    for coin in coins:
        curCoin = int((total - curTot) / coin)
        curTot += curCoin * coin
        totCoin += curCoin

    if total - curTot > 0:
        return -1

    return totCoin