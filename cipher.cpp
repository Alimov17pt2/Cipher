#include "Cipher.h"
#include <cctype>
#define ALPHABET_SZ 26

Cipher::Cipher(int key) {
	if (key <= 0) throw CipherException();
	this->key = key % ALPHABET_SZ;
}

Cipher::~Cipher(){}

void Cipher::NomalizeText(string& text)
{
	// Удаление знаков пунктуации и пробелов
	for (unsigned z = 0; z < text.size();)
	{
		if (ispunct((unsigned char)text[z]) 
		|| isspace((unsigned char)text[z])) {
			text.erase(z,1);
		}
		else {
			z++;
		}
	}
	// Перевод маленьких букв в большие, удаление знаков пунктуации
	for (unsigned i = 0; i < text.size(); i++)
	{
		if (islower((unsigned char)text[i])) {
			text[i] = toupper((unsigned char)text[i]);
		}
	}
}

void Cipher::CheckText(string& text) {
	// Проверка на недопустимые символы
	for (unsigned i = 0; i < text.size(); i++)
	{
		if (!isupper((unsigned char)text[i])) 
			throw CipherException();
	}
}

void Cipher::Encrypt(string& inText)
{
	if (inText.empty()) throw CipherException();
	NomalizeText(inText);
	CheckText(inText);
	for (unsigned i = 0; i < inText.length(); i++)
	{
		inText[i] = (((inText[i]-'A') + key) % ALPHABET_SZ) + 'A';
	}
}

void Cipher::Decrypt(string & outText)
{
	if (outText.empty()) throw CipherException();
	CheckText(outText);
	for (unsigned i = 0; i < outText.size(); i++)
	{
		outText[i] = ((ALPHABET_SZ + (outText[i] - 'A') - key) % ALPHABET_SZ) + 'A';
	}
}