#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
	public:
    int DigitAtIndex(int n){
    	if(n<10) return n;
    	
    	int digit = 1;
    	int sumoffront =0;
    	
    	while(true){		
    		n -= sumoffront;
    		sumoffront = SumOfFrontNum(digit);	
    		if(n<sumoffront) break;
    		digit++;
		}
		
		int basenum = n/digit;
		int indexinnum = n%digit;
		cout<<basenum<<" "<<indexinnum<<endl;
		int start = pow(10,digit-1);
		int  num = start + basenum;
		cout<<start<<" "<<num<<endl;
		int result;
		//求一个数字的第 x 位 ，从右往左算
		int indexfromright = digit - indexinnum;
		for(int i =1;i<digit;i++){
			int temp = num%10; 
			if(indexfromright == i){
				result = temp;
				break;
			}
			num/=10;
		}
    	return result;
	}
	
	int SumOfFrontNum(int digit){
		if(digit <1) return 0;
		if(digit == 1){
			return 10;
		}		
		return digit*9 * pow(10,digit-1);
	}
} ;

class Solutionjianzhi{
	public:
	int digitAtIndex(int index){
		if(index< 0) return -1;
		
		int digits = 1;
		while(true){
			int numbers = countOfIntegers(digits);
			if(index <numbers * digits){
				return digitAtIndex(index,digits);
			}
			index-=digits*numbers;
			digits++;
		}
		return -1;
	}
	int countOfIntegers(int digits){
		if(digits == 1)return 10;
		
		int count = (int)pow(10,digits-1);
		return 9*count;
	}
	int digitAtIndex(int index,int digits){
		int number = beginNumber(digits) + index/digits;
		int indexFromRight = digits - index%digits;
		for(int i =1;i<indexFromRight;i++){
			number/=10;
		}
		return number%10;
	}
	int beginNumber(int digits){
		if(digits==1) return 0;
		
		return pow(10,digits-1);
	}
};

int main(){
	Solution s;
	cout<<s.DigitAtIndex(1001)<<endl;
	Solutionjianzhi sj;
	cout<<sj.digitAtIndex(1001)<<endl;
	return 0;
} 
