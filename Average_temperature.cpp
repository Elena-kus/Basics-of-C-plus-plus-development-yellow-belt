#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {

 	unsigned int N;
	cin >> N;
	vector <int> value (N);

	for (size_t i=0;i<value.size();i++)
		cin >> value[i];

	int64_t sum = 0;
	for (int i : value)
		sum +=i;

	int avg = sum / static_cast<int>(N);

	int count = 0;
	for (int i : value) {
		if (i>avg)
			++count;
	}

	cout << count << endl;

	for (size_t i=0;i<value.size();i++)
		if(value[i]>avg)
			cout << i << " ";
	cout << '\n';
	
	return 0;
}



