#include "db.cpp"

#include <iostream>
#include <string>
using namespace std;

void tampilkanMenu();
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

totalPesanan *daftarPesanan    = nullptr; // array untuk menyimpan daftar pesanan dengan nilai nullptr
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

    // mengecek input valid
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // jika pilihan tidak sesuai, maka akan meminta pengguna untuk memilih ulang
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

    // menambahkan nasi sesuai pilihan
    switch (pilihan) {
        case 1 : tambahkanPesanan("Nasi", 1500); break;
        case 2 : tambahkanPesanan("Nasi", 1000); break;
        case 3 : tambahkanPesanan("Nasi", 0); break;
        default: cout << "Pilihan tidak valid"; break;
    }

    // menampilkan menu
    tampilkanMenu();

    return 0;
}

void tampilkanMenu() {
    do { // melakukan perulangan selama lanjutkanPesanan() bernilai true
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
            case 1 : pesanMakanan(); break; // memanggil fungsi pesanMakanan
            case 2 : pesanMinuman(); break; // memanggil fungsi pesanMinuman
            case 3 : tampilkanTotalPesanan(); break; // memanggil fungsi tampilkanTotalPesanan
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

    // Memeriksa apakah pengguna ingin memesan lagi
    if (lanjut == "Y" || lanjut == "y") { // jika pengguna memilih Y atau y maka akan mengembalikan nilai true
        return true;                      // Kembali ke menu utama
    } else if (lanjut == "N" || lanjut == "n") { // jika pengguna memilih N atau n
        if (daftarPesanan != nullptr) { // jika daftar pesanan tidak kosong maka akan menampilkan total
                                        // pesanan
            tampilkanTotalPesanan();    // menampilkan total pesanan
            return true;                // kembali ke menu utama
        } else {
            cout << "\nTerimaksih telah berkunjung"; // jika daftar pesanan kosong maka akan menampilkan pesan
            return false;                            // Keluar dari program
        }
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
        case 1:
            tampilkanMenuByJenis("Telur");
            break; // Memanggil fungsi tampilkanMenuByJenis dengan parameter Telur
        case 2:
            tampilkanMenuByJenis("Ayam");
            break; // Memanggil fungsi tampilkanMenuByJenis dengan parameter Ayam
        case 3:
            tampilkanMenuByJenis("Sayur");
            break; // Memanggil fungsi tampilkanMenuByJenis dengan parameter Sayur
        case 4:
            tampilkanMenuByJenis("Lain-lain");
            break; // Memanggil fungsi tampilkanMenuByJenis dengan parameter Lain-lain
        default: cout << "Pilihan tidak valid\n"; break; // Jika pilihan tidak valid
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
        case 1:
            tampilkanMenuByJenis("Air putih");
            break; // Memanggil fungsi tampilkanMenuByJenis dengan parameter Air putih
        case 2:
            tampilkanMenuByJenis("Teh");
            break; // Memanggil fungsi tampilkanMenuByJenis dengan parameter Teh
        default: cout << "Pilihan tidak valid\n"; break; // Jika pilihan tidak valid
    }
}

void tampilkanMenuByJenis(string jenisPilihan) {
    cout << "\n================================================\n";
    bool found = false;                   // untuk mengecek apakah ada makanan dengan jenis tersebut
    int  nomor = 1;
    for (const auto &item : menuList) {   // Melakukan perulangan untuk setiap item dalam menuList
        if (item.jenis == jenisPilihan) { // Jika item memiliki jenis yang sama dengan jenisPilihan
            cout << nomor << ". " << item.nama << " (Rp " << item.harga
                 << ")\n";                // Menampilkan nomor dan nama makanan
            nomor++;                      // Menambahkan 1 ke nomor
            found = true;                 // Mengubah found menjadi true
        }
    }
    if (!found) {
        cout << "Tidak ada makanan dengan jenis '" << jenisPilihan << "'.\n";
    } // Jika tidak ada makanan dengan jenis tersebut

    cout << "\nAnda mau pesan apa? (1-" << nomor - 1 << "): ";
    cin >> pilihan;

    if (cin.fail() || pilihan < 1 || pilihan >= nomor) { // Jika input tidak valid
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Pilihan tidak valid.\n";
    } else {
        int indeksMenu = 0;
        for (int i = 0; i < sizeof(menuList) / sizeof(menuList[0]);
             i++) {                                  // Melakukan perulangan untuk setiap item dalam menuList
            if (menuList[i].jenis == jenisPilihan) { // Jika item memiliki jenis yang sama dengan jenisPilihan
                if (--pilihan == 0) { // Mengurangi pilihan sebanyak 1, Jika pilihan adalah 1, maka pada
                                      // elemen yang pertama kali cocok, pilihan akan menjadi 0.
                    indeksMenu = i;   // Menyimpan indeks menu
                    break;
                }
            }
        }
        tambahkanPesanan(menuList[indeksMenu].nama, menuList[indeksMenu].harga); // Menambahkan pesanan
    }
}

void tambahkanPesanan(const string &nama, int harga) {
    if (jumlahPesanan == kapasitasPesanan) { // Jika kapasitas pesanan sudah penuh
        if (kapasitasPesanan == 0) {         // Jika kapasitas pesanan masih 0
            kapasitasPesanan = 2;            // Kapasitas pesanan diatur ke 2
        } else {
            kapasitasPesanan *= 2;           // jika tidak, maka Kapasitas pesanan dikalikan dengan 2
        }

        totalPesanan *temp = new totalPesanan[kapasitasPesanan];                // Membuat array baru
        for (int i = 0; i < jumlahPesanan; i++) { temp[i] = daftarPesanan[i]; } // Menyalin daftar pesanan
        delete[] daftarPesanan;                     // Menghapus daftar pesanan lama
        daftarPesanan = temp;                       // Mengganti daftar pesanan dengan array baru
    }
    daftarPesanan[jumlahPesanan++] = {nama, harga}; // Menambahkan pesanan
    cout << "\nPesanan '" << nama << "' berhasil ditambahkan ke daftar pesanan.\n";
}

void tampilkanTotalPesanan() {
    cout << "\n================================================\n";
    cout << "Daftar Pesanan Anda:\n";
    if (jumlahPesanan == 0) {
        cout << "Belum ada pesanan.\n";
        return;
    }
    for (int i = 0; i < jumlahPesanan; i++) { // Melakukan perulangan untuk setiap pesanan
        cout << i + 1 << ". " << daftarPesanan[i].nama << " (Rp " << daftarPesanan[i].harga << ")\n";
        totalHarga += daftarPesanan[i].harga; // Menambahkan total harga
    }
    cout << "Total Harga: Rp " << totalHarga << "\n";

    bayarPesanan(); // memanggil fungsi bayarPesanan
}

void bayarPesanan() {
    cout << "\n================================================\n";
    cout << "Apakah anda ingin membayar pesanan? (y/n): ";
    cin >> lanjut;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }

    if (lanjut == "Y" || lanjut == "y") { // Jika pengguna memilih Y atau y
        cout << "\nTotal Harga: Rp " << totalHarga << endl;

        if (totalHarga > uang) {          // Jika total harga lebih besar dari uang
            cout << "Uang anda tidak cukup." << endl;
            cout << "Silahkan kembali lagi kalau ada uangnya." << endl;
            delete[] daftarPesanan;
            exit(0);
        } else {
            uang -= totalHarga; // Mengurangi uang dengan total harga
            cout << "Uang Anda: Rp " << uang << endl;
            cout << "\nTerimakasih telah berkunjung ^_^." << endl;
            delete[] daftarPesanan;
            exit(0);
        }
    } else if (lanjut == "N" || lanjut == "n") { // Jika pengguna memilih N atau n
        return;                                  // Mengulang program
    } else {
        cout << "\nInput tidak valid. Silakan coba lagi.";
        return;                                  // Ulangi  jika input tidak valid
    }
}
