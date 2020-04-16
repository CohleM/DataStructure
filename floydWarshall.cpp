#include <bits/stdc++.h>
using namespace std;

signed main() {
    
	int n; cin >>n;
	int a[n][n];
	//takes edges of the graph
	for(int i = 0; i <n; i++){
		for(int j = 0; j<n; j++){
			cin >>a[i][j];
		}
	}
	//floyd warshall 
	for(int k = 0;  k< n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
			}
		}

	}
	int q; cin >>q;
	while(q--){
		int x,y,z; cin>>x>>y>>z;
		//query on the final matrix
		cout << a[x][y] + a[y][z] <<" "<< ( a[x][y] + a[y][z] ) - a[x][z]<<"\n"; 
	}
	return 0;
}