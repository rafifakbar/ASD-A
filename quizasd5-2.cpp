#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string kode_brg;
    string nama_brg;
    double jmlstok;
} DataKaryawan;

typedef struct elm *alamatelm;

typedef struct elm {
    DataKaryawan Kontainer;
    alamatelm next;
} elemen;

typedef struct {
    elemen *first;
    elemen *last;
} queue;

void buatQkosong(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isKosong(queue Q) {
    bool hasil = false;
    if (Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

int jmlElemen(queue Q) {
    int hasil = 0;

    if (Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;

        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void add(string kode_brg, string nama_brg, double jmlstok, queue *Q) {
    elemen *info;
    info = new elemen;

    info->Kontainer.kode_brg = kode_brg;
    info->Kontainer.nama_brg = nama_brg;
    info->Kontainer.jmlstok = jmlstok;
    info->next = NULL;

    if ((*Q).first == NULL) {
        (*Q).first = info;
    } else {
        (*Q).last->next = info;
    }
    (*Q).last = info;
}

void del(queue *Q) {
    if ((*Q).first != NULL) {
        elemen *hapus = (*Q).first;

        if (jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        } else {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        delete hapus;
    }
}

void CetakQueue(queue Q) {
    if (Q.first != NULL) {
        cout << "MENAMPILKAN QUEUE" << endl;
        elemen *bantu = Q.first;
        int i = 1;

        while (bantu != NULL) {
            cout << "-----------------------------" << endl;
            cout << "Elemen ke        : " << i << endl;
            cout << "Kode Barang      : " << bantu->Kontainer.kode_brg << endl;
            cout << "Nama Barang      : " << bantu->Kontainer.nama_brg << endl;
            cout << "Jumlah Stok	  : " << bantu->Kontainer.jmlstok << endl;

            bantu = bantu->next;
            i++;
        }
        cout << "-----------------------------" << endl;
    } else {
        cout << "Queue Kosong" << endl;
    }
}

int main() {
    queue Q;
    buatQkosong(&Q);

    CetakQueue(Q);
    cout << endl;

    cout << "============================" << endl;

    add("11111", "Baju", 10000, &Q);
    add("22222", "Jaket", 20000, &Q);
    add("33333", "Celana", 30000, &Q);
    add("44444", "Sepatu", 40000, &Q);
    add("55555", "Sandal", 50000, &Q);
    

    CetakQueue(Q);

    cout << "============================" << endl;

    del(&Q);
    CetakQueue(Q);

    cout << endl;

    del(&Q);
    CetakQueue(Q);

    cout << "============================" << endl;

    return 0;
}