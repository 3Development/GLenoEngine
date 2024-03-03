import math
import sys


def rotate(coordinate,angle):
    rotation = complex(math.cos(angle * (math.pi/180)),  math.sin(angle * (math.pi/180)))
    return coordinate * rotation;



if __name__ == "__main__":
    real = float(sys.argv[1])
    img = float(sys.argv[2])
    a = complex(real,img)

    print(rotate(a,float(sys.argv[3])))