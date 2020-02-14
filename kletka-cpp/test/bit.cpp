#include "stdio.h"

struct device 
{ 
	unsigned n1 : 3;
	unsigned n2 : 3;
};

int main()
{
	struct device s;
	s.n1 = 3;
	for(int i = 0; i<s.n1; i++)
		printf("%d\n", i);
}
