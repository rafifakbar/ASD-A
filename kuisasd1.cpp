#include <iostream>
#include <string>
using namespace std;

int main () {

struct buku {
string judul;
string pengarang;
int tahun;
float harga; };

buku Data; 

Data.judul = "Laskar Pelangi";
Data.pengarang = "Budi";
Data.tahun = 1945;
Data.harga = 20000;
cout << endl;
cout << endl;

cout << "Judul Buku = " << Data.judul << endl;
cout << "Pengarang = " << Data.pengarang << endl;
cout << "Tahun Terbit = " << Data.tahun << endl;
cout << "Harga = " << Data.harga << endl;

cin.get ();
}