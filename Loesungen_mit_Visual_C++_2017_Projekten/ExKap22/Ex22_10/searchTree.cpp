// ---------------------------------------------------------
// searchTree.cpp
// Implementierung der Klasse SearchTree.
// ---------------------------------------------------------
#include "searchTree.h"

void SearchTree::insertRec( int n, Node* &r_pn)
{
   if( r_pn == 0)
      r_pn = new Node(n); 
   else
   {
      if( n <= r_pn->data)
        insertRec(n, r_pn->left);
      else
        insertRec(n, r_pn->right);
   }
}

bool SearchTree::search( int val) const
{
   Node *np = root;
   bool found = false;
   while( np != NULL && !found)
   {
      if( val == np->data)
         found = true;
      else if( val < np->data)
         np = np->left;
      else
         np = np->right;
   }
   return found;
}

Node* SearchTree::getNodePtr( int nr) const
{
   if( nr == 1)
      return root;

   Node* np = getNodePtr( nr/2);
   if( np)
      return nr%2 == 0 ? np->left : np->right;
   else
      return NULL;
}

// Spitze des Baums anzeigen
void SearchTree::printTop(int hight) const
{
   int w = 64;                     // Breite des Baumes
   Node* np = NULL;
   int start = 1, cnt = 0;

   if( hight < 0)
       hight = count;              // Gesamter Baum

   for( int h = 0; h <= hight && cnt < count; ++h)
   { // Jeweils eine Ebene des Baumes ausgeben: 
     cout.width(w/2);              // Für die erste Zahl 
     for( int nr=start; nr < 2*start && cnt < count; ++nr)
     {
        if(np = getNodePtr(nr))
          cout << np->data,  ++ cnt;
        else
          cout << '*';
        cout.width(w);
     }
     cout << endl << endl;
     start *= 2;                   // Startnummer und Feldbreite                   
     w /= 2;                       // der nächsten Ebene. 
   }
}

void SearchTree::clearRec(Node* pn)
{
   if(pn)
   {
      clearRec( pn->left);
      clearRec( pn->right);
      delete pn;
   }
}

void SearchTree::printLNR_Rec(ostream& os, Node* pn) const
{
   if(pn)
   {
      printLNR_Rec( os, pn->left);
      os << setw(10) << pn->data;
      printLNR_Rec( os, pn->right);
   }
}

void SearchTree::printNLR_Rec(ostream& os, Node* pn) const
{
   if(pn)
   {
      os << pn->data << endl;
      printNLR_Rec( os, pn->left);
      printNLR_Rec( os, pn->right);
   }
}
