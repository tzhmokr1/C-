// ---------------------------------------------------------
// color.cpp
// Definiert die Methoden der Klasse RGB_Color wie zuvor.
// Auﬂerdem wird die Methode setColor() definiert.
// ---------------------------------------------------------

#include "color.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool RGB_Color::chooseColor()
{
   int r=0, g=0, b=0;
   cout << "Geben Sie den Rot-, Gruen- und Blauanteil einer Farbe ein:"
        << endl;
   cout << "  rot   (0, ... , 255): ";
   if( !(cin >> r)  ||  r < 0  ||  r > 255)  return false;

   cout << " gruen (0, ... , 255): ";    
   if( !(cin >> g)  ||  g < 0  ||  g > 255)  return false;

   cout << "  blau  (0, ... , 255): ";    
   if( !(cin >> b)  ||  b < 0  ||  b > 255)  return false;

   red   = (unsigned char)r;
   green = (unsigned char)g;
   blue  = (unsigned char)b;

   return true;
}

void RGB_Color::display() const
{
    cout << "rot: "     << setw(3) << (int)red
         << "  gruen: " << setw(3) << (int)green
         << "  blau: "  << setw(3) << (int)blue << endl;
}

/*
// Eine Version mit Windows Dialog-Boxen

#include "color.h"
#include <windows.h>
#include <commdlg.h>

#include <sstream>         // Klasse stringstream
using namespace std;
  
void RGB_Color::display() const
{
    stringstream ss;
    ss << "rot: " << (int)red << "  gruen: " << (int)green
       << "  blau: "<< (int)blue << "\n";

    int dispElement = COLOR_ACTIVECAPTION;
    COLORREF color0 = GetSysColor(dispElement),
             color1 = RGB(red, green, blue);

    SetSysColors(1, &dispElement, &color1);
    MessageBox(NULL, ss.str().c_str(), "Color", MB_OK);
    SetSysColors(1, &dispElement, &color0);
    Sleep(100);
}

static COLORREF CustColors[16];

static CHOOSECOLOR cc = { sizeof(CHOOSECOLOR), NULL, NULL, (COLORREF)0, CustColors, 
                          CC_RGBINIT | CC_SOLIDCOLOR  };

bool RGB_Color::chooseColor()
{
    cc.rgbResult = RGB(red, green, blue);
    if( ChooseColor( &cc) )
    {
        setColor( GetRValue(cc.rgbResult), 
                  GetGValue(cc.rgbResult),
                  GetBValue(cc.rgbResult)); 
        return true;
    }
    else
        return false;
}
*/

void RGB_Color::setColor(ColorID clr)
{
    red = 0, green = 0, blue = 0;

    switch(clr)
    {
        case BLACK:    break; 
        case RED:      red   = 255;
                       break;
        case GREEN:    green = 255;
                       break;
        case BLUE:     blue  = 255;
                       break;
        case YELLOW:   red   = 255;  green = 255;
                       break;
        case CYAN:     green = 255;  blue  = 255;
                       break;
        case MAGENTA:  red   = 255;  blue  = 255;
                       break;
        case WHITE:    red   = 255;  green = 255;  blue  = 255;
                       break;
        case DARK_GRAY: red = 80;    green = 80;   blue  = 80;
                       break;
        case LIGHT_GRAY: red= 160;   green = 160;  blue  = 160;
                       break;
    }
}
