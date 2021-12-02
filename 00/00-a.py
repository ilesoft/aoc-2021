import sys

def main(depths):
    pre = None
    count = 0

    for depth in depths:
        depth = int(depth.strip())
        if pre != None and pre < depth:
            count = count + 1
        pre = depth
    print(count)
f = open(sys.argv[1], "r")
main(f.readlines())
