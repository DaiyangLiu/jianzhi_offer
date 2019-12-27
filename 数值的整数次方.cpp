#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
    //保证base和exponent不同时为0
    //替换fabs(base-0.0)<1e-8，不得使用库函数 
        //if(((base-0.0)<1e-8 || (0.0-base)<1e-8)  && exponent <= 0)
	    if(fabs(base-0.0)<1e-8  && exponent <= 0) //如果base为零，而exponent小于等于零，则无意义，返回零 
	    	return 0;
		if(exponent==0) return 1; //如果x为除零以外的任意数值，而exponent为0，则结果直接等于1 
		if(fabs(base-0.0)<1e-8) return 0;//如果base为零，而exponent为正数，则结果直接等于0 
		
		//目前只剩下base大于零小于零， exponent大于零小于零的情况
		//先对base求abs(exponent)的次方，如果exponent为负，则再求其结果的倒数
		//因为不得使用库函数，所以要换一种方式求  abs(exponent)
		unsigned int abs_exponent = (unsigned int) exponent; 
		if(exponent < 0){
			abs_exponent = (unsigned int)(-abs_exponent);
		}
		
		double result = 1.0;
		for(int i=0;i<abs_exponent;i++){
			result *= base;
		} 
		
		if(exponent<0){
			result = 1.0/result;
		}
		return result;
    }
    
    double Power2(double base, int exponent) {
    //递归方式 
	    if(fabs(base-0.0)<1e-8  && exponent <= 0) //如果base为零，而exponent小于等于零，则无意义，返回零 
	    	return 0;
		if(exponent==0) return 1; //如果x为除零以外的任意数值，而exponent为0，则结果直接等于1 
		if(fabs(base-0.0)<1e-8) return 0;//如果base为零，而exponent为正数，则结果直接等于0 
		
		
		unsigned int abs_exponent = (unsigned int) exponent; 
		if(exponent < 0){
			abs_exponent = (unsigned int)(-abs_exponent);
		}
		
		double result = circle(base, abs_exponent);
		if(exponent<0){
			result = 1.0/result;
		}
		return result;
    }
    
    double circle(double base, unsigned int exponent){
    	
    	if(exponent == 1) return base;
    	//if(exponent == 2) return base*base;
    	
		//如何判定该数为奇数或是偶数呢
		//奇数 
    	if(exponent%2 == 1) return circle(base,(exponent-1)/2)*circle(base,(exponent-1)/2)*base;
    	else return circle(base,(exponent)/2)*circle(base,(exponent)/2);
	}
	
//===============书上示例========================================
  double Power3(double base, int exponent) {
        if(fabs(base-0.0)<1e-8  && exponent <= 0) //如果base为零，而exponent小于等于零，则无意义，返回零 
	    	return 0;
		if(exponent==0) return 1; //如果x为除零以外的任意数值，而exponent为0，则结果直接等于1 
		if(fabs(base-0.0)<1e-8) return 0;//如果base为零，而exponent为正数，则结果直接等于0 
		
		unsigned int abs_exponent = (unsigned int) exponent; 
		if(exponent < 0){
			abs_exponent = (unsigned int)(-abs_exponent);
		}
		double result  = circle2(base,abs_exponent>>1);
		result *= result; 
		if((abs_exponent & 0x1) == 1){//是奇数 
			result *=base; 
		}
       	if(exponent<0){
			result = 1.0/result;
		}
		return result;
    }
    
    double circle2(double base, unsigned int exponent){
    	
    	double result = 1.0;
		for(int i=0;i<exponent;i++){
			result *= base;
		} 
		return result;
	}
//===============书上示例========================================

};


int main(){
	double base;
	int exponent;
	Solution s;
	while(cin>>base>>exponent){
        cout<< s.Power3(base,exponent) <<endl;
	}
	return 0;
} 
