#!/bin/bash

g++ -o test_zd test_zd.cpp

if [ $? -eq 0 ]; then
    ./test_zd
else
    echo "Ошибка компиляции"
fi
