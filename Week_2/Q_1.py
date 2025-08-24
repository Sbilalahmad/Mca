print("This program is to extract each digit from an integer in reverse order")

def revDigitOf(n):
    while n!=0:
        digit=n%10
        n//=10
        print(digit,end=" ")
num=int(input("Enter the number to extract it's digits : "))
rd=revDigitOf(num)
