# wifi_strangerthings_wall
A Stranger Things light wall built around a simple ESP8266 (ESP_01) module and a WS2811 light string.  
The entire thing can be built for less than $20.

The ESP8266 runs a simple socket server looking for a string on port 80.  Once one is sent, the line is parsed
into characters and displayed on the NeoPixel board one by one.  A simple one line command in Linux can send
the string to be displayed:

#> echo "Im trapped in the upside down" | nc 192.168.1.229 80
