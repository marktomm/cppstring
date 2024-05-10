#!/bin/sh

set -xe

[ ! -d build ] && mkdir build

g++ -g string_traits.cpp -o build/string_traits && gdb -x gdb_commands.txt --args build/string_traits
