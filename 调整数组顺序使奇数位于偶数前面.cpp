#include <cstdio>
#include <iostream>
#include <vector>
using namespace std; 


//奇数部分在前，偶数部分在后 
//奇数和奇数，偶数和偶数之间的相对位置不发生改变
 
class Solution {
public:
	void reOrderArray(vector<int> &array){
		//唉，乱写的，竟然过了。思路就是找到一个连续的奇数段，一起往前移动 
		int length = array.size();
        int k = length-1;
        
        while(k>0){	
        	int s=k;
        	while(s>=0 &&isOdd(array[s])){
        		s--;
			}
			//[s+1,k] 都是奇数， 而 s是偶数
			//if(s<0) 说明 0 的位置都是奇数
			if(s<0) return;
			int even_num = array[s];//s,偶数存在的地方 
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
    // 这个解答，会导致奇数和偶数之前的位置会发现变化 
        int length = array.size();
        int i = 0, j = length-1;
        while(j>i){
        	while(i<j && isOdd(array[i])){//是奇数则继续往后走 
        		i++;
			}
			while(i<j && !isOdd(array[j])){//是偶数则继续往前走 
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
	        return false; //偶数 
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
