import random

def f_print(f, line):
    f.write(line + "\n\n")


def func(f, word):
    for i in ["empty_file, rand_file"]:
        line = 'diff <(./my_grep ' + '"' + word + '"' + ' '                 +          '  test_files/' + str(i) + '.txt) <(grep  ' + '"' + word + '"' + ' '                              + ' test_files/' + str(i) + '.txt)'
        f_print(f, line)
        line = 'diff <(./my_grep ' + '"' + word + '"' + ' -c '              +          '  test_files/' + str(i) + '.txt) <(grep  ' + '"' + word + '"' + ' -c '                           + '  test_files/' + str(i) + '.txt)'
        f_print(f, line)
        line = 'diff <(./my_grep ' + '"' + word + '"' + ' -n -b '           +          '  test_files/' + str(i) + '.txt) <(grep  ' + '"' + word + '"' + ' -n -b '                        + '  test_files/' + str(i) + '.txt)'
        f_print(f, line)
        line = 'diff <(./my_grep ' + '"' + word + '"' + ' -n -b -v '        +          '  test_files/' + str(i) + '.txt) <(grep  ' + '"' + word + '"' + ' -n -b -v '                     + '  test_files/' + str(i) + '.txt)'
        f_print(f, line)
        line = 'diff <(./my_grep ' + '"' + word + '"' + ' -n -b -v -c '     +          '  test_files/' + str(i) + '.txt) <(grep  ' + '"' + word + '"' + ' -n -b -v -c '                  + '  test_files/' + str(i) + '.txt)'
        f_print(f, line)
        line = 'diff <(./my_grep ' + '"' + word + '"' + ' -n -b -v -A '     + str(i) + '  test_files/' + str(i) + '.txt) <(grep  ' + '"' + word + '"' + ' -n -b -v -A '      + str(i)    + '  test_files/' + str(i) + '.txt)'
        f_print(f, line)
    
dic = " abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ  "


def build_test_sh():
    f = open("my_test.sh", "a")
    f_print(f, "#!/bin/bash")
    f_print(f, "")
    func(f, "")
    for i in range(4):
        func(f, dic*i)
    for n in range(1, 4):
        func(f, "".join(random.choices(dic, k=n)))
    f.close()


def build_rand_file():
    f = open("rand_file.txt", "a")
    for i in range(int(1e3)):
        f_print(f, "".join(random.choices(dic, k=random.randint(0, 2**8))))
    f.close()

build_rand_file()