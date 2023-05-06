import random


def f_print(f, line, i=None):
    if (i!=None):
        i = 1
        #f.write("echo test number " + str(i[0]) +"\n")
    f.write(line + "\n\n")


def func(f, word, i):
    for cur_file in ["empty_file", "rand_file"]:
        line = 'diff <(./my_grep ' + '"' + word + '"' + '   -n -x -A '     +          '0  test_files/' + str(cur_file) + '.txt) <(grep  ' + '"' + word + '"' + '   -n -x -A '                  + '0  test_files/' + str(cur_file) + '.txt)'
        f_print(f, line, i)
        i[0] = i[0]+1
        line = 'diff <(./my_grep ' + '"' + word + '"' + '   -n -x -v -A '     +          '1  test_files/' + str(cur_file) + '.txt) <(grep  ' + '"' + word + '"' + '   -n -x -v -A '                  + '1  test_files/' + str(cur_file) + '.txt)'
        f_print(f, line, i)
        i[0] = i[0]+1
        line = 'diff <(./my_grep ' + '"' + word + '"' + ' -c -n -x -v -A '     +          '2  test_files/' + str(cur_file) + '.txt) <(grep  ' + '"' + word + '"' + ' -c -n -x -v -A '                  + '2  test_files/' + str(cur_file) + '.txt)'
        f_print(f, line, i)
        i[0] = i[0]+1


lst = [chr(x) for x in range(33, 127)]
lst.append(" ")
lst.append("    ")
dic = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

def build_test_sh():
    i = [1]
    f = open("my_test.sh", "a")
    f_print(f, "#!/bin/bash")
    for j in range(1, 4):
        func(f, dic*j, i)
    for n in range(1, 5):
        func(f, "".join(random.choices(dic, k=n)), i)
    f.close()


def build_rand_file():
    f = open("rand_file.txt", "a")
    for d in dic:
        f_print(f, d*2)
    for i in range(int(1e3)):
        f_print(f, "".join(random.choices(dic, k=random.randint(1, 2**8))))
    f.close()

build_test_sh()
build_rand_file()
