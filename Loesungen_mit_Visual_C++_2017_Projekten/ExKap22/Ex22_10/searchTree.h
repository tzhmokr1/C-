// ---------------------------------------------------------
// searchTree.h
// Definition der Klassen Node und SearchTree.
// ---------------------------------------------------------
#ifndef _SEARCHTREE_
#define _SEARCHTREE_

#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
  private:
    int data;
    Node *left, *right;
  public:
    Node( int d)
    : data(d), left(NULL), right(NULL)
    {}
    friend class SearchTree;
};

class SearchTree
{
  private:
    Node* root;        // Zeiger auf die Wurzel
    int count;         // Anzahl Knoten im Baum

    // private Methoden:
    SearchTree(const SearchTree&);            // Kopie und
    SearchTree& operator=(const SearchTree&); // Zuweisung
                                              // verhindern.
    void insertRec( int n, Node* &r_pn);
    void clearRec(Node* pn);

    void printLNR_Rec(ostream& os, Node* pn) const;
    void printNLR_Rec(ostream& os, Node* pn) const;

  public:
    SearchTree() : root(0), count(0) {}
    ~SearchTree() { clearRec(root); }

    int getCount() const {  return count; }
    void insert(int n) { insertRec( n, root);  ++count; }
    bool search( int val) const;

    Node* getNodePtr( int nr) const;
    void printTop(int hight = -1) const;

    void clear() { clearRec(root);  root = NULL; count = 0; }

    void printLNR(ostream& os) const { printLNR_Rec( os, root); }
    void printNLR(ostream& os) const { printNLR_Rec( os, root); }
};

inline ostream& operator<<( ostream& os, const SearchTree& t)
{
    t.printLNR(os);
    return os;
}

#endif  //  _SEARCHTREE_
