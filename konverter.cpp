#include <iostream>
#include <cmath>  
#include <string>
using namespace std;

template <typename T>
//Class untuk Implementasi Struktur Data Vector
class Vector {
private:
    T* data;
    int capacity;
    int size;

public:
    Vector() : data(nullptr), capacity(0), size(0) {}

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T* newData = new T[newCapacity];
            
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        
        data[size] = value;
        size++;
    }

    T& operator[](int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        throw std::out_of_range("Index out of range");
    }

    const T& operator[](int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        throw std::out_of_range("Index out of range");
    }

    T front() const {
        if (size > 0) {
            return data[0];
        }
        throw std::out_of_range("Vector is empty");
    }

    T back() const {
        if (size > 0) {
            return data[size - 1];
        }
        throw std::out_of_range("Vector is empty");
    }

    void pop_back() {
        if (size > 0) {
            size--;
        } else {
            throw std::out_of_range("Vector is empty");
        }
    }

    void erase(T index) {
        if (index >= 0 && index < size) {
            for (T i = index; i < size - 1; i++) {
                data[i] = data[i + 1];
            }
            size--;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    bool empty() const {
        return (size == 0);
    }

    void clear() {
        delete[] data;
        data = nullptr;
        capacity = 0;
        size = 0;
    }
    int getSize() const {
        return size;
    }

    T* begin() {
        return data;
    }

    const T* begin() const {
        return data;
    }

    T* end() {
        return data + size;
    }

    const T* end() const {
        return data + size;
    }
};

// Class Untuk Implementasi Struktur Data Stack
class Stack {
	private:
		Vector<int> dt;
	public:
		void push(int n){
			dt.push_back(n);
		}
		int pop(){
			int n = dt.back();
			dt.pop_back();
			return n;
		}
		int top(){
			return dt.back();
		}
		int size(){
			return dt.getSize();
		}
		bool empty(){
			return dt.empty();
		}
};

// Class Untuk Implementasi Struktur Data Queue
class Queue{
	private: 
		Vector<int> dt;
	public: 
		void push(int n){
			dt.push_back(n);
		}
		int pop() {
        int n = dt.front();
        dt.erase(0);
        return n;
    }
		int front(){
			return dt.front();
		}
		int size(){
			return dt.getSize();
		}
		bool empty(){
			return dt.empty();
		}
};

// Class Desimal
class Desimal{
    string keluaran;
    Vector<int> historyMasukkan;
    Vector<string> output;
    public:
    Desimal(){
        keluaran = "";
    }

    // Fungsi untuk mengonversi bilangan desimal ke biner
    string desimalKeBiner(int input){
		Stack binerStack; 
        int tmp; 
        int bin = 0; 
		//convert; 
		while(input != 0){
			tmp = input%2;
			binerStack.push(tmp); 
			input = input/2; 
		}
		    // cetak; 
		while(!binerStack.empty()){
		        bin= bin*10 +binerStack.pop();
		    }
		keluaran = to_string(bin);
        output.push_back(keluaran);
		return keluaran; 
		
	}

    // Fungsi untuk mengonversi bilangan desimal ke oktal
    string desimalKeOktal(int input) {
        Stack octalStack;
        historyMasukkan.push_back(input);

        keluaran = "";

        while (input > 0) {
            int sisa = input % 8;
            octalStack.push(sisa);            
            input /= 8;
        }

        while (!octalStack.empty()) {
            keluaran += to_string(octalStack.top());
            octalStack.pop();
        }

        output.push_back(keluaran);
        return keluaran;
    }
    
    // Fungsi untuk mengonversi bilangan desimal ke Heksadesimal
    string desimalKeHeksa(int input){
        Stack heksaStack;
        historyMasukkan.push_back(input);

        keluaran = "";

        while(input > 0){
        int remainder = input % 16;
        // koversi digit ke ascii
        if(remainder < 10){
            heksaStack.push(remainder + '0');
        }else{
            heksaStack.push(remainder + 55);
        }
        input/=16;
        }
        // membangun string heksa dari stack
        while(!heksaStack.empty()){
            keluaran += heksaStack.top();
            heksaStack.pop();
        }
        
        output.push_back(keluaran);
        return keluaran;
	}

    // Fungsi untuk mencetak history masukkan bilangan desimal
    void printHistory(){
        cout << "Desimal: " << endl;
        for(int i=0; i < historyMasukkan.getSize(); i++){
            if (i == 0)
                cout << historyMasukkan[i];
            else
                cout << "," << " " << historyMasukkan[i] ;
        }
        cout << endl;
    }

    // Fungsi untuk mencetak hasil konversi
    void printHasil(){
        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < output.getSize(); i++) {
            if (i == 0) {
                cout << "Biner: " << output[i] << endl;
            } else if (i == 1) {
                cout << "Oktal: " << output[i] << endl;
            } else {
                cout << "Heksa: " << output[i] << endl;
            }
        }
        output.clear();
    }
};

// Class Biner
class Biner{
    string keluaran;
    Vector<int> historyMasukkan;
    Vector<string> output;
    public:
    Biner(){
        keluaran = "";
    }

    // Fungsi untuk mengonversi bilangan biner ke desimal
    string binerKeDesimal(int input){
	    Queue binerQueue; 
        int tmp; 
	    while(input!=0 ){
	        tmp = input%10; 
	        binerQueue.push(tmp); 
	        input = input/10; 
	    }
	    
	    int dec =0; int i= 0; int x;  
	    while(!binerQueue.empty()){
	        x= binerQueue.front();
	        dec =dec + x*pow(2,i); 
	        i++;
	        binerQueue.pop();
	    }
        
        keluaran = to_string(dec);
        output.push_back(keluaran);
	    return keluaran;
	}

    // Fungsi untuk mengonversi bilangan biner ke oktal
    void binerKeOktal(){
        int masukkan = stoi(output[0]);
        Desimal d;
        keluaran = d.desimalKeOktal(masukkan);
        output.push_back(keluaran);
    }

    void binerKeHeksa(){
        int masukkan = stoi(output[0]);
        Desimal d;
        keluaran = d.desimalKeHeksa(masukkan);
        output.push_back(keluaran);
    }

     // Fungsi untuk mencetak history masukkan bilangan oktal
    void printHistory(){
        cout << "Oktal: " << endl;
        for(int i=0; i < historyMasukkan.getSize(); i++){
            if (i == 0)
                cout << historyMasukkan[i];
            else
                cout << "," << " " << historyMasukkan[i] ;
        }
        cout << endl;
    }

    // Fungsi untuk mencetak hasil konversi
    void printHasil(){
        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < output.getSize(); i++) {
            if (i == 0) {
                cout << "Desimal: " << output[i] << endl;
            } else if (i == 1) {
                cout << "Oktal: " << output[i] << endl;
            } else {
                cout << "Heksa: " << output[i] << endl;
            }
        }
        output.clear();
    }
};

// Class Oktal
class Oktal{
    string keluaran;
    Vector<int> historyMasukkan;
    Vector<string> output;
    public:
    Oktal(){
        keluaran = "";
    }

    // Fungsi untuk mengonversi bilangan oktal ke desimal
    string oktalKeDesimal(int input) {

        historyMasukkan.push_back(input);
        int sisa = 0;
        int hasil = 0;

        for(int i = 0; input > 0; ++i){
            sisa = input % 10;
            if (sisa == 8 || sisa == 9){
                cout << "Angka tidak valid!" << endl;
                break;
            }
            hasil += sisa * pow(8, i);
            input /= 10;
        }
        
        keluaran = to_string(hasil);

        if(sisa == 8 || sisa == 9){
            return 0;
        } else{
            output.push_back(keluaran);
            return keluaran;
        }
    }

    // Fungsi untuk mengonversi bilangan oktal ke biner
    void oktalKeBiner(){
        int masukkan = stoi(output[0]);
        Desimal d;
        keluaran = d.desimalKeBiner(masukkan);
        output.push_back(keluaran);
    }

    // Fungsi untuk mengonversi bilangan oktal ke heksa
    void oktalKeHeksa() {
        int masukkan = stoi(output[0]);
        Desimal d;
        keluaran = d.desimalKeHeksa(masukkan);
        output.push_back(keluaran);
    }

    // Fungsi untuk mencetak history masukkan bilangan oktal
    void printHistory(){
        cout << "Oktal: " << endl;
        for(int i=0; i < historyMasukkan.getSize(); i++){
            if (i == 0)
                cout << historyMasukkan[i];
            else
                cout << "," << " " << historyMasukkan[i] ;
        }
        cout << endl;
    }

    // Fungsi untuk mencetak hasil konversi
    void printHasil(){
        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < output.getSize(); i++) {
            if (i == 0) {
                cout << "Desimal: " << output[i] << endl;
            } else if (i == 1) {
                cout << "Biner: " << output[i] << endl;
            } else {
                cout << "Heksa: " << output[i] << endl;
            }
        }
        output.clear();
    }
};

// Class Heksa
class Heksa{
    int keluaran;
    Vector<int> historyMasukkan;
    Vector<int> output;
    public:
    Heksa(){
        keluaran = 0;
    }

    // Fungsi untuk mengonversi bilangan heksa ke desimal
    int heksaKeDesimal(const string& hexadecimal) {
		    Queue heksaQueue;
		    for (char c : hexadecimal) {
		        heksaQueue.push(c);
		    }

		    keluaran = 0;
		    int power = hexadecimal.length() - 1;

		    while (!heksaQueue.empty()) {
		        char digit = heksaQueue.front();
		        heksaQueue.pop();

		        int value;
		        if (isdigit(digit)) {
		            value = digit - '0';
		        } else {
		            value = toupper(digit) - 'A' + 10;
		        }

		        keluaran += value * pow(16, power);
		        power--;
		    }

            output.push_back(keluaran);
		    return keluaran;
		}

    // Fungsi untuk mengonversi bilangan heksa ke biner
    void heksaKeBiner(){
        Desimal d;
        keluaran = stoi(d.desimalKeBiner(output[0]));
        output.push_back(keluaran);
    }

    // Fungsi untuk mengonversi bilangan heksa ke oktal
    void heksaKeOktal(){
        Desimal d;
        keluaran = stoi(d.desimalKeOktal(output[0]));
        output.push_back(keluaran);
    }

    // Fungsi untuk mencetak history masukkan bilangan oktal
    void printHistory(){
        cout << "Oktal: " << endl;
        for(int i=0; i < historyMasukkan.getSize(); i++){
            if (i == 0)
                cout << historyMasukkan[i];
            else
                cout << "," << " " << historyMasukkan[i] ;
        }
        cout << endl;
    }

    // Fungsi untuk mencetak hasil konversi
    void printHasil(){
        cout << "Hasil konversi: " << endl;
        for (int i = 0; i < output.getSize(); i++) {
            if (i == 0) {
                cout << "Desimal: " << output[i] << endl;
            } else if (i == 1) {
                cout << "Biner: " << output[i] << endl;
            } else {
                cout << "Oktal: " << output[i] << endl;
            }
        }
        output.clear();
    }
};

int main(){
    Desimal d;
    Biner b;
    Oktal o;
    Heksa h;
    char ch;
begin:
    int pilihanAwal, masukkan;
    string input;
    cout << "Pilih Format Bilangan Masukkan:\n";
    cout << "1. Desimal\n";
    cout << "2. Biner\n";
    cout << "3. Oktal\n";
    cout << "4. Heksadesimal\n";
    // cout << "5. History Konversi\n";
    cout << "Pilih: ";
    cin >> pilihanAwal;

    switch (pilihanAwal)
    {
    //Desimal
    case 1:
        cout << "Masukkan bilangan desimal: ";
        cin >> masukkan;
        d.desimalKeBiner(masukkan);
        d.desimalKeOktal(masukkan);
        d.desimalKeHeksa(masukkan);
        d.printHasil();
        break;
    case 2:
        cout << "Masukkan bilangan biner: ";
        cin >> masukkan;
        b.binerKeDesimal(masukkan);
        b.binerKeOktal();
        b.binerKeHeksa();
        b.printHasil();
        break;
    //oktal
    case 3:
        cout << "Masukkan bilangan oktal: ";
        cin >> masukkan;
        o.oktalKeDesimal(masukkan);
        o.oktalKeBiner();
        o.oktalKeHeksa();
        o.printHasil();
        break;
    //heksa
    case 4:
        cout << "Masukkan bilangan heksadesimal: ";
        cin >> input;
        h.heksaKeDesimal(input);
        h.heksaKeBiner();
        h.heksaKeOktal();
        h.printHasil();
        break;
    
    // //history
    // case 5:
    //     int pilihanHistory;
    //     cout << "Pilih History Format Bilangan yang ingin dilihat:\n";
    //     cout << "1. Desimal\n";
    //     cout << "2. Oktal\n";
    //     cout << "3. Heksadesimal\n";
    //     cout << "4. History Konversi\n";
    //     cout << "Pilih: ";
    //     cin >> pilihanHistory;
    //     switch (pilihanHistory)
    //     {
    //     case 1:
    //         d.printHistory();
    //         break;
    //     // case 2:
    //     //     o.printHistory();
    //     //     break;
    //     // case 3:
    //     //     h.printHistory();
    //     //     break;
    //     default:
    //         break;
    //     }
    //     break;
    default:
        cout << "Pilihan tidak valid." << endl;
        break;
    }

    cout << "Apakah anda ingin lanjut mengonversi? (y/n)" << endl;
    fflush(stdin);
    cin >> ch;
    if(ch=='y'||ch=='Y')
        goto begin;
    else
        cout << "Terima Kasih <3";

    return 0;
}