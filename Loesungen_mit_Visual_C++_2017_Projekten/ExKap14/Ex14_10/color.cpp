// ---------------------------------------------------------------
// color.cpp
// Definiert die Methoden chooseColor() und display() 
// der Klasse RGB_Color.
// ---------------------------------------------------------------

#include "color.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool RGB_Color::chooseColor()
{
   int r=0, g=0, b=0;
   cout << "Geben Sie Rot-, Gruen- und Blauanteil "
           "einer Farbe ein:"
        << endl;
   cout << "  rot   (0, ... , 255): ";
   if( !(cin >> r)  ||  r < 0  ||  r > 255)  return false;

   cout << "  gruen (0, ... , 255): ";    
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
    cout << "  rot: "   << setw(3) << (int)red
         << "  gruen: " << setw(3) << (int)green
         << "  blau: "  << setw(3) << (int)blue << endl;
}

/*
// --- Eine Version, die Windows Dialog-Boxen verwendet ---

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
