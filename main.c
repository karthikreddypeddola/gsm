#include<wiringPi.h>
#include<wiringserial.h>
#include<stdio.h>
#include <string.h>
#include<unistd.h>
#include<termios.h>
char str[currentDT]
int main()
{
 
int uart0_filestream= -1;
uart0_filestream = open("/dev/ttys0",9600);
 unsigned char tx_buffer[] = "\r";
        unsigned char tx_buffer1[] = "AT+CMGF=1\r\n";
        unsigned char tx_buffer2[] = "AT+CMGS=\"+16476741649\"\r\n";
        unsigned char tx_buffer3[] = "1\r\n";
        unsigned char tx_buffer4[]="\032";
        unsigned char tx_buffer5[]="AT+CNMI=2,2,0,0,0\r\n";
if (uart0_filestream != -1)
        {
                printf("%s\n",tx_buffer);
                int count = write(uart0_filestream,tx_buffer ,sizeof(tx_buffer) );
                usleep(10000000);
                int rcount = read(uart0_filestream,(void*)rx_buffer, 255);
                if (rcount < 0)
                {
                        printf("\n");
                }
                else if (rcount == 0)
                {
                        printf("Recieved 0 characters\n",rcount);
                }
                else
                {
                        rx_buffer[rcount] = '\0';
                        printf("%i bytes read: %s\n",rcount,rx_buffer);
                }

while(currentDT=datetime.datetime.now())
{
  printf("currentDT");
}
voidsetup()
{
      printf(" if h == 21 and m == 37 and s == 10:                  #Morning  8:0:0 ti$
                printf("data")
                os.system('espeak -s40 \"{}\"'.format(data))
                send(str(data));
                printf(\"Send\"\n");
      return 0;
}

		