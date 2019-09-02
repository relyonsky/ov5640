/*
 * emio_initial.c
 *
 *  Created on: 2016年10月22日
 *      Author: Administrator
 */

#include"xgpiops.h"
#include"emio_initial.h"

static XGpioPs psGpioInstancePtr;
int Miz702_EMIO_init(void)
{
	XGpioPs_Config* GpioConfigPtr;
	int xStatus;
	//--MIO 的初始化
	GpioConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	if(GpioConfigPtr == NULL)
	return XST_FAILURE;

	xStatus = XGpioPs_CfgInitialize(&psGpioInstancePtr,GpioConfigPtr,GpioConfigPtr->BaseAddr);
	if(XST_SUCCESS != xStatus)
	print(" PS GPIO INIT FAILED \n\r");

	//--MIO 的输入输出操作
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, SCL_PIN1,DIRECTION_OUTPUT);//
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, SDA_PIN1,DIRECTION_OUTPUT);//
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, SCL_PIN2,DIRECTION_OUTPUT);//
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, SDA_PIN2,DIRECTION_OUTPUT);//
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, SCL_PIN3,DIRECTION_OUTPUT);//
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, SDA_PIN3,DIRECTION_OUTPUT);//
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, SCL_PIN4,DIRECTION_OUTPUT);//
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, SDA_PIN4,DIRECTION_OUTPUT);//

	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, SCL_PIN1,1);//
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, SDA_PIN1,1);//
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, SCL_PIN2,1);//
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, SDA_PIN2,1);//
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, SCL_PIN3,1);//
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, SDA_PIN3,1);//
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, SCL_PIN4,1);//
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, SDA_PIN4,1);//
	return xStatus;
}

void CLOCK_HIGH(u8 Channel)
{
	if(Channel == 0)
	XGpioPs_WritePin(&psGpioInstancePtr,SCL_PIN1, 1);
	else if(Channel == 1)
	XGpioPs_WritePin(&psGpioInstancePtr,SCL_PIN2, 1);
	else if(Channel == 2)
	XGpioPs_WritePin(&psGpioInstancePtr,SCL_PIN3, 1);
	else if(Channel == 3)
	XGpioPs_WritePin(&psGpioInstancePtr,SCL_PIN4, 1);
	else
	xil_printf("Parameter Error!");
}

void CLOCK_LOW(u8 Channel)
{
	if(Channel == 0)
	XGpioPs_WritePin(&psGpioInstancePtr,SCL_PIN1, 0);
	else if(Channel == 1)
	XGpioPs_WritePin(&psGpioInstancePtr,SCL_PIN2, 0);
	else if(Channel == 2)
	XGpioPs_WritePin(&psGpioInstancePtr,SCL_PIN3, 0);
	else if(Channel == 3)
	XGpioPs_WritePin(&psGpioInstancePtr,SCL_PIN4, 0);
	else
	xil_printf("Parameter Error!");
}

void DATA_HIGH(u8 Channel)
{
	if(Channel == 0)
	XGpioPs_WritePin(&psGpioInstancePtr,SDA_PIN1, 1);
	else if(Channel == 1)
	XGpioPs_WritePin(&psGpioInstancePtr,SDA_PIN2, 1);
	else if(Channel == 2)
	XGpioPs_WritePin(&psGpioInstancePtr,SDA_PIN3, 1);
	else if(Channel == 3)
	XGpioPs_WritePin(&psGpioInstancePtr,SDA_PIN4, 1);
	else
	xil_printf("Parameter Error!");
}

void DATA_LOW(u8 Channel)
{
	if(Channel == 0)
	XGpioPs_WritePin(&psGpioInstancePtr,SDA_PIN1, 0);
	else if(Channel == 1)
	XGpioPs_WritePin(&psGpioInstancePtr,SDA_PIN2, 0);
	else if(Channel == 2)
	XGpioPs_WritePin(&psGpioInstancePtr,SDA_PIN3, 0);
	else if(Channel == 3)
	XGpioPs_WritePin(&psGpioInstancePtr,SDA_PIN4, 0);
	else
	xil_printf("Parameter Error!");
}

