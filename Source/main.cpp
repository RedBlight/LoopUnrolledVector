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
	LuVector3d A( 1.1, 2.2, 3.3 );

	LuVector3d B( 1.1, 2.2, 3.3 );

	B += A;


	cout << B << endl;

	system( "pause" );
	return 0;
}