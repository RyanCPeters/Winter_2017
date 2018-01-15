#include <vector>
#include <iostream>
#include "quicksort.cpp"
using namespace std;

int main() {
	vector<int> v1 = { 67,26,11,87,84,30,14,63,59,28,6,18 };
	vector<int> v2 = { 14,36,89,69,50,15,31,38,92 };
	quicksort qs = quicksort();
	qs.qsBeginSorting(v1);
	qs.qsBeginSorting(v2);

	for (int i = 0; i < v1.size(); ++i) cout << v1.at(i) << " ";
	cout << endl;
	for (int i = 0; i < v2.size(); ++i) cout << v2.at(i) << " ";
	cout << endl;

	vector<int> vMerged;
	vMerged.assign(v1.begin(), v1.end());
	vMerged.emplace_back(v2.begin(), v2.end());

	for (int i = 0; i < vMerged.size(); ++i) cout << vMerged.at(i) << " ";
	cout << endl;

	

	
}