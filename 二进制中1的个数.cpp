#include <cstdio>
#include <iostream>
using namespace std;

 
class Solution {
public:
     int  NumberOf1(int n) {
     	//本方法是移动flag，用唯一的1去进行与操作，进行计算 
         unsigned int flag = 1;
         int count = 0;
         //32位的整数，需要循环32次 
         while(flag){ 
		 //终止条件是什么？？？ 
		 //不能是while(flag <= n)，因为一旦n是负数或者是最大的正数，该条件就不成立 
         	if(n&flag){
         		count++;
			 }
			 cout<<"now flag= "<<flag<<endl;
         	flag = flag<<1;
		 }
		 return count;
     }
     
     int  NumberOf1_plan2(int n) {
        //利用n 与 n-1相与的操作，可以将n最右边的1变为零。
		//从而可以进行数次同样的操作，直到把n中的所有1 都变为零 
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
