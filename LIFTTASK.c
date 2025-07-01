/*
 * File:   LIFTTASK.c
 * Author: dharsan
 *
 * Created on July 1, 2025, 2:33 PM
 */

#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
#include <xc.h>
int a=0,s=0;
char data;
void delay(unsigned int a)
{
    while(a--);
}
void pulse() 
{
RE1=1;
delay(1000);
RE1=0;
delay(1000);}

lcd(char rs,char data)
{
    RE0=rs;
    PORTD=data;
    pulse();
    
}
void string(char *str)
{
    while(*str)
    {
        lcd(1,*str++);
    }
}
void main()
{
        PORTA=0X00;
        PORTC=0X00;
        PORTD=PORTE=0X00;
        TRISA=0X0F;
        TRISC=0X0F;
        TRISD=TRISE=0X00;
        ANSEL=ANSELH=0X00;
        lcd(0,0X38);
        lcd(0,0X0E);
        while(1){
         
            if(RA0==1)
            {   
                lcd(0,0X01);
                lcd(0,0X80);
                string("GROUND FLOOR");
               
                a=0;
            }
             if(RA1==1)
            {   
                lcd(0,0X01);
                lcd(0,0X80);
                string("FIRST FLOOR");
                a=1;
            }
             if(RA2==1)
            {   
               
                a=2;
                 lcd(0,0X01);
                lcd(0,0X80);
                string("SECOND FLOOR");
            } 
            if(RA3==1)
            {   
                a=3;
                 lcd(0,0X01);
                lcd(0,0X80);
                string("THIRD FLOOR");
            }
            
             if(RC0==1)
            {
                s=0;
            }
             if(RC1==1)
            {
                s=1;
            }
             if(RC2==1)
            {
                s=2;
            } 
            if(RC3==1)
            {
                s=3;
            }
            
            if(a>s)
            {
                RC4=1;
                RC5=0;
            }
             if(a<s)
            {
                RC5=1;
                RC4=0;
            }
             if(a==s)
            {
                RC4=0;
                RC5=0;
            }
        }
}