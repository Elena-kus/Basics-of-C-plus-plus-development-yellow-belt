#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

int GetDistinctRealRootCount(double a, double b, double c) {

	int count;
	if (a != 0) {
		int D = b*b-4*a*c;
		if(D<0)
			count = 0;
		else if (D==0)
			count = 1;
		else if (D>0)
			count = 2;

	} else {
	if (b==0){
		count = 0;
	}else{
		count = 1;
		}

	}
	return count;
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << "!=" << u << " Hint: " << hint;
    throw runtime_error(os.str());
  }
}

void QuadradicEquation(){
	AssertEqual(GetDistinctRealRootCount(1, 1, 1), 0, "000");
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0,"001");
	AssertEqual(GetDistinctRealRootCount(2, 10, 1), 2,"111");
	AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "100");
	AssertEqual(GetDistinctRealRootCount(1, 0, -4), 2, "101");
	AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, "010");
	AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "100");
	AssertEqual(GetDistinctRealRootCount(1, 1, 0), 2, "110");
}


class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func) {
    try {
      func();
      cerr << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr  << " fail: " << e.what() << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

int main() {

	TestRunner tr;
	tr.RunTest(QuadradicEquation);

  return 0;
}
