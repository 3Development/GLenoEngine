


zFar = 200
zNear = 2

def zNormalizationFormula1(z):
    firstPart =  -(zFar + zNear) / (zFar - zNear)
    secondPart = -(2*zFar*zNear) / (zFar - zNear)

    print("firstPart is ",firstPart, "  secondPart is ", secondPart)

    print(z," * ",firstPart," + ",secondPart, " = ",(z*firstPart)+secondPart)
    



if __name__ == "__main__":
    for i in range(195,205):
        zNormalizationFormula1(-i)