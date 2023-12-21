// -----------------------------------------------------
// color.h 
// Definiert die Klasse RGB_Color.
// -----------------------------------------------------
#ifndef _RGB_COLOR_
#define _RGB_COLOR_

class RGB_Color
{
  private:
    unsigned char red, green, blue;

  public:
    RGB_Color() { red = 0;  green = 0;  blue = 0; }
    RGB_Color(int r, int g, int b)  { setColor( r, g, b); }

    void setColor(int r, int g, int b)
    {  setR(r);  setG(g);  setB(b);   }

    void setR(int r) {  red   = (unsigned char)r; }
    void setG(int g) {  green = (unsigned char)g; }
    void setB(int b) {  blue  = (unsigned char)b; }

    int  getR() const {  return red;   }
    int  getG() const {  return green; }
    int  getB() const {  return blue;  }

    void display() const;

    bool chooseColor();
};

#endif   // _RGB_COLOR_
