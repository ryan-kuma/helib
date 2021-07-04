#include <iostream>
#include <fstream>



using namespace std;



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

int main(int argc, char *argv[])
{
  ifstream infile("database");
  int l=100;
  int n=32;
  long num = 0;
  long data[100][32];
  for(int i=0;i<100;i++){
    for(int j=0;j<32;j++){
      infile>>data[i][j];
    }
  }
  cout<<"database:"<<endl;
  if(l < 100) 
  	for(uint32_t i = 0; i < l; ++i) showLargeVec(data[i], n);
  else {
	for(uint32_t i = 0; i < 3; ++i) 
		showLargeVec(data[i], n);
	cout << "[......................" << endl;
	showLargeVec(data[l-1], n);
  }
  
  srand(time(NULL));
  clock_t start = clock();
  long* pa, pb=30;
  int nTests=3;
  int count=0;
  long slotsMax=-999;
  long slotsMin=999;
  pa = data[rand()%l];// random select
  for(int j=0;j<32;j++){
    if(pa[j]>slotsMax){
      	slotsMax=pa[j];
    }
    if(pa[j]<slotsMin){
        slotsMin=pa[j];
    }
  }
    cout << "slotsMax: " << slotsMax << endl;
    cout << "slotsMin: " << slotsMin << endl;
  clock_t end = clock();
  cout << "Operation time: " << (end - start)/(nTests*1000.) << " ms." << endl;
 }
