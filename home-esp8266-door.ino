/**
Copyright 2016 Michael Troger <https://michaeltroger.com>
This file is part of Home Surveillance with Node.js.

Home Surveillance with Node.js is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Home Surveillance with Node.js is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Home Surveillance with Node.js.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include "wificonf.h"

// Remote site information
const char hostname[] = "192.168.1.161";
const int port = 3000;

WiFiClient client;

// door sensor
const int doorPin = 14;
#define CLOSED 0
#define OPENED 1
int doorState = CLOSED;

void setup() {
  WiFi.begin(WIFI_SSID, WIFI_PSK);
}

void loop() {
  if(digitalRead(doorPin) == HIGH && doorState == OPENED) { 
      doorState = CLOSED;
  }
  if(digitalRead(doorPin) == LOW && doorState == CLOSED) { 
      doorState = OPENED;
      
      client.connect(hostname, port);
      
      // do a HTTP get request
      client.println("GET /door HTTP/1.1");
      client.print("Host: ");
      client.println(hostname);
      client.println("Connection: close");
      client.println();
  }
}

