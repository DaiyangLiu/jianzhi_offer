#include <cstdio>
#include <iostream>
#include <algorithm> 
using namespace std;
//ţ����������������������С�� 
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
    	if(numbers.size()<=4) return false;
    	int length = numbers.size();
        sort(numbers.begin(),numbers.end());
		//�ж��Ƿ�����������ͬ����(0����)������ֱ�ӷ���false
		for(int i = 0;i<length-1;i++){
			if(numbers[i]!=0 && numbers[i]==numbers[i+1]){
				return false;
			}
		} 
		int count_0 = 0,j=0;
		//ͳ��������� 
		while(j<length && numbers[j] == 0){
			count_0++;
			j++;
		}
		if(count_0 == 4) return true;//����鵽���ĸ�������ֱ�ӷ���true 
		// ʵ�����ֵ���ʼλ��Ϊ0+count_0 [count_0,5) 
		int times = length - count_0; //ʵ�����ֵĸ��� 
		times--;//�������һ���㣬����4��ʵ�����֣���ô��Щ����һ��Ҫ�Ƚ����� 
		for(int i = length-1; times>0 ; i--,times--){
			int n = numbers[i] - numbers[i-1] -1;
			count_0-=n;
			if(count_0<0) return false;
		}
		return true;	
    }
};

int main(){
	Solution s;
//	cout<<s.IsContinuous({0,1,5,4,3})<<endl;
//	cout<<s.IsContinuous({0,0,5,4,3})<<endl;
//	cout<<s.IsContinuous({0,7,5,4,3})<<endl;
//	cout<<s.IsContinuous({0,11,5,4,3})<<endl;
//	cout<<s.IsContinuous({0,0,0,4,3})<<endl;
//	cout<<s.IsContinuous({6,1,5,4,3})<<endl;
    cout<<s.IsContinuous({0,3,2,6,4})<<endl;
    cout<<s.IsContinuous({0,1,0,0,7})<<endl;
	return 0;
} 
