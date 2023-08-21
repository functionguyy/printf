#!/bin/bash

gcc -Wno-format -c *.c
ar rcs lib2.a *.o
gcc -Wno-format main.c -L. lib2.a
