#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindNumsAppearOnce(vector<int> data){
    	if(data.size()==0) return -1;
    	int countbit[32] = {0};
    	int length = data.size();
    	for(int i = 0; i<length;i++){
    		//数字的哪一位不为零，就存进countbit的哪一个元素
			int bitMask =1;
			for(int j = 31;j>=0;j--){//31表示最低位 
				int bit = data[i]&bitMask;
				if(bit!=0){
					countbit[j]++;
				}
				bitMask=bitMask<<1;
			}
		}
		
		int result = 0 ;
		for(int i =0;i<32;i++){ //注意下面这两个语句的顺序 	注释里这个顺序就是错的 result += countbit[i]%3; result= result<<1;，
		//想象如果此时i=31，则做了加法运算之后，又左移一位，岂不是就又把个位给空出来了 
			result= result<<1;
			result += countbit[i]%3;		
		}
    	return result;
	} 
};

int main(){
	vector<int> data{1,1,1,2,2,2,3};
	Solution s;
	cout<<s.FindNumsAppearOnce(data);
	return 0;
}
