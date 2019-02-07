#include <iostream>
int MAXLEN = 10;
using namespace std;

int main (){
	int * foo; 							//declaring pointer
	foo = new (nothrow) int[MAXLEN];  	// now foo is pointing at the 0th element of an array
	int * fooclone = foo; 							// (nothrow) prevents the program from shutting down when heap space doesnt have enough memory
										// if there is not enough space in heap, it will just return nullptr
										//dynamically allocated stuffs are in heap space, others are in stack. 
	if (foo == nullptr){
		cout << "Not enough space in heap"<<endl;
		}
	for (int i = 0 ; i<MAXLEN ; i++){	//conventional way to access array element
		foo[i] = i+10;
		cout << *(fooclone)<<endl;
		fooclone++;
		}
	cout << "printing the array element..."<<endl<<endl;
	
	for (int j = 0 ; j<MAXLEN ; j++){
		cout << *foo+(j) << endl;		//differnt way to access array element. it has to be a pointer type 
		}
	delete[] foo;						                //delete function deallocates the allocated element. 
										//delete[] deallocates the array of allocated stuffs 
									
	return 0;
	}
