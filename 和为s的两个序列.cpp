#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
 

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    	vector<int> result;
		if(array.size() <= 1 ) return result;
        int ahead = 0,behead = array.size()-1;
        
        while(ahead < behead){
        	int temp = array[ahead] +array[behead];
        	if(temp == sum){
        		result.push_back(array[ahead]);
        		result.push_back(array[behead]);
        		break;
			}else if(temp>sum){
				behead--;
			}else if(temp<sum){
				ahead++;
			}
		}
		return result;
    }
};

int main(){
	vector<int> data={1,2,4,7,11,15};
	Solution s;
	vector<int> result = s.FindNumbersWithSum(data,15);
	for(int i =0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
