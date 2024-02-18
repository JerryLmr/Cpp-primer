#include<iostream>
using namespace std;
namespace Exercise{
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 10;
/*using Exercise::ivar;	//1
using Exercise::dvar;
using Exercise::limit;*/

// using namespace Exercise;	//3

void mainp(){
	// using Exercise::ivar;	//2
	// using Exercise::dvar;
	// using Exercise::limit;

	using namespace Exercise;	//4

    cout << Exercise::ivar;
	double dvar = 3.1416;
	int iobj = limit + 1;
	++Exercise::ivar;
	++::ivar;
}

int main()
{
    mainp();
	return 0;
}