s1="This is a string where I'm gonna find all charactors at even indeces"
for i in range(len(s1)):
    if i%2 == 0:
        print(s1[i],end=" ")