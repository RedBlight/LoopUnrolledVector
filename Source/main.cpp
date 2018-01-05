#include "LuVector.hpp"
#include <iostream>
#include <complex>
#include <thread>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;
using namespace LUV;
using namespace complex_literals;

int main()
{
	LuVector<3,double> A( 1.1, 2.2, 3.3 );

	LuVector<3,double> B( 1, 10, 100 );

	//B += A;
	
	//B += A + A;

	//B += B + 5;
	B = 5 + B;

	cout << B << endl;

	system( "pause" );
	return 0;
}