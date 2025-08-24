"""1. Write a program to create a function cal_sum_sub() that accepts two variables and
calculates addition and subtraction. Also, it must return both addition and subtraction
in a single return call"""
def cal_sum_sub(n1,n2):
    sum=n1+n2
    sub=n1-n2
    print(f"Addition of {n1} and {n2} ={sum}")
    print(f"Subtraction of {n1} and {n2} ={sub}")
    
n1=int(input("Enter the number 1 :"))
n2=int(input("Enter the number 2 :"))

cal_sum_sub(n1,n2)