// ------------------------------------------------------
// ex13_08.cpp
// Testet die Klasse Random durch
// Simulation eines einfachen Würfelspiels. 
// ------------------------------------------------------
#include "random.h"
#include <iostream>
using namespace std;

class Player
{
  private:
    int score;
  public:
    void gamble();
    int  getScore();
};

int Player::getScore() { return score; }

void Player::gamble()
{
    Random dice;
    dice.init(1,6);

    int i, rn;            // Index, Zufallszahl
    score= 0;
    for( i=0; i<5; ++i)
    {
        rn = dice.random();
        cout << rn << ", ";
        score += rn;
    }
    cout << "   Summe: " << score << endl;
}

int main()
{
    Player player1, player2;
    char yn;
    do
    {
       cout << "\n1. Spieler: ";  player1.gamble();
       cout << "\n2. Spieler: ";  player2.gamble();

       if( player1.getScore () > player2.getScore ())
           cout << "\nDer 1. Spieler gewinnt." << endl;
       else if( player1.getScore() < player2.getScore())
           cout << "\nDer 2. Spieler gewinnt." << endl;
       else
           cout << "\nUnentschieden!" << endl;

       cout << "\nFortsetzen (j/n)?" << endl; 
       cin  >> yn;
    } while(yn == 'j' || yn == 'J');

    return 0;
}
