#include <iostream>
#include <fstream>
#include<cmath>


using namespace std;



double mCosineMeasure(long* mvec1, long* mvec2, long slots){
	long mval = 0;
	long mxx = 0, myy = 0;
	for (long i = 0; i < slots; i++)
	{
		mval += mvec1[i] * mvec2[i];
		mxx += mvec1[i] * mvec1[i];
		myy += mvec2[i] * mvec2[i];
	}
	//cout << "In fact: " << mval/(sqrt((double)mxx) * sqrt((double)myy)) << endl;
	//cout << "Appr: " << mval/(apprSqrt((double)mxx) * apprSqrt((double)myy)) <<  endl;
	return mval/(sqrt((double)mxx) * sqrt((double)myy));
}

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
  long* pa, *pb;
  int nTests=3;
  int count=0;
    pa = data[rand()%l];// random select
    pb = data[rand()%l];
    double cos = mCosineMeasure(pa, pb, n);
    cout<<"Cosine measure: "<<cos<<endl;
  clock_t end = clock();
  cout << "Operation time: " << (end - start)/(nTests*1000.) << " ms." << endl;
 }
