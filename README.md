# json-c_test

## do install json-c first
$ git clone heeps://github.com/json-c/json-c.git
$ cd json-c
$ ./autogen.sh
$ ./configure
$ make
$ sudo make install

## make example code
$ gcc -o test01 test01.c -ljson-c
