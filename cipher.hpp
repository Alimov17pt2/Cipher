#pragma once
#include <string>
#include <exception>

using namespace std;

class CipherException :exception
{
public:
	const char* what() const noexcept
	{
		return "Cipher error";
	}
};

class Cipher
{
	int key;
	void CheckText(string& );
	void NomalizeText(string& );
	
public:
	explicit Cipher(int key);
	~Cipher();
	void Encrypt(string& inText);
	void Decrypt(string& outText);
};