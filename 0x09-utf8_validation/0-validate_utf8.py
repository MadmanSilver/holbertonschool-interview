#!/usr/bin/python3
""" Contains the validUTF8 function. """

def validUTF8(data):
    """ Checks if a given dataset is valid UTF-8 encoding. """
    conts = 0
    for byte in data:
        byte = byte & 255
        if conts == 0:
            if byte >> 7 == 0:
                conts = 0
            elif byte >> 5 == 6:
                conts = 1
            elif byte >> 4 == 14:
                conts = 2
            elif byte >> 3 == 30:
                conts = 3
            else:
                return False
        else:
            if byte >> 6 != 2:
                return False
            conts -= 1
    
    if conts > 0:
        return False

    return True