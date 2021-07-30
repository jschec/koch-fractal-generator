#!/bin/bash
g++ -std=c++11 -o koch *.cpp

# output test.ps file
./koch 72 360 504 360 1 > test.ps

# re-run to check for memory leaks
valgrind --leak-check=full ./koch 72 360 504 360 1 > valgrind-out.txt 2>&1
NOLEAKMSG="in use at exit: 0 bytes in 0 blocks"
grep "$NOLEAKMSG" valgrind-out.txt


#valgrind --leak-check=full \
#         --show-leak-kinds=all \
#         --track-origins=yes \
#         --verbose \
#         --log-file=valgrind-out.txt \
#         ./koch 72 360 504 360 1