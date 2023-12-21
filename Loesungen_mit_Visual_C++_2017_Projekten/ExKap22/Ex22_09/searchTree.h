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

  public:
    SearchTree() : root(0), count(0) {}

    int getCount() const {  return count; }
    void insert(int n) { insertRec( n, root);  ++count; }
    bool search( int val) const;

    Node* getNodePtr( int nr) const;
    void printTop(int hight = -1) const;
};
#endif  //  _SEARCHTREE_
