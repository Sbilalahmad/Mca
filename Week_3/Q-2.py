depth=int(input("Enter the depth of the pattern : "))

for i in range(0,depth+1):
    for j in range(0,i):
        print("*",end=" ")
    print(" ")
    
for i in range(depth-1,0,-1):
    for j in range(i,0,-1):
        print("*",end=" ")
    print(" ")
    