/* #include "invsqr.hpp" */
#include <iostream>
/* #include <malloc.h> */
#include <math.h>
#include <vector>

int main() 
{
	int input;
	std::cin >> input;

	const float threehalfs = 1.5F;
	float x2 = input * 0.5F;
	float y = input;

	long i = * ( long * ) &y;
	i = 0x5f3759df - ( i >> 1 );
	y = * ( float * ) &i;

	y = y * ( threehalfs - ( x2 * y * y ) );

	std::cout << y << "\n";
	return 0;
}
