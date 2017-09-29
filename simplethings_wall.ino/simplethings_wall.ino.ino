/*
 * Stranger things  wall
 * Based on :
 * https://github.com/sparkfun/Stranger_Things_Wall
 * But modified heavily.
 */


#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include "letters.h"

#define PIN            2      // Only 2 GPIO available
#define NUMPIXELS      50     // 50 lights to a string, only one string

const char* ssid = "*****";
const char* password = "****";

WiFiServer server(80);  // Server on port 80

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

int delayVal = 500;   // How long to display the letter
int offDelay = 250;   // Off time between letters

void setup() 
{
  Serial.begin(115200);
  pixels.begin(); 
  Serial.printf("\nConnecting to %s ", ssid);
  WiFi.begin(ssid, password);                   // build a simple server
  while (WiFi.status() != WL_CONNECTED)         // Wait for a connection
  {
    delay(500);
    Serial.print(".");    
  }
  Serial.println(" connected");
  server.begin();                             
}




void loop()
{

  WiFiClient client = server.available();   // check for a client
  if (client)
  {
    Serial.println("\n[Client connected]");
    while (client.connected())
    {
      if (client.available())
      {
        String line = client.readStringUntil('\r');   // read up to a carriage return
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

// Parse the string into characters and call the light driver
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



