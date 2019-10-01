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
	"version":"1.0",<br>
	"params":<br>
	{<br>
		"light_switch":1,<br>
		"light_intensity":21,<br>
		"led_r":0,<br>
		"led_g":0,<br>
		"led_b":0,<br>
		"uv":114,<br>
		"temp":28.25,<br>
		"hum":0<br>
	}<br>
}<br>
