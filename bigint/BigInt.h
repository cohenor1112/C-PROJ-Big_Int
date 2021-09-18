#ifndef __BigInt_
#define __BigInt_


struct BigInt
{
	char* digits; // no leading zeros, doesn't end with '\0' 
	int n_digits;
};

BigInt BigInt_create(const char* s); //create from C string.
									 //The string is NULL terminated and contains
									 //only characters between ‘0’ to ‘9’.

void BigInt_print(const BigInt& bi); //print number to the screen

BigInt BigInt_create(int num); //creat from int

int BigInt_compare(const BigInt& a, const BigInt& b); //-1 if a<b
													   // 0 if a = b
													   // 1 if a>b


void BigInt_assign(BigInt& a, const BigInt& b); // create copy of b in a (like a = b; in integers)
												// a <- b


void BigInt_destroy(BigInt& bi); // Free memory dynamically allocated

void BigInt_inc(BigInt& num); // increase by 1

BigInt BigInt_add(const BigInt& a, const BigInt& b); // a + b

/////////////////////////////////////////////////////////////////////

//The n'th Fibonacci number n(1)=1,n(2)=1,n(3)=2,n(4)=3,n(5)=5,...
BigInt fibo(unsigned int n);

//sqrt(x)
BigInt sqrt(const BigInt& x);

/////////////////////////////////////////////////////////////////////
//assistance function (of my own)

int no_leading_0_len(const char* s);

/////////////////////////////////////////////////////////////////////
//Operator Overloads:

int operator==(const BigInt& a, const BigInt& b);
BigInt operator+(const BigInt& a, const BigInt& b);

//assistance function (of my own)
int operator<(const BigInt& a, const BigInt& b);




#endif