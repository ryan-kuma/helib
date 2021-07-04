#include <iostream>
#include <fstream>



using namespace std;

class line{
public:
  double a;
  double b;
  line(){
    a=0;
    b=0;
  }
  ~line(){
    ;
  }
};


line mLeastSquare(long* mvec1, long* mvec2, long slots) {
	//b = [sum(xi*yi)/n - mean(x)*mean(y)] / [sum(xi^2)/n - mean(x)^2]
	long sumxy = 0, sumx = 0, sumy = 0, sumxx = 0;
	for (long i = 0; i < slots; i++)
	{
		sumxy += mvec1[i] * mvec2[i];
		sumx += mvec1[i];
		sumy += mvec2[i];
		sumxx += mvec1[i] * mvec1[i];
	}
	line line;
	line.b = ((double)sumxy/slots - (double)sumx/slots*sumy/slots);
	double inv = ((double)sumxx/slots - (double)sumx/slots*sumx/slots);
	line.b /= inv;
	line.a = (double)sumy/slots - line.b*sumx/slots;
	return line;
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
    line mls = mLeastSquare(pa, pb, n);
    cout<<"parameter:"<<endl;
    cout<<"a: "<<mls.a<<endl;
    cout<<"b: "<<mls.b<<endl;
  clock_t end = clock();
  cout << "Operation time: " << (end - start)/(nTests*1000.) << " ms." << endl;
 }
