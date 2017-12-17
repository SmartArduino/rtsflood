
#include <ESP8266WiFi.h>

extern "C" {
  #include "user_interface.h"
}

byte channel;


uint8_t packet[128] = {0xb4, 0x00, 0xa8, 0x01, 0x00, 0x26, 0xad, 0x68, 0x23, 0xdf, 0xe4, 0x95, 0x6e, 0x42, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

void setup()
{
  delay(500);
  Serial.begin(115200);
      channel = 11; 

  wifi_set_opmode(STATION_MODE);
  wifi_promiscuous_enable(1); 
  wifi_set_channel(channel);

}

void loop()
{
  
    // Randomize channel //
    int ret;
    

    //Serial.println("11. Sending packet\n");
    ret = wifi_send_pkt_freedom(packet, 24, 0);
    //wifi_send_pkt_freedom(packet, 17, 0);
    //wifi_send_pkt_freedom(packet, 17, 0);
    //Serial.println("23. Sentt packet " + (String) ret + "...\n");
    //delay(1);
}

