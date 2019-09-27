#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std; 

//动态规划版本 
class Solution {
public:
    int cutRope(int number) {
    	//动态规划版本 
        if(number<2) return 0;
        if(number==2) return 1;
        if(number ==3 ) return 2;
        
        int *products= new int[number+1];
        
        products[0]=0;
        products[1]=1;
        products[2]=2;
        products[3]=3;
        
        for(int i = 4;i<= number;i++){
        	int max=0,temp;
        	for(int j=0;j<=i/2;j++){
        		temp = products[j]*products[i-j];
        		if(temp>max){
        			max = temp;
				}
			}
        	products[i] = max;
		}
		int ans = products[number];
		delete[] products;
		return ans;
    }
    
    int cutRopeGreed(int number) {
    	//贪心算法版本 
        if(number<2) return 0;
        if(number==2) return 1;
        if(number ==3 ) return 2;
		
		//n>=5的情况
		int times=number /3;
		int last = number - times*3;  
		if(last == 1) return pow(3,times-1) *4;
		if(last == 2) return pow(3,times) *2;
		if(last == 0) return pow(3,times); 
    }
    
    int cutRopeGreedJianzhi(int number) {
    	//贪心算法版本   书上示例 
        if(number<2) return 0;
        if(number==2) return 1;
        if(number ==3 ) return 2;
		
		//n>=5的情况
		int timesOf3=number /3;
		if(number - pow(3,timesOf3) == 1){
			timesOf3--;
		}
		
		int timesOf2 = (number -timesOf3 * 3)/2;
		cout<<timesOf2<<endl;
		return (int)(pow(3,timesOf3)) * (int)(pow(2,timesOf2));
    }
};


int main(){
	Solution s;
	cout<<s.cutRope(8)<<endl;
	cout<<s.cutRopeGreed(8)<<endl;
	cout<<s.cutRopeGreedJianzhi(8)<<endl;
	return 0;
}
