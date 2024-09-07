#!/bin/sh

set -xe

[ ! -d build ] && mkdir build

g++ -g string.cpp -o build/string && gdb -x gdb_commands.txt --args build/string
