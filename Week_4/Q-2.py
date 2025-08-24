"""2. Write a function to return True if the first and last number of a given list are the same.
If the numbers are different, return False."""

def isfirstEqualLast(arg):
    n=len(arg)
    if arg[0] == arg[n-1]:
        return True
    return False

ar=[11,22,55,44,66,788,77,11]
ar2=[11,22,55,44,66,788,77,1]
print(isfirstEqualLast(ar))
print(isfirstEqualLast(ar2))