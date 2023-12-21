// -------------------------------------------------------
// ex05_06.cpp
// Das Programm berechnet den Kredit, den eine Bank 
// für eine monatlich zu zahlende Rate gewährt.
// -------------------------------------------------------

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
    double installment = 0.0, interest = 1.0, credit;
    int months = 0;

    cout << "Geben Sie die Monatsrate an:    "; 
    cin  >> installment; 
    cout << "Geben Sie den Zinssatz an:      "; 
    cin  >> interest; 
    cout << "Geben Sie die Anzahl Monate an: "; 
    cin  >> months;

    double q  = 1 + interest/(12*100),
           qn = pow(q, months);
    credit = installment * (1 - qn) / (qn - q*qn);

    cout.precision(2);
    cout << "Und hier ist Ihr Kredit:        " 
         << fixed <<  credit << endl;

    return 0;
}
