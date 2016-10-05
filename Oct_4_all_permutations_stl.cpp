// next_permutation example to generate all permutation for n
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation
#include <vector>		// std::vector

// class generator:
struct c_unique {
  int current;
  c_unique() {current=0;}
  int operator()() {return ++current;}
} UniqueNumber;

void myfunction (int i) {  // function:
  std::cout << i << ' ';
}

int main () {
	std::vector<int> myints(4);
	std::generate (myints.begin(), myints.end(), UniqueNumber);

	do {
		for_each(myints.begin(), myints.end(),myfunction);
		std::cout << std::endl;
	} while(std::next_permutation(myints.begin(), myints.end()));

  return 0;
}
