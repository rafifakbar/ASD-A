#include <iostream>
using namespace std;

class mahasiswa{
public:
char npm[9];
char nama[30];
float ipk;

};

int main (){

mahasiswa mhs ;
cout << "no pokok mahasiswa = "; cin >> mhs.npm;
cout << "nama mahasiswa = "; cin >> mhs.nama;
cout << "IPK  = "; cin >> mhs.ipk;
cout << endl;
cout << "=======================================" <<  endl;
cout<< " DATA ANDA " <<endl;
cout << "=======================================" <<  endl;
cout << "no pokok mahasiswa = "<< mhs.npm << endl;
cout << "nama mahasiswa = "<< mhs.nama << endl;
cout << "IPK = "<< mhs.ipk << endl;
cin.get();
}