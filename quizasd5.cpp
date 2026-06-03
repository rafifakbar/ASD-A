#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string nip;
    string nama_karyawan;
    double gaji;
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

void add(string nip, string nama_karyawan, double gaji, queue *Q) {
    elemen *info;
    info = new elemen;

    info->Kontainer.nip = nip;
    info->Kontainer.nama_karyawan = nama_karyawan;
    info->Kontainer.gaji = gaji;
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
            cout << "NIP              : " << bantu->Kontainer.nip << endl;
            cout << "Nama Karyawan   : " << bantu->Kontainer.nama_karyawan << endl;
            cout << "Gaji Karyawan	  : " << bantu->Kontainer.gaji << endl;

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

    add("4523210666", "Budi", 10000, &Q);
    add("4523210777", "Susi", 20000, &Q);
    add("4523210888", "Nuri", 30000, &Q);
    add("4523210999", "Bimo", 40000, &Q);
    add("4523210555", "Arif", 50000, &Q);
    add("4523210444", "Rido", 60000, &Q);
    add("4523210222", "Ella", 70000, &Q);

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