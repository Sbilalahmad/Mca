"""5. Write a program to remove characters from a string starting from the nth position to
the last and return a new string. Example: remove_chars("aligarh", 3) should output
ali."""

def remove_chars(urstring , n):
    l1=list(urstring)
    length=len(l1)
    newString=""
    for i in range(n,length):
        newString=newString+str(l1[i])
    print(newString)
    for i in range(length,n):
        l1.pop
    urstring=""
    for i in range(n):
        urstring=urstring+str(l1[i])
    print(urstring)
    
remove_chars("Depart ment of cs.",3)

