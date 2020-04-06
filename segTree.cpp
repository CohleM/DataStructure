#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int st[N];

//takes O(logn) time

void update(int left,int right,int ind,int value,int root) {

	if(ind > right || ind < left )
		return;
	//first update itself and then it's children
	st[root] = st[root] + value;
	//updates from top to bottom 
	if(left != right ){
		int mid = (left + right ) / 2;
		update(left,mid,ind,value,2*root + 1);
		update(mid + 1,right,ind,value,2*root + 2);
	}

}
int query(int left,int right ,int gl,int gr,int ind){

	if( left >= gl && right <= gr) return st[ind];
	if(left > gr || right < gl) return 0;
	
	int mid = ( left + right) / 2;
	return query(left, mid ,gl,gr,2*ind+1) + query(mid+1,right,gl,gr,2*ind+2);
}
//takes O(N) time 
int createSegtree(int *arr,int left,int right,int ind){

	if(left == right) {
		st[ind] = arr[left]; 
		return arr[left];
	}
		int mid = ( left + right) / 2;
		st[ind] = createSegtree(arr,left, mid , 2*ind + 1) + createSegtree(arr,mid + 1,right, 2*ind + 2);
		return st[ind];
	
}

int main(){
	 #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int arr[] = {1,3,5,7,9,11};
	createSegtree(arr,0,5,0);
	for(int i =0; i <=15; i++) cout << st[i] << "   ";
	cout <<"\n";
	cout << query(0,5,1,3,0) <<"querrryyyy\n";

	int diff = 10 - arr[1];
	arr[1] = 10;
	update(0,5,1,diff,0);

		for(int i =0; i <=15; i++) cout << st[i] << "   ";
	//int st[2*5-1];
	//createSegtree(st,arr);
	return 0;
}