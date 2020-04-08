#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;
        deque<int> candidate;//maxcandidate;
        if(num.size()==0 || size == 0||num.size()<size) return result;
        //num.size() < size ��ô�����أ�ֱ�ӷ������ֵ��
		 
		 int i = 0;
		 //�ȴ����һ�Σ�δ���������ڵĲ��� 
		 for(;i<size&&i<num.size();i++){
		 	cout<<num[i]<<" ";
		 	if(candidate.empty()){
		 		candidate.push_back(i);
			 }else{
			 	while(!candidate.empty() && num[candidate.back()] < num[i]){
			 		candidate.pop_back();
				}
			 	candidate.push_back(i);
			 }
		 }
		 result.push_back(num[candidate.front()]);
		 
		 //�������Ĳ��֣�ÿ����һ����Ԫ�أ�������һ�����ֵ
		 for(;i<num.size();i++){
		 	//��С�±� i-(szie-1)
		 	cout<<num[i]<<" ";
			 while(!candidate.empty() && candidate.front() < (i-(size-1))){
			 	candidate.pop_front();
			 } 
			 while(!candidate.empty() && num[candidate.back()] < num[i]){
			 		candidate.pop_back();
			 }
			 candidate.push_back(i);
			 result.push_back(num[candidate.front()]);
		 } 
		 
		 return result;
		 
    }
};

int main(){
	Solution s;
	//16,14,12,10,8,6,4],5 
	//vector<int> result = s.maxInWindows({2,3,4,2,6,2,5,1},3);
	vector<int> result = s.maxInWindows({16,14,12,10,8,6,4},5);
	for(int i =0;i<result.size();i++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
