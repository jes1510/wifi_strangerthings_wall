/*
 * Stranger things  wall
 * Based on :
 * https://github.com/sparkfun/Stranger_Things_Wall
 * But modified heavily.
 */


#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>
#include "letters.h"
#include "phrases.h"

#define PIN            2      // Only 2 GPIO available
#define NUMPIXELS      50     // 50 lights to a string, only one string

long lastTime = millis();

const char* ssid = "silence";
const char* password = "ilovesugarcookies";

WiFiServer server(80);  // Server on port 80

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

int delayVal = 500;   // How long to display the letter
int offDelay = 250;   // Off time between letters
int randomUpdateTime = 5000; 


void setup() 
{
  int pixel = 0;
  Serial.begin(115200);
  pixels.begin(); 
  Serial.printf("\nConnecting to %s ", ssid);
  WiFi.begin(ssid, password);                   // build a simple server
  while (WiFi.status() != WL_CONNECTED)         // Wait for a connection
  {
    delay(500);
    Serial.print(".");   
    pixels.setPixelColor(pixel, pixels.Color(0,0,255));   // Sequentially turn on the pixels to signify waiting
    pixels.show(); 
    pixel ++;
    if (pixel >= NUMPIXELS) {
      allPixels(255,0,0); // Flash RED to show no connection yet
      delay(2000);
      allPixels(0,0,0);   // clear them
      pixel = 0;      
    }
  }

  allPixels(0,255,0); // Flash green to show good connection
  delay(2000);
  allPixels(0,0,0);   // clear them
  
  Serial.println(" connected");
  server.begin();      
  lastTime = millis();                   
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
        allPixels(0,0,0);
        delay(1000);
        parse(line);
        delay(1000);         
      }
    }
    delay(1); // give the web browser time to receive the data
    // close the connection:
    client.stop();
    Serial.println("[Client disonnected]");
  }
  else {
    if ((millis() - lastTime) > randomUpdateTime) {
      allRandom();
      lastTime = millis();
    }
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
    }     
  }
  

void allPixels(int r, int g, int b) {
  int i;
  for (i=0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(r,g,b));
  }
  pixels.show();
}


void lightUp(int letter) {
  pixels.setPixelColor(letter - 1, pixels.Color(128,128,128));
  pixels.show();
  delay(delayVal);
  pixels.setPixelColor(letter - 1, pixels.Color(0,0,0));  
  pixels.show();
  delay(offDelay);
}


// Set an individual lamp to a random color (R, G, or B)
// Pass the pixel # , brightness is optional
void randomColor (int pixel, int brightness = 255) {
  int randomColor;
  randomColor = random(3);
  if (randomColor == 0) {
    pixels.setPixelColor(pixel, pixels.Color(brightness,0,0));
  }
  if (randomColor == 1) {
    pixels.setPixelColor(pixel, pixels.Color(0,brightness,0));
  }

  if (randomColor == 2) {
    pixels.setPixelColor(pixel, pixels.Color(0,0,brightness));
  }
}


void allRandom() {
  int i;
  for (i=0; i < NUMPIXELS; i++) {
    randomColor(i, 64);
  }
  pixels.show();
}


