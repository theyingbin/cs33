#!/bin/sh

./configure \
    LDFLAGS="-Xlinker --rpath=/usr/local/cs/gcc-$(gcc -dumpversion)/lib"

make clean
make CFLAGS='-g3 -O2 -fno-inline -fstack-protector-strong'
mv src/thttpd src/thttpd-sp

make clean
make CFLAGS='-g3 -O2 -fno-inline -static-libasan -fsanitize=address'
mv src/thttpd src/thttpd-as

make clean
make CFLAGS='-g3 -O2 -fno-inline -fno-stack-protector -z execstack'
mv src/thttpd src/thttpd-no
