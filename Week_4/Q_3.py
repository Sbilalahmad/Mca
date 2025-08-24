# 3. Given a list of numbers, write a program to turn every item of the list into its square

def sqrOf(arr):
    for i in range(len(arr)):
        arr[i] = arr[i]**2
    return arr

alist=[2,3,4,5,6,7,8,9]
print(sqrOf(alist)) 