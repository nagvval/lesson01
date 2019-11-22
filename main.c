#include "DSP28x_Project.h"

void InitLED(void);
void delay(unsigned long i);

void main(void) {

   InitSysCtrl();
   InitPieCtrl();
   InitPieVectTable();

   IER = 0x0000;
   IFR = 0x0000;

   InitLED();

   GpioDataRegs.GPASET.bit.GPIO1 = 1;
   GpioDataRegs.GPASET.bit.GPIO2 = 1;
   GpioDataRegs.GPASET.bit.GPIO3 = 1;

   while(1) {

       GpioDataRegs.GPASET.bit.GPIO0 = 1;
       //GpioDataRegs.GPACLEAR.bit.GPIO1 = 1;
       //GpioDataRegs.GPASET.bit.GPIO2 = 1;
       //GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;

       delay(1000000);

       GpioDataRegs.GPACLEAR.bit.GPIO0 = 1;
       //GpioDataRegs.GPASET.bit.GPIO1 = 1;
       //GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
       //GpioDataRegs.GPASET.bit.GPIO3 = 1;

       delay(1000000);

   }

}

void delay(unsigned long i){
    while(--i){};
}

void InitLED(void){

    EALLOW;

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;

    GpioCtrlRegs.GPADIR.all = 0xFFFFFFFF;

    EDIS;

}
