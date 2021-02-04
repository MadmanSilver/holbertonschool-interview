#!/usr/bin/python3
""" Reads and parses logs from stdin. """
import sys
import signal
import traceback

i = 1
total_size = 0
codes = {'200': 0, '301': 0, '400': 0, '401': 0,
         '403': 0, '404': 0, '405': 0, '500': 0}


def pstuff(sig=None, frame=None):
    """ Prints stats. """
    print("File size: {}".format(total_size))
    if codes['200'] != 0:
        print("200: {}".format(codes['200']))
    if codes['301'] != 0:
        print("301: {}".format(codes['301']))
    if codes['400'] != 0:
        print("400: {}".format(codes['400']))
    if codes['401'] != 0:
        print("401: {}".format(codes['401']))
    if codes['403'] != 0:
        print("403: {}".format(codes['403']))
    if codes['404'] != 0:
        print("404: {}".format(codes['404']))
    if codes['405'] != 0:
        print("405: {}".format(codes['405']))
    if codes['500'] != 0:
        print("500: {}".format(codes['500']))

try:
    for line in sys.stdin:
        line = line.split()
        total_size += int(line[-1])
        codes[line[-2]] += 1
        if i % 10 == 0:
            pstuff()
        i += 1
finally:
    pstuff()
