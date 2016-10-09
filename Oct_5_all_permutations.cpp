// n permutation
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

// class generator:
struct c_unique {
  int current;
  c_unique() {current=0;}
  int operator()() {return ++current;}
} UniqueNumber;

// function:
void myfunction (int i) {
  std::cout << i << ' ';
}

int main()
{
	int n=5;

	std::vector<int> myints(n);
	std::vector<int>::iterator first = myints.begin(), last = myints.end();

	std::generate (first, last, UniqueNumber);

	std::for_each(first, last, myfunction);
	std::cout << std::endl;

	for(;;) {
		std::vector<int>::iterator mt = last-2;
		while(*mt > *(mt+1) && mt-- != first);

		if (mt < first) break;

		std::vector<int>::iterator kt = last-1;
		while(*mt > *kt) kt--;

		std::iter_swap(mt, kt);
		std::reverse(mt+1, last);

		std::for_each(first, last, myfunction);
		std::cout << std::endl;
	}
}
