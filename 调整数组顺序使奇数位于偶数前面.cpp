#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        int even_tag = -1;
        int even_len = 0;
        int i = 0;
        cout<<"reorder"<<endl;
        while(even_tag+even_len < len){
        	if( isEven(array[i])){ // ����ż�� 
        	    cout<<"if( isEven(array[i]))"<<endl;
        		if(even_tag == -1){
        			even_tag = i;
        			even_len++;
				}else{
					even_len++;
				}
				i++; 
        		cout<<"even_tag: "<<even_tag<<" even_len: "<<even_len<<endl;
			}else{ //�������� 
			    cout<<"if( !isEven(array[i]))"<<endl;
				if(even_tag == -1){//Ŀǰ��û������ż�������Լ������� 
					i++;
				}else{//Ŀǰ��Ҫ��ǰ���ż�����е���˳�� 
					int temp_odd = array[i] ;
					for(int j = even_len;j>0;j--){
						array[i - (even_len - j)] = array[even_tag + j - 1];
					}
					array[even_tag] = temp_odd;
					i=even_tag;
					even_tag = -1;
					even_len = 0;
				}
			}
				vector<int>::iterator iter=array.begin();
				for(;iter!=array.end();iter++){
					cout<<*iter<<" "; 
				}
				cout<<endl;
		}
    }
    
    bool isEven(const int n){
    	return (n&1)==0;
		//return !(n%2);
	}
};

int main(){
	vector<int> arr;
	for(int i =1;i<=10;i++){
		arr.push_back(i);
	}


	vector<int>::iterator iter=arr.begin();
	for(;iter!=arr.end();iter++){
		cout<<*iter<<" "; 
	}
	cout<<endl;
	//cout<<rand()<<endl;
	Solution s;
	s.reOrderArray(arr);
    iter=arr.begin();
	for(;iter!=arr.end();iter++){
		cout<<*iter<<" "; 
	}
	return 0;
} 
