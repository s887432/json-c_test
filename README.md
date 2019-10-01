# json-c_test

## do install json-c first
$ git clone https://github.com/json-c/json-c.git<br>
$ cd json-c<br>
$ ./autogen.sh<br>
$ ./configure<br>
$ make<br>
$ sudo make install<br>

## make example code
$ gcc -o test01 test01.c -ljson-c<br>

## usage
$ test_01 version<br>
$ test_01 params.light_switch

## test01.json
{<br>
<blockquote>"version":"1.0",<br>
<blockquote>"params":<br>
<blockquote>{<br>
<blockquote><blockquote>"light_switch":1,<br>
<blockquote><blockquote>"light_intensity":21,<br>
<blockquote><blockquote>"led_r":0,<br>
<blockquote><blockquote>"led_g":0,<br>
<blockquote><blockquote>"led_b":0,<br>
<blockquote><blockquote>"uv":114,<br>
<blockquote><blockquote>"temp":28.25,<br>
<blockquote><blockquote>"hum":0<br>
<blockquote>}<br>
}<br>
