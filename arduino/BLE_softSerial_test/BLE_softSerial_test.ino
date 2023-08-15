#include <SoftwareSerial.h>

SoftwareSerial ble_device(0); // HM-10 TX/RX pins

void setup() { 
  ble_device.begin(9600); // prepare BLE module
}

void loop() {
  delay(1000); // delay in-between readings
  int f = 10; // send temperature data
  char f_str[6]; // prepare character array to send
  dtostrf(f,2,1,f_str); // format data into char array
  ble_device.write(f_str); // send to BLExAR
}
