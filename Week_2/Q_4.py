num=int(input("Enter the number upto which you want the factorial : "))
prod=1
for i in range(1,num+1):
    prod *= i
    print(f"{prod} ",end=" ")