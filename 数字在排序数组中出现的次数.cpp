#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
 
 
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()==0) return 0;
        cout<<"find first k"<<endl;
        int first = GetFirstK(data,k,0,data.size()-1);
        cout<<"find end k"<<endl;
        int last = GetLastK(data,k,0,data.size()-1);
        int result = 0;
        if(first>-1 && last>-1 ){
        	cout<<"first = "<<first<<" last = "<<last<<endl;
        	result = last-first+1;
		}
		return result;
    }
    
    int GetFirstK(vector<int> data ,int k,int start, int end){
    	cout<<"GetFirstK"<<" start = "<<start<<" end = "<<end<<endl;
    	if(start>end){
    		return -1;
		}
		int mid = (start+end)/2;
		
		if(data[mid] == k){
			if(mid == 0){
				return mid;
			}else if(mid>0 &&data[mid-1]!=k){
				return mid;
			}else if(mid>0 &&data[mid-1]==k){
				end = mid-1;
			}
		}
		
		if(k<data[mid]){
			end = mid -1;
		}
		if(k>data[mid]){
			start = mid+1;
		}
		return GetFirstK(data,k,start,end);
	}
	
	int GetLastK(vector<int> data ,int k,int start, int end){
		cout<<"GetLastK"<<" start = "<<start<<" end = "<<end<<endl;
    	if(start>end){
    		return -1;
		}
		int mid = (start+end)/2;
		
		if(data[mid] == k){
			if(mid == data.size()-1){
				return mid;
			}else if(mid<(data.size()-1) && data[mid+1]!=k){
				return mid;
			}else if(mid<(data.size()-1) && data[mid+1]==k){
				start = mid+1;
			}
		}
		
		if(k<data[mid]){
			end = mid -1;
		}
		if(k>data[mid]){
			start = mid+1;
		}
		return GetLastK(data,k,start,end);
	}
    
}; 
 
//class Solution {
//public://第一次写，递归部分太复杂 
//    int GetNumberOfK(vector<int> data ,int k) {
//        if(data.size()==0) return 0;
//        cout<<"find first k"<<endl;
//        int first = GetFirstK(data,k,0,data.size()-1);
//        cout<<"find end k"<<endl;
//        int last = GetLastK(data,k,0,data.size()-1);
//        int result = 0;
//        if(first>-1 && last>-1 ){
//        	cout<<"first = "<<first<<" last = "<<last<<endl;
//        	result = last-first+1;
//		}
//		return result;
//    }
//    
//    int GetFirstK(vector<int> data ,int k,int start, int end){
//    	cout<<"GetFirstK"<<" start = "<<start<<" end = "<<end<<endl;
//    	if(end==start){
//    		if(k!=data[start]){
//    			return -1;
//			}else{
//				return start;
//			}
//		}
//    	
//    	int result=-1;
//		int mid = (end+start)/2;
//    	if(k<data[mid]){
//    		if((mid-1)>=start){
//    			result = GetFirstK(data,k,start,mid-1);	
//			}
//		}else if(k>data[mid]){
//			if((mid+1)<=end){
//				result = GetFirstK(data,k,mid+1,end);
//			}
//		}else if(k==data[mid]){
//			if(mid>0&&data[mid-1] == k){
//				result = GetFirstK(data,k,start,mid-1);
//			}else if(mid>0&&data[mid-1] != k){
//				result = mid;
//			}else if(mid == 0 && data[mid] == k){
//				result = mid;
//			}
//		}
//    	return result;
//	}
//	
//	int GetLastK(vector<int> data ,int k,int start,int end){
//		cout<<"GetLastK"<<" start = "<<start<<" end = "<<end<<endl;
//		if(end==start){
//    		if(k!=data[start]){
//    			return -1;
//			}else{
//				return start;
//			}
//		}
//    	
//    	int result=-1;
//		int mid = (end+start)/2;
//    	if(k<data[mid]){
//    		if((mid-1)>=start){
//    			result = GetLastK(data,k,start,mid-1);
//			}
//		}else if(k>data[mid]){
//			if((mid+1)<=end){
//				result = GetLastK(data,k,mid+1,end);
//			}
//		}else if(k==data[mid]){
//			if((mid+1)<data.size()&&data[mid+1] == k){
//				result = GetLastK(data,k,mid+1,end);
//			}else if((mid+1)<data.size()&&data[mid+1] != k){
//				result = mid;
//			}else if(mid == (data.size()-1) && data[mid] == k){
//				result = mid;
//			}
//		}
//    	return result;
//	}
//};

int main(){
	vector<int> data = {3,3,3,3,4,5};
	Solution s;
	cout<<"find 3"<<endl;
	cout<<s.GetNumberOfK(data,3)<<endl;
	cout<<"find 1"<<endl;
	cout<<s.GetNumberOfK(data,1)<<endl;
	cout<<"find 0"<<endl;
	cout<<s.GetNumberOfK(data,0)<<endl;
	return 0;
}
