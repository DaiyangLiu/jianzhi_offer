#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
//�����ѵİ취
//push_heap(): vector�� push_back(), push_heap()
//����Ԫ�ص�����
//9 8 2 6 7 0 1 4 3 5 
//v.push_back(10)
// 9 8 2 6 7 0 1 4 3 5 10 
//push_heap(v.begin(),v.end(),less<int>()) 
//10 9 2 6 8 0 1 4 3 5 7  

//pop_heap(): ��pop_heap(),vector��pop_back()
//�������ѵ����Ԫ�� 
// 9 8 2 6 7 0 1 4 3 5 
//pop_heap(v.begin(),v.end(),less<int>())
//8 7 2 6 5 0 1 4 3 9  
//v.pop_back() 
// 8 7 2 6 5 0 1 4 3
class Solution {
public:
    void Insert(int num)
    {
    	if(  ((min.size()+max.size()) & 1) == 0 ) {//�Ѵ�����Ϊż�� ������������С�� 
    		
    		if(max.size()>0 && num < max[0]){  //��������Ƿ� С�����ѵ�����������ǣ�����Ҫ�������֡� 
    			//�������������� 
    			max.push_back(num);
    			push_heap(max.begin(),max.end(),less<int>());
    			
				//��ȡ���ѵ������ 
				num = max[0];
				
				//��������������� 
				pop_heap(max.begin(),max.end(),less<int>());
				max.pop_back(); 
			}
		
			min.push_back(num);
    		push_heap(min.begin(),min.end(), greater<int>());
		}else{//�Ѵ�����Ϊ���� �������������� 
			if(min.size()>0 && num > min[0] ){ //��������Ƿ������С�ѵ���С��
			    //������������С��
				min.push_back(num);
				push_heap(min.begin(),min.end(),greater<int>());
				//��ȡ��С����С��
				num=min[0];
				//������С��
				pop_heap(min.begin(),min.end(),greater<int>());
				min.pop_back();   
			}
			max.push_back(num);
			push_heap(max.begin(),max.end(),less<int>());
		}

        
    }

    double GetMedian()
    { 
        if(max.size() == 0 && min.size() == 0) return 0;
        if(max.size() == min.size()){
        	return (max[0]+min[0])/2.0;
		}else{
			if(max.size()>min.size()){
				return max[0];
			}else{
				return min[0];
			}
		}
    
    }
public:
	vector<int> min;  //��С�� 
	vector<int> max;  //���� 

};

int main(){
	
	Solution s;
	for(int i = 0;i<10;i++){
		s.Insert(i);
	}
	cout<<"min"<<endl;
	for(int i =0;i<s.min.size();i++){
		cout<<s.min[i]<<" ";
	}
	cout<<endl<<"max"<<endl;
	for(int i =0;i<s.max.size();i++){
		cout<<s.max[i]<<" ";
	}
	cout<<endl;
	cout<<s.GetMedian()<<endl;
	
	return 0;
}
