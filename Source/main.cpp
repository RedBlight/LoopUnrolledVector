#include "LuVector.hpp"
#include <iostream>
#include <complex>
#include <thread>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <random>
#include <time.h>

using namespace std;
using namespace LUV;
using namespace complex_literals;

int main()
{
	// OPERTAOR OVERLOAD TESTS

	LuVector3d A( 10, 100, 1000 );
	LuVector3d B( 3, 5, 7 );

	A = A + 1;
	cout << A << endl;
	A = A - 1;
	cout << A << endl;
	A = A * 10;
	cout << A << endl;
	A = A / 10;
	cout << A << endl;

	cout << endl;
	
	A += 1;
	cout << A << endl;
	A -= 1;
	cout << A << endl;
	A *= 10;
	cout << A << endl;
	A /= 10;
	cout << A << endl;

	cout << endl;
	
	A = A + B;
	cout << A << endl;
	A = A - B;
	cout << A << endl;
	A = A * B;
	cout << A << endl;
	A = A / B;
	cout << A << endl;

	cout << endl;
	
	A += B;
	cout << A << endl;
	A -= B;
	cout << A << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;

	cout << endl;

	A = -A;
	cout << A << endl;

	cout << endl;
	
	// COMPLEX VECTOR TEST

	LuVector3c C( ( 1.0 + 0.0i ) * A + ( 0.0 + 1.0i ) * B );
	cout << C << endl;

	cout << endl;

	//////////////////////////////////////
	// PERFORMANCE TEST
	//////////////////////////////////////

	cout << "Summing 100 million vectors:" << endl;
	cout << endl;

	default_random_engine generator;
	uniform_real_distribution< double > distribution( -10.0, 10.0 );

	const size_t repN = 10000;
	const size_t loopN = 10000;
	const size_t vecN = 3; 

	LuVector< vecN, double > luvArr[ loopN ];
	double oldArr[loopN][vecN];

	for( size_t idx = 0; idx < loopN; ++idx )
	{
		for( size_t idn = 0; idn < vecN; ++idn )
		{
			oldArr[idx][idn] = distribution( generator );
		}
		luvArr[idx] = LuVector< vecN, double >( oldArr[idx][0], oldArr[idx][1], oldArr[idx][2] );
	}

	LuVector< vecN, double > luvArrTotal( 0 );
	double oldArrTotal[vecN] = { 0, 0, 0 };

	clock_t start, diff;

	// Array performance

	start = clock();
	for( size_t idr = 0; idr < repN; ++idr )
	{
		for( size_t idx = 0; idx < loopN; ++idx )
		{
			for( size_t idn = 0; idn < vecN; ++idn )
			{
				oldArrTotal[idn] += oldArr[idx][idn];
			}
		}
	}
	diff = clock() - start;
	
	cout << oldArrTotal[0] << "," << oldArrTotal[1] << "," << oldArrTotal[2] << endl;
	cout << "Array: " << diff << " msec" << endl;
	cout << endl;

	// Loop unrolled array performance

	oldArrTotal[0] = 0;
	oldArrTotal[1] = 0;
	oldArrTotal[2] = 0;
	start = clock();
	for( size_t idr = 0; idr < repN; ++idr )
	{
		for( size_t idx = 0; idx < loopN; ++idx )
		{
			oldArrTotal[0] += oldArr[idx][0];
			oldArrTotal[1] += oldArr[idx][1];
			oldArrTotal[2] += oldArr[idx][2];
		}
	}
	diff = clock() - start;
	
	cout << oldArrTotal[0] << "," << oldArrTotal[1] << "," << oldArrTotal[2] << endl;
	cout << "Loop unrolled array: " << diff << " msec" << endl;
	cout << endl;

	// LuVector performance

	start = clock();
	for( size_t idr = 0; idr < repN; ++idr )
	{
		for( size_t idx = 0; idx < loopN; ++idx )
		{
			luvArrTotal += luvArr[idx];
		}
	}
	diff = clock() - start;

	cout << luvArrTotal << endl;
	cout << "LuVector: " << diff << " msec" << endl;
	cout << endl;


	system( "pause" );
	return 0;
}