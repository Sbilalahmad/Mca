"""4. Given two Python lists, write a program to iterate both lists simultaneously and display
items from list 1 in original order and items from list 2 in reverse order."""


L1=[2,3,4,5,6,7,8,9]
L2=[20,30,40,50,60,90,77,99]
L2.reverse()
m=max(len(L1),len(L2))
for i in range(m):
    if i<len(L1):
        print(L1[i],end=" ")
    if i<len(L2):
        print(L2[i],end=" ")

