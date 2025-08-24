print("Enter the numbers between which you want to find all the primes.")
n1=int(input("Enter the initial number "))
n2=int(input("Enter the final number "))

def isPrime(args):
    count=0
    for i in range(1,args+1):
        if args%i==0:
            count+=1
    if count==2:
        return True
    return False

for i in range(n1,n2+1):
    if isPrime(i):
        print(i,end=" ")