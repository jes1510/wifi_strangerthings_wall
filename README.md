# wifi_strangerthings_wall
A Stranger Things light wall built around a simple ESP8266 (ESP_01) module and a WS2811 light string.  
The entire thing can be built for less than $20.

The ESP8266 runs a simple socket server looking for a string on port 80.  Once one is sent, the line is parsed
into characters and displayed on the NeoPixel board one by one.  A simple one line command in Linux can send
the string to be displayed:

#> echo "Im trapped in the upside down" | nc 192.168.1.229 80

Lights:
https://www.amazon.com/gp/product/B017HAWXF0/ref=oh_aui_detailpage_o03_s00?ie=UTF8&psc=1

ESP-01:
https://www.amazon.com/kuman-ESP8266ESP-01-Wireless-Transceiver-Tutorial/dp/B016D5LCSO/ref=sr_1_4?ie=UTF8&qid=1506743326&sr=8-4&keywords=esp+01

You'll also need a 3.3v regulator and a 5v power supply.  The ESP-01 drives my lights fine at 3.3v but your
mileage may vary.  A level shifter may be needed if you have problems.
