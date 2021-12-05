import sys
from math import floor

class Board:
    def __init__(self, numbers):
        self.numbers = numbers
        self.sum = sum(numbers)
        self.x_win_check = [0, 0, 0, 0, 0]
        self.y_win_check = [0, 0, 0, 0, 0]

    def set(self, number):
        if number not in self.numbers:
            return False

        i = self.numbers.index(number) 
        column = i % 5
        row = floor(i / 5)

        self.sum -= number

        self.x_win_check[column] += 1
        self.y_win_check[row] += 1

        if 5 in self.x_win_check or 5 in self.y_win_check:
            print(self.sum * number)
            return True


def main(lines):
    draw_queue = lines[0].split(",") 

    lines = lines[1:]  # remove draw_queue
    boards = []
    next_board = []

    for line_as_str in lines:
        line = []
        while len(line_as_str) > 2:
            line.append(int(line_as_str[:3].strip()))
            line_as_str = line_as_str[3:]

        if len(line) == 0:
            continue

        next_board.extend(line)
        if len(next_board) == 25:
[1, 3, 2, 1, 3]
            boards.append(Board(next_board))
            next_board = []

    for draw in draw_queue:
        for board in boards:
            if board.set(int(draw)):
                return

f = open(sys.argv[1], "r")
main(f.readlines())
