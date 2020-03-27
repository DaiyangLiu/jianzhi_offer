#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
//调整堆的办法
//push_heap(): vector先 push_back(), push_heap()
//插入元素到最大堆
//9 8 2 6 7 0 1 4 3 5 
//v.push_back(10)
// 9 8 2 6 7 0 1 4 3 5 10 
//push_heap(v.begin(),v.end(),less<int>()) 
//10 9 2 6 8 0 1 4 3 5 7  

//pop_heap(): 先pop_heap(),vector再pop_back()
//弹出最大堆的最大元素 
// 9 8 2 6 7 0 1 4 3 5 
//pop_heap(v.begin(),v.end(),less<int>())
//8 7 2 6 5 0 1 4 3 9  
//v.pop_back() 
// 8 7 2 6 5 0 1 4 3
class Solution {
public:
    void Insert(int num)
    {
    	if(  ((min.size()+max.size()) & 1) == 0 ) {//已存总数为偶数 ，新数插入最小堆 
    		
    		if(max.size()>0 && num < max[0]){  //检查新数是否 小于最大堆的最大数，如是，则需要交换数字。 
    			//将新数插入最大堆 
    			max.push_back(num);
    			push_heap(max.begin(),max.end(),less<int>());
    			
				//获取最大堆的最大数 
				num = max[0];
				
				//将最大堆最大数弹出 
				pop_heap(max.begin(),max.end(),less<int>());
				max.pop_back(); 
			}
		
			min.push_back(num);
    		push_heap(min.begin(),min.end(), greater<int>());
		}else{//已存总数为奇数 ，新数插入最大堆 
			if(min.size()>0 && num > min[0] ){ //检查新数是否大于最小堆的最小数
			    //将新数插入最小堆
				min.push_back(num);
				push_heap(min.begin(),min.end(),greater<int>());
				//获取最小堆最小数
				num=min[0];
				//弹出最小数
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
	vector<int> min;  //最小堆 
	vector<int> max;  //最大堆 

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
