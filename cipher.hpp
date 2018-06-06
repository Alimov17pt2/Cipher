#pragma once
#include <string>
#include "CipherExeptions.hpp"

using namespace std;

class Cipher
{
	Cipher(Cipher const&);
	Cipher& operator=(Cipher const&);

	int key_;
	void CheckText(string& );
	void NomalizeText(string& );
	
public:
	explicit Cipher(int );
	void Encrypt(string& );
	void Decrypt(string& );
};