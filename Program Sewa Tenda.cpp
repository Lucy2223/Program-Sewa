#include <iostream>

using namespace std;

struct Booking {
  char nama[10][10], tgl[10][10];
  string jawab;
  int jumlah, lama[10], total, menu, pilih, tenda, tipe[10];
} book;

void header(){
system("cls");
cout << "=====================\n"; 
cout << "SEWA TENDA PERNIKAHAN\n";
cout << "=====================\n"; 
}

void showListTenda() {
  cout << "\nList & Harga Tenda Pernikahan :\n\n";
  cout << "      || TIPE ||                                 || HARGA ||\n\n" ;
  cout << "1. Tenda Ekonomis                          Rp 300,000 per hari\n"; 
  cout << "2. Tenda Plafon (Terlaris)                 Rp 600,000 per hari\n";
  cout << "3. Tenda VIP (Favorit Pelanggan)           Rp 900,000 per hari\n"; 
  cout << "4. Tenda Gelombang Datar                   Rp 1,200,000 per hari\n";
  cout << "5. Tenda Sentris                           Rp 1,600,000 per hari\n";
  cout << "6. Tenda Para-Para                         Rp 1,900,000 per hari\n";
  cout << "7. Tenda Para-Para Kombinasi Flower Drop   Rp 2,200,000 per hari\n";
  cout << "8. Tenda Lorong Flower Drop                Rp 2,500,000 per hari\n";
}

double getHargaPerHari(int hargaTenda) {
  switch (hargaTenda) {
    case 1:
      return 300000;
    case 2:
      return 600000;
    case 3:
      return 900000;
    case 4:
      return 1200000;
    case 5:
      return 1600000;
    case 6:
      return 1900000;
    case 7:
      return 2200000;
    case 8:
      return 2500000;
    default:
      return 0;
  }
}

int main(){

// Menu
menu:
header();

cout << "\n1. List & Harga Tenda\n";
cout << "2. Sewa Tenda\n";
cout << "3. Lihat Detail Penyewaan\n";
cout << "4. Keluar\n";

cout << "\nSilahkan Pilih : "; cin >> book.pilih;

switch (book.pilih){

  case(1): // List Tenda

  showListTenda(); 

    cout << "\nkembali ke Menu utama (Ya/Tidak) ? "; cin >> book.jawab;

    if(book.jawab == "ya" || book.jawab == "Ya" ){
      goto menu;
    break;}

  case(2): // Sewa Tenda

  cout << "\nMasukkan jumlah tenda yang ingin disewa  : "; cin >> book.jumlah;

  for (int i = 0; i < book.jumlah; i++) {
    cout << "\nMasukkan nama penyewa                    : "; cin >> book.nama[i];
    cout << "\nMasukkan berapa hari penyewaan           : "; cin >> book.lama[i];
    cout << "\nMasukkan tanggal penyewaan (dd/mm/yy)    : "; cin >> book.tgl[i];

    showListTenda();

    int tipeIndex;
    cout << "\nPilih tipe tenda (1-8) : "; cin >> tipeIndex;
    book.tipe[i] = tipeIndex;
    goto menu;
    break;
  }

  case(3): // Penyewa

    for (int j = 0; j < book.jumlah; j++) {

      cout << "\n====================\n";
      cout << "  DETAIL PENYEWAAN\n";
      cout << "====================\n"; 

      cout << "\nNama pembooking    : " << book.nama[j] << endl << endl;
      cout << "Lama penyewaan     : " << book.lama[j] << " hari" << endl << endl;
      cout << "Tanggal sewa       : " << book.tgl[j]  << endl << endl;
      cout << "Tipe tenda         : " << book.tipe[j] << endl << endl;
      cout << "Jumlah tenda       : " << book.jumlah << endl << endl;

      double hargaPerHari = getHargaPerHari(book.tipe[j]);
      book.total = (hargaPerHari*book.jumlah) * book.lama[j];
      cout << "Biaya sewa         : Rp " << book.total << endl << endl;
      
    cout << "\nApakah ingin Kembali Ke Menu Utama (Ya/Tidak) ? "; cin >> book.jawab;
      if (book.jawab == "ya" || book.jawab == "YA" ) {
        goto menu;
        break; }
      
      break;
    }

  case(4): // Keluar

    cout << "\nTerima Kasih Telah Belanja Di Toko Kami\n\n";
  break;

  default: 

    cout << "\nPilihan Tidak Valid, Silahkan Pilih Menu 1 - 4 !\n";
    cout << "\nApakah ingin Kembali Ke Menu Utama (Ya/Tidak) ? "; cin >> book.jawab;
      if (book.jawab == "ya" || book.jawab == "YA" ) {
      goto menu;
      break; }
  
  }
}

