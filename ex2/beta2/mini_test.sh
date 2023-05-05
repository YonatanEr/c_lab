#!/bin/bash




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
