#include <cstdio>
#include <iostream>
#include <string> 
#include <vector> 
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        vector<int> copy(data);
		
		long long  result = InversePairsCore(copy,data,0,data.size()-1);//在牛客网上，数组的较长，逆序对可能会很多，所以用long long 
		return result%1000000007;
    }
    
    long long InversePairsCore(vector<int> &copy, vector<int> &data, int start,int end){
    	if(start == end) return 0;
    	
    	int length = (end-start)/2;
    	long long left = InversePairsCore(copy, data, start,start+length);
    	long long right = InversePairsCore(copy, data, start+length+1,end);

    	long long count = 0;
    	int i = start + length;
    	int j = end;
    	int indexcopy = end;

    	while(i>=start && j>= (start+length+1)){
    		if(data[i] > data[j] ){
    			copy[indexcopy--] = data[i--];
    			count+= j -start-length;
			}else{
				copy[indexcopy--] = data[j--];
			}
		}
		while(i>=start){
			copy[indexcopy--] = data[i--];
		}
    	
    	while(j>= (start+length+1)){
    		copy[indexcopy--] = data[j--];
		}
		//data = copy; //如果使用这个语句，会赋值在这个函数之外的数组部分，浪费时间 
		for(int k = start;k<=end;k++){
			data[k] = copy[k];
		}
    	return left + right +count;
	}
    
};

int main(){
	vector<int> data = {7,5,6,4};
	Solution s;
	cout<<s.InversePairs(data)<<endl;
	return 0;
}
