import sys

def convert4to2d(points):
    x = points[0] / points[3]
    y = points[1] / points[3]
    z = points[2] / points[3]
    print("3d ",[x,y,z])
    return convert3to2d([x,y,z]) 

def convert3to2d(points):
    x = points[0] / points[2]
    y = points[1] / points[2]
    return [x,y]




if __name__ == "__main__":
    input = [float(c) for c in sys.argv[1].split(',')] 
    print("2d ",convert4to2d(input))