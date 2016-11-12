// n permutation
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int n=3;

	vector<int> myints(n);
	vector<int>::iterator first = myints.begin(), last = myints.end();

	generate(first, last, []{ static unsigned int k=0; return ++k; });
	for_each(first, last, [](int &i){ cout << i << ' '; });
	cout << endl;

	for(;;) {
		vector<int>::iterator mt = last-2;
		while(*mt > *(mt+1) && mt-- != first);

		if (mt < first) break;

		vector<int>::iterator kt = last-1;
		while(*mt > *kt) kt--;

		iter_swap(mt, kt);
		reverse(mt+1, last);

		for_each(first, last, [](int &i){ cout << i << ' '; });
		cout << endl;
	}
}
