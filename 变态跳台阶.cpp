#include <cstdio>
#include <iostream>
#include <cmath> 
using namespace std;



class Solution {
public:
    int jumpFloorII(int number) {
    	
    	return pow(2,number-1);
    }
};

int main()
{
	Solution s;
	cout<<s.jumpFloorII(1)<<endl;
	cout<<s.jumpFloorII(2)<<endl;
	cout<<s.jumpFloorII(3)<<endl;
	return 0;
 } 
