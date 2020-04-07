#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    	if(data.size() == 0) return;
		//依次做异或运算
		int resultofxor=0;
		int lengthofdata = data.size();
		for(int i =0;i<lengthofdata;i++){
			resultofxor^=data[i];
		}
		cout<<"resultofxor = "<<resultofxor<<endl;
		//找到异或结果第一个等于1的位置（从右到左） 
		unsigned int indexbit = FindFirstOneInNum(resultofxor);
		cout<<"indexbit = "<<indexbit<<endl;
		//把数组分成两部分，分别异或
		*num1 = 0;
		*num2 = 0;
		for(int i =0;i<lengthofdata;i++){
			if(isBitn(data[i],indexbit)){
				*num1 ^= data[i]; 
			}else{
				*num2 ^= data[i]; 
			}
		}  
		return;
    }
    
    unsigned int FindFirstOneInNum(int num){
    	//找一个数的二进制的第一个1
		 unsigned int indexbit = 0;
		 cout<<"num&1 = "<<(num&1)<<endl;
		 cout<<"(num&1)==0 = "<<((num&1)==0)<<endl;
		 cout<<"(indexbit<8*sizeof(int)) = "<<(indexbit<8*sizeof(int))<<endl;
		 while((((num&1)==0) && (indexbit<8*sizeof(int)) )){//要注意这里的括号 
		 	num = num>>1;
		 	indexbit++;
		 }
		 return indexbit;
	} 
	
	bool isBitn(int num,unsigned int indexbit){
		//判断一个数的第 indexbit位（从右到左）是否为1 
		num = num>>indexbit;
		return (num&1); 
	}
};

int main(){
	vector<int> data{2,4,3,6,3,2,5,5};
	Solution s;
	int a,b;
	s.FindNumsAppearOnce(data,&a,&b);
	cout<<a<<" "<<b<<endl;
	return 0;
} 
