// n permutation
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	unsigned int n;
	cout << "The number of objects: ";
	cin >> n;

	vector<unsigned int> myints(n);
	vector<unsigned int>::iterator first = myints.begin(), last = myints.end();

	generate(first, last, []{ static unsigned int k=0; return ++k; });
	for_each(first, last, [](unsigned int &i){ cout << i << ' '; });
	cout << endl;

	vector<unsigned int>::iterator mt, kt;
	for(;;) {
		mt = last-2;
		while(*mt > *(mt+1) && mt-- != first);

		if (mt < first) break;

		kt = last-1;
		while(*mt > *kt) kt--;

		iter_swap(mt, kt);
		reverse(mt+1, last);

		for_each(first, last, [](unsigned int &i){ cout << i << ' '; });
		cout << endl;
	}
}

