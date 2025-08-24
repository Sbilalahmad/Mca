# -*- coding: utf-8 -*-


n1=int(input("Enter 1st number :"))
n2=int(input("Enter 2nd number :"))
prod=n1*n2
print("Product of ",n1, " and " ,n2, " = ",prod)
if prod<=5000:
    s=n1+n2
    print("Sum of ", n1," and ",n2," = " ,s)
else:
    print("The product is greater than 5000 so no sum will print.")
