/*
  SD card datalogger

 This example shows how to log data from three analog sensors
 to an SD card using the SD library.

 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */
#include <SPI.h>
#include <SD.h>

#include <OneWire.h>
#include <DallasTemperature.h>


const int chipSelect = 4;
float a[20]; 
// Data wire is plugged into pin 2 on the Arduino
/*


//#define ONE_WIRE_BUS11 11
////#define ONE_WIRE_BUS12 12
//*/
#define ONE_WIRE_BUS0 2
#define ONE_WIRE_BUS1 3
#define ONE_WIRE_BUS2 5
#define ONE_WIRE_BUS3 6
#define ONE_WIRE_BUS4 7
#define ONE_WIRE_BUS5 8

#define ONE_WIRE_BUS6 9

int ONE_WIRE_BUS7 = A0;    // select the input pin for the potentiometer
int ONE_WIRE_BUS8 = A1;    // select the input pin for the potentiometer
int ONE_WIRE_BUS9 = A2;    // select the input pin for the potentiometer
int ONE_WIRE_BUS10 = A3;    // select the input pin for the potentiometer
/*int ONE_WIRE_BUS13 = A4;// select the input pin for the potentiometer
int ONE_WIRE_BUS14 = A5;    // select the input pin for the potentiometer

// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
/**/
OneWire oneWire0(ONE_WIRE_BUS0);
OneWire oneWire1(ONE_WIRE_BUS1);
OneWire oneWire2(ONE_WIRE_BUS2);
OneWire oneWire3(ONE_WIRE_BUS3);
OneWire oneWire4(ONE_WIRE_BUS4);
OneWire oneWire5(ONE_WIRE_BUS5);
OneWire oneWire6(ONE_WIRE_BUS6);
OneWire oneWire7(ONE_WIRE_BUS7);
OneWire oneWire8(ONE_WIRE_BUS8);
OneWire oneWire9(ONE_WIRE_BUS9);
OneWire oneWire10(ONE_WIRE_BUS10);
/*OneWire oneWire13(ONE_WIRE_BUS13);
OneWire oneWire14(ONE_WIRE_BUS14);
*/
DallasTemperature sensors0(&oneWire0);
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);
DallasTemperature sensors3(&oneWire3);
DallasTemperature sensors4(&oneWire4);
DallasTemperature sensors5(&oneWire5);
DallasTemperature sensors6(&oneWire6);
DallasTemperature sensors7(&oneWire7);
DallasTemperature sensors8(&oneWire8);
DallasTemperature sensors9(&oneWire9);
DallasTemperature sensors10(&oneWire10);
/*DallasTemperature sensors13(&oneWire13);
DallasTemperature sensors14(&oneWire14);
    
 */
void setup(void) {
  // Open serial communications and wait for port to open:
    /* */
   Serial.begin(9600);
 
    sensors0.begin();
  sensors1.begin();
   sensors2.begin();
   sensors3.begin();
  sensors4.begin();
   sensors5.begin();
   sensors6.begin();
   sensors7.begin();
   sensors8.begin();
  sensors9.begin();
  sensors10.begin();
   /* sensors13.begin();
   sensors14.begin();*/
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
 
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  Serial.println("Data1,Data2,Data3,Data4,Data5,Data6,Data7,Data8,Data9,Data10,Data11,Data12,Data13,Data14,Data15");


}

void loop(void) {
Serial.print("DATA,TIME,");
/*  
*/
  sensors0.requestTemperatures(); // Send the command to get temperatures
  sensors1.requestTemperatures(); // Send the command to get temperatures
  sensors2.requestTemperatures(); // Send the command to get temperatures
  sensors3.requestTemperatures(); // Send the command to get temperatures
  sensors4.requestTemperatures(); // Send the command to get temperatures
  sensors5.requestTemperatures(); // Send the command to get temperatures
  sensors6.requestTemperatures(); // Send the command to get temperatures  
  sensors7.requestTemperatures(); // Send the command to get temperatures
  sensors8.requestTemperatures(); // Send the command to get temperatures
 sensors9.requestTemperatures(); // Send the command to get temperatures
  sensors10.requestTemperatures(); // Send the command to get temperatures
 /*sensors13.requestTemperatures(); // Send the command to get temperatures
 sensors14.requestTemperatures(); // Send the command to get temperatures
 */
  //sensors10.requestTemperatures(); // Send the command to get temperatures
  
  //Serial.println("DONE");
/*

*/

a[0]=sensors0.getTempCByIndex(0);
a[1]=sensors1.getTempCByIndex(0);
a[2]=sensors2.getTempCByIndex(0);
a[3]=sensors3.getTempCByIndex(0);
a[4]=sensors4.getTempCByIndex(0);
a[5]=sensors5.getTempCByIndex(0);
a[6]=sensors6.getTempCByIndex(0);
a[7]=sensors7.getTempCByIndex(0);
a[8]=sensors8.getTempCByIndex(0);
a[9]=sensors9.getTempCByIndex(0);

a[10]=sensors10.getTempCByIndex(0);
/*a[13]=sensors13.getTempCByIndex(0);
a[14]=sensors14.getTempCByIndex(0);
*/
  // make a string for assembling the data to log:
  String dataString = "";

  // read three sensors and append to the string:
   
    
     for (int x=0; x <= 10; x++) {
    float sensor =a[x] ;
    dataString += String(sensor);
    
      dataString += ",";
    
  }
    
    delay(500);
  

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    //Serial.println("hamim");
    Serial.println(dataString);
  
  
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
  }
 
