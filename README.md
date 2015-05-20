# Pulse-Sensor-Belt
This is a project I did for my finals. It is called a pulse sensor belt. fairly simple, pulse sensor sends readings to arduino, arduino triggers led strip based on values receive.

Things you will need:
1 Arduino Uno R3
1 Adafruit NeoPixel Strip – White 60 LED – WHITE PRODUCT ID: 1138
1 Belt
1 Battery Pack 5v
1 Pulse Sensor Amped
1 Usb cable - Standard A-B
Jumper wires (I used 8) varies depending on where you want to put the Arduino
Heat Shrink Tubing (optional)
rubber glue, strings, anything, you can use to hold the strip to the belt.

read up or understand your softwares and how to set them up
Pulse Sensor Amped - how to guide - http://pulsesensor.com/pages/code-and-guide 
Adafruit NeoPixel Strip – White 60 LED – WHITE PRODUCT ID: 1138 - http://www.adafruit.com/products/1138 Also at https://github.com/adafruit/Adafruit_NeoPixel

Step 1: Get the software
download and install the arduino software for your computer OS - http://www.arduino.cc/en/Main/Software

Step 2: Summary of Operation
As blood pumps through your body, the pulse sensor senses the flow through your pulse. Each pulse read is sent to the arduino and 
processed to whatever setting you set the bmp to, which in turn triggers the led strip. Simple.

Step 3: Run the arduino
Open the 2 files you have just downloaded (interrupt.ino and PulseSensorAmped_Ardunio_a.ino) in the arduino 
After you open the 2 files, save the file into your arduino folder.

Step 4: Connections
Make sure your computer can detect your arduino after you connect it via the usb (type A-B)
If you don't know how to connect, read this link for windows http://www.arduino.cc/en/guide/windows or 
for Mac http://www.arduino.cc/en/Guide/MacOSX
MAKE SURE YOUR ARDUINO IS NOT CONNECTED TO THE COMPUTER / DISCONNECT YOUR ARDUINO
Connect the Pulse Sensor to: red wire to 5v pin, black wire to ground pin, and Purple wire to Analog Pin #0 on your favorite Arduino, or Arduino compatible device
Connect the led strip to:  red wire to 5v pin, black wire to ground pin, and yellow or white (wire color may be different) to pin #5
If you are unsure where/how to connect your wires, please look up your software guide for connections. 
In other to make it easy for you to connect, you can combine the wire since both red (5v) and black(ground) wires use the same voltage. 
-use the heat shrink to cover the connections. 

Step 5: upload
After the wire connections, you can connect the arduino back to your computer. 
Click on upload in the arduino, give it a few seconds to upload, after the upload put the pulse sensor strap on your finger tip or anywhere you can get a good reading.
You can adjust the pulse sensor in interrupt.ino file.


THESE VARIBALBES ARE IMPORTANT
  //variables for neopixel
#include <Adafruit_NeoPixel.h>
#define PIN 6
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(59, PIN, NEO_GRB + NEO_KHZ800); //mine is 59 because I removed 1 of the light.
 
//variables for pulse
int pulsePin = A0; // Pulse Sensor Purple wire
int ledStrip = 6; //led strip data wire (white or yellow)
//int fadeRate = 0; not needed
