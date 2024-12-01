#include <string>
using namespace std;

struct menu {
        string nama;
        int    harga;
        string kategori;
        string jenis;
};

struct totalPesanan {
        string nama;
        int    harga;
};

menu menuList[] = {
    {     "Telur dadar",  1500, "Makanan",     "Telur"},
    {     "Telur bulat",  1500, "Makanan",     "Telur"},
    {      "Telur asin",  1500, "Makanan",     "Telur"},
    {     "Ayam goreng",  1500, "Makanan",      "Ayam"},
    {      "Ayam bakar",  1500, "Makanan",      "Ayam"},
    {       "Opor ayam", 15000, "Makanan",      "Ayam"},
    {          "Capcay",  1500, "Makanan",     "Sayur"},
    {     "Sayur bayam",  1500, "Makanan",     "Sayur"},
    {       "Sayur sop",  1500, "Makanan",     "Sayur"},
    {             "Mie",  1200, "Makanan", "Lain-lain"},
    {        "Perkedel",  1000, "Makanan", "Lain-lain"},
    { "Air putih biasa",  1000, "Minuman", "Air putih"},
    {"Air putih dingin",  1000, "Minuman", "Air putih"},
    {    "Es teh manis",  1000, "Minuman",       "Teh"},
    {       "Teh tawar",  1000, "Minuman",       "Teh"},
};
