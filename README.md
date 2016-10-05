# home-esp8266-door

This is an Arduino project for use with the ESP8266 in form of a NodeMCU. It is part of the DIY home surveillance with a Raspberry Pi as server https://github.com/michaeltroger/home

This program detects a door opening via a connected magnetic switch and sends a request to the web server when the door opened.

create a file named `wificonf.h` with your wifi login credentials like:

`const char[] WIFI_SSID = "your-ssid";
const char[] WIFI_PSK = "your password";`
