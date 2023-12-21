// -------------------------------------------------------
// polynom.h
// Definition der Klasse Polynomial.
// -------------------------------------------------------
#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

class Polynomial
{
  private:
    double *arrCoef;    // Zeiger auf den Vektor mit den Koeffizienten.
    int degree;         // Grad des Polynoms (= Lange des Vektors - 1). 

    // Private Hilfsfunktion erzeugt und initalisiert den Vektor arrCoef:
    void init( double coef[], int g);

  public:
    // Konstruktoren:
    Polynomial( double coef[], int g) { init( coef, g); }
    Polynomial( double a0 = 0.0, double a1 = 0.0,
                double a2 = 0.0, double a3 = 0.0); 
    Polynomial( const Polynomial& p) { init( p.arrCoef, p.degree); };

    ~Polynomial() { delete [] arrCoef; }           // Destruktor

    int getDegree() const { return degree; }
    double evaluate( double x) const;
    void display() const;

    Polynomial& operator=(const Polynomial& p);    // Zuweisung
    Polynomial& operator+=(const Polynomial& p);   // += Operator
};

#endif  // _POLYNOMIAL_
