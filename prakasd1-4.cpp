#include <iostream>
using namespace std;

struct Node {
int uts;
int uas;
int n1, n2;
};
Node *P, *Q;

int main (){
P = new Node;
P -> n1 = 99;
Q = new Node;
Q -> n2 = 78;

cout << endl;
cout << "Isi variabel P = " << P-> n1 << endl;
cout << "Isi variabel Q = " << Q-> n2 << endl;
cout << endl ;
cin.get (); 
}