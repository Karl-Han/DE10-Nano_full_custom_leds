# DE10-Nano Full-Custom Minimum LEDs

This respository includes everything that is generated, so you can use `rpt` and `sof` to reproduce it directly. The original Youtube video by Bo Gao is for DE10-Standard, which differs in both FPGA module and DDR module from DE10-Nano.

## Overview

Requirements:

- Have a DE10-Nano Board
- Downloaded 
    - Quartus Prime (22.1 Lite in my case) 
    - SoC EDS (20.1 in my case)
    - DE10-Nano CD-ROM, including System Builder executable, (Rev. C in my case by looking at the backside of PCB)
- Watch the video at least once and map the goals with different timestamps

Goals:

- Learn to use System Builder by Terasic on DE10-Nano

Steps:

1. Use System Builder to generate `hps.qsys` to automatically get the project file and top-level module `DE10_NANO` with minimum useful pins.
2. Use Platform Designer (Qsys) to configure HPS and connection to the new PIO IP `led`.
3. Connect module `hps` with top-level module `DE10_NANO`.
4. Generate `hps_0.h` to get the `LED_BASE` in Lightweight HPS2FPGA address space.
5. Cross-compile `led.c` to executable for HPS.
6. Generate `rbf` from `sof` to be used directly by rsYocto in my case.

## TODOs

- [ ] Use System Builder to generate `hps.qsys` to automatically get the project file and top-level module `DE10_NANO` with minimum useful pins.
- [ ] Use Platform Designer (Qsys) to configure HPS and connection to the new PIO IP `led`.
- [ ] Connect module `hps` with top-level module `DE10_NANO`.
- [ ] Generate `hps_0.h` to get the `LED_BASE` in Lightweight HPS2FPGA address space.
- [ ] Cross-compile `led.c` to executable for HPS.
- [ ] Generate `rbf` from `sof` to be used directly by rsYocto in my case.

## Detailed Steps

### 1. Project Generation

What has been done by System Builder:

- Pin Assignment
- Top-Level Design Module Generation

### 2. Configuration of 

# References

- Complete Video from Bo Gao for DE10-Standard: https://www.youtube.com/watch?v=XXMeiVhjaZU
- Quartus Primt Lite 22.1: https://www.intel.com/content/www/us/en/software-kit/757262/intel-quartus-prime-lite-edition-design-software-version-22-1-for-windows.html
- Intel SoC EDS 20.1: https://www.intel.com/content/www/us/en/software-kit/661080/intel-soc-fpga-embedded-development-suite-soc-eds-standard-edition-software-version-20-1-for-linux.html
- Terasic DE10-Nano Resrouces: https://www.terasic.com.tw/cgi-bin/page/archive.pl?Language=English&CategoryNo=167&No=1046&PartNo=4