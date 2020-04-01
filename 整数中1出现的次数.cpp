#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	if(n<=0) return 0;	
    	char strN[50];
    	sprintf(strN,"%d",n);
    	cout<<"dealing with "<<strN<<endl;
    	return NumberOf1(strN);
	}
	
	int NumberOf1(const char * strN){
		if(!strN||*strN<'0'||*strN>'9'||*strN=='\0')
	        return 0;
	        
	    int first = *strN - '0';
		unsigned int length = static_cast<unsigned int>(strlen(strN));
		//为最后1位做处理	
		if(length == 1 && first == 0){
			return 0;
		}
		if(length ==1 && first >0){
			return 1;
		}
		//处理最高位 
		int numFirstDigit = 0;
		if(first > 1){
			numFirstDigit = PowerBase10(length-1);
		}else if(first ==1){ //留心这里的判断，必须时first == 1, 不能省略 
			numFirstDigit = atoi(strN+1) + 1;
		}		
		//处理后几位
		int numOtherDigits = first * (length-1) *PowerBase10(length-2); 
		//处理构造范围剩下的数
		int numRecursive = NumberOf1(strN+1); 
		return numFirstDigit + numOtherDigits + numRecursive;		
	}
	int PowerBase10(int n){
		int result = 1;
		for(int i = 0;i<n;i++){
			result *= 10;
		}
		return result;
	}   
};

int main(){
	Solution s;
	cout<<s.NumberOf1Between1AndN_Solution(321);
	return 0;
}
