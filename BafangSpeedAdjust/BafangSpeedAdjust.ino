#include <SPI.h>
#include <mcp2515.h>

struct can_frame canMsg;
MCP2515 mcp2515(10);

struct can_frame canMsg35;

bool speedSet = false;

void setup() {
  Serial.begin(115200);
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_250KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();

  Serial.println("Setup ok");
  Serial.println();

  //Original read: 82F83203 6 C4 09 C0 2B CE 08 => C4 09 => 09C4 => 2500 => 25km/h
  //Set:           85103203 6 AC 0D C0 2B CE 08 => AC 0D => 0DAC => 3500 => 35km/h
  //New read:      82F83203 6 AC 0D C0 2B CE 08
  
  canMsg35.can_id  = 0x85103203 | CAN_EFF_FLAG;
  canMsg35.can_dlc = 6;
  canMsg35.data[0] = 0xAC;
  canMsg35.data[1] = 0x0D;
  canMsg35.data[2] = 0xC0;
  canMsg35.data[3] = 0x2B;
  canMsg35.data[4] = 0xCE;
  canMsg35.data[5] = 0x08;
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
      Serial.print(canMsg.can_id, HEX); //Print ID
      Serial.print(" "); 
      Serial.print(canMsg.can_dlc, HEX); //Print DLC
      Serial.print(" ");
      
      for (int i = 0; i<canMsg.can_dlc; i++)  { //Print the data
        Serial.print(canMsg.data[i],HEX);
        Serial.print(" ");
      }
  
      Serial.println();
  }

  //Write speed setting after 10 seconds waiting
  if(!speedSet && currentMillis > 10000){
    speedSet = true;
    Serial.println("------ WRITING SPEED ------");
    Serial.println("------ WRITING SPEED ------");
    Serial.println("------ WRITING SPEED ------");
    Serial.println("------ WRITING SPEED ------");
    Serial.println("------ WRITING SPEED ------");
    Serial.println("------ WRITING SPEED ------");
    mcp2515.sendMessage(MCP2515::TXB1, &canMsg35);
    Serial.println("----------- DONE ----------");
    Serial.println("----------- DONE ----------");
    Serial.println("----------- DONE ----------");
    Serial.println("----------- DONE ----------");
    Serial.println("----------- DONE ----------");
    Serial.println("----------- DONE ----------");
  }
}
