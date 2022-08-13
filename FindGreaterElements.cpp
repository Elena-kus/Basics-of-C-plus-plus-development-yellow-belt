#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border){

	auto it = find_if(elements.begin(),elements.end(),[&](T x){ return x > border;});

	vector <T> result;

	auto j = elements.end();

	while(it!=j){
		result.push_back(*it);
		++it;
	}

	return result;
}

int main() {

	 for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
	    cout << x << " ";
	  }
	  cout << endl;

	  string to_find = "Python";
	  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
	  return 0;
}
