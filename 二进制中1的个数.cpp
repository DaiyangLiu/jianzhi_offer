#include <cstdio>
#include <iostream>
using namespace std;

 
class Solution {
public:
     int  NumberOf1(int n) {
     	//���������ƶ�flag����Ψһ��1ȥ��������������м��� 
         unsigned int flag = 1;
         int count = 0;
         //32λ����������Ҫѭ��32�� 
         while(flag){ 
		 //��ֹ������ʲô������ 
		 //������while(flag <= n)����Ϊһ��n�Ǹ��������������������������Ͳ����� 
         	if(n&flag){
         		count++;
			 }
			 cout<<"now flag= "<<flag<<endl;
         	flag = flag<<1;
		 }
		 return count;
     }
     
     int  NumberOf1_plan2(int n) {
        //����n �� n-1����Ĳ��������Խ�n���ұߵ�1��Ϊ�㡣
		//�Ӷ����Խ�������ͬ���Ĳ�����ֱ����n�е�����1 ����Ϊ�� 
        int count = 0;         
        while(n){
        	n = n&(n-1);
        	count++;
		}
		return count;
     }
};

int main(){
	int n;
	Solution s;
	while(cin>>n){
		cout<<"counting "<<n<<endl;
		cout<<"answer: "<<s.NumberOf1_plan2(n)<<endl;	
	}
	return 0;
}
