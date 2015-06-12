# Project
Ethernet based Internet clock

#include "mbed.h"
#include "EthernetInterface.h"
#include "NTPClient.h"
#include "uLCD_4DGL.h"
// Parameters
char* domain_name = "0.uk.pool.ntp.org";
int port_number = 123;
// Networking
EthernetInterface eth;
NTPClient ntp_client;
// Graphic LCD - TX, RX, and RES pins
uLCD_4DGL uLCD(p9,p10,p11);
int main() {

    time_t ct_time;
    char time_buffer[80];    

    // Initialize LCD
    uLCD.baudrate(115200);
    uLCD.background_color(BLACK);
    uLCD.cls();

    // Connect to network and wait for DHCP
    uLCD.locate(0,0); 
    uLCD.printf("Getting IP Address\n");
    eth.init();
    if ( eth.connect() == -1 ) {
        uLCD.printf("ERROR: Could not\nget IP address");
        return -1;
    }
    uLCD.printf("IP address is \n%s\n\n",eth.getIPAddress());
    wait(1);

    // Read time from server
    uLCD.printf("Reading time...\n\r");
    ntp_client.setTime(domain_name, port_number);
    uLCD.printf("Time set\n");
    wait(2);
    eth.disconnect();

    // Reset LCD
    uLCD.background_color(WHITE);
    uLCD.textbackground_color(WHITE);
    uLCD.color(RED);
    uLCD.cls();
    uLCD.text_height(2);

    // Loop and update clock
    while (1) {
        uLCD.locate(0, 1);
        ct_time = time(NULL);
        strftime(time_buffer, 80, "    %a %b %d\n    %T %p %z\n    %Z\n", \
                                                localtime(&ct_time));
        uLCD.printf("    UTC/GMT:\n%s", time_buffer);
        wait(0.1);
    }
}
