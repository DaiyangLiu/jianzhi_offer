#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
	int GetMissingNumber(vector<int> data){
		if(data.size()==0) return -1;
		int length = data.size();//n-1
		int missingn = -1;
		int mid;
		int start = 0,end = length-1;
		
		while(start<=end){			
		    cout<<"start = "<<start<<" end = "<<end<<endl;
			mid = (start+end)>>1;
			if(mid == data[mid]){
				start = mid +1;
				if(start>end){
					missingn = start;
				}
			}else if(mid < data[mid]){
				if(mid == 0){
					missingn = mid;
					break;
				}else if(mid>0 && data[mid-1] == (mid-1)){
					missingn = mid;
					break;
				}else{
					end = mid;
				}
			}		
		}
		return missingn;
	}
}; 

int main(){
	vector<int> data = {0,1,2,3};
	Solution s;
	cout<<s.GetMissingNumber(data)<<endl;
	return 0;
}
