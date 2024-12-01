#include "db.cpp"

#include <iostream>
#include <string>
using namespace std;

void menu();
bool lanjutkanPesanan();
void tampilkanMenuByJenis(string jenisPilihan);
void pesanMakanan();
void pesanMinuman();
void tambahkanPesanan(const string &nama, int harga);
void tampilkanTotalPesanan();
void bayarPesanan();

int    pilihMenu;
string lanjut;
int    pilihan;
int    uang       = 10000;
int    totalHarga = 0;

totalPesanan *daftarPesanan    = nullptr;
int           jumlahPesanan    = 0;
int           kapasitasPesanan = 0;

int main() {
    cout << "================================================\n"
         << "\t\tWARTEG KEBUMEN \n"
         << "================================================\n"
         << endl;

    cout << "Selamat datang di Warteg Kebumen!" << endl;
    cout << "Apakah anda ingin menggunakan nasi?\n";

    cout << "1. Ya (Rp 1.500)\n"
         << "2. Setengah (Rp 1.000)\n"
         << "3. Tidak\n"
         << endl;

    cout << "Pilih (1-3): ";
    cin >> pilihan;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }

    do {
        if (pilihan < 1 || pilihan > 3) {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            cout << "\nPilih nasi (1-3): ";
            cin >> pilihan;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
    } while (pilihan < 1 || pilihan > 3);

    switch (pilihan) {
        case 1 : tambahkanPesanan("Nasi", 1500); break;
        case 2 : tambahkanPesanan("Nasi", 1000); break;
        case 3 : tambahkanPesanan("Nasi", 0); break;
        default: cout << "Pilihan tidak valid"; break;
    }

    menu();

    return 0;
}

void menu() {
    do {
        cout << "\n================================================\n";
        cout << "Silahkan pilih menu di bawah ini\n";

        cout << "1. Makanan\n"
             << "2. Minuman\n"
             << "3. Lihat Total Pesanan\n"
             << "4. Keluar\n"
             << endl;

        cout << "Pilih menu (1-4): ";
        cin >> pilihMenu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (pilihMenu) {
            case 1 : pesanMakanan(); break;
            case 2 : pesanMinuman(); break;
            case 3 : tampilkanTotalPesanan(); break;
            case 4 : cout << "Terimakasih telah berkunjung\n"; return;
            default: cout << "Pilihan tidak valid\n"; break;
        }
    } while (lanjutkanPesanan());
}

bool lanjutkanPesanan() {
    cout << "\n================================================\n";
    cout << "Apakah anda ingin memesan lagi? (y/n): ";
    cin >> lanjut;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Input tidak valid, silakan pilih Y atau N." << endl;
        return lanjutkanPesanan(); // Meminta input ulang
    }

    if (lanjut == "Y" || lanjut == "y") {
        return true; // Kembali ke menu utama
    } else if (lanjut == "N" || lanjut == "n") {
        if (daftarPesanan != nullptr) {
            tampilkanTotalPesanan();
        } else {
            cout << "\nTerimaksih telah berkunjung";
        }
        return false;              // Keluar dari program
    } else {
        cout << "\nInput tidak valid. Silakan coba lagi.";
        return lanjutkanPesanan(); // Ulangi  jika input tidak valid
    }
}

void pesanMakanan() {
    cout << "\n================================================\n";
    cout << "Pilih jenis makanan:\n";

    cout << "1. Telur\n"
         << "2. Ayam\n"
         << "3. Sayur\n"
         << "4. Lain-lain\n"
         << endl;

    cout << "Pilih jenis (1-4): ";
    cin >> pilihMenu;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }

    switch (pilihMenu) {
        case 1 : tampilkanMenuByJenis("Telur"); break;
        case 2 : tampilkanMenuByJenis("Ayam"); break;
        case 3 : tampilkanMenuByJenis("Sayur"); break;
        case 4 : tampilkanMenuByJenis("Lain-lain"); break;
        default: cout << "Pilihan tidak valid\n"; break;
    }
}

void pesanMinuman() {
    cout << "\n================================================\n";
    cout << "Pilih jenis minuman:\n";

    cout << "1. Air putih\n"
         << "2. Teh\n"
         << endl;

    cout << "Pilih jenis (1-2): ";
    cin >> pilihMenu;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }

    switch (pilihMenu) {
        case 1 : tampilkanMenuByJenis("Air putih"); break;
        case 2 : tampilkanMenuByJenis("Teh"); break;
        default: cout << "Pilihan tidak valid\n"; break;
    }
}

void tampilkanMenuByJenis(string jenisPilihan) {
    cout << "\n================================================\n";
    bool found = false; // Flag untuk mengecek apakah ada makanan dengan jenis tersebut
    int  nomor = 1;
    for (const auto &item : menuList) {
        if (item.jenis == jenisPilihan) {
            cout << nomor << ". " << item.nama << " (Rp " << item.harga << ")\n";
            nomor++;
            found = true;
        }
    }
    if (!found) { cout << "Tidak ada makanan dengan jenis '" << jenisPilihan << "'.\n"; }

    cout << "\nAnda mau pesan apa? (1-" << nomor - 1 << "): ";
    cin >> pilihan;

    if (cin.fail() || pilihan < 1 || pilihan >= nomor) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Pilihan tidak valid.\n";
    } else {
        int indeksMenu = 0;
        for (int i = 0; i < sizeof(menuList) / sizeof(menuList[0]); i++) {
            if (menuList[i].jenis == jenisPilihan) {
                if (--pilihan == 0) {
                    indeksMenu = i;
                    break;
                }
            }
        }
        tambahkanPesanan(menuList[indeksMenu].nama, menuList[indeksMenu].harga);
    }
}

void tambahkanPesanan(const string &nama, int harga) {
    if (jumlahPesanan == kapasitasPesanan) {
        if (kapasitasPesanan == 0) {
            kapasitasPesanan = 2;
        } else {
            kapasitasPesanan *= 2;
        }

        totalPesanan *temp = new totalPesanan[kapasitasPesanan];
        for (int i = 0; i < jumlahPesanan; i++) { temp[i] = daftarPesanan[i]; }
        delete[] daftarPesanan;
        daftarPesanan = temp;
    }
    daftarPesanan[jumlahPesanan++] = {nama, harga};
    cout << "\nPesanan '" << nama << "' berhasil ditambahkan ke daftar pesanan.\n";
}

void tampilkanTotalPesanan() {
    cout << "\n================================================\n";
    cout << "Daftar Pesanan Anda:\n";
    if (jumlahPesanan == 0) {
        cout << "Belum ada pesanan.\n";
        return;
    }
    for (int i = 0; i < jumlahPesanan; i++) {
        cout << i + 1 << ". " << daftarPesanan[i].nama << " (Rp " << daftarPesanan[i].harga << ")\n";
        totalHarga += daftarPesanan[i].harga;
    }
    cout << "Total Harga: Rp " << totalHarga << "\n";

    bayarPesanan();
}

void bayarPesanan() {
    cout << "\n================================================\n";
    cout << "Apakah anda ingin membayar pesanan? (y/n): ";
    cin >> lanjut;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }

    if (lanjut == "Y" || lanjut == "y") {
        cout << "\nTotal Harga: Rp " << totalHarga << endl;

        if (totalHarga > uang) {
            cout << "Uang anda tidak cukup." << endl;
            cout << "Silahkan kembali lagi kalau ada uangnya." << endl;
            delete[] daftarPesanan;
            exit(0);
        } else {
            uang -= totalHarga;
            cout << "Uang Anda: Rp " << uang << endl;
            cout << "\nTerimakasih telah berkunjung ^_^." << endl;
            delete[] daftarPesanan;
            exit(0);
        }
    } else if (lanjut == "N" || lanjut == "n") {
        return;
    } else {
        cout << "\nInput tidak valid. Silakan coba lagi.";
        return; // Ulangi  jika input tidak valid
    }
}
