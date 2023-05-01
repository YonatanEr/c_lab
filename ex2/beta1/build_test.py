import random

def f_print(f, line):
    f.write(line + "\n")


def func(f, word):
    line = 'diff <(./grep "' + word + '" rand_file.txt) <(grep "' + word + '" rand_file.txt)'
    f_print(f, line)
    f_print(f, '') 
    

dic = " abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ  "

f = open("my_test.sh", "w")

f_print(f, "#!/bin/bash")

f_print(f, "")

func(f, "")

for x in dic:
    func(f, x)


for i in range(2**4):
    func(f, dic*i)


for i in range(2**8):
    for n in range(2, 8):
        func(f, "".join(random.choices(dic, k=n)))

f.close()




f = open("rand_file.txt", "w")
for i in range(int(1e3)):
    f_print(f, "".join(random.choices(dic, k=random.randint(0, 2**8))))
f.close()