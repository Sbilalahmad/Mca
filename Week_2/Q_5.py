
def sumOfDigitsOf(n):
    count=0
    while n!=0:
        count+=n%10
        n//=10
    return count

num=int(input("Enter the number to get sum of  it's digits :"))
di=sumOfDigitsOf(num)
print(f"Sum of the digits of {num} = {di}")