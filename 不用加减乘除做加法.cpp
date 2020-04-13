#include <cstdio>
#include <iostream>
using namespace std;
 
class Solution {
public:
    int Add(int num1, int num2)
    {
    	int sum=0,carry=0;
    	do{
    		sum = num1^num2;
    		carry = (num1&num2)<<1; //需要进位相加的1 
    		num1=sum;
    		num2=carry;
		}while(num2!=0);
		return sum;

    }
};

int main(){
	
	Solution s;
	
	cout<<s.Add(5,17);
	return 0;
}
