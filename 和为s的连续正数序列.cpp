#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        
        int small=1,big=2;
        int cursum = small + big;
        while(small<((1+sum)/2)){
        	
        	if(cursum == sum){
        		vector<int> ans;
        		for(int i = small;i<=big;i++){
        			ans.push_back(i);
				}
				result.push_back(ans);
				cursum -= small;
				small++;
			}else if(cursum > sum){
				cursum -=small;
				small++;
			}else if(cursum < sum){
				++big;
				cursum += big; 
			}
		}
		return result;
    }
};


int main(){
	Solution s;
	vector<vector<int> > result = s.FindContinuousSequence(15);
	for(int i =0;i<result.size();i++){
		for(int j = 0;j<result[i].size();j++)
		{
		    cout<<result[i][j]<<" ";	
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}

