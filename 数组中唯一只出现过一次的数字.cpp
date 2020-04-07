#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int FindNumsAppearOnce(vector<int> data){
    	if(data.size()==0) return -1;
    	int countbit[32] = {0};
    	int length = data.size();
    	for(int i = 0; i<length;i++){
    		//���ֵ���һλ��Ϊ�㣬�ʹ��countbit����һ��Ԫ��
			int bitMask =1;
			for(int j = 31;j>=0;j--){//31��ʾ���λ 
				int bit = data[i]&bitMask;
				if(bit!=0){
					countbit[j]++;
				}
				bitMask=bitMask<<1;
			}
		}
		
		int result = 0 ;
		for(int i =0;i<32;i++){ //ע����������������˳�� 	ע�������˳����Ǵ�� result += countbit[i]%3; result= result<<1;��
		//���������ʱi=31�������˼ӷ�����֮��������һλ�����Ǿ��ְѸ�λ���ճ����� 
			result= result<<1;
			result += countbit[i]%3;		
		}
    	return result;
	} 
};

int main(){
	vector<int> data{1,1,1,2,2,2,3};
	Solution s;
	cout<<s.FindNumsAppearOnce(data);
	return 0;
}
