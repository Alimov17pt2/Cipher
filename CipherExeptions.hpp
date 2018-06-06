#pragma once
#include <exception>

class CipherException : public std::exception
{
public:
	virtual const char* what() const =0;
};


class KeyException : public  CipherException
{
	const char* what() const
	{
		return "Key must be positive integer";
	}
};

class TextException : public CipherException
{
	const char* what() const 
	{
		return "Text contain unacceptable symbols";
	}
};