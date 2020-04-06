#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
	int GetNumberSameAsIndex(vector<int> data){
		if(data.size()==0) return -1;
		int length = data.size();//n-1
		int mid;
		int start = 0,end = length-1;
		int result = -1;
		while(start<=end){
		cout<<"start = "<<start<<" end = "<<end<<endl;			
		 	mid = (start + end)>>1;
		 	
			if(mid > data[mid]){
				start = mid + 1;				
			}
			if(mid < data[mid]){
				end = mid - 1;
			}
			if(mid == data[mid]){
				result = mid;
				break;
			}
		}
		return result;
	}
}; 

int main(){
	vector<int> data = {-3,-1,1,3,5};
	Solution s;
	cout<<s.GetNumberSameAsIndex(data)<<endl;
	return 0;
}
