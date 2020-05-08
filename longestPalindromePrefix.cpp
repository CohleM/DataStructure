//KMP log(n) solution to find long suffix palindrome.
#include <bits/stdc++.h> 

using namespace std; 

  
// Function used to calculate the longest prefix 
// which is also a suffix 

int kmp(string s) 
{ 
    vector<int> lps(s.size(), 0); 
    for (int i = 1; i < s.size(); i++) { 
        int previous_index = lps[i - 1]; 
        while (previous_index > 0 && s[i] != s[previous_index]) { 
            previous_index = lps[previous_index - 1]; 
        } 
        lps[i] = previous_index + (s[i] == s[previous_index] ? 1 : 0); 

    } 

     // Returns size of lps 

    return lps[lps.size() - 1]; 
} 

int main() {

	string s("dfdce");
	string r = s;
	s += "#";
	reverse(r.begin(), r.end());

	s += r;
	cout <<kmp(s)<<"\n";
	//solve();

	return 0;
}