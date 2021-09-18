#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif // _DEBUG
//----------------------------------------------------------
#include <iostream>
using namespace std;
#include "BigInt.h"
#include <string.h>
//----------------------------------------------------------

void BigInt_inc(BigInt& num)
{
	int carry = 1; // initialize carry for 1 to increse in 1 at the start
	for (int i = num.n_digits - 1; i >= 0; i--)
	{
		int temp = num.digits[i] - '0' + carry;
		num.digits[i] = temp % 10 + '0';
		carry = temp / 10;
	}
	if (carry)
	{
		char* temp = new char[num.n_digits + 1];
		for (int i = 0; i < num.n_digits; i++)
			temp[i + 1] = num.digits[i];
		temp[0] = '0' + 1;
		num.n_digits++;
		delete[] num.digits;
		num.digits = temp;
	}
}
BigInt BigInt_add(const BigInt& a, const BigInt& b)
{
	int carry = 0;
	BigInt myint = { 0,0 };
	int max, min, aindex, bindex; // aindex is index off a and bindex is the same with b
	bindex = b.n_digits - 1;
	aindex = a.n_digits - 1;
	if (a.n_digits >= b.n_digits)
	{
		max = a.n_digits;
		min = b.n_digits;
	}
	else
	{
		max = b.n_digits;
		min = a.n_digits;
	}
	myint.digits = new char[max];
	myint.n_digits = max;
	for (int i = max - 1; i >= 0; i--)
	{
		if (aindex < 0)
		{
			myint.digits[i] = (b.digits[bindex] - '0' + carry) % 10 + '0';
			carry = (b.digits[bindex] - '0' + carry) / 10;
		}
		else if (bindex < 0)
		{
			myint.digits[i] = (a.digits[aindex] - '0' + carry) % 10 + '0';
			carry = (a.digits[aindex] - '0' + carry) / 10;
		}
		else
		{
			myint.digits[i] = (a.digits[aindex] - '0' + b.digits[bindex] - '0' + carry) % 10 + '0';
			carry = (a.digits[aindex] - '0' + b.digits[bindex] - '0' + carry) / 10;
		}
		aindex--;
		bindex--;
	}
	if (carry)
	{
		char* temp = new char[myint.n_digits + 1];
		for (int i = 0; i < myint.n_digits; i++)
			temp[i + 1] = myint.digits[i];
		delete[] myint.digits;
		myint.digits = temp;
		myint.n_digits++;
		myint.digits[0] = '0' + 1;
	}
	return myint;
}