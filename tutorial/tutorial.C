#include <stdio.h>

void add_four(int &a)
{
	a += 4;
}
int main()
{
	int x = 4;

	add_four(x);
	printf("x = %d\n", x);

	
	return 0;
}

