#include <iostream>
#include <fstream>
#include "message.h"

using namespace std;

// define flags FLAG_PRINT_ZZX, FLAG_PRINT_POLY, FLAG_PRINT_VEC, functions
//        decryptAndPrint(ostream, ctxt, sk, ea, flags)
//        decryptAndCompare(ctxt, sk, ea, pa);

void showLargeVec(long* vals, long size) {
	cout << "[";
	cout << vals[0];
	if (size <= 16) {
		for (long i = 1; i < size; ++i) cout << ", " << vals[i];
	}else {
		for (long i = 1; i < 16; ++i) cout << ", " << vals[i];
		cout << ", ..., " << vals[size-1];
	}
	cout << "]" << endl;
}

long* randomLongArray(long n, long bound) {
	long* res = new long[n];
	for (long i = 0; i < n; ++i) {
		res[i] = rand() % bound;
	}
	return res;
}

void generateMessages(long** res, uint32_t l, long n, long logb) {
	// Genarate Messages //
	long bound = 1 << logb;
	for (uint32_t i = 0; i < l; ++i) {
		res[i] = randomLongArray(n, bound);
	}
	if(l < 7) for(uint32_t i = 0; i < l; ++i) showLargeVec(res[i], n);
	else {
		for(uint32_t i = 0; i < 3; ++i) 
			showLargeVec(res[i], n);
		cout << "[......................" << endl;
		showLargeVec(res[l-1], n);
	}
}

int main(int argc, char *argv[])
{
  long logb = 7;
  int l = 100;
  long n = 32;
	long** data = new long*[l];
  cout << "Generating Messages(" << l << "*" << n << "):" << endl;
  srand(time(NULL));
  generateMessages(data, l, n, logb);
  ofstream outfile("database");
  for(int i=0;i<100;i++){
  	for(int j=0;j<32;j++){
  		outfile<<data[i][j]<<" ";
  	}
  	outfile<<"\n";
  }
  outfile.close();
  std::cout<<"database generated."<<std::endl;
  return 0;
}



