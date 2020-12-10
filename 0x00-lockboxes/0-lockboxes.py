#!/usr/bin/python3


def canUnlockAll(boxes):
    keys = [0]
    last = 0

    while last < len(keys):
        last = len(keys)
        for box in range(len(boxes)):
            if box in keys:
                for key in boxes[box]:
                    if key < len(boxes) and key not in keys:
                        keys.append(key)

    return len(keys) == len(boxes)
