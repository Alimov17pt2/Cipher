#include "Cipher.hpp"
#include <cctype>
#define ALPHABET_SZ 26

Cipher::Cipher(int key):key_(key % ALPHABET_SZ) {
	if (key_ <= 0) throw KeyException();
}

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
			throw TextException();
	}
}

void Cipher::Encrypt(string& inText)
{
	if (inText.empty()) return;
	NomalizeText(inText);
	CheckText(inText);
	for (unsigned i = 0; i < inText.length(); i++)
	{
		inText[i] = (((inText[i]-'A') + key_) % ALPHABET_SZ) + 'A';
	}
}

void Cipher::Decrypt(string & outText)
{
	if (outText.empty()) return;
	CheckText(outText);
	for (unsigned i = 0; i < outText.size(); i++)
	{
		outText[i] = ((ALPHABET_SZ + (outText[i] - 'A') - key_) % ALPHABET_SZ) + 'A';
	}
}