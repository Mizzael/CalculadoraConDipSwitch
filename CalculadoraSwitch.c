#include <18F4620.h>
#fuses HS,NOWDT,NOMCLR, /*INTRC_IO*/
#use delay(clock=16 MHZ)

//Aqui deben ir las interfaces tales como la rs-232, I^2C
/*
#define _DEBUG_SERIAL_

#ifdef _DEBUG_SERIAL_
   #define TX_232    PIN_C6
   #define RX_232    PIN_C7
   #use RS232(BAUD=9600,XMIT=TX_232,BITS=8,PARITY=N,STOP=1,UART1,RCV=RX_232)
   #use fast_io(c)
#endif
*/

//Aqui deben ir la IsR's interrupciones
   //int_rda
   //int_timer0

//variables globales

//aqui el void main(void)
void main(void)
{
   int Valor1;
   int Valor2;
   int Result;
   int Opcion;
   
   int FlagSuma;
   int FlagResta;
   int FlagDiv;
   int FlagMult;
   
   set_tris_a(0xC0);
   set_tris_b(0x00);
   
   set_tris_c(0x00);
   set_tris_d(0x00);
   set_tris_e(0x00);
   
   setup_oscillator(OSC_16MHZ);
   //Aqui iniciaizamos todo
   while(1)
   {
      Valor1=input_c();
      Valor2=input_d();
      Opcion=input_e();
      
      if((Opcion&0x01)==0x01){
         FlagSuma=1;
      }
      else{
         FlagSuma=0;
      }
      
      if((Opcion&0x02)==0x02){
         FlagResta=1;
      }
      else{
         FlagResta=0;
      }
      
      if((Opcion&0x04)==0x04){
         FlagMult=1;
      }
      else{
         FlagMult=0;
      }
      
      if((Opcion&0x08)==0x08){
         FlagDiv=1;
      }
      else{
         FlagDiv=0;
      }
      
      if(FlagSuma==1){
         Result=Valor1+Valor2;
      }
      
      if(FlagResta==1){
         Result=Valor1-Valor2;
      }
      
      if(FlagMult==1){
         Result=Valor1*Valor2;
      }
      
      if(FlagDiv==1){
         Result=Valor1/Valor2;
      }

      output_a(Result);
      output_b(Result>>6);
   }
}

