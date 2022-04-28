#!/bin/bash
g++ -o RW.o -Wall -Wextra RW_objects.cpp RW_test.cpp 2>ignore/compil_errors.txt
echo "Compilation"
./RW.o 1>ignore/output.txt 2>ignore/errors.txt
echo "Execution"
echo "Output data is located in output.txt, errors -- in errors.txt"
