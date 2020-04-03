#include <cstdio>
#include <iostream>
using namespace std;


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index <= 0) return 0; 
    	int * puglyarray = new int[index];
    	puglyarray[0] = 1;
    	int nextIndex = 1;
    	int *pmultiply2 = puglyarray;
    	int *pmultiply3 = puglyarray;
    	int *pmultiply5 = puglyarray;
    	
    	while(nextIndex < index){
    		int newmax = min3(*pmultiply2 * 2,*pmultiply3 * 3,*pmultiply5 * 5 );
    		cout<<newmax<<endl;
    		puglyarray[nextIndex] = newmax;
    		
    		while( ((*pmultiply2)*2 )<= newmax){
    			pmultiply2++;
			}
    		while(((*pmultiply3)*3 )<= newmax){
    			pmultiply3++;
			}
    		while(((*pmultiply5)*5 )<= newmax){
    			pmultiply5++;
			}    		
    		nextIndex ++;
		}
    	int result = puglyarray[index-1];
    	delete [] puglyarray;
    	return result;
    
    }
    int min3(int number1,int number2,int number3){
    	int min = number1<number2?number1:number2;
    	min = min<number3?min:number3;
    	return min;
	}
};

int main(){
	Solution s;
	cout<<s.GetUglyNumber_Solution(7)<<endl;
	return 0;
} 
