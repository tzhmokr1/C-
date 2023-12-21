// ---------------------------------------------------
// ex26_02.h
// Definition der Klassen Base und Derived.
// ---------------------------------------------------

class Base
{
  protected:
    double x;
  public:
    Base(double ax){ x = ax; }
    double getX() const{ return x; }
    virtual int getY() const =0;
    virtual double multiply(double fact) =0;
};
/*
class Derived : public Base
{
  private:
    int y;
  public:
    Derived(double ax, int ay): Base(ax) { y = ay; }
    int getY() const { return y; }
    double multiply() { return getX()*y; }
};

class Derived : public Base
{
  private:
    int y;
  public:
    Derived(double ax, int ay):Base(ax){ y = ay;}
    int getY() const { return y; }
    void multiply(double fact) { x *= fact; }
};
*/
class Derived : public Base
{
  private:
    int y;
  public:
    Derived(double ax, int ay):Base(ax) { y = ay;}
    int getY() const { return y; };
    double multiply( double fact ) { return getX()*y; }
};

