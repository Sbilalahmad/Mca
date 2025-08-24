# -*- coding: utf-8 -*-
print("This program is to calculate the cube of all numbers from 1 to a given number.")

def cubeUpto(n):
    
    for i in range(1,n+1,1):
        print(f" Cube of {i} = {i**3}")
num=int(input("Enter the number upto which you want the cubes : "))
cubeUpto(num)