SDK code of video capture and processing based on zynq 7035

Including main.cpp i2c_ctr emio_config and ov7725 config.

The block design in Vivado:
![BlockDesign](https://github.com/relyonsky/ov5640/blob/master/image.png)

i2c_ctr and emio_ mainly configure camera parameters
osd is the IP core of double path video display
ov7725 is the IP core mainly convert 8-bit ov7725 signal to 24-bit signal to output
