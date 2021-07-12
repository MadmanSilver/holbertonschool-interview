#!/usr/bin/python3
""" Imma measure an island! """


def island_perimeter(grid):
    """ This mah brain! """
    y = 0
    x = 0
    perim = 2
    direction = 2

    if not isinstance(grid, list):
        return 0

    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if grid[y][x]:
                break
        if x + 1 != len(grid[0]):
            break

    if len(grid) <= 0 or len(grid[0]) <= 0:
        return 0

    if len(grid) == 1 and len(grid[0]) == 1:
        return 4

    if y + 1 == len(grid) and x + 1 == len(grid[0]):
        return 0

    prev_y = y
    prev_x = x

    if x + 1 < len(grid[0]) and grid[y][x + 1]:
        x += 1
        direction = 1
    elif y + 1 < len(grid) and grid[y + 1][x]:
        perim += 1
        y += 1
        direction = 2
    else:
        return 4

    while x != prev_x or y != prev_y:
        if direction == 0:
            if x - 1 >= 0 and grid[y][x - 1]:
                x -= 1
                direction = 3
            elif y - 1 >= 0 and grid[y - 1][x]:
                perim += 1
                y -= 1
                direction = 0
            elif x + 1 < len(grid[0]) and grid[y][x + 1]:
                perim += 2
                x += 1
                direction = 1
            else:
                perim += 3
                y += 1
                direction = 2
        elif direction == 1:
            if y - 1 >= 0 and grid[y - 1][x]:
                y -= 1
                direction = 0
            elif x + 1 < len(grid[0]) and grid[y][x + 1]:
                perim += 1
                x += 1
                direction = 1
            elif y + 1 < len(grid) and grid[y + 1][x]:
                perim += 2
                y += 1
                direction = 2
            else:
                perim += 3
                x -= 1
                direction = 3
        elif direction == 2:
            if x + 1 < len(grid[0]) and grid[y][x + 1]:
                x += 1
                direction = 1
            elif y + 1 < len(grid) and grid[y + 1][x]:
                perim += 1
                y += 1
                direction = 2
            elif x - 1 >= 0 and grid[y][x - 1]:
                perim += 2
                x -= 1
                direction = 3
            else:
                perim += 3
                y -= 1
                direction = 0
        else:
            if y + 1 < len(grid) and grid[y + 1][x]:
                y += 1
                direction = 2
            elif x - 1 >= 0 and grid[y][x - 1]:
                perim += 1
                x -= 1
                direction = 3
            elif y - 1 >= 0 and grid[y - 1][x]:
                perim += 2
                y -= 1
                direction = 0
            else:
                perim += 3
                x += 1
                direction = 1

    return perim
