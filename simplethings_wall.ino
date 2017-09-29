/*
 * Stranger things  wall
 * Based on :
 * https://github.com/sparkfun/Stranger_Things_Wall
 * But modified heavily.
 */


#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include "letters.h"

#define PIN            2
#define NUMPIXELS      50

const char* ssid = "silence";
const char* password = "ilovesugarcookies";

WiFiServer server(80);
 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

int delayVal = 500; 
int offDelay = 250;

String readString;

void setup() 
{
  Serial.begin(115200);
  pixels.begin(); 

  Serial.printf("\nConnecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  server.begin();
}




void loop()
{

  WiFiClient client = server.available();
  // wait for a client (web browser) to connect
  if (client)
  {
    Serial.println("\n[Client connected]");
    while (client.connected())
    {
      if (client.available())
      {
        String line = client.readStringUntil('\r');
        Serial.print("Received: ");
        Serial.println(line);
        parse(line);
         
      }
    }
    delay(1); // give the web browser time to receive the data

    // close the connection:
    client.stop();
    Serial.println("[Client disonnected]");
  }
}


void parse(String readString) {
    for (int i=0; i<readString.length() + 1; i++) { 
      Serial.print("Parsing: ");
      Serial.println(readString[i]);
      switch(readString[i])
      {  
        case '\\' :
          return;
          break;
          
        case ' ' :
          delay(delayVal);
          break;
          
        case 'a':
        case 'A':
          lightUp(A);
          break;
          
        case 'b':
        case 'B':
          lightUp(B);
          break;
        case 'c':
        case 'C':
          lightUp(C);
          break;
        case 'd':
        case 'D':
          lightUp(D);
          break;
        case 'e':
        case 'E':
          lightUp(E);
          break;
        case 'f':
        case 'F':
          lightUp(F);
          break;
        case 'g':
        case 'G':
          lightUp(G);
          break;
        case 'h':
        case 'H':
          lightUp(H);
          break;
        case 'i':
        case 'I':
          lightUp(I);
          break;
        case 'j':
        case 'J':
          lightUp(J);
          break;
        case 'k':
        case 'K':
          lightUp(K);
          break;
        case 'l':
        case 'L':
          lightUp(L);
          break;
        case 'm':
        case 'M':
          lightUp(M);
          break;
        case 'n':
        case 'N':
          lightUp(N);
          break;
        case 'o':
        case 'O':
          lightUp(O);
          break;
        case 'p':
        case 'P':
          lightUp(P);
          break;
        case 'q':
        case 'Q':
          lightUp(Q);
          break;
        case 'r':
        case 'R':
          lightUp(R);
          break;
        case 's':
        case 'S':
          lightUp(S);
          break;
        case 't':
        case 'T':
          lightUp(T);
          break;
        case 'u':
        case 'U':
          lightUp(U);
          break;
        case 'v':
        case 'V':
          lightUp(V);
          break;
        case 'w':
        case 'W':
          lightUp(W);
          break;
        case 'x':
        case 'X':
          lightUp(X);
          break;
        case 'y':
        case 'Y':
          lightUp(Y);
          break;
        case 'z':
        case 'Z':
          lightUp(Z);
          break;      
        default:
          break;
      }
    }     readString = "";
  }
  


void lightUp(int letter)
{
  pixels.setPixelColor(letter - 1, pixels.Color(255,255,255));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(letter - 1, pixels.Color(0,0,0));  
  pixels.show();
  delay(offDelay);
}



