#include <iostream>
using namespace std;

class Desimal{
    int angka1, angka2, i;
    public:
    Desimal(){angka1=angka2=i=0;}
    // Fungsi untuk mengonversi bilangan desimal ke oktal
    void desimalKeOktal() {
        cout << "Masukkan bilangan desimal: ";
        cin >> angka1;

        angka2 = 0; 
        i = 1;
        
        while (angka1 != 0) {
            int sisa = angka1 % 8;
            angka2 += sisa * i;
            angka1 /= 8;
            i *= 10;
        }

        print();
    }
    
    //Fungsi untuk print hasil
    void print(){
        cout << "Hasil konversi: " << angka2 << endl;
    }
};

class Oktal{
    int angka1, angka2, i;
    public:
    Oktal(){angka1=angka2=i=0;}

    // Fungsi untuk menghitung perpangkatan bilangan
    int pangkat(int basis, int eksponen) {
        int hasil = 1;
        for (int i = 0; i < eksponen; ++i) {
            hasil *= basis;
        }
        return hasil;
    }

    // Fungsi untuk mengonversi bilangan oktal ke desimal
    int oktalKeDesimal() {
        cout << "Masukkan bilangan oktal: ";
        cin >> angka1; //bilangan oktal

        angka2 = 0; //bilangan desimal 
        i = 0;
        int sisa;
        while (angka1 != 0) {
            sisa = angka1 % 10;
            if (sisa == 8 || sisa == 9){
                cout << "Angka tidak valid!";
                break;
            }
            angka2 += sisa * pangkat(8, i);
            ++i;
            angka1 /= 10;
        }
        if(sisa == 8 || sisa == 9){
            return 0;
        } else{
            print();
        }
    }

    void print(){
        cout << "Hasil konversi: " << angka2 << endl;
    }
};


int main() {
    Desimal d;
    Oktal o;

    int pilihanAwal;
    cout << "Pilih Format Bilangan Masukkan:\n";
    cout << "1. Desimal\n";
    cout << "2. Biner\n";
    cout << "3. Oktal\n";
    cout << "4. Heksadesimal\n";
    cout << "Pilih: ";
    cin >> pilihanAwal;

    int pilihanAkhir;

    switch (pilihanAwal)
    {
    //Desimal
    case 1:
        //menu
        cout << "Pilih Format Bilangan Konversi:\n";
        cout << "1. Biner\n";
        cout << "2. Oktal\n";
        cout << "3. Heksadesimal\n";
        cout << "Pilih: ";
        cin >> pilihanAkhir;
        //case
        switch (pilihanAkhir)
        {
            case 1:
                d.desimalKeOktal();
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        break;
    //oktal
    case 2:
        //menu
        cout << "Pilih Format Bilangan Konversi:\n";
        cout << "1. Desimal\n";
        cout << "2. Biner\n";
        cout << "3. Heksadesimal\n";
        cout << "Pilih: ";
        cin >> pilihanAkhir;
        //case
        switch (pilihanAkhir)
        {
            case 1:
                o.oktalKeDesimal();
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
    }

    return 0;
}
