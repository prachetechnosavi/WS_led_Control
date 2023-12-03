# WS2812B Control
Control RGB values of WS2812B led strip from a webpage. This project is for ESP8266 boards.
This project will allow you to set any colour on WS2812B led strip from a webpage.

Libraries required for this project
1. ESP8266WiFi
2. ESPAsyncTCP
3. ESPAsyncWebServer
4. Adafruit_NeoPixel

Circuit Diagram:-
![Schematic_WS2812B led control_2023-12-03](https://github.com/prachetechnosavi/WS_led_Control/assets/64555378/10e5e2e3-ddbc-4fe7-94a8-101181bfcb40)

Type you Wifi SSID and Password in the code and then Upload the code and open Serial monitor. 
When the module connects to the WiFi, The Local IP address gets printed.
Copy that IP address and paste it in the address bar of your browser. The below webpage will appear.

<img width="959" alt="webpage_ws_led" src="https://github.com/prachetechnosavi/WS_led_Control/assets/64555378/eaed4b6e-493f-4b9d-90a0-c9a0dddb67b1">

From this Webpage you can set the RGB values of led strip and hit on the submit button. 
The page will load after that and the slider positions will be reset to default positions.  
