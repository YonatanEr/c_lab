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

diff <(./my_grep "" test_files/test1.txt) <(grep "" test_files/test1.txt)

diff <(./my_grep " " test_files/test1.txt) <(grep " " test_files/test1.txt)

diff <(./my_grep "a" test_files/test1.txt) <(grep "a" test_files/test1.txt)

diff <(./my_grep "aa" test_files/test1.txt) <(grep "aa" test_files/test1.txt)

diff <(./my_grep "" test_files/test2.txt) <(grep "" test_files/test2.txt)

diff <(./my_grep " " test_files/test2.txt) <(grep " " test_files/test2.txt)

diff <(./my_grep "a" test_files/test2.txt) <(grep "a" test_files/test2.txt)

diff <(./my_grep "a" -n test_files/test2.txt) <(grep "a" -n test_files/test2.txt)

diff <(./my_grep "ab" -n test_files/test2.txt) <(grep "ab" -n test_files/test2.txt)

diff <(./my_grep "a" -v test_files/test2.txt) <(grep "a" -v test_files/test2.txt)

diff <(./my_grep "a" -b test_files/test2.txt) <(grep "a" -b test_files/test2.txt)

diff <(./my_grep "ab" -v -b test_files/test2.txt) <(grep "ab" -v -b test_files/test2.txt)

diff <(./my_grep "a" -c test_files/test2.txt) <(grep "a" -c test_files/test2.txt)

diff <(./my_grep "ab" -c test_files/test2.txt) <(grep "ab" -c test_files/test2.txt)

diff <(./my_grep "ab" -c -b -n test_files/test2.txt) <(grep "ab" -c -b -n test_files/test2.txt)

diff <(./my_grep "ab" -v -b test_files/test1.txt) <(grep "ab" -v -b test_files/test1.txt)

diff <(./my_grep "a" -c test_files/test1.txt) <(grep "a" -c test_files/test1.txt)

diff <(./my_grep "ab" -c test_files/test1.txt) <(grep "ab" -c test_files/test1.txt)

diff <(./my_grep "ab" -c -b -n test_files/test1.txt) <(grep "ab" -c -b -n test_files/test1.txt)

diff <(./my_grep "g" -c -b -n test_files/test1.txt) <(grep "g" -c -b -n test_files/test1.txt)

diff <(./my_grep " " -c -b -n test_files/test1.txt) <(grep " " -c -b -n test_files/test1.txt)

diff <(./my_grep "U" -c -b -n test_files/test1.txt) <(grep "U" -c -b -n test_files/test1.txt)

diff <(./my_grep -E "U" -c   -b -n test_files/test1.txt) <(grep -E "U" -c   -b -n test_files/test1.txt)

diff <(./my_grep -E "U" -b -n test_files/test1.txt) <(grep -E "U" -b -n test_files/test1.txt)

diff <(./my_grep -E "UUUUU" -b -n -v test_files/test1.txt) <(grep -E "UUUUU" -b -n -v test_files/test1.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test1.txt) <(grep -E "A" -b -n -v test_files/test1.txt)

diff <(./my_grep -E "A" -b -n -v -c test_files/test1.txt) <(grep -E "A" -b -n -v -c test_files/test1.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test1.txt) <(grep -E "A" -b -n -v test_files/test1.txt)

diff <(./my_grep -E "abcdkf" -b -n -v test_files/test1.txt) <(grep -E "abcdkf" -b -n -v test_files/test1.txt)

diff <(./my_grep "ab" -v -b test_files/test2.txt) <(grep "ab" -v -b test_files/test2.txt)

diff <(./my_grep "a" -c test_files/test2.txt) <(grep "a" -c test_files/test2.txt)

diff <(./my_grep "ab" -c test_files/test2.txt) <(grep "ab" -c test_files/test2.txt)

diff <(./my_grep "ab" -c -b -n test_files/test2.txt) <(grep "ab" -c -b -n test_files/test2.txt)

diff <(./my_grep "g" -c -b -n test_files/test2.txt) <(grep "g" -c -b -n test_files/test2.txt)

diff <(./my_grep " " -c -b -n test_files/test2.txt) <(grep " " -c -b -n test_files/test2.txt)

diff <(./my_grep "U" -c -b -n test_files/test2.txt) <(grep "U" -c -b -n test_files/test2.txt)

diff <(./my_grep -E "U" -c   -b -n test_files/test2.txt) <(grep -E "U" -c   -b -n test_files/test2.txt)

diff <(./my_grep -E "U" -b -n test_files/test2.txt) <(grep -E "U" -b -n test_files/test2.txt)

diff <(./my_grep -E "UUUUU" -b -n -v test_files/test2.txt) <(grep -E "UUUUU" -b -n -v test_files/test2.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test2.txt) <(grep -E "A" -b -n -v test_files/test2.txt)

diff <(./my_grep -E "A" -b -n -v -c test_files/test2.txt) <(grep -E "A" -b -n -v -c test_files/test2.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test2.txt) <(grep -E "A" -b -n -v test_files/test2.txt)

diff <(./my_grep -E "abcdkf" -b -n -v test_files/test2.txt) <(grep -E "abcdkf" -b -n -v test_files/test2.txt)

diff <(./my_grep "g" -c -b -n test_files/test3.txt) <(grep "g" -c -b -n test_files/test3.txt)

diff <(./my_grep " " -c -b -n test_files/test3.txt) <(grep " " -c -b -n test_files/test3.txt)

diff <(./my_grep "U" -c -b -n test_files/test3.txt) <(grep "U" -c -b -n test_files/test3.txt)

diff <(./my_grep -E "U" -c   -b -n test_files/test3.txt) <(grep -E "U" -c   -b -n test_files/test3.txt)

diff <(./my_grep -E "U" -b -n test_files/test3.txt) <(grep -E "U" -b -n test_files/test3.txt)

diff <(./my_grep -E "UUUUU" -b -n -v test_files/test3.txt) <(grep -E "UUUUU" -b -n -v test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test3.txt) <(grep -E "A" -b -n -v test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v -c test_files/test3.txt) <(grep -E "A" -b -n -v -c test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test3.txt) <(grep -E "A" -b -n -v test_files/test3.txt)

diff <(./my_grep -E "abcdkf" -b -n -v test_files/test3.txt) <(grep -E "abcdkf" -b -n -v test_files/test3.txt)

diff <(./my_grep "ab" -v -b test_files/test3.txt) <(grep "ab" -v -b test_files/test3.txt)

diff <(./my_grep "a" -c test_files/test3.txt) <(grep "a" -c test_files/test3.txt)

diff <(./my_grep "ab" -c test_files/test3.txt) <(grep "ab" -c test_files/test3.txt)

diff <(./my_grep "ab" -c -b -n test_files/test3.txt) <(grep "ab" -c -b -n test_files/test3.txt)

diff <(./my_grep "g" -c -b -n test_files/test3.txt) <(grep "g" -c -b -n test_files/test3.txt)

diff <(./my_grep " " -c -b -n test_files/test3.txt) <(grep " " -c -b -n test_files/test3.txt)

diff <(./my_grep "U" -c -b -n test_files/test3.txt) <(grep "U" -c -b -n test_files/test3.txt)

diff <(./my_grep -E "U" -c   -b -n test_files/test3.txt) <(grep -E "U" -c   -b -n test_files/test3.txt)

diff <(./my_grep -E "U" -b -n test_files/test3.txt) <(grep -E "U" -b -n test_files/test3.txt)

diff <(./my_grep -E "UUUUU" -b -n -v test_files/test3.txt) <(grep -E "UUUUU" -b -n -v test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test3.txt) <(grep -E "A" -b -n -v test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v -c test_files/test3.txt) <(grep -E "A" -b -n -v -c test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test3.txt) <(grep -E "A" -b -n -v test_files/test3.txt)

diff <(./my_grep -E "abcdkf" -b -n -v test_files/test3.txt) <(grep -E "abcdkf" -b -n -v test_files/test3.txt)

diff <(./my_grep "ab" -v -b test_files/test4.txt) <(grep "ab" -v -b test_files/test4.txt)

diff <(./my_grep "a" -c test_files/test4.txt) <(grep "a" -c test_files/test4.txt)

diff <(./my_grep "ab" -c test_files/test4.txt) <(grep "ab" -c test_files/test4.txt)

diff <(./my_grep "ab" -c -b -n test_files/test4.txt) <(grep "ab" -c -b -n test_files/test4.txt)

diff <(./my_grep "g" -c -b -n test_files/test4.txt) <(grep "g" -c -b -n test_files/test4.txt)

diff <(./my_grep " " -c -b -n test_files/test4.txt) <(grep " " -c -b -n test_files/test4.txt)

diff <(./my_grep "U" -c -b -n test_files/test4.txt) <(grep "U" -c -b -n test_files/test4.txt)

diff <(./my_grep -E "U" -c   -b -n test_files/test4.txt) <(grep -E "U" -c   -b -n test_files/test4.txt)

diff <(./my_grep -E "U" -b -n test_files/test4.txt) <(grep -E "U" -b -n test_files/test4.txt)

diff <(./my_grep -E "UUUUU" -b -n -v test_files/test4.txt) <(grep -E "UUUUU" -b -n -v test_files/test4.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test4.txt) <(grep -E "A" -b -n -v test_files/test4.txt)

diff <(./my_grep -E "A" -b -n -v -c test_files/test4.txt) <(grep -E "A" -b -n -v -c test_files/test4.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test4.txt) <(grep -E "A" -b -n -v test_files/test4.txt)

diff <(./my_grep -E "abcdkf" -b -n -v test_files/test4.txt) <(grep -E "abcdkf" -b -n -v test_files/test4.txt)

diff <(./my_grep "ab" -v -b test_files/test5.txt) <(grep "ab" -v -b test_files/test5.txt)

diff <(./my_grep "a" -c test_files/test5.txt) <(grep "a" -c test_files/test5.txt)

diff <(./my_grep "ab" -c test_files/test5.txt) <(grep "ab" -c test_files/test5.txt)

diff <(./my_grep "ab" -c -b -n test_files/test5.txt) <(grep "ab" -c -b -n test_files/test5.txt)

diff <(./my_grep "g" -c -b -n test_files/test5.txt) <(grep "g" -c -b -n test_files/test5.txt)

diff <(./my_grep " " -c -b -n test_files/test5.txt) <(grep " " -c -b -n test_files/test5.txt)

diff <(./my_grep "U" -c -b -n test_files/test5.txt) <(grep "U" -c -b -n test_files/test5.txt)

diff <(./my_grep -E "U" -c   -b -n test_files/test5.txt) <(grep -E "U" -c   -b -n test_files/test5.txt)

diff <(./my_grep -E "U" -b -n test_files/test5.txt) <(grep -E "U" -b -n test_files/test5.txt)

diff <(./my_grep -E "UUUUU" -b -n -v test_files/test5.txt) <(grep -E "UUUUU" -b -n -v test_files/test5.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test5.txt) <(grep -E "A" -b -n -v test_files/test5.txt)

diff <(./my_grep -E "A" -b -n -v -c test_files/test5.txt) <(grep -E "A" -b -n -v -c test_files/test5.txt)

diff <(./my_grep -E "A" -b -n -v test_files/test5.txt) <(grep -E "A" -b -n -v test_files/test5.txt)

diff <(./my_grep -E "abcdkf" -b -n -v test_files/test5.txt) <(grep -E "abcdkf" -b -n -v test_files/test5.txt)



diff <(./my_grep "" < test_files/test1.txt) <(grep "" < test_files/test1.txt)

diff <(./my_grep " " < test_files/test1.txt) <(grep " " < test_files/test1.txt)

diff <(./my_grep "a" < test_files/test1.txt) <(grep "a" < test_files/test1.txt)

diff <(./my_grep "aa" < test_files/test1.txt) <(grep "aa" < test_files/test1.txt)

diff <(./my_grep "" < test_files/test2.txt) <(grep "" < test_files/test2.txt)

diff <(./my_grep " " < test_files/test2.txt) <(grep " " < test_files/test2.txt)

diff <(./my_grep "a" < test_files/test2.txt) <(grep "a" < test_files/test2.txt)

diff <(./my_grep "aa" < test_files/test2.txt) <(grep "aa" < test_files/test2.txt)

diff <(./my_grep "" < test_files/test1.txt) <(grep "" < test_files/test1.txt)

diff <(./my_grep " " < test_files/test1.txt) <(grep " " < test_files/test1.txt)

diff <(./my_grep "a" < test_files/test1.txt) <(grep "a" < test_files/test1.txt)

diff <(./my_grep "aa" < test_files/test1.txt) <(grep "aa" < test_files/test1.txt)

diff <(./my_grep "" < test_files/test2.txt) <(grep "" < test_files/test2.txt)

diff <(./my_grep " " < test_files/test2.txt) <(grep " " < test_files/test2.txt)

diff <(./my_grep "a" < test_files/test2.txt) <(grep "a" < test_files/test2.txt)

diff <(./my_grep "a" -n < test_files/test2.txt) <(grep "a" -n < test_files/test2.txt)

diff <(./my_grep "ab" -n < test_files/test2.txt) <(grep "ab" -n < test_files/test2.txt)

diff <(./my_grep "a" -v < test_files/test2.txt) <(grep "a" -v < test_files/test2.txt)

diff <(./my_grep "a" -b < test_files/test2.txt) <(grep "a" -b < test_files/test2.txt)

diff <(./my_grep "ab" -v -b < test_files/test2.txt) <(grep "ab" -v -b < test_files/test2.txt)

diff <(./my_grep "a" -c < test_files/test2.txt) <(grep "a" -c < test_files/test2.txt)

diff <(./my_grep "ab" -c < test_files/test2.txt) <(grep "ab" -c < test_files/test2.txt)

diff <(./my_grep "ab" -c -b -n < test_files/test2.txt) <(grep "ab" -c -b -n < test_files/test2.txt)

diff <(./my_grep "ab" -v -b < test_files/test1.txt) <(grep "ab" -v -b < test_files/test1.txt)

diff <(./my_grep "a" -c < test_files/test1.txt) <(grep "a" -c < test_files/test1.txt)

diff <(./my_grep "ab" -c < test_files/test1.txt) <(grep "ab" -c < test_files/test1.txt)

diff <(./my_grep "ab" -c -b -n < test_files/test1.txt) <(grep "ab" -c -b -n < test_files/test1.txt)

diff <(./my_grep "g" -c -b -n < test_files/test1.txt) <(grep "g" -c -b -n < test_files/test1.txt)

diff <(./my_grep " " -c -b -n < test_files/test1.txt) <(grep " " -c -b -n < test_files/test1.txt)

diff <(./my_grep "U" -c -b -n < test_files/test1.txt) <(grep "U" -c -b -n < test_files/test1.txt)

diff <(./my_grep -E "U" -c   -b -n < test_files/test1.txt) <(grep -E "U" -c   -b -n < test_files/test1.txt)

diff <(./my_grep -E "U" -b -n < test_files/test1.txt) <(grep -E "U" -b -n < test_files/test1.txt)

diff <(./my_grep -E "UUUUU" -b -n -v < test_files/test1.txt) <(grep -E "UUUUU" -b -n -v < test_files/test1.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test1.txt) <(grep -E "A" -b -n -v < test_files/test1.txt)

diff <(./my_grep -E "A" -b -n -v -c < test_files/test1.txt) <(grep -E "A" -b -n -v -c < test_files/test1.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test1.txt) <(grep -E "A" -b -n -v < test_files/test1.txt)

diff <(./my_grep -E "abcdkf" -b -n -v < test_files/test1.txt) <(grep -E "abcdkf" -b -n -v < test_files/test1.txt)

diff <(./my_grep "ab" -v -b < test_files/test2.txt) <(grep "ab" -v -b < test_files/test2.txt)

diff <(./my_grep "a" -c < test_files/test2.txt) <(grep "a" -c < test_files/test2.txt)

diff <(./my_grep "ab" -c < test_files/test2.txt) <(grep "ab" -c < test_files/test2.txt)

diff <(./my_grep "ab" -c -b -n < test_files/test2.txt) <(grep "ab" -c -b -n < test_files/test2.txt)

diff <(./my_grep "g" -c -b -n < test_files/test2.txt) <(grep "g" -c -b -n < test_files/test2.txt)

diff <(./my_grep " " -c -b -n < test_files/test2.txt) <(grep " " -c -b -n < test_files/test2.txt)

diff <(./my_grep "U" -c -b -n < test_files/test2.txt) <(grep "U" -c -b -n < test_files/test2.txt)

diff <(./my_grep -E "U" -c   -b -n < test_files/test2.txt) <(grep -E "U" -c   -b -n < test_files/test2.txt)

diff <(./my_grep -E "U" -b -n < test_files/test2.txt) <(grep -E "U" -b -n < test_files/test2.txt)

diff <(./my_grep -E "UUUUU" -b -n -v < test_files/test2.txt) <(grep -E "UUUUU" -b -n -v < test_files/test2.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test2.txt) <(grep -E "A" -b -n -v < test_files/test2.txt)

diff <(./my_grep -E "A" -b -n -v -c < test_files/test2.txt) <(grep -E "A" -b -n -v -c < test_files/test2.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test2.txt) <(grep -E "A" -b -n -v < test_files/test2.txt)

diff <(./my_grep -E "abcdkf" -b -n -v < test_files/test2.txt) <(grep -E "abcdkf" -b -n -v < test_files/test2.txt)

diff <(./my_grep "g" -c -b -n < test_files/test3.txt) <(grep "g" -c -b -n < test_files/test3.txt)

diff <(./my_grep " " -c -b -n < test_files/test3.txt) <(grep " " -c -b -n < test_files/test3.txt)

diff <(./my_grep "U" -c -b -n < test_files/test3.txt) <(grep "U" -c -b -n < test_files/test3.txt)

diff <(./my_grep -E "U" -c   -b -n < test_files/test3.txt) <(grep -E "U" -c   -b -n < test_files/test3.txt)

diff <(./my_grep -E "U" -b -n < test_files/test3.txt) <(grep -E "U" -b -n < test_files/test3.txt)

diff <(./my_grep -E "UUUUU" -b -n -v < test_files/test3.txt) <(grep -E "UUUUU" -b -n -v < test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test3.txt) <(grep -E "A" -b -n -v < test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v -c < test_files/test3.txt) <(grep -E "A" -b -n -v -c < test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test3.txt) <(grep -E "A" -b -n -v < test_files/test3.txt)

diff <(./my_grep -E "abcdkf" -b -n -v < test_files/test3.txt) <(grep -E "abcdkf" -b -n -v < test_files/test3.txt)

diff <(./my_grep "ab" -v -b < test_files/test3.txt) <(grep "ab" -v -b < test_files/test3.txt)

diff <(./my_grep "a" -c < test_files/test3.txt) <(grep "a" -c < test_files/test3.txt)

diff <(./my_grep "ab" -c < test_files/test3.txt) <(grep "ab" -c < test_files/test3.txt)

diff <(./my_grep "ab" -c -b -n < test_files/test3.txt) <(grep "ab" -c -b -n < test_files/test3.txt)

diff <(./my_grep "g" -c -b -n < test_files/test3.txt) <(grep "g" -c -b -n < test_files/test3.txt)

diff <(./my_grep " " -c -b -n < test_files/test3.txt) <(grep " " -c -b -n < test_files/test3.txt)

diff <(./my_grep "U" -c -b -n < test_files/test3.txt) <(grep "U" -c -b -n < test_files/test3.txt)

diff <(./my_grep -E "U" -c   -b -n < test_files/test3.txt) <(grep -E "U" -c   -b -n < test_files/test3.txt)

diff <(./my_grep -E "U" -b -n < test_files/test3.txt) <(grep -E "U" -b -n < test_files/test3.txt)

diff <(./my_grep -E "UUUUU" -b -n -v < test_files/test3.txt) <(grep -E "UUUUU" -b -n -v < test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test3.txt) <(grep -E "A" -b -n -v < test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v -c < test_files/test3.txt) <(grep -E "A" -b -n -v -c < test_files/test3.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test3.txt) <(grep -E "A" -b -n -v < test_files/test3.txt)

diff <(./my_grep -E "abcdkf" -b -n -v < test_files/test3.txt) <(grep -E "abcdkf" -b -n -v < test_files/test3.txt)

diff <(./my_grep "ab" -v -b < test_files/test4.txt) <(grep "ab" -v -b < test_files/test4.txt)

diff <(./my_grep "a" -c < test_files/test4.txt) <(grep "a" -c < test_files/test4.txt)

diff <(./my_grep "ab" -c < test_files/test4.txt) <(grep "ab" -c < test_files/test4.txt)

diff <(./my_grep "ab" -c -b -n < test_files/test4.txt) <(grep "ab" -c -b -n < test_files/test4.txt)

diff <(./my_grep "g" -c -b -n < test_files/test4.txt) <(grep "g" -c -b -n < test_files/test4.txt)

diff <(./my_grep " " -c -b -n < test_files/test4.txt) <(grep " " -c -b -n < test_files/test4.txt)

diff <(./my_grep "U" -c -b -n < test_files/test4.txt) <(grep "U" -c -b -n < test_files/test4.txt)

diff <(./my_grep -E "U" -c   -b -n < test_files/test4.txt) <(grep -E "U" -c   -b -n < test_files/test4.txt)

diff <(./my_grep -E "U" -b -n < test_files/test4.txt) <(grep -E "U" -b -n < test_files/test4.txt)

diff <(./my_grep -E "UUUUU" -b -n -v < test_files/test4.txt) <(grep -E "UUUUU" -b -n -v < test_files/test4.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test4.txt) <(grep -E "A" -b -n -v < test_files/test4.txt)

diff <(./my_grep -E "A" -b -n -v -c < test_files/test4.txt) <(grep -E "A" -b -n -v -c < test_files/test4.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test4.txt) <(grep -E "A" -b -n -v < test_files/test4.txt)

diff <(./my_grep -E "abcdkf" -b -n -v < test_files/test4.txt) <(grep -E "abcdkf" -b -n -v < test_files/test4.txt)

diff <(./my_grep "ab" -v -b < test_files/test5.txt) <(grep "ab" -v -b < test_files/test5.txt)

diff <(./my_grep "a" -c < test_files/test5.txt) <(grep "a" -c < test_files/test5.txt)

diff <(./my_grep "ab" -c < test_files/test5.txt) <(grep "ab" -c < test_files/test5.txt)

diff <(./my_grep "ab" -c -b -n < test_files/test5.txt) <(grep "ab" -c -b -n < test_files/test5.txt)

diff <(./my_grep "g" -c -b -n < test_files/test5.txt) <(grep "g" -c -b -n < test_files/test5.txt)

diff <(./my_grep " " -c -b -n < test_files/test5.txt) <(grep " " -c -b -n < test_files/test5.txt)

diff <(./my_grep "U" -c -b -n < test_files/test5.txt) <(grep "U" -c -b -n < test_files/test5.txt)

diff <(./my_grep -E "U" -c   -b -n < test_files/test5.txt) <(grep -E "U" -c   -b -n < test_files/test5.txt)

diff <(./my_grep -E "U" -b -n < test_files/test5.txt) <(grep -E "U" -b -n < test_files/test5.txt)

diff <(./my_grep -E "UUUUU" -b -n -v < test_files/test5.txt) <(grep -E "UUUUU" -b -n -v < test_files/test5.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test5.txt) <(grep -E "A" -b -n -v < test_files/test5.txt)

diff <(./my_grep -E "A" -b -n -v -c < test_files/test5.txt) <(grep -E "A" -b -n -v -c < test_files/test5.txt)

diff <(./my_grep -E "A" -b -n -v < test_files/test5.txt) <(grep -E "A" -b -n -v < test_files/test5.txt)

diff <(./my_grep -E "abcdkf" -b -n -v < test_files/test5.txt) <(grep -E "abcdkf" -b -n -v < test_files/test5.txt)
