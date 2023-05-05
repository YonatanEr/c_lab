#!/bin/bash

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b     -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b     -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "9"   -n -b     -A 0  test_files/empty_file.txt) <(grep -E   "9"   -n -b     -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "9"   -n -b     -v -A 1  test_files/empty_file.txt) <(grep -E   "9"   -n -b     -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "9" -c -n -b     -v -A 2  test_files/empty_file.txt) <(grep -E   "9" -c -n -b     -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "9"   -n -b     -A 0  test_files/rand_file.txt) <(grep -E   "9"   -n -b     -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "9"   -n -b     -v -A 1  test_files/rand_file.txt) <(grep -E   "9"   -n -b     -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "9" -c -n -b     -v -A 2  test_files/rand_file.txt) <(grep -E   "9" -c -n -b     -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "MU"   -n -b     -A 0  test_files/empty_file.txt) <(grep -E   "MU"   -n -b     -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "MU"   -n -b     -v -A 1  test_files/empty_file.txt) <(grep -E   "MU"   -n -b     -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "MU" -c -n -b     -v -A 2  test_files/empty_file.txt) <(grep -E   "MU" -c -n -b     -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "MU"   -n -b     -A 0  test_files/rand_file.txt) <(grep -E   "MU"   -n -b     -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "MU"   -n -b     -v -A 1  test_files/rand_file.txt) <(grep -E   "MU"   -n -b     -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "MU" -c -n -b     -v -A 2  test_files/rand_file.txt) <(grep -E   "MU" -c -n -b     -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy"   -n -b     -A 0  test_files/empty_file.txt) <(grep -E   "JDy"   -n -b     -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy"   -n -b     -v -A 1  test_files/empty_file.txt) <(grep -E   "JDy"   -n -b     -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy" -c -n -b     -v -A 2  test_files/empty_file.txt) <(grep -E   "JDy" -c -n -b     -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy"   -n -b     -A 0  test_files/rand_file.txt) <(grep -E   "JDy"   -n -b     -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy"   -n -b     -v -A 1  test_files/rand_file.txt) <(grep -E   "JDy"   -n -b     -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy" -c -n -b     -v -A 2  test_files/rand_file.txt) <(grep -E   "JDy" -c -n -b     -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b     -A 0  test_files/empty_file.txt) <(grep -E   "JyB4"   -n -b     -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b     -v -A 1  test_files/empty_file.txt) <(grep -E   "JyB4"   -n -b     -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4" -c -n -b     -v -A 2  test_files/empty_file.txt) <(grep -E   "JyB4" -c -n -b     -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b     -A 0  test_files/rand_file.txt) <(grep -E   "JyB4"   -n -b     -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b     -v -A 1  test_files/rand_file.txt) <(grep -E   "JyB4"   -n -b     -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4" -c -n -b     -v -A 2  test_files/rand_file.txt) <(grep -E   "JyB4" -c -n -b     -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "9"   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "9"   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "9"   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "9"   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "9" -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "9" -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "9"   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "9"   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "9"   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "9"   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "9" -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "9" -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "MU"   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "MU"   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "MU"   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "MU"   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "MU" -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "MU" -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "MU"   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "MU"   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "MU"   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "MU"   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "MU" -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "MU" -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy"   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "JDy"   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy"   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "JDy"   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy" -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "JDy" -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy"   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "JDy"   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy"   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "JDy"   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy" -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "JDy" -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "JyB4"   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "JyB4"   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4" -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "JyB4" -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "JyB4"   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "JyB4"   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4" -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "JyB4" -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "[1-9].."   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "[1-9].."   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "[1-9].."   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "[1-9].."   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "[1-9].." -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "[1-9].." -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "[1-9].."   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "[1-9].."   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "[1-9].."   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "[1-9].."   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "[1-9].." -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "[1-9].." -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "(1|9).."   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "(1|9).."   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "(1|9).."   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "(1|9).."   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "(1|9).." -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "(1|9).." -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "(1|9).."   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "(1|9).."   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "(1|9).."   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "(1|9).."   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "(1|9).." -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "(1|9).." -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy"   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "JDy"   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy"   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "JDy"   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy" -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "JDy" -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy"   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "JDy"   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy"   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "JDy"   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy" -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "JDy" -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b  -x -A 0  test_files/empty_file.txt) <(grep -E   "JyB4"   -n -b  -x -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b  -x -v -A 1  test_files/empty_file.txt) <(grep -E   "JyB4"   -n -b  -x -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4" -c -n -b  -x -v -A 2  test_files/empty_file.txt) <(grep -E   "JyB4" -c -n -b  -x -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b  -x -A 0  test_files/rand_file.txt) <(grep -E   "JyB4"   -n -b  -x -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b  -x -v -A 1  test_files/rand_file.txt) <(grep -E   "JyB4"   -n -b  -x -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4" -c -n -b  -x -v -A 2  test_files/rand_file.txt) <(grep -E   "JyB4" -c -n -b  -x -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "[1-9].."   -n -b   -A 0  test_files/empty_file.txt) <(grep -E   "[1-9].."   -n -b   -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "[1-9].."   -n -b   -v -A 1  test_files/empty_file.txt) <(grep -E   "[1-9].."   -n -b   -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "[1-9].." -c -n -b   -v -A 2  test_files/empty_file.txt) <(grep -E   "[1-9].." -c -n -b   -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "[1-9].."   -n -b   -A 0  test_files/rand_file.txt) <(grep -E   "[1-9].."   -n -b   -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "[1-9].."   -n -b   -v -A 1  test_files/rand_file.txt) <(grep -E   "[1-9].."   -n -b   -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "[1-9].." -c -n -b   -v -A 2  test_files/rand_file.txt) <(grep -E   "[1-9].." -c -n -b   -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "(1|9).."   -n -b   -A 0  test_files/empty_file.txt) <(grep -E   "(1|9).."   -n -b   -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "(1|9).."   -n -b   -v -A 1  test_files/empty_file.txt) <(grep -E   "(1|9).."   -n -b   -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "(1|9).." -c -n -b   -v -A 2  test_files/empty_file.txt) <(grep -E   "(1|9).." -c -n -b   -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy"   -n -b   -v -A 1  test_files/empty_file.txt) <(grep -E   "JDy"   -n -b   -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy"   -n -b   -A 0  test_files/empty_file.txt) <(grep -E   "JDy"   -n -b   -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy" -c -n -b   -v -A 2  test_files/empty_file.txt) <(grep -E   "JDy" -c -n -b   -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "JDy"   -n -b   -A 0  test_files/rand_file.txt) <(grep -E   "JDy"   -n -b   -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy"   -n -b   -v -A 1  test_files/rand_file.txt) <(grep -E   "JDy"   -n -b   -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "JDy" -c -n -b   -v -A 2  test_files/rand_file.txt) <(grep -E   "JDy" -c -n -b   -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b   -A 0  test_files/empty_file.txt) <(grep -E   "JyB4"   -n -b   -A 0  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b   -v -A 1  test_files/empty_file.txt) <(grep -E   "JyB4"   -n -b   -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4" -c -n -b   -v -A 2  test_files/empty_file.txt) <(grep -E   "JyB4" -c -n -b   -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b   -A 0  test_files/rand_file.txt) <(grep -E   "JyB4"   -n -b   -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4"   -n -b   -v -A 1  test_files/rand_file.txt) <(grep -E   "JyB4"   -n -b   -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "JyB4" -c -n -b   -v -A 2  test_files/rand_file.txt) <(grep -E   "JyB4" -c -n -b   -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E  "(1|9).."   -n -b   -A 0  test_files/rand_file.txt) <(grep -E   "(1|9).."   -n -b   -A 0  test_files/rand_file.txt)

diff <(./my_grep -E  "(1|9).."   -n -b   -v -A 1  test_files/rand_file.txt) <(grep -E   "(1|9).."   -n -b   -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E  "(1|9).." -c -n -b   -v -A 2  test_files/rand_file.txt) <(grep -E   "(1|9).." -c -n -b   -v -A 2  test_files/rand_file.txt)


diff <(./my_grep -E "[1-9].."   -n -b   -A 0  test_files/rand_file.txt) <(grep -E  "[1-9].."   -n -b   -A 0  test_files/rand_file.txt)

diff <(./my_grep -E "[1-9].."   -n -b   -v -A 1  test_files/rand_file.txt) <(grep -E  "[1-9].."   -n -b   -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E "[1-9].." -c -n -b   -v -A 2  test_files/rand_file.txt) <(grep -E  "[1-9].." -c -n -b   -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E "(|a)(b|9).."   -n -b   -A 0  test_files/empty_file.txt) <(grep -E  "(|a)(b|9).."   -n -b   -A 0  test_files/empty_file.txt)

diff <(./my_grep -E "(|a)(b|9).."   -n -b   -v -A 1  test_files/empty_file.txt) <(grep -E  "(|a)(b|9).."   -n -b   -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E "(|a)(b|9).." -c -n -b   -v -A 2  test_files/empty_file.txt) <(grep -E  "(|a)(b|9).." -c -n -b   -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E "(|a)(b|9).."   -n -b   -A 0  test_files/rand_file.txt) <(grep -E  "(|a)(b|9).."   -n -b   -A 0  test_files/rand_file.txt)

diff <(./my_grep -E "(|a)(b|9).."   -n -b   -v -A 1  test_files/rand_file.txt) <(grep -E  "(|a)(b|9).."   -n -b   -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E "(|a)(b|9).." -c -n -b   -v -A 2  test_files/rand_file.txt) <(grep -E  "(|a)(b|9).." -c -n -b   -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E "JDy"   -n -b   -A 0  test_files/empty_file.txt) <(grep -E  "JDy"   -n -b   -A 0  test_files/empty_file.txt)

diff <(./my_grep -E "JDy"   -n -b   -v -A 1  test_files/empty_file.txt) <(grep -E  "JDy"   -n -b   -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E "JDy" -c -n -b   -v -A 2  test_files/empty_file.txt) <(grep -E  "JDy" -c -n -b   -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E "JDy"   -n -b   -A 0  test_files/rand_file.txt) <(grep -E  "JDy"   -n -b   -A 0  test_files/rand_file.txt)

diff <(./my_grep -E "JDy"   -n -b   -v -A 1  test_files/rand_file.txt) <(grep -E  "JDy"   -n -b   -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E "JDy" -c -n -b   -v -A 2  test_files/rand_file.txt) <(grep -E  "JDy" -c -n -b   -v -A 2  test_files/rand_file.txt)

diff <(./my_grep -E "(a|bc).."   -n -b   -A 0  test_files/empty_file.txt) <(grep -E  "(a|bc).."   -n -b   -A 0  test_files/empty_file.txt)

diff <(./my_grep -E "(a|bc).."   -n -b   -v -A 1  test_files/empty_file.txt) <(grep -E  "(a|bc).."   -n -b   -v -A 1  test_files/empty_file.txt)

diff <(./my_grep -E "(a|bc).." -c -n -b   -v -A 2  test_files/empty_file.txt) <(grep -E  "(a|bc).." -c -n -b   -v -A 2  test_files/empty_file.txt)

diff <(./my_grep -E "(a|bc).."   -n -b   -A 0  test_files/rand_file.txt) <(grep -E  "(a|bc).."   -n -b   -A 0  test_files/rand_file.txt)

diff <(./my_grep -E "(a|bc).."   -n -b   -v -A 1  test_files/rand_file.txt) <(grep -E  "(a|bc).."   -n -b   -v -A 1  test_files/rand_file.txt)

diff <(./my_grep -E "(a|bc).." -c -n -b   -v -A 2  test_files/rand_file.txt) <(grep -E  "(a|bc).." -c -n -b   -v -A 2  test_files/rand_file.txt)




