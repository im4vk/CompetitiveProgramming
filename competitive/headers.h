#include <iostream>
#include <stdlib.h>
#include <unordered_set>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <chrono>
#include <random>
#include <ratio>
#include <thread>
#include <ostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

void init_code();
void timerEnd();
#define startTime auto begin1 = chrono::system_clock::now();
#define endTime auto end1 = chrono::system_clock::now();
startTime;
void __attribute__((constructor)) init_code(); // to run at start of program
void __attribute__((destructor)) timerEnd(); // to run at exit of program


vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}

void __print(int x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(char x) { cerr << x; }
void __print(const char *x) { cerr << x; }
void __print(const string &x) { cerr << x; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ", ";
    __print(x.second);
    cerr << '}';
}

template<typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) {
        cerr << (f++ ? ", " : "");
        __print(i);
    }
    cerr << "}";
}

void _print() {
    cerr << "]\n";
}

void _print(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx,
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 

template<typename T, typename... V>
void _print(vector<string> args, int idx, int LINE_NUM, T t, V... v) {
    if(idx == 0) cerr << "Line(" << LINE_NUM << ") ";
    cerr << args[idx] << " = ";
    __print(t);
    if (sizeof...(v)) {
        cerr << ", ";
    }
    _print(args, idx+1, LINE_NUM, v...);
}
using i64 = long long int;
#define deb(...) _print(vec_splitter(#__VA_ARGS__), 0,  __LINE__, __VA_ARGS__)
#define int long long int
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
#define lop1(i,n) for(int i=1;i<=n;++i)
#define lopr(i,n) for(int i=n-1;i>=0;--i)
#define F first
#define S second
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define pb(x) push_back(x)
#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define fix(x) cout << setprecision(x) << fixed ;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto dist=uniform_int_distribution<int>(1,1e18);

void init_code(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("deb.txt", "w", stderr);
}

void timerEnd(){
    endTime;
    time_t end_time = chrono::system_clock::to_time_t(end1);
    cerr<< endl;
    cerr << "Executed at: " << ctime(&end_time) << endl;
    cerr << "Exec time: " << chrono::duration_cast<chrono::duration<double > >(end1 - begin1).count() << " seconds" << endl;
}

void presolve(){

    // a[1] = 1;a[2] = 2;a[3] =3;
    // for(int i=4;i<40005;i++){
    //     int k = a[i]; vector < int > b;
    //     while(k){
    //         b.pb(k%10);
    //         k = k/10;
    //     }
    //     int bs = b.size();
    //     if(bs == 3 or bs == 2){
    //         if(b[0] == b[bs-1]) k = 1;
    //         else k = 0;
    //     }
    //     else if(bs == 5 or bs == 4){
    //         if(b[0] == b[bs-1] and b[1] == b[bs-2]) k = 1;
    //         else k = 0;
    //     }
    //     else k =1;
    //     a[i] = a[i-1]+1+k;
    // }

}

// imXinora
// xinora5110@topyte.com 