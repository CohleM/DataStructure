#include <bits/stdc++.h> 
#define RFOR(a,n) for(int i = a;  i< n; i++)
#define FOR(n) RFOR(0,n)
using namespace std;


int main() {
	int arr[] = {3,4,7,2,-3,1,4,2,1};
	int k = 7;
	unordered_map<int,int> prefixSum;

	int currSum = 0,cnt=0;
	FOR(9)
	{
		currSum += arr[i];
		if(currSum == k) cnt++;
		if(prefixSum.find(currSum - k) != prefixSum.end()) cnt += prefixSum[currSum - k];
		prefixSum[currSum]++;
	}

	cout <<cnt;

	return 0;
}