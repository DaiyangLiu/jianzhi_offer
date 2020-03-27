#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int greatsum = 0x80000000, sum = 0;
    	int i = 0;

    	while(i< array.size()){
    		if(sum <= 0){
    			sum = array[i];
			}else{
				sum += array[i];
			}	    
    	    if(greatsum < sum){
    	    	greatsum = sum;
			}
            ++i;
		}
        return greatsum;
    }
    
    int FindGreatestSumOfSubArray_Dyanmic(vector<int> array) {
    	int greatsum = 0x80000000, sum = 0;
    	int i = 0;
    	while(i<array.size()){
    		if(i == 0 || sum <= 0){
    			sum = array[i];
			}else{
				sum += array[i];
			}
			if(greatsum < sum ){
				greatsum = sum;
			}
			++i;
		}
        return greatsum;
    }
};

//class Solution {
//public:
//    int FindGreatestSumOfSubArray(vector<int> array) {
//    	int greatsum = -999999, sum = 0;
//    	int i = 0;
//    	sum = array[i];
//    	greatsum = sum;
//    	i++;
//    	while(i< array.size()){
//    		if(sum > 0){
//    			if(array[i] > 0){
//	    			sum += array[i];
//	   				if(greatsum < sum){
//						greatsum = sum;
//					}
//					i++;
//				}else{
//					if((sum + array[i]) < 0 ){ //忽略了可能全部都是负数的情况 
//						sum = 0;		
//						i++;
//					}else if( (sum+array[i])>=0 ){
//						sum += array[i];
//						i++;
//					}
//				}
//			}else{
//				sum = array[i];
//   				if(greatsum < sum){
//					greatsum = sum;
//				}
//				i++;
//			}
//		}
//        return greatsum;
//    }
//};


int main(){
	vector<int> v={1,-2,3,10,-4,7,2,-5};
	//vector<int> v= {-2,-8,-1,-5,-9};
	Solution s;
	cout<<s.FindGreatestSumOfSubArray_Dyanmic(v)<<endl;
	return 0;
} 

