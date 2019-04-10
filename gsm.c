#include <stdio.h>

#include <unistd.h>   //Used for UART

#include <fcntl.h>    //Used for UART

#include <termios.h>  //Used for UART

//#include <wiringPi.h>


int main ()

{

        int uart0_filestream = -1;
        uart0_filestream = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY | O_NDELAY); //Open in non blocking read/write mode

        if (uart0_filestream == -1)     //ERROR - CAN'T OPEN SERIAL PORT
        {
                printf("Error - Unable to open UART.  Ensure it is not in use by another application\n");
        }

        struct termios options;
        tcgetattr(uart0_filestream, &options);
        options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;         //<Set baud rate
        options.c_iflag = IGNPAR;
        options.c_oflag = 0;
        options.c_lflag = 0;

        options.c_cc[VMIN] = 0;
        options.c_cc[VTIME] = 0;
        tcflush(uart0_filestream, TCIFLUSH);
        tcsetattr(uart0_filestream, TCSANOW, &options); // Transmitting
        //----- TX BYTES -----
        unsigned char tx_buffer[] = "\r";
        unsigned char tx_buffer1[] = "AT+CMGF=1\r\n";
        unsigned char tx_buffer2[] = "AT+CMGS=\"+16476741649\"\r\n";
        unsigned char tx_buffer3[] = "Hello World\r\n";
        unsigned char tx_buffer4[]="\032";
        unsigned char tx_buffer5[]="AT+CNMI=2,2,0,0,0\r\n";
	 //---- RX BYTES ----
        unsigned char rx_buffer[256];
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
		
		printf("%s\n",tx_buffer1);
                count = write(uart0_filestream,tx_buffer1 ,sizeof(tx_buffer1) );
                usleep(10000000);
                rcount = read(uart0_filestream,(void*)rx_buffer,255);
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


                printf("%s\n",tx_buffer2);
                count = write(uart0_filestream,tx_buffer2 ,sizeof(tx_buffer2) );
                usleep(10000000);
                rcount = read(uart0_filestream,(void*)rx_buffer, 255);
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



                printf("%s\n",tx_buffer3);
                count = write(uart0_filestream,tx_buffer3 ,sizeof(tx_buffer3) );
		usleep(10000000);
                if (count < 0)
                {
                        printf("\n");
                }
                else
                {
                        printf("Sent %d characters\n",count);
                }

                rcount=read(uart0_filestream, (void*)rx_buffer, 255);
                if(rcount<0)
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


                printf("%s\n",tx_buffer4);
                count = write(uart0_filestream,tx_buffer4 ,sizeof(tx_buffer4) );
                usleep(10000000);
                if (count < 0)
                {
                        printf("\n");
                }
                else
                {
                        printf("Sent %d characters\n",count);
                }

                rcount=read(uart0_filestream, (void*)rx_buffer, 255);
                if(rcount<0)
                {
                        printf("\n");
		}
                else
                {
                        printf("Sent %d characters\n",count);
                }

                rcount=read(uart0_filestream, (void*)rx_buffer, 255);
                if(rcount<0)
                {
                        printf("\n");
                }
                else if(rcount == 0)
                {
                        printf("Received 0 characters\n");
                }
                else
                {
                        rx_buffer[rcount] = '\0';
                        printf("%i bytes read: %s\n",rcount,rx_buffer);
                }

                printf("%s\n",tx_buffer5);
                count = write(uart0_filestream,tx_buffer5 ,sizeof(tx_buffer5) );
                usleep(10000000);
                if (count < 0)
                {
                        printf("\n");
                }
                else
                {
                        printf("Sent %d characters\n",count);
		}
                int i=4;
                for(i;i>0;i=i-1)
                {
                rcount=read(uart0_filestream,(void*) rx_buffer, sizeof(rx_buffer));

                if(rcount<0)
                {
                        printf("\n");
                }
                else
                {
                        printf("Recieved %d characters\n",rcount);
                        if(rx_buffer[0]=='#'){
                                if(rx_buffer[1]='a'){
                                        if(rx_buffer[2]=='0'){
                                        //wiringPiSetup () ;
                                        //pinMode (0, OUTPUT) ;
                                        //digitalWrite (0, HIGH) ; delay (500) ;
                                        printf("LED ON");
                                        }
				  }
                                }
                        }
                }
                rx_buffer[rcount] = '\0';

                printf("Received: %s\n",rx_buffer);
                sleep(10);
                }
        }
}




                }
                        }
                }
                rx_buffer[rcount] = '\0';

                printf("Received: %s\n",rx_buffer);
		sleep(10);
                }
        }
}