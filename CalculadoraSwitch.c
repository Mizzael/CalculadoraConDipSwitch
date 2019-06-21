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
   int Operacion;
   
   set_tris_a(0xC0);
   set_tris_b(0x80);
   set_tris_c(0xFF);
   set_tris_d(0xFF);
   set_tris_e(0x07);
   //Aqui iniciaizamos todo
   while(1)
   {
      Valor1=input_c();
      Valor2=input_d();
      
      if((Operacion&0x80)==0x80){
         Result=Valor1+Valor2;
         Operacion=0x00;
      }
      output_a(Result);
   }
}

