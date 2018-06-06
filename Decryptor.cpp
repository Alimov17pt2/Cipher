#include <iostream>
#include "Cipher.hpp"

using namespace std;

void main() {

	string inputTxt = "";
	string inputKey = "";

	cout << "Provide decrypt key: ";
	getline(cin, inputKey);

	cout << "Input encrypted text: ";
	getline(cin, inputTxt);

	try
	{
		Cipher ciph(stoi(inputKey));
		ciph.Decrypt(inputTxt);
	}
	catch (invalid_argument&)
	{
		cout << "Error: key must be positive integer" << endl;
		return;
	}
	catch (CipherException const& exp)
	{
		cout << "Error: " << exp.what() << endl;
		return;
	}
	cout << endl << "Decrypted text: " << inputTxt << endl;
}


