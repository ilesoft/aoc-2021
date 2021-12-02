import sys

def main(depths):
    pre_window_sum = None
    count = 0
    i = 0
    while True:
        if (i + 3) > len(depths):
            print(count)
            break
        new_window_sum = int(depths[i]) + int(depths[i + 1]) + int(depths[i + 2])
        if pre_window_sum != None and pre_window_sum < new_window_sum:
            count = count + 1
        pre_window_sum = new_window_sum
        i = i + 1
f = open(sys.argv[1], "r")
main(f.readlines())
