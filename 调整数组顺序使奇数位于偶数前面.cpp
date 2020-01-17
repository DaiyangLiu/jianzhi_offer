#include <cstdio>
#include <iostream>
#include <vector>
using namespace std; 


//����������ǰ��ż�������ں� 
//������������ż����ż��֮������λ�ò������ı�
 
class Solution {
public:
	void reOrderArray(vector<int> &array){
		//������д�ģ���Ȼ���ˡ�˼·�����ҵ�һ�������������Σ�һ����ǰ�ƶ� 
		int length = array.size();
        int k = length-1;
        
        while(k>0){	
        	int s=k;
        	while(s>=0 &&isOdd(array[s])){
        		s--;
			}
			//[s+1,k] ���������� �� s��ż��
			//if(s<0) ˵�� 0 ��λ�ö�������
			if(s<0) return;
			int even_num = array[s];//s,ż�����ڵĵط� 
			int to_k = s;
			while(to_k<k){
				array[to_k] = array[to_k+1];
				to_k++;
			}
			array[k] = even_num; 
			k--;
			 
		}
        
	}
	
	
    void reOrderArray_changeOrder(vector<int> &array) {
    // �����𣬻ᵼ��������ż��֮ǰ��λ�ûᷢ�ֱ仯 
        int length = array.size();
        int i = 0, j = length-1;
        while(j>i){
        	while(i<j && isOdd(array[i])){//����������������� 
        		i++;
			}
			while(i<j && !isOdd(array[j])){//��ż���������ǰ�� 
				j--;
			} 
			if(i<j){
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
    }
    
    bool isOdd(int x){
    	if((x&1)==0){
	        return false; //ż�� 
	    }
    	return true;
	}
};

int main(){
	//vector<int> a{1,2,3,4,5,6,7};
	vector<int> a{2,1};
	Solution s;
	s.reOrderArray(a);
	for(int i ; i<a.size(); i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
