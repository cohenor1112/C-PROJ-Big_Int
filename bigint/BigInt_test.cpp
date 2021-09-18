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

int main()
{
	//create from C string
	BigInt a = BigInt_create("00099999999999999999999");
	BigInt_print(a);
	cout << endl;

	//creat from int
	BigInt b = BigInt_create(9345);
	BigInt_print(b);
	cout << endl;

	// compare
	int i = BigInt_compare(a, b);
	BigInt_print(a);
	switch (i)
	{
	case 0: cout << " == ";
		break;
	case 1: cout << " > ";
		break;
	case -1: cout << " < ";
		break;
	default: cout << "???";
	}
	BigInt_print(b);
	cout << endl;

	// assign
	BigInt_assign(b, a);
	BigInt_print(b);
	cout << endl << "After assigning b to a, compare = ";
	cout << BigInt_compare(a, b) << endl;

	// inc
	BigInt_print(a);
	cout << " + 1 = ";
	BigInt_inc(a);
	BigInt_print(a);
	cout << endl;

	// add
	BigInt c = BigInt_create(93652);
	BigInt d = BigInt_add(a, c);
	BigInt_print(a);
	cout << " + ";
	BigInt_print(c);
	cout << " = ";
	BigInt_print(d);
	cout << endl;
	BigInt_destroy(a);
	BigInt_destroy(b);
	BigInt_destroy(c);
	BigInt_destroy(d);

	cout << endl << "before fibo and sqrt functions Leaks: " << _CrtDumpMemoryLeaks() << endl;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << endl << "testing fibo and sqrt : " << endl << endl;

	//The n'th Fibonacci number n(1)=1,n(2)=1,n(3)=2,n(4)=3,n(5)=5,...
	BigInt fibo_test = fibo(100);
	cout << "fibo answer: ";
	BigInt_print(fibo_test);
	BigInt_destroy(fibo_test);
	cout << endl;

	//sqrt(x)
	BigInt sqrt_test = BigInt_create(9);
	BigInt ans = sqrt(sqrt_test);
	cout << "sqrt answer: ";
	BigInt_print(ans);
	BigInt_destroy(sqrt_test);
	BigInt_destroy(ans);

	cout << endl << "after fibo and sqrt functions Leaks: " << _CrtDumpMemoryLeaks() << endl;


	return 0;
}