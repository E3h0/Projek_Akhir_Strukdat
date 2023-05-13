#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// Class Untuk Implementasi Struktur Data
template <typename T>
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

template <class T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int count;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(T value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        count--;

        if (isEmpty()) {
            rearNode = nullptr;
        }
    }

    T front() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            exit(1);
        }
        return frontNode->data;
    }

    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }
};

// Class untuk Konversi bilangan
class Converter{
	public: 
		// Decimal ke heksadesimal
		string DecToHex(int dec){
			Stack st;
			string res = "0x";
			while(dec > 0){
				int remainder = dec % 16;

				// koversi digit ke ascii
				if(remainder < 10){
					st.push(static_cast<char>(remainder + 48));
				}else{
					st.push(static_cast<char>(remainder + 55));
				}
				dec/=16;
			}
			// membangun string heksa dari stack
			while(!st.empty()){
				res += st.top();
				st.pop();
			}
			return res;
		}
		// Heksadesimal ke Decimal
		int HexToDec(const string& hexadecimal) {
		    Queue<char> hexQueue;
		    for (char c : hexadecimal) {
		    	char hex = toupper(c);
		        hexQueue.enqueue(hex);
		    }

		    int decimal = 0;
		    int power = hexadecimal.length() - 1;

		    while (!hexQueue.isEmpty()) {
		        char digit = hexQueue.front();
		        hexQueue.dequeue();

		        int value;
		        if (isdigit(digit)) {
		            value = digit - '0';
		        } else {
		            value = toupper(digit) - 'A' + 10;
		        }

		        decimal += value * pow(16, power);
		        power--;
		    }

		    return decimal;
		}
	
	//Decimal To Biner
	int DecToBin(int n){
		Stack st; int tmp; int bin =0; 
		//convert; 
		while(n!= 0){
			tmp = n%2;
			st.push(tmp); 
			n = n/2; 
		}
		    // cetak; 
		while(!st.empty()){
		        bin= bin*10 +st.pop();
		    }
		
		return bin; 
		
	}
	
	//Biner To Decimal
	int BinToDec(int n){
	    Queue<int> qu; int tmp; 
	    while(n!=0 ){
	        tmp = n%10; 
	        qu.enqueue(tmp); 
	        n= n/10; 
	    }
	    
	    //cetak decimal
	    int dec =0; int i= 0; int x;  
	    while(!qu.isEmpty()){
	        x= qu.front();
	        dec =dec+ x*pow(2,i); 
	        i++;
	        qu.dequeue();
	    }
	    return dec;
	}

	//Decimal ke Octal
	string DecToOc(int input) {
        Stack octalStack;
        string keluaran = "";

        while (input > 0) {
            int sisa = input % 8;
            octalStack.push(sisa);            
            input /= 8;
        }

        while (!octalStack.empty()) {
            keluaran += to_string(octalStack.top());
            octalStack.pop();
        }
        return keluaran;
    }

    //Octal ke Decimal
    string OcToDec(int input) {
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
        
        string keluaran = to_string(hasil);

        if(sisa == 8 || sisa == 9){
            return 0;
        }else{
            return keluaran;
        }
    }

};


// Entry Point Driver
int main(){
	Converter conv;
begin: 
	int ops, input, bin, dec;
	string hex, octal, decs;
	char ask;
	cout << "Pilih menu berikut untuk melakukan konversi:\n";
	cout << "1. Desimal To Any Format\n";
    cout << "2. Biner To Any Format\n";
    cout << "3. Oktal To Any Format\n";
    cout << "4. Heksadesimal To Any Format\n";
    cout << "Masukkan menu yang dipilih (cukup angkanya saja): ";
    cin >> ops;

	switch(ops){
		case 1: 
			cout << "Masukkan bilangan desimal: ";
			cin >> input;
			cout << endl;
			cout << "=========HASIL===========\n";
			bin = conv.DecToBin(input); 
			cout << "Binary = " << bin << endl;
			octal = conv.DecToOc(input); 
			cout << "octal = " << octal << endl;
			hex = conv.DecToHex(input); 
			cout << "Heksadesimal = " << hex << endl;
			cout << "=========================\n" << endl;
			break;
		case 2:
			cout << "Masukkan bilangan biner: ";
			cin >> input;
			cout << endl;
			cout << "=========HASIL===========\n";
			dec = conv.BinToDec(input); 
			cout << "Decimal = " << dec << endl;
			octal = conv.DecToOc(dec); 
			cout << "Octal = " << octal << endl;
			hex = conv.DecToHex(dec); 
			cout << "Heksadesimal = " << hex << endl;
			cout << "=========================\n" << endl;
			break;
		case 3:
			cout << "Masukkan bilangan octal: ";
			cin >> input;
			cout << endl;
			cout << "=========HASIL===========\n";
			decs = conv.OcToDec(input); 
			cout << "Decimal = " << decs << endl;
			bin = conv.DecToBin(dec); 
			cout << "Binary = " << bin << endl;
			hex = conv.DecToHex(dec); 
			cout << "Heksadesimal = " << hex << endl;
			cout << "=========================\n" << endl;
			break;
		case 4:
			cout << "Masukkan bilangan heksa (tanpa 0x): ";
			cin >> hex;
			cout << endl;
			cout << "=========HASIL===========\n";
			dec = conv.HexToDec(hex); 
			cout << "Decimal = " << dec << endl;
			octal = conv.DecToOc(dec); 
			cout << "Octal = " << octal << endl;
			bin = conv.DecToBin(dec); 
			cout << "Binary = " << bin << endl;
			cout << "=========================\n" << endl;
			break;
		default: 
			cout << "Menu yang dipilih tidak valid!!!" << endl;
			break;
	}
	cout << "Apakah anda ingin melanjutkan konversi? (y/n)" << endl;
    fflush(stdin);
    cin >> ask;
    if(ask=='y'||ask=='Y')
        goto begin;
    else
        cout << "Terima Kasih <3";
    return 0;
}