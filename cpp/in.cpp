#include<iostream>
#include "in.h"
using namespace std;
int main(int argc, char *argv[]) {
	int* vals = new int[5];
	int val = 0;
	int counter = 0;
	int tmpval = 0;
	for(counter = 0;counter < 5;counter++) {
		cout << "Enter value #" << counter + 1 << ":";
		cin >> tmpval;
		cout << "\n";
		vals[counter]=tmpval;
	}
	while(1) {
		cout << "Enter the value to look for: ";
		cin >> val;
		cout << "\n";
		if(val!=0) break;
	}
	if(in(val,vals,5)) {
		cout << val << " is in the set!\n";
	} else {
		cout << val << " is not in the set...\n";
	}
	return 0;
}
