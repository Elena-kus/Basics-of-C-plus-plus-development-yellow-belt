#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border){

	if(numbers.empty()) {return numbers.end();}

	auto it  = numbers.lower_bound(border);

	if(it == numbers.end()) { return prev(numbers.end());}
	if(it == numbers.begin()){ return numbers.begin();}
	if(*it==border){return it;}

	if(abs(border-*prev(it) > abs(*it - border))){return it;}
	else return prev(it);

	return prev(numbers.lower_bound(border));
}

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;

  set<int> empty_set;

  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
