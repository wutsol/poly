#include "poly.h"
#include <iostream>
using namespace std;

int main()
{
	Poly test,pa,pb;
	pa.InputPoly(2);
	pb.InputPoly(3);
	test.MergePoly(pa, pb);
	test.OutputPoly();
	system("pause");
	return 0;
}