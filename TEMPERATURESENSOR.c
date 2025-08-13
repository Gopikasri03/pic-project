#include<stdio.h>
#include<string.h>
#include<pic.h>
__CONFIG(0X2CE4);



void delay(unsigned int t)
{
    while(t--);
}

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
    
    PORTA=PORTD=PORTE=0X00;
    TRISA=0X09;
    TRISD=TRISE=0X00;
    ANSEL=0X01;
    ANSELH=0X00;
    ADCON0=0X81;
    ADCON1=0XB0;
    lcd(0,0X38);
    lcd(0,0X0E);
    lcd(0,0X0C);
  //  lcd(0,0X01);
    lcd(0,0X80);
        
    int high,low,val;
    
    while(1)
    {
        GO=1;
        while(GO==1);
        {
            low=ADRESL;
            high=ADRESH;
            
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
        }
        
        lcd(0,0X80);
        //float volt=val*5/1023;
        
        int a=val%1000;
        int b=a/100;
        int c=a%100;
        int d=c/10;
        int e=c%10;
        
        lcd(1,((val/1000)+48));
        
        lcd(1,b+48);
        //lcd(1,46);
        lcd(1,d+48);
        lcd(1,e+48);
        
        lcd(0,0X85);
        float p=(float)val*150.0/1023.0;
            int q=(int)p*10;
            //lcd(1,(q/100)+48);
            int t=q%100;
            //lcd(1,(t/10)+48);
            lcd(1,'5');
            lcd(1,46);
            //lcd(1,(t%10)+48);
            if(1023>=150)
            {
                lcd(1,'0');
            }
            
            lcd(0,0X89);
            a=150/100;
            b=150%100;
            c=b/10;
            d=b%10;
            lcd(1,a+48);
            lcd(1,c+48);
            lcd(1,d+48);
            //lcd(0,0XDF);
            lcd(1,248);
            lcd(1,'C');
         
            
    }
}