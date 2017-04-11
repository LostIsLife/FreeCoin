#include <iostream>

int test(int a, int b, int c)
{
		  return (&b)[-1];
}

int main()
{
	std::cout << test(1, 2, 3) << std::endl;
	return 0;
}
