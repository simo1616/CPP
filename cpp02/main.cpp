#include <iostream>

using namespace std;

int main ()
{
	int n = 5;
	int rawv;
	int bits = 8;

	cout << "n = " << n << " et bits = " << bits << endl;

	cout << "n << bit = " << (n << bits) << endl; // n * 2^8
	
	rawv = 2.2 * (1 << bits);
	cout << "rawv = " << rawv << endl;
	cout << "rawv = " << (float)rawv << endl;
	float f = rawv / float(1 << bits);
	cout << "rawv / float(1 << bits) = " << f << endl;
	int i = rawv >> bits;
	cout << "rawv >> bits = " << i << endl;


}