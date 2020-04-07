#include <bits/stdc++.h>
using namespace std;


void update(int* bitTree,int* arr,int index ,int val){
	//12 is the length of bitTree
	index +=1;
	while(index <= 12) {
		bitTree[index] += val;
		index = index + (index & (-index));		
	}
}


void create(int* bitTree,int* arr,int length){
	for(int i = 0; i < length; i++) update(bitTree,arr,i,arr[i]);
}


int getSum(int* bitTree,int index) {
	index +=1;
	int sum = 0;
	while(index > 0){
		cout << bitTree[index] << "gg"<<endl;
		sum += bitTree[index];
		index = index - (index & (-index));
	}
	return sum;
}

int main() {
	int arr[] =  {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int bitTree[12+1] = {0};
	create(bitTree,arr,12);
	//point update // range query
	//update(bitTree,arr,5,2);
	cout << getSum(bitTree,6) - getSum(bitTree,5) << "\n";
	cout <<"0  ";
	for( int a : arr) cout << a << "  "; 
	cout <<"0  \n";
	for( int a : bitTree ) cout << a << "  "; 
	return 0;
}