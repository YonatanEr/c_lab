#!/bin/bash

gcc -Wextra -Wall *.c -o my_grep



diff <(./my_grep "" test_files/test1.txt) <(grep "" test_files/test1.txt)

diff <(./my_grep " " test_files/test1.txt) <(grep " " test_files/test1.txt)

diff <(./my_grep "a" test_files/test1.txt) <(grep "a" test_files/test1.txt)

diff <(./my_grep "aa" test_files/test1.txt) <(grep "aa" test_files/test1.txt)



diff <(./my_grep "" test_files/test2.txt) <(grep "" test_files/test2.txt)

diff <(./my_grep " " test_files/test2.txt) <(grep " " test_files/test2.txt)

diff <(./my_grep "a" test_files/test2.txt) <(grep "a" test_files/test2.txt)

diff <(./my_grep "aa" test_files/test2.txt) <(grep "aa" test_files/test2.txt)


diff <(./my_grep "" test_files/test3.txt) <(grep "" test_files/test3.txt)

diff <(./my_grep " " test_files/test3.txt) <(grep " " test_files/test3.txt)

diff <(./my_grep "a" test_files/test3.txt) <(grep "a" test_files/test3.txt)

diff <(./my_grep "aa" test_files/test3.txt) <(grep "aa" test_files/test3.txt)

