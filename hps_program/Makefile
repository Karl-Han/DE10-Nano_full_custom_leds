DIR				:= /opt/arm/gcc-arm-10.3-2021.07-x86_64-arm-none-linux-gnueabihf/bin
CROSS_COMPILER 	:= ${DIR}/arm-none-linux-gnueabihf-

all: 
	${CROSS_COMPILER}gcc -Dsoc_cv_av -O2 -o led led.c
	${CROSS_COMPILER}strip -s led

clean: 
	rm -rf led
