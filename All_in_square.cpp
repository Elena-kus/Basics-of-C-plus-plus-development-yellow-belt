#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename First , typename Second > pair <First , Second > operator *(const pair <First , Second >& p1, const pair <First , Second >& p2);
template <typename T> vector <T> operator *(const vector <T>& v1, const vector <T> &v2);
template <typename Key, typename Value> map <Key,Value> operator *(const map <Key, Value> &m1, const map<Key,Value> &m2);
template <typename T> T Sqr(T x);

template <typename First , typename Second> 
pair <First , Second > operator *(const pair <First , Second >& p1, const pair <First , Second >& p2) {

	pair<First, Second> p_kv(p1.first*p2.first,p1.second*p2.second);
	return  p_kv;
}

template <typename T>
vector <T> operator *(const vector <T>& v1, const vector <T> &v2) {

	vector <T> v_kv;
	for( size_t i =0; i<v1.size();i++){
		v_kv.push_back(v1[i]*v2[i]);
	}
	return v_kv;
}

template <typename Key, typename Value> 
map <Key,Value> operator *(const map <Key, Value> &m1, const map<Key,Value> &m2){

	map <Key,Value> m_vk;

	for(auto i: m1){
		m_vk[i.first] = i.second*i.second;
	}

	return m_vk;
}

template <typename T>
T Sqr(T x){
	return x*x;
}

int main() {

	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0 ;
}
