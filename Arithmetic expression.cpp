#include <iostream>
#include <deque>
#include <string>
#include <stack>

using namespace std;

bool Priority (string operation) {
	if (operation == "*" || operation == "/")
		return true;
	else return false;
}

int main() {

	int x, q;
	cin >> x >> q;

	if (q==0){
		cout << x;
		return 0;
	}

	string operation;
	int number;

	deque <string> result;

	string s = to_string(x);
	result.push_back(s);

	stack <string> operations;

	for ( int i=0; i<q; i++) {
			cin >> operation >> number;

			if (operations.size() > 0)
				if ((Priority(operation) && !Priority(operations.top()))) {

			result.push_front("(");
			result.push_back(")");
			}

			operations.push(operation);
			result.push_back(" ");
			result.push_back(operation);
			result.push_back(" ");
			result.push_back(to_string(number));
		}

	for(auto i: result)
		cout << i;

	return 0;
}
