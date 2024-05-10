#!/bin/sh

set -xe

[ ! -d build ] && mkdir build

g++ string_traits.cpp -o build/string_traits && build/string_traits && echo $?
