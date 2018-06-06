//#include <iostream>
//#include "Cipher.hpp"
//
//using namespace std;
//
//void main() {
//	
//	string inputTxt = "";
//	string inputKey = "";
//
//	cout << "Provide encrypt key: ";
//	getline(cin, inputKey);
//
//	cout << "Input text: ";
//	getline(cin, inputTxt);
//	
//	try
//	{
//		Cipher ciph(stoi(inputKey));
//		ciph.Encrypt(inputTxt);
//	}
//	catch (invalid_argument&)
//	{
//		cout << "Error: key must be positive integer" << endl;
//		return;
//	}
//	catch (CipherException const& exp)
//	{
//		cout << "Error: " << exp.what() << endl;
//		return;
//	}
//	cout << endl << "Encrypted text: " << inputTxt << endl;
//}
//
//
