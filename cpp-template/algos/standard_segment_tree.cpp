/* author: (g)theoden42 */
#include <bits/stdc++.h>
using namespace std;

struct SegTree {
	struct node {
        //change code here
	};
	
	//neutral element here
    node iden = {};
	// fix these two functions
	node combine(node& a, node& b){
 		node t;
        // how to combine two nodes
 		return t;
 	}
 	node single_value(int v){
 		node t;
        // what to store in leaves corresponding to array value v
 		return t;
 	}
    
	int sz = 1;
	vector<node> arr;
	void init(int n){
		while(sz < n){
			sz *= 2;
		}
		arr.resize(2 * sz, iden);
	}

	void build(vector<int>& a){
		build(a, 0, 0, sz);
	}

	void set(int ind, int value){
		setUtil(ind, value, 0, 0, sz);
	}

	node get(int l, int r){
		return getUtil(l, r, 0, 0, sz);
	}

	void build(vector<int>& a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				arr[x] = single_value(a[lx]);
			}	
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	}

	node getUtil(int l, int r, int x, int lx, int rx){
		if(lx >= l && rx <= r){
			return arr[x];
		}
		else if(lx >= r || rx <= l){
			return iden;
		}
		int m = (lx + rx) / 2;
		getUtil(l, r, 2 * x + 1, lx, m);
		getUtil(l, r, 2 * x + 2, m, rx);
		return combine(arr[2 * x + 1], arr[2 * x + 2]);
	}

	void setUtil(int ind, int val, int x, int lx, int rx){
		if(rx - lx == 1){
			arr[x] = single_value(val);
			return;
		}

		int m = (lx + rx) / 2;
		if(ind < m){
			setUtil(ind, val, 2 * x + 1, lx, m);
		}
		else{
			setUtil(ind, val, 2 * x + 2, m, rx);
		}

		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	}
};
