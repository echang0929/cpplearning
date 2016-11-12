// n choose r combination
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	unsigned int n=10;
	unsigned int r=5;

	vector<unsigned int> myints(r);
	vector<unsigned int>::iterator first = myints.begin(), last = myints.end();

	generate(first, last, []{ static unsigned int k=0; return ++k; });
	for_each(first, last, [](unsigned int &i){ cout << i << ' '; });
	cout << endl;

	while((*first) != n-r+1){
		vector<unsigned int>::iterator mt = last;

		while (*(--mt) == n-(last-mt)+1);
		(*mt)++;
		while (++mt != last) *mt = *(mt-1)+1;

		for_each(first, last, [](unsigned int &i){ cout << i << ' '; });
		cout << endl;
	}
}
