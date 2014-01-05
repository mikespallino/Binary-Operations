#include <iostream>
#include <bitset>
#include <string>

using namespace std;

void do_add(bitset<8> a, bitset<8> b);
void do_subtract(bitset<8> a, bitset<8> b);
void do_multiply(bitset<8> a, bitset<8> b);
void do_divide(bitset<8> a, bitset<8> b);

bitset<2> add(bool a, bool b, bool cin);
bitset<2> subtract(bool a, bool b, bool borin);
bitset<2> multiply(bool a, bool b, bool c);
bitset<2> divide(bool a, bool b, bool c);

int main() {
	unsigned short int term1;
	unsigned short int term2;
	string operation;

	cout << "Enter a number between 0 - 255: ";
	cin >> term1;
	cout << "Enter a number between 0 - 255: ";
	cin >> term2;

	if(term1 > term2) {
		unsigned short int t = term2;
		term2 = term1;
		term1 = t;
	}


	bitset<8> inputBitsT1 = term1;
	bitset<8> inputBitsT2 = term2;

	cout << "The first term in binary is : " << inputBitsT1 << endl;
	cout << "The second term in binary is: " << inputBitsT2 << endl;
	cout << "\nWhat operation would you like to perform? (+, -, *, /, quit) ";
	cin >> operation;

	while(operation != "quit") {
		if(operation == "+") {
			do_add(inputBitsT1, inputBitsT2);
		} else if (operation == "-") {
			do_subtract(inputBitsT1, inputBitsT2);
		} else if (operation == "*") {
			do_multiply(inputBitsT1, inputBitsT2);
		} else if (operation == "/") {
			do_divide(inputBitsT1, inputBitsT2);
		} else if(operation == "quit") {
			system("pause");
			return 0;
		} else {
			cout << "Error: Invalid operation chosen." << endl;
		}
		cout << "\nWhat operation would you like to perform? (+,-,*,/, quit) ";
		cin >> operation;
	}

	system("pause");

	return 0;
}

void do_add(bitset<8> a, bitset<8> b) {
	bitset<9> sum;
	bool c = 0;
	for(int i = 0; i < 8; i++) {
		sum[i] = add(a[i], b[i], c)[0];
		c = add(a[i], b[i], c)[1];
	}
	sum[8] = c;

	cout << "\nSum: " << sum << endl;
}

void do_subtract(bitset<8> a, bitset<8> b) {
	bitset<8> difference;
	bool bor = 0;
	for(int i = 0; i < 8; i++)
	{
		difference[i] = subtract(a[i], b[i], bor)[0];
		bor = subtract(a[i], b[i], bor)[1];
	}

	cout << "\nDifference: " << difference << endl;
}

//TODO: Implement
void do_multiply(bitset<8> a, bitset<8> b) {
}

//TODO: Implement
void do_divide(bitset<8> a, bitset<8> b) {
}

bitset<2> add(bool a, bool b, bool cin)  {
	bitset<2> sum;
	bool s;
	bool c;

	s = (a^b) ^ cin;
	c = (a&b)|(cin&(a^b));
	sum[0] = s;
	sum[1] = c;
	return sum;
}

bitset<2> subtract(bool a, bool b, bool borin)  {
	bitset<2> difference;
	bool d;
	bool borout;

	d = borin ^ (a^b);
	borout = (!(a^b) & borin) | (a&(!b));
	difference[0] = d;
	difference[1] = borout;
	return difference;
}

//TODO: Implement
bitset<2> multiply(bool a, bool b, bool c) {
	bitset<2> b1 = a;
	return b1;
}

//TODO: Implement
bitset<2> divide(bool a, bool b, bool c) {
	bitset<2> b1 = a;
	return b1;
}