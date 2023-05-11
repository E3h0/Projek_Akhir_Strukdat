#include <iostream>
#include <vector>
#include <algorithm>

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

class Queue{
	private: 
		vector<int> dt;
	public: 
		void push(int n){
			dt.push_back(n);
		}
		int pop(){
			int n = dt.front();
			dt.erase(dt.begin());
			return n;
		}
		int front(){
			return dt.front();
		}
		int size(){
			return dt.size();
		}
		bool empty(){
			return dt.empty();
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
					st.push(remainder + '0');
				}else{
					st.push(remainder + 55);
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
		int HexToDec(string hex){
			Queue qu;
			for(int i = 2; i < hex.length(); i++){
				if(hex[i] >= '0' && hex[i] <= '9'){
					qu.push(hex[i] - '0');
				}
				else{
					qu.push(hex[i] - 55);
				}
			}
			int dec = 0;
			int pow = 1;

			// Ubah digit heksa ke desimal
			while(!qu.empty()){
				dec += qu.front() * pow;
				qu.pop();
				pow *= 16;
			}
			return dec;
		}
};


// Entry Point Driver
int main(){
	Converter conv;
	int dec=13;
	string hex = "0xD";
	string res;
	int res1;
	res = conv.DecToHex(dec);
	res1 = conv.HexToDec(hex);
	cout << res << endl;
	cout << res1 << endl;
}