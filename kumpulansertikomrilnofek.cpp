#include <iostream>
#include <string>

using namespace std;

void menu(){
    int i=1, pil[20], harga[20], jum[20], total[20], total_s = 0, total_sd = 0, diskon = 0, bayar, kembalian, total_a = 0;
    string nama[20], menu[20], vc;
    char ulang;
    do {
        cout << "===========================================================\n";
        cout << "=================Program Kasir Honest Grup=================\n";
        cout << "===========================================================\n\n";
        cout << "========================================\n";
        cout << "1.Beef with Sambal Matah     :Rp. 57.000\n";
        cout << "2.Chicken with torched mentai:Rp. 44.000\n";
        cout << "3.Beef Teriyaki              :Rp. 55.000\n";
        cout << "4.Chicken With Japanese Curry:Rp. 44.000\n";
        cout << "5.Butter Chicken             :Rp. 45.000\n";
        cout << "6.Es Kopi Cheer Me Up        :Rp. 20.000\n";
        cout << "7.Es Kopi Latte Lowkey       :Rp. 23.000\n";
        cout << "8.Es Coklat Cozy             :Rp. 27.000\n";
        cout << "9.Es Manggo Yakult Booster   :Rp. 21.000\n";
        cout << "10.Mineral Water             :Rp. 5000\n";
        cout << "========================================\n";
        
        cout << "Masukan Nama Anda :";
        cin >> nama[i];
        cout << "==========================\n";
        cout << "Pilih Menu yang akan Di Pesan :";
        cin >> pil[i];
        cout << "==========================\n";

        switch (pil[i]){
            case 1:
                cout << "Anda Memesan : Beef with Sambal Matah     :Rp. 57.000\n";
                menu[i] = "Beef Sambal Matah";
                harga[i] = 57000;
                break;
            case 2:
                cout << "Anda Memesan : Chicken with torched mentai:Rp. 44.000\n";
                menu[i] = "Chicken torched mentai";
                harga[i] = 44000;
                break;
            case 3:
                cout << "Anda Memesan : Beef Teriyaki              :Rp. 55.000\n";
                menu[i] = "Beef Teriyaki";
                harga[i] = 55000;
                break;
            case 4:
                cout << "Anda Memesan : Chicken With Japanese Curry:Rp. 44.000\n";
                menu[i] = "Chicken Japanese Curry";
                harga[i] = 44000;
                break;
            case 5:
                cout << "Anda Memesan : Butter Chicken             :Rp. 45.000\n";
                menu[i] = "Butter Chicken";
                harga[i] = 45000;
                break;
            case 6:
                cout << "Anda Memesan : Es Kopi Cheer Me Up        :Rp. 20.000\n";
                menu[i] = "Es Kopi Cheer Me Up";
                harga[i] = 20000;
                break;
            case 7:
                cout << "Anda Memesan : Es Kopi Latte Lowkey       :Rp. 23.000\n";
                menu[i] = "Es Kopi Latte Lowkey";
                harga[i] = 23000;
                break;
            case 8:
                cout << "Anda Memesan : Es Coklat Cozy             :Rp. 27.000\n";
                menu[i] = "Es Coklat Cozy";
                harga[i] = 27000;
                break;
            case 9:
                cout << "Es Manggo Yakult Booster   :Rp. 21.000\n";
                menu[i] = "Es Manggo";
                harga[i] = 21000;
                break;
            case 10:
                cout << "Anda Memesan : Mineral Water             :Rp. 5.000\n";
                menu[i] = "Mineral Water";
                harga[i] = 5000;
                break;
            default:
                cout << "Menu Tidak Tersedia\n";
                exit(0);
        }

        cout << "Masukan Jumlah Menu Yang Mau DiPesan :";
        cin >> jum[i];
        cout << "=========================================\n";
        cout << "Apakah Ada Tambahan Lain :(Y|T)";
        cin >> ulang;
        total[i] = harga[i] * jum[i];
        total_s += total[i];
        i++;
    } while (ulang == 'Y' || ulang == 'y');

    cout << "Pesanan Atas Nama :" << nama[i-1] << endl;
    cout << "================================================================================\n";
    cout << "No       Menu Pesanan                Jumlah Beli          Harga           Total\n";
    for(int a = 1; a < i; a++) {
        cout << a << "\t" << menu[a] << "\t\t\t" << jum[a] << "\t\t" << harga[a] << "\t\t" << total[a] << endl;
    }
    cout << "Total Yang harus Di Bayar :" << total_s << endl;

    if (total_s >= 100000) {
        diskon = 40000;
    } else if (total_s >= 60000) {
        diskon = 10000;
    }

    cout << "=======================================\n";
    cout << "Total Setelah Diskon Promo :" << (total_s - diskon) << endl;
    cout << "=======================================\n";
    cout << "Masukan Kode Voucher (Jika Ada)(Y|T)";
    char ya;
    cin >> ya;
    cout << "=======================================\n";
    if (ya == 'y' || ya == 'Y') {
        cout << "Masukan Kode Voucher :";
        cin >> vc;
        if (vc == "honest20" || vc == "Honest20") {
            total_s = total_s - diskon - 20000;
            cout << "Jumlah Bayar Setelah Diskon :" << total_s << endl;
        } else if (vc == "Honest10" || vc == "honest10") {
            total_sd = total_s - diskon - ((total_s - diskon) * 10 / 100);
            cout << "Jumlah Bayar Setelah Diskon :" << total_sd << endl;
        } else if (vc == "honest15" || vc == "Honest15") {
            total_sd = total_s - diskon - ((total_s - diskon) * 15 / 100);
            cout << "Jumlah Bayar Setelah Diskon :" << total_sd << endl;
        } else {
            cout << "Voucher Tidak Tersedia!\n";
            exit(0);
        }
    } else {
        total_sd = total_s - diskon;
    }

    cout << "\n======================================\n";
    cout << "Bayar      :";
    cin >> bayar;
    cout << "=====================================================\n";
    kembalian = bayar - total_sd;
    if (kembalian >= 0) {
        cout << "Kembalian  :" << kembalian << endl;
        cout << "---Terima kasih Telah Berbelanja--- " << endl;
    } else {
        cout << "------Uang Anda Kurang !-----" << endl;
        cout << "=====================================================\n";
    }
    cout << "Apakah Anda Ingin Memesan lagi :(Y|T)";
    cin >> ulang;

} while (ulang == 'Y' || ulang == 'y');
}

void sewa(){
    string nama, kendaraan;
    int jenis, lama, harga, tambahan, total, total_s = 0;
    char ulang;
    do {
        cout << "===========================================================================" << endl;
        cout << "No          Jenis Kendaraan          Harga per 2 jam        Harga unuk Jam " << endl;
        cout << "                                                               Berikutnya  " << endl;
        cout << "1.           Sepeda Biasa               Rp.30.000              Rp.10.000   " << endl;
        cout << "2.           Sepeda Family              Rp.25.000              Rp.15.000   " << endl;
        cout << "3.           Otooped                    Rp.35.000              Rp.15.000   " << endl;
        cout << "===========================================================================" << endl;
        cout << endl;
        cout << "Silahkan Masukan Nama Anda :";
        cin >> nama;
        cout << "====================================================" << endl;
        cout << "Jenis Kendaraan Yang Di Pinjam :";
        cin >> jenis;
        cout << "====================================================" << endl;

        switch (jenis) {
            case 1:
                kendaraan = "Sepeda Biasa";
                harga = 30000;
                tambahan = 10000;
                break;
            case 2:
                kendaraan = "Sepeda Family";
                harga = 25000;
                tambahan = 15000;
                break;
            case 3:
                kendaraan = "Otooped";
                harga = 35000;
                tambahan = 15000;
                break;
            default:
                cout << "Kendaraan Tidak Tersedia!\n";
                exit(0);
        }

        cout << "Silahkan Masukan Durasi Peminjaman (dalam jam):";
        cin >> lama; 
        total = harga + ((lama - 2) * tambahan);
        total_s += total;

        cout << "Nama Penjunjung                 :" << nama << endl;
        cout << "================================" << endl;
        cout << "Jenis Kendaraan Yang Di pinjam :" << kendaraan << endl;
        cout << "================================" << endl;
        cout << "Lama Sewa                      :" << lama << endl;
        cout << "===============================" << endl;
        cout << "Tambahan                       :" << tambahan << endl;
        cout << "===============================" << endl;
        cout << endl;

        cout << "Total Bayar                       :" << total << endl;
        cout << "============================================" << endl;
        cout << "Apakah Anda Ingin Mengulang ?(Y|T):";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');
}

void bmi() {
    int jenis, hasil;
    float bmi, berat, tinggi, meter;
    char ulang;
    do {
        cout << "==================================================\n";
        cout << "==========Program Hitung Berat Badan==============\n";
        cout << "==================================================\n\n";
        cout << "==================================================\n";
        cout << "1.Laki-laki\n";
        cout << "2.Perempuan\n";
        cout << "==================================================\n";

        cout << "Inputkan Jenis Kelamin (1|2):";
        cin >> jenis;
        cout << "=============================\n";
        cout << "Input Berat Badan (kg)       :";
        cin >> berat;
        cout << "=============================\n";
        cout << "Input Tinggi Badan (cm)      :";
        cin >> tinggi;
        cout << "=============================\n";
        
        meter = tinggi / 100;
        bmi = berat / (meter * meter);

        switch (jenis) {
            case 1:
                hasil = ((tinggi - 100) - (0.10 * (tinggi - 100)));
                break;
            case 2:
                hasil = ((tinggi - 100) - (0.15 * (tinggi - 100)));
                break;
            default:
                cout << "Jenis Kelamin Tidak Ada!\n";
                continue;
        }

        if (bmi < 18.5) {
            cout << "Anda Tergolong Sebagai : Kurus\n";
        } else if (bmi >= 18.5 && bmi < 24.9) {
            cout << "Anda Tergolong Sebagai : Normal\n";
        } else if (bmi >= 25 && bmi < 29.9) {
            cout << "Anda Tergolong Sebagai : Overweight\n";
        } else {
            cout << "Anda Tergolong Sebagai : Obesitas\n";
        }

        cout << "\nBMI        :" << bmi << endl;
        cout << "==========================\n";
        cout << "Berat Badan Ideal Anda Menurut Rumus Broca :" << hasil << endl;
        cout << "============================================\n";
        cout << "Apakah Anda Ingin Mengulang Program (Y|T)?";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');
}

int main() {
    int pil, a = 1;
    string pass = "12", password;
    cout << "==================================\n";
    cout << "======Kumpulan Sertikom===========\n";
    cout << "==================================\n";

    do {
        cout << "Masukan Password :";
        cin >> password;
        system("cls");
        if (password == pass) {
            cout << "1. Program Menu\n";
            cout << "2. Program Sewa\n";
            cout << "3. Program Berat Badan\n";
            cout << "Masukan Pilihan Program :";
            cin >> pil;
            switch (pil) {
                case 1:
                    menu();
                    break;
                case 2:
                    sewa();
                    break;
                case 3:
                    bmi();
                    break;
                default:
                    exit(0);
            }
        }
        a++;
    } while (a <= 3);
    
    cout << "Anda Kami Blokir\n";
    return 0;
}
