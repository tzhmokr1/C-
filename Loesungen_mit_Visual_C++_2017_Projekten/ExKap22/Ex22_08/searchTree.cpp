// --------------------------------------------------------
// searchTree.cpp
// Implementierung der Klasse SearchTree.
// --------------------------------------------------------
#include "searchTree.h"

void SearchTree::insertRec( int n, Node* &r_pn)
{
   if( r_pn == 0)
      r_pn = new Node(n); 
   else
   {
      cout << n << " : " << r_pn->data   // Zu Testzwecken
           << endl;
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
