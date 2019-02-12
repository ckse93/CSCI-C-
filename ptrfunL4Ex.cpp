#include <iostream>
#include <fstream>
using namespace std;

int * getnums(string filename, int& count);	

int main(){

int  *p, *q;
int val;

val = 10;
p = &val;

cout << p  << endl << endl;
cout << *p << endl << endl;

q = p;

cout << q << endl << endl;
cout << *q << endl << endl;

val++;

cout << *p << endl;
cout << *q << endl;
cout << (*p)++ << endl;
cout << *q<< endl;

cout << endl<< endl;


int nums[5] = {3,5,7,11,13};

p = nums;
for (int i = 0; i < 5; i++) {
	cout << p[i] << "  ";
}
cout << endl<< endl;

q = nums;
for (int i = 0; i < 5; i++) {
	cout << *q << "  ";
	q++;
}
cout << endl<< endl;

int *end = nums + 5;

for (p = nums; p < end; p++)
	cout << *p << "  ";
	
cout << endl << endl;

int *r;

r = new int;
*r = 12;
cout << *r << endl;
delete r;

return 0;

}

