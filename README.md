# Particle Detect
 code base and hw files for pm2.5 detector
 
This file is the assembly guide of the dust detector

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)

## General info
This project is assembling a dust detector based on the ESP32 SoC and the Sharp's dust sensor GP2Y1010AU0F.
	
## Technologies
Project is created with:
* Arduino IDE version(at least): 1.8.10 
* Adafruit GFX library version: 1.8.4
* Adafruit LED Backpack library version: 1.1.6

Required Hardware:
* 150 Ohms Resistor * 1
* 220 uF Capacitor * 1
* Adafruit ESP32 Feather * 1
* Optical Dust Sensor - GP2Y1010AU0F * 1
* 7 Segment Display - KW4-56NCLB-P * 1
* protoboard * 1
* some wires
* soldering iron kit * 1
* 4.2/3.7V Lithium Polimer or Lithium Ion battery * 1 (OPTIONAL)

## Setup
1. To solder the devices, check the assembly in the link:
https://github.com/Trefex/arduino-airquality/tree/master/Module_Dust-Sensor

Here is the images of how to set up the electronic components on the breadboard, follow the patterns and you can easily solder the components on the protoboard. 
(Warning: this picture looks bad, we may probably need a clearer one!)
![Image of integratedCircuit](https://github.com/CriticalMaking/particleDetect/blob/Luther's-version/dustsensor/images/002.jpg)

Here is the images of how components are soldered on the protoboard (lack of image, please upload one if someone have it):




2. After installed the Arduino IDE, open it, and go to "Tools -> Manage Libraries," in the Library Manager, search for all the libraries mentioned above and lick on "Install."

3. Download the sensor_Luther.ino file, compile and load it to the ESP32 board with a USB wire.

4. Plug out of the USB wire, plug in the battery wire, the dust sensor should work as usual.

5. Integrate these parts into a 3D-printed case.
![Image of integratedCircuit](https://github.com/CriticalMaking/particleDetect/blob/Luther's-version/dustsensor/images/001.jpg)




