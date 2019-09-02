/*
 * main.c
 *
 *  Created on: 2017年8月2日
 *      Author: Administrator
 */
#include "ov7725_config.h"
#include "xil_io.h"
#include "xparameters.h"

#define VDMA_BASEADDR0	XPAR_AXI_VDMA_0_BASEADDR
#define VDMA_BASEADDR1	XPAR_AXI_VDMA_1_BASEADDR
#define VDMA_BASEADDR2	XPAR_AXI_VDMA_2_BASEADDR
#define VDMA_BASEADDR3	XPAR_AXI_VDMA_3_BASEADDR


#define VIDEO_BASEADDR0 0x01000000
#define VIDEO_BASEADDR1 0x02000000
#define VIDEO_BASEADDR2 0x03000000

#define VIDEO_BASEADDR3 0x04000000
#define VIDEO_BASEADDR4 0x05000000
#define VIDEO_BASEADDR5 0x06000000

#define VIDEO_BASEADDR6 0x07000000
#define VIDEO_BASEADDR7 0x08000000
#define VIDEO_BASEADDR8 0x09000000

#define VIDEO_BASEADDR9 0x0a000000
#define VIDEO_BASEADDRa 0x0b000000
#define VIDEO_BASEADDRb 0x0c000000



#define H_ACTIVE	640*3
#define V_ACTIVE	480
#define H_STRIDE	640

#define DEMO_MAX_FRAME	(1920*1080*3)
#define DEMO_STRIDE		(1920*3)

/*
void Sensor_single_AF()
{
	u8	recev_buf[0];
	iic_ov5640_write(&Iic,0x3000,0x00);
	iic_ov5640_read(&Iic,0x3004,&recev_buf[0]);
	xil_printf("register 0x3004 = 0x%x\n",recev_buf[0]);
	iic_ov5640_read(&Iic,0x3001,&recev_buf[0]);
	xil_printf("register 0x3001 = 0x%x\n",recev_buf[0]);
	iic_ov5640_read(&Iic,0x3005,&recev_buf[0]);
	xil_printf("register 0x3005 = 0x%x\n",recev_buf[0]);
	iic_ov5640_write(&Iic,0x3022,0x03);
	usleep(500);
	iic_ov5640_read(&Iic,0x3022,&recev_buf[0]);
	xil_printf("register 0x3022 = 0x%x\n",recev_buf[0]);
	iic_ov5640_read(&Iic,0x3029,&recev_buf[0]);
	xil_printf("register 0x3029 = 0x%x\n",recev_buf[0]);
}
*/
void main()
{
	// Initialize OV5640 regesiter
	Miz702_EMIO_init();
	ov7725_init_rgb(0);
	ov7725_init_rgb(1);
	ov7725_init_rgb(2);
	ov7725_init_rgb(3);

	//Sensor_single_AF();

	//Xil_Out32((VDMA_BASEADDR + 0x030), 0x108B);// enable circular mode
	Xil_Out32((VDMA_BASEADDR0 + 0x030), 0x108B);// enable circular mode
	Xil_Out32((VDMA_BASEADDR0 + 0x0AC), VIDEO_BASEADDR0);	// start address
	Xil_Out32((VDMA_BASEADDR0 + 0x0B0), VIDEO_BASEADDR1);	// start address
	Xil_Out32((VDMA_BASEADDR0 + 0x0B4), VIDEO_BASEADDR2);	// start address
	Xil_Out32((VDMA_BASEADDR0 + 0x0A8), (H_STRIDE*4));		// h offset (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR0 + 0x0A4), (H_ACTIVE));		// h size (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR0 + 0x0A0), V_ACTIVE);			// v size (480)
		/*****************从DDR读数据设置**********************/
	Xil_Out32((VDMA_BASEADDR0 + 0x000), 0x8B); 		// enable circular mode
	Xil_Out32((VDMA_BASEADDR0 + 0x05c), VIDEO_BASEADDR0); 	// start address
	Xil_Out32((VDMA_BASEADDR0 + 0x060), VIDEO_BASEADDR1); 	// start address
	Xil_Out32((VDMA_BASEADDR0 + 0x064), VIDEO_BASEADDR2); 	// start address
	Xil_Out32((VDMA_BASEADDR0 + 0x058), (H_STRIDE*4)); 		// h offset (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR0 + 0x054), (H_ACTIVE)); 		// h size (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR0 + 0x050), V_ACTIVE); 			// v size (480)

	//Xil_Out32((VDMA_BASEADDR + 0x030), 0x108B);// enable circular mode
	Xil_Out32((VDMA_BASEADDR1 + 0x030), 0x108B);// enable circular mode
	Xil_Out32((VDMA_BASEADDR1 + 0x0AC), VIDEO_BASEADDR3);	// start address
	Xil_Out32((VDMA_BASEADDR1 + 0x0B0), VIDEO_BASEADDR4);	// start address
	Xil_Out32((VDMA_BASEADDR1 + 0x0B4), VIDEO_BASEADDR5);	// start address
	Xil_Out32((VDMA_BASEADDR1 + 0x0A8), (H_STRIDE*4));		// h offset (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR1 + 0x0A4), (H_ACTIVE));		// h size (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR1 + 0x0A0), V_ACTIVE);			// v size (480)
		/*****************从DDR读数据设置**********************/
	Xil_Out32((VDMA_BASEADDR1 + 0x000), 0x8B); 		// enable circular mode
	Xil_Out32((VDMA_BASEADDR1 + 0x05c), VIDEO_BASEADDR3); 	// start address
	Xil_Out32((VDMA_BASEADDR1 + 0x060), VIDEO_BASEADDR4); 	// start address
	Xil_Out32((VDMA_BASEADDR1 + 0x064), VIDEO_BASEADDR5); 	// start address
	Xil_Out32((VDMA_BASEADDR1 + 0x058), (H_STRIDE*4)); 		// h offset (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR1 + 0x054), (H_ACTIVE)); 		// h size (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR1 + 0x050), V_ACTIVE); 			// v size (480)

	//Xil_Out32((VDMA_BASEADDR + 0x030), 0x108B);// enable circular mode
	Xil_Out32((VDMA_BASEADDR2 + 0x030), 0x108B);// enable circular mode
	Xil_Out32((VDMA_BASEADDR2 + 0x0AC), VIDEO_BASEADDR6);	// start address
	Xil_Out32((VDMA_BASEADDR2 + 0x0B0), VIDEO_BASEADDR7);	// start address
	Xil_Out32((VDMA_BASEADDR2 + 0x0B4), VIDEO_BASEADDR8);	// start address
	Xil_Out32((VDMA_BASEADDR2 + 0x0A8), (H_STRIDE*4));		// h offset (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR2 + 0x0A4), (H_ACTIVE));		// h size (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR2 + 0x0A0), V_ACTIVE);			// v size (480)
		/*****************从DDR读数据设置**********************/
	Xil_Out32((VDMA_BASEADDR2 + 0x000), 0x8B); 		// enable circular mode
	Xil_Out32((VDMA_BASEADDR2 + 0x05c), VIDEO_BASEADDR6); 	// start address
	Xil_Out32((VDMA_BASEADDR2 + 0x060), VIDEO_BASEADDR7); 	// start address
	Xil_Out32((VDMA_BASEADDR2 + 0x064), VIDEO_BASEADDR8); 	// start address
	Xil_Out32((VDMA_BASEADDR2 + 0x058), (H_STRIDE*4)); 		// h offset (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR2 + 0x054), (H_ACTIVE)); 		// h size (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR2 + 0x050), V_ACTIVE); 			// v size (480)

	//Xil_Out32((VDMA_BASEADDR + 0x030), 0x108B);// enable circular mode
	Xil_Out32((VDMA_BASEADDR3 + 0x030), 0x108B);// enable circular mode
	Xil_Out32((VDMA_BASEADDR3 + 0x0AC), VIDEO_BASEADDR9);	// start address
	Xil_Out32((VDMA_BASEADDR3 + 0x0B0), VIDEO_BASEADDRa);	// start address
	Xil_Out32((VDMA_BASEADDR3 + 0x0B4), VIDEO_BASEADDRb);	// start address
	Xil_Out32((VDMA_BASEADDR3 + 0x0A8), (H_STRIDE*4));		// h offset (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR3 + 0x0A4), (H_ACTIVE));		// h size (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR3 + 0x0A0), V_ACTIVE);			// v size (480)
		/*****************从DDR读数据设置**********************/
	Xil_Out32((VDMA_BASEADDR3 + 0x000), 0x8B); 		// enable circular mode
	Xil_Out32((VDMA_BASEADDR3 + 0x05c), VIDEO_BASEADDR9); 	// start address
	Xil_Out32((VDMA_BASEADDR3 + 0x060), VIDEO_BASEADDRa); 	// start address
	Xil_Out32((VDMA_BASEADDR3 + 0x064), VIDEO_BASEADDRb); 	// start address
	Xil_Out32((VDMA_BASEADDR3 + 0x058), (H_STRIDE*4)); 		// h offset (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR3 + 0x054), (H_ACTIVE)); 		// h size (640 * 4) bytes
	Xil_Out32((VDMA_BASEADDR3 + 0x050), V_ACTIVE); 			// v size (480)

	while (1) ;


}



