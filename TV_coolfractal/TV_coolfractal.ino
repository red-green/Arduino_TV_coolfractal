#include <TVout.h>

TVout TV;

#define SIZECON 1.6

void setup() {
  TV.begin(NTSC,120,96);
  
  randomSeed(analogRead(0));
}

void loop() {
  float a = random(1000.0) / 1000.0;
  float b = 0.9998;
  float c = 2.0 - 2.0 * a;
  float j = 0.0;
  float x = 0.0;
  float y = (random(1000.0)/1000.0) * 12.0 + 0.1;
  float z = 0.0;
  float xp = 0.0;
  float yp = 0.0;
  
  for (int i = 0; i < 700; i++) {
    z = x;
    x = b * y + j;
    j = a * x + c * pow(x,2) / (1 + pow(x,2));
    y = j - z;
    xp = (x * SIZECON) + 64;
    yp = (y * SIZECON) + 48;
    
    TV.set_pixel(xp,yp,INVERT);
    
  }
}
