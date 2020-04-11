#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5;
int a[N];


void solve() {

	int a[] = {-2,-11,3,2,-1,2,-3};
	int max_for_some_blocks =  0; // start from 0 and check the sums 
	int max_among_all = a[0]; //let us suppose max of all is the initial block

	for(int i = 0; i <7; i++){	
		max_for_some_blocks = max_for_some_blocks + a[i];
		//if(max_among_all < max_for_some_blocks ) max_among_all = max_for_some_blocks; //or below code can be written
		max_among_all = max(max_for_some_blocks,max_among_all);

		if(max_for_some_blocks < 0) max_for_some_blocks = 0;
	}
	cout << max_among_all<<endl;
	

}	 
signed main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 //    #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
	int t=1;
	//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
