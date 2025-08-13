#include<stdio.h>
#include<string.h>
#include<pic.h>
__CONFIG(0X2CE4);

void delay(unsigned int t)
{
    while(t--);
}

int time=0;float distance;

void enable()
{
    RE1=1;
    delay(500);
    RE1=0;
    delay(500);
}


void lcd(char rs,char data)
{
    RE0=rs;
    PORTD=data;
    enable();
}
    
void main()
 
{
    PORTA=PORTB=PORTC=PORTD=PORTD=PORTD=PORTE=0X00;
    TRISB=TRISC=TRISD=TRISE=0X00;
    T1CON=0X07;
    TRISA=0X01;
    TMR1=0;
    
     lcd(0,0X38);
     lcd(0,0X0C);
     lcd(0,0X80);
        
        
    while(1)
    {
        TMR1=0;
        RA1=0;  //TR
        delay(10);
        RA1=1;
        delay(10);
        RA0=0;
        while(RA0==0);
        TMR1ON=1;
        while(RA0==0);   //ECHO
        TMR1ON=1;
        while(RA0==1)
        {
            TMR1ON=0;
            time=TMR1;
            delay(1000);
            distance=(float) time*0.0343/2;
            lcd(0,0X80);
            lcd(1,'A');
        }
    }
}