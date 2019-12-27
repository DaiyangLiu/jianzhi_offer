#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
    //��֤base��exponent��ͬʱΪ0
    //�滻fabs(base-0.0)<1e-8������ʹ�ÿ⺯�� 
        //if(((base-0.0)<1e-8 || (0.0-base)<1e-8)  && exponent <= 0)
	    if(fabs(base-0.0)<1e-8  && exponent <= 0) //���baseΪ�㣬��exponentС�ڵ����㣬�������壬������ 
	    	return 0;
		if(exponent==0) return 1; //���xΪ���������������ֵ����exponentΪ0������ֱ�ӵ���1 
		if(fabs(base-0.0)<1e-8) return 0;//���baseΪ�㣬��exponentΪ����������ֱ�ӵ���0 
		
		//Ŀǰֻʣ��base������С���㣬 exponent������С��������
		//�ȶ�base��abs(exponent)�Ĵη������exponentΪ���������������ĵ���
		//��Ϊ����ʹ�ÿ⺯��������Ҫ��һ�ַ�ʽ��  abs(exponent)
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
    //�ݹ鷽ʽ 
	    if(fabs(base-0.0)<1e-8  && exponent <= 0) //���baseΪ�㣬��exponentС�ڵ����㣬�������壬������ 
	    	return 0;
		if(exponent==0) return 1; //���xΪ���������������ֵ����exponentΪ0������ֱ�ӵ���1 
		if(fabs(base-0.0)<1e-8) return 0;//���baseΪ�㣬��exponentΪ����������ֱ�ӵ���0 
		
		
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
    	
		//����ж�����Ϊ��������ż����
		//���� 
    	if(exponent%2 == 1) return circle(base,(exponent-1)/2)*circle(base,(exponent-1)/2)*base;
    	else return circle(base,(exponent)/2)*circle(base,(exponent)/2);
	}
	
//===============����ʾ��========================================
  double Power3(double base, int exponent) {
        if(fabs(base-0.0)<1e-8  && exponent <= 0) //���baseΪ�㣬��exponentС�ڵ����㣬�������壬������ 
	    	return 0;
		if(exponent==0) return 1; //���xΪ���������������ֵ����exponentΪ0������ֱ�ӵ���1 
		if(fabs(base-0.0)<1e-8) return 0;//���baseΪ�㣬��exponentΪ����������ֱ�ӵ���0 
		
		unsigned int abs_exponent = (unsigned int) exponent; 
		if(exponent < 0){
			abs_exponent = (unsigned int)(-abs_exponent);
		}
		double result  = circle2(base,abs_exponent>>1);
		result *= result; 
		if((abs_exponent & 0x1) == 1){//������ 
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
//===============����ʾ��========================================

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
