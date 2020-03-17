#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	stack<int> sdata;
	
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {	
        int lengthpush = pushV.size();
		int lengthpop = popV.size();
		
		if(lengthpush==0 && lengthpop == 0 ) return true;
		if(lengthpush!=lengthpop) return false;
		
        int pushtag=0;
        bool order = true;
		for(int i =0;i<lengthpop;i++){
			if(sdata.empty()){
				sdata.push(pushV[pushtag++]);
			}
			while(sdata.top()!= popV[i] &&pushtag< lengthpush){
				sdata.push(pushV[pushtag++]);
			}
			if(sdata.top()== popV[i]){
				sdata.pop();
				continue;
			}else{
				order = false;
				break;
			}
		}
		return order; 
    }
};


int main(){
	Solution s;
//	vector<int> pushV={1,2,3,4,5};
//	vector<int> popV = {4,3,5,1,2};
		vector<int> pushV={1,2,3};
	vector<int> popV = {3,1,2};
	cout<<s.IsPopOrder(pushV,popV)<<endl;
	return 0;
}
