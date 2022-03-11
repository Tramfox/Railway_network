#!/bin/bash
g++ -o RW.o -Wall -Wextra RW_station.cpp RW_test.cpp 2>compil_errors.txt
echo "Compilation is completed"
./RW.o 1>output.txt 2>errors.txt
echo "Execution is complited"
echo "Output data is located in output.txt, errors -- in errors.txt"
