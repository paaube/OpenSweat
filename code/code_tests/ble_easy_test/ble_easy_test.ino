int random_variable;
int static_variable = 500;
#include "BluetoothSerial.h" \\ il faut downloader cette librairie

// #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
// #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
// #endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("RP2040test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20); \\ tests pour recevoir des données
   random_variable = random(0, 1000);
  SerialBT.print("E"); \\ pour imprimer des donner seulement ajouter BT dans le serial print
  SerialBT.print(random_variable);
  SerialBT.print(",");
  SerialBT.print(static_variable);
  SerialBT.print("\n");
}
