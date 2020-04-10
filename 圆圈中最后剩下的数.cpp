#include <cstdio>
#include <iostream>
#include <list>
using namespace std; 

class Solution {
public:
    int LastRemaining_Solution(int n, int m)//����һ��������ʽ�Ļ������� 
    {
    	if(n<1) return -1;
    	list<int> remain;
		for(int i=0;i<n;i++){
			remain.push_back(i);
		} 
		list<int>::iterator iter ; 
		iter = remain.begin();
		int count = m-1;
		while(remain.size()>1){
			
			while(count!=0){
				iter++;
				if(iter == remain.end()){//��֤������ָ��һ��ʵ�壬����remain.end() ,����while�е�ѭ�������ͻ᲻�� 
				    iter = remain.begin();
			    }
				count--;
			}
			iter = remain.erase(iter);		
			if(iter == remain.end()){//��֤������ָ��һ��ʵ�壬����remain.end() ,����while�е�ѭ�������ͻ᲻�� 
				iter = remain.begin();
			}
			count = m-1;			
		}
		
		return *(remain.begin());
        
    }
    
    
    int Reverse(int n, int m){
    	if(n<1) return -1;
    	int last = 0;
    	for(int i = 2;i<=n;i++){
    		last = (last+m)%i;
		}
		return last;
	}
};

int main(){
	Solution s;
	cout<<"ans = "<<s.LastRemaining_Solution(5,3)<<endl;//3
	cout<<"r ans = "<<s.Reverse(5,3)<<endl;
//	cout<<"ans = "<<s.LastRemaining_Solution(6,4)<<endl;
	cout<<"ans = "<<s.LastRemaining_Solution(6,7)<<endl;//4
	cout<<"r ans = "<<s.Reverse(6,7)<<endl;
	return 0;
}
