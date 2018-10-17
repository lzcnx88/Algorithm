/* ****************************
Auther      : zj
Created Time: 2018年10月17日 星期三 20时00分11秒
File Name   : gc.cpp
***************************** */
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
using namespace std;
#define MAXN 27

int g[MAXN][MAXN];
int color[MAXN];
int m, n_v, sum;

bool isOk(int v){
	for(int i = 0;i < n_v; ++i){
		if(g[v][i] == 1 && color[v] == color[i]) 
			return false;
	}
	return true;
}

void graph_coloring(int v){
	if(v > n_v){
		sum++;
	}else{
		for(int i = 0;i < m; i++){
			color[v] = i;
			if(isOk(v)) graph_coloring(v+1);
			color[v] = -1;
		}
	}
}

int gc_least(int n){
	
	n_v = n;
	for(int i = 1; i <= 4; ++i){
		sum = 0, m = i;
		memset(color, -1, sizeof(color));
		graph_coloring(0);
		if(sum != 0) return i; 
	}
}

int main(){

	int T;
	while(cin >> T && T){
		string s;
		memset(g, 0, sizeof(g));

		for(int i = 0;i < T; ++i){
			cin >> s;
			int op = s[0] - 'A';
			for(int j = 2; j < s.size(); ++j){
				int ed = s[j] - 'A';
				g[op][ed] = 1;
			}
		}

		int res = gc_least(T);
		if(res == 1)
			cout << res << " channel needed." << endl;
		else
			cout << res << " channels needed." << endl;
	}

	return 0;
}
