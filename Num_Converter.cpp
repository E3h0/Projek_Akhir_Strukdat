#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

// Class Untuk Implementasi Struktur Data
class Stack {
	private:
		vector<int> dt;
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
			return dt.size();
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
		        hexQueue.enqueue(c);
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
};


// Entry Point Driver
int main(){
	Converter conv;
	
	int dec = 218;
	string res1 = conv.DecToHex(dec);

	int dec2 = 173;
	string res2 = conv.DecToHex(dec2);
	
	string hex = "da";
	int res = conv.HexToDec(hex);
	int res3 = conv.DecToBin(dec2);
	int res4 = conv.BinToDec(res3);
	
	cout << "res = " << res << endl;
	cout << "res1 = " << res1 << endl;
	cout << "res2 = " << res2 << endl;
	cout<< "res3 = " <<res3<<endl;
	cout<<"res4 = "<<res4<<endl;
}
