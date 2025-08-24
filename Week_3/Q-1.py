depth=int(input("Enter the depth of the pattern : "))

for i in range(depth,0,-1):
    for j in range(i,0,-1):
        print(j,end=" ")
    print(" ")