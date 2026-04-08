#include <iostream>
using namespace std;

int main () {

int *pn;
pn = new int ;
*pn = 100;

cout << endl;
cout << " Isi variabel = "<< *pn <<endl;
cout << endl;
cin.get () ;
}