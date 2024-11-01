/*************************************************************************************************
 *  Created By: NewEra TEL324 STUDENTS 
 *  Created On: 23 SEP, 2024
 *  ANIMAL_TRACKING_SYSTEM 
 *  LoRa-Blink-LoRA-AT-COMMANDS
 ***********************************************************************************************/

#include <SoftwareSerial.h>

#define RX 3
#define TX 2
SoftwareSerial LoRaSerial(RX, TX); // RX, TX

void setup() {
  Serial.begin(115200); // Initialize USB Serial
  delay(1000);
  
  LoRaSerial.begin(115200); // Initialize Software Serial
  
}

void loop() {
  // Check if data is available on USB Serial
  while (Serial.available()) {
    String data = Serial.readString();
    LoRaSerial.println(data); // Send data to Software Serial

    //Serial.flush() //is very slow
  }

  // Check if data is available on Software Serial
  while (LoRaSerial.available()) {
    String data = LoRaSerial.readString();
    Serial.println(data); // Send data to USB Serial

    //LoRaSerial.flush();
  }
} 
/  ===================  AT COMMANDS COM3 ======================= 
# select baut rate 115200 
# No Line ending

AT 

results = +OK 

AT +ADDRESS? 

results = +12 

AT +ADDRESS=1   // for demonstration purpose,  address= 0-65535 

results = +OK  

AT +ADDRESS?   //verify address 

results = +ADDRESS=1 

AT +NETWORKID? 

results = +NETWORKID=5

AT +NETWORKID=7 

press ENTER

AT +NETWORKID?   //verify Network , range 0-16, # Make sure u set same network for both modules

results = +NETWORKID=7 

AT +BAND? 

results = +BAND=434000000   // default frequency band 

AT+VER? 

AT+UID? 

AT+FACTORY

# Manufacturer defaults：
# BAND：915MHz 
# UART：115200
# Spreading Factor：12 
# Bandwidth：125kHz 
# Coding Rate：1
# Preamble Length：4
# Address：0 
# Network ID：0
# CRFOP：15 

# Example: Set the output power as 10dBm,
AT+CRFOP=10

# Example : Set the password as below:

# FABC0002EEDCAA90FABC0002EEDCAA90

AT+CPIN=FABC0002EEDCAA90FABC0002EEDCAA90

Example : Set the parameters as below: <Spreading Factor> 7,<Bandwidth> 20.8KHz, <Coding Rate> 4,<Programmed Preamble>5,

AT+PARAMETER=7,3,4,5  

# <Bandwidth>0~9 list as below
0 : 7.8KHz (not recommended, over spec.) 
1 : 10.4KHz (not recommended, over spec.) 
2 : 15.6KHz 
3 : 20.8 KHz
4 : 31.25 KHz
5 : 41.7 KHz
6 : 62.5 KHz
7 : 125 KHz (default).
8 : 250 KHz
9 : 500 KHz

# Communication within 3 km: Recommend to set 

“AT + PARAMETER = 10,7,1,7”

# More than 3 km: Recommend to set 

“ AT + PARAMETER = 12,4,1,7”

5. Use “AT+SEND” to send data to the specified ADDRESS. Please use “LoRa® Modem Calculator 
Tool” to calculate the transmission time. Due to the program used by the module, the payload 
part will increase more 8 bytes than the actual data length


------------------------------- RECIEVED MSG -----------------------------

# +RCV=2,5,HELLO,-55,40 

AT +SEND=2,5,HELLO   // Target second module 




//  ===================  AT COMMANDS COM7 ======================= 
# select baut rate 115200 
# Both NL & CR

AT 

results = +OK 

AT +ADDRESS? 

results = +5 

AT +ADDRESS=2   // for demonstration purpose,  address= 0-65535,# Make sure u set IT DIFFRENTLY

results = +OK  

AT +ADDRESS?   //verify address 

results = +ADDRESS=2 

AT +NETWORKID? 

results = +NETWORKID=5

AT +NETWORKID=7 

press ENTER

AT +NETWORKID?   //verify Network , range 0-16, # Make sure u set same network for both modules

results = +NETWORKID=7 

AT +BAND? 

results = +BAND=434000000   // default frequency band 

AT +SEND=1,5,HELLO  // now u can send data to device 1, 5 is the number char, then data=HELLO

--------------------------------------------------------------
# +RCV=1,5,HELLO,-54,40 
/**************************************************************************************************** 

