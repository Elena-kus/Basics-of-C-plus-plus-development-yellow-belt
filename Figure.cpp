#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class Figure{
public:
	virtual string Name () const = 0;
	virtual double Perimeter () const = 0;
	virtual double Area () const = 0;
};

class Triangle : public Figure {
public: Triangle (const int& a, const int& b, const int& c, const string& name):
	_a(a),_b(b),_c(c),type(name){}

string Name()const override {
		return type;
}

double Perimeter() const override {
	return _a + _b + _c;
}

double Area() const override {
	double p = (_a+_b+_c)/2.;
	return sqrt(p*(p-_a)*(p-_b)*(p-_c));
}

private:
	const int _a;
	const int _b;
	const int _c;
	const string type;

};

class Circle : public Figure{
public: Circle (const int& r, const string& name) :_r(r), type(name){}

string Name()const override {
		return type;
}

double Perimeter() const override {
	return 2*3.14*_r;
}

double Area() const override {
	return 3.14*_r*_r;
}

private:
	const int _r;
	const string type;
};

class Rect : public Figure{
public: Rect (const int& w, const int& h, const string& name):
	wight(w),height(h),type(name){}

string Name()const override {
		return type;
}

double Perimeter() const override {
	return wight*2+height*2;
}

double Area() const override {
	return wight*height;
}

private:
	const int wight;
	const int height;
	const string type;
};


shared_ptr <Figure> CreateFigure(istringstream& is){

	string type;
	is >> type;

	if(type == "RECT"){
		int w;
		int h;
		is >> w >> h;
		shared_ptr <Figure> R  = make_shared<Rect>(w,h,type);
		return R;
	} else if (type == "TRIANGLE"){
		int a;
		int b;
		int c;
		is >> a >> b >> c;
		shared_ptr <Figure> T =  make_shared<Triangle>(a,b,c,type);
		return T;
	} else if(type == "CIRCLE"){
		int r;
		is >> r;
		shared_ptr <Figure> C =  make_shared<Circle>(r,type);
	    return C;
	}
}

int main() {

  vector<shared_ptr<Figure>> figures;

  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
