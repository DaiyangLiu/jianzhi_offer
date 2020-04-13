#include <cstdio>
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> B; 
		if(A.size()==0) return B;
		int length = A.size();
    	vector<int> C;
    	vector<int> D;
    	C.push_back(1);
    	for(int i=1;i<length;i++){   		
    		C.push_back(C.back() * A[i-1]);
		}
		D.push_back(1);
		for(int i=length-2;i>=0;i--){
			D.push_back(D.back() * A[i+1]);
		}
		reverse(D.begin(),D.end());
		for(int i=0;i<length;i++){
			B.push_back(C[i]*D[i]);
		}
		return B;
    }
};

int main(){
	Solution s;
	vector<int> A={1,2,3,4,5,6};
	vector<int> B;
	B = s.multiply(A);
	for(int i=0;i<B.size();i++){
		cout<<B[i]<<" ";
	}
	return 0;
}
