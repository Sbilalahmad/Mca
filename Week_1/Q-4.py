print("This program will check if the entered number is palindrone or not.")

num=input("Ente a number to check : ")
numi=num[::-1]

if num ==numi:
    print("This number is palindron")
else:
    print("This number is not a palindrone.")