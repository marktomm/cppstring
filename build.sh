#!/bin/sh

set -xe

[ ! -d build ] && mkdir build

# g++ -g string_traits.cpp -o build/string_traits && build/string_traits && echo $?

g++ -g string.cpp -o build/string && build/string && echo $?
