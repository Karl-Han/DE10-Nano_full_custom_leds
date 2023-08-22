#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/mman.h>
// #include<unistd.h>

#include "hps_0.h"

#define REG_BASE    0xff200000  // LW HPS2FPGA Bridge Base Addr
#define REG_SPAN    0x00200000  // Span of Addr

void *base;
uint32_t *led;
int fd;

void handler(int signo){
    printf("Received %d\n", signo);
    *led = 0;
    munmap(base, REG_SPAN);
    close(fd);
    exit(0);
}

int main(){
    int i = 0;
    fd = open("/dev/mem", O_RDWR | O_SYNC);
    if(fd <0){
        printf("Can't open memory.\n");
        return -1;
    }

    base = mmap(NULL, REG_SPAN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, REG_BASE);
    if(base == MAP_FAILED){
        printf("Can't map memory.\n");
        close(fd);
        return -1;
    }
    led = (uint32_t*)(base + LED_BASE);
    signal(SIGINT, handler);

    while(1){
        usleep(250000);
        if(i <7)
            i++;
        else
            i = 0;
        // *led <<=1;
        * led = 1<<i;
    }
}
