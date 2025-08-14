#include<pic.h>
__CONFIG(0X2CE4);

void delay(unsigned int t)
{
    while(t--);
}

void timer(int a) 
  {
    int count = 0;
    while (count < 125 * a) 
    {
        if (T0IF == 1) 
        {
            TMR0 = 131;
            count++;
            T0IF = 0;

        }
    }
}

void lcd(char rs, char data) 
{
    RE0 = rs;
    PORTD = data;
    RE1 = 1;
    for (int i = 0; i < 100; i++);
    RE1 = 0;
    for (int i = 0; i < 100; i++);
}

void string(char*str) 
{
    while (*str) 
    {
        lcd(1, *str++);
    }
}

int num[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0x6D, 0X7D, 0X07, 0X7F, 0X6F};

void main()
{
    PORTA=PORTB=PORTC=PORTD=PORTE=0X00;
    TRISA=0XFF;
    TRISB=TRISC=TRISD=TRISE=0X00;
    ANSEL=ANSELH=0X00;
    OPTION_REG = 0X05;
    TMR0 = 131;
    lcd(0, 0X38);
    lcd(0, 0X0E);
    
    int a=0;
    int c=0;
    while(1)
    {
        if(RA0==1)
        {
            
            a++;
        }
        if((RA1==1)&&(a>=1))
        {
          
            
            lcd(0,0X80);
            string("STOP");
            lcd(0,0XC0);
            string("GO");
            for(int i=0;i<10;i++)
            {
              RC3=0;
              RC4=0;
            RC7=1;
            RC6=1;
            PORTB=num[i];
            timer(1);
            }
            
          
            lcd(0,0X01);
            lcd(0,0X80);
            string("GO");
            lcd(0,0XC0);
            string("STOP");
            for(int i=0;i<10;i++)
            {
                 RC7=0;
            RC6=0;
                RC3=1;
                RC4=1;
                PORTB=num[i];
                timer(1);
            }
             
        }
        if((RA2==1)&&(a>=1))
        {
            c++;
            while((RA2==1)&& (a>=1));
        }
        if(c>=10)
        {
            PORTC=0X00;
            lcd(0,0X80);
            string("STOP");
            lcd(0,0XC0);
            string("GO");
            for(int i=0;i<10;i++)
            {
            RC7=1;
            RC6=1;
            RC2=RC3=RC4=RC5=0;
            PORTB=num[i];
            timer(1);
            
            }
        }
        }
 }