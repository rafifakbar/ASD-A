include <iostream>
using namespace std;

typedef struct {
string npm;
string nama_mhs;
double nilai;
}NilaiMK;

typedef struct elm *alamatelm;
typedef struct elm {
NilaiMK Kontainer;
alamatelm next;
}elemen;

typedef struct {
elemen* top;
}
stack;

void buatSTkosong (stack *S) {
(*S).top = NULL;
}

int isKosong(stack S){
bool hasil = false;

if(S.top == NULL) {
hasil = true;
}
return hasil;
}

int jmlElemen (stack S) {
int hasil = 0;

if(S.top != NULL) {
elemen *bantu;
bantu = S.top;

while(bantu != NULL){
hasil = hasil + 1;
bantu = bantu -> next;
}
}
return hasil;

void push (string npm, string nama_mhs, double nilai, stack *S) {
elemen *info;
info = new elemen;
info -> Kontainer.npm = npm;
info -> Kontainer.nama_mhs = nama_mhs;
info -> Kontainer.nilai = nilai;

if ((*S).top == NULL) {
cout << "Stack Penuh" << endl;
info -> next = NULL;
}
else{
info -> next = (*S).top;
}
(*S).top = info;
info = NULL
}

void Pop(stack *S) {
if ((*S).top != NULL) {
elemen *hapus = (*S).top;
if(jmlElemen(*S) == 1){
(*S).top = NULL;
}
else {
(*S).top = (*S).top -> next;
}
hapus -> next = NULL;
delete hapus;
}
else {
cout << "Stack Kosong" << emdl;
}
}

void CetakStack(stack S)
{
if (S.top != NULL)
{
cout << " MENMPILKAN STACK " << endl ;
elemen *bantu = S.top;
int i = 1;
while (bantu != NULL)
{
cout << "===================================" << endl;
cout << " Elemen ke                   : " << i << endl;
cout << " Nomor Pokok Mahasiswa       : " << bantu -> Kontainer.npm << endl;
cout << " Nama Mahasiswa              : " << bantu -> Kontainer.nama_mhs << endl;
cout << " Nilai Mahasiswa             : " << bantu -> Kontainer.nilai << endl;

bantu = bantu -> next ;
i=i +1;
}
cout << "===================================" << endl;
}
else 
{
cout << "Stack Kosong" << endl;
}
}

int main () {
stack S;

buatSTkosong(&S);
CetakStack(S);
cout << endl;
cout << endl;
cout << "============================" << endl;
push ("4525210001", "A", 99.11, &S); 
push ("4525210002", "B", 99.22, &S); 
push ("4525210003", "D", 99.33, &S); 
push ("4525210004", "F", 99.44, &S);
push ("4525210005", "G", 99.55, &S); 
push ("4525210006", "H", 99.66, &S); 
push ("4525210007", "I", 99.77, &S); 
CetakStack (S);
cout << "=============================" << endl;
cout << endl;
cout << endl;
Pop (&S);
CetakStack(S);
cout << endl;
cout << endl;
Pop (&S);
CetakStack(S);
cout << "=============================" << endl;
eturn 0;
}
