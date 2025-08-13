#include<stdio.h>
#include<string.h>



#include<pic.h>
__CONFIG(0X2CE4);


void delay(unsigned int t)
{
    while(t--);
}
int low,high,val=0,f,j;
float v;
char s[20];
void enable()
{
    RE1=1;
    delay(5000);
    RE1=0;
    delay(5000);
}

void lcd(char rs,char data)
{
    RE0=rs;
    PORTD=data;
    enable();
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
    
    PORTA=PORTB=PORTD=PORTE=0X00;
    TRISD=TRISE=0X00;
    TRISB=0X01;
    ADCON0=0XB1;      //ADC AND AN12 CHANNEL ENABLE
    ADCON1=0X80;
    TRISA=0X03;
    ANSEL = 0X00;
    ANSELH = 0X10;
     lcd(0,0X38);
     lcd(0,0X0C);
     lcd(0,0X80);
     lcd(0,0X0E);
        
    while(1)
     {
      low=ADRESL;
      high=ADRESH;
      GO=1;
    while(GO==1)
    {
            
            lcd(0,0X80);
            if(high==0)
            {
                val=low; 
            }
            
            lcd(0,0X80);
            if(high==1)
            {
                val=low+256;
                 
            }
            
            lcd(0,0X80);
            if(high==2)
            {
                val=low+512;
                 
            }
            
            lcd(0,0X80);
            if(high==3)
            {
                val=low+768;
            }
      
            if(RA0==1)
            {
        lcd(0,0X80);
        v =(val*5.0)/1023.0;   //voltage
		
        string("CELCIUS:");
        j=v*100;                  // CELSIUS VALUE
        lcd(1,(j/100)%10+48);
        lcd(1,(j/10)%10+48);
        lcd(1,(j%10)+48);
        
         }
            if(RA1==1)
            {
                lcd(0,0xC0);
                string("FARENHEIT:");
                f=(j*9)/5+32;      //FARAENHEIT FORMULA
                /*lcd(1,(f/100)%10+48);
                lcd(1,(f/10)%10+48);
                lcd(1,(f%10)+48);*/
                sprintf(s,"%d",f);
                string(s);
            }
            if(f>98)
            {
                RB1=1;      //ABOVE BODY TEMPERATURE
            }
     }
}
}