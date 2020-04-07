#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    	if(data.size() == 0) return;
		//�������������
		int resultofxor=0;
		int lengthofdata = data.size();
		for(int i =0;i<lengthofdata;i++){
			resultofxor^=data[i];
		}
		cout<<"resultofxor = "<<resultofxor<<endl;
		//�ҵ��������һ������1��λ�ã����ҵ��� 
		unsigned int indexbit = FindFirstOneInNum(resultofxor);
		cout<<"indexbit = "<<indexbit<<endl;
		//������ֳ������֣��ֱ����
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
    	//��һ�����Ķ����Ƶĵ�һ��1
		 unsigned int indexbit = 0;
		 cout<<"num&1 = "<<(num&1)<<endl;
		 cout<<"(num&1)==0 = "<<((num&1)==0)<<endl;
		 cout<<"(indexbit<8*sizeof(int)) = "<<(indexbit<8*sizeof(int))<<endl;
		 while((((num&1)==0) && (indexbit<8*sizeof(int)) )){//Ҫע����������� 
		 	num = num>>1;
		 	indexbit++;
		 }
		 return indexbit;
	} 
	
	bool isBitn(int num,unsigned int indexbit){
		//�ж�һ�����ĵ� indexbitλ�����ҵ����Ƿ�Ϊ1 
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
