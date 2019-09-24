#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
 

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
		//判断是否为空
        if(length==0) return 0; 
		//判断是否为未打乱顺序的数组
		if(rotateArray[0] < rotateArray[length-1]){
			return rotateArray[0];
		}
		
		int index1=0,index2=length-1,indexmid=length/2;
		
		while(index2-index1>1){
			//这里也要注意，我把这个写到了while循环外面 ，写在while循环外面和里面都可以 ，但是写在里面更和逻辑，更保险 
			//比如样例：1，1，1，1，2，0，1，（0+6）/2 =3,中间元素为1，从而 也无法判断数组分隔情况 
		    //判断是否无法判断递增数组的分隔情况，比如 1，0，1，1，1 和 1，1，1，0，1
			if(rotateArray[index1] == rotateArray[index2] && rotateArray[index1] == rotateArray[indexmid]){
				//只能顺序遍历
				int min=rotateArray[index1] ;
				for(int i=index1+1;i<=index2;i++){
					if(min>rotateArray[i]){
						min=rotateArray[i];
					}
				}
				return min; 
			}
			//正常旋转数组
			if(rotateArray[index1]<=rotateArray[indexmid]){
				index1=indexmid;				
			}else{
				index2=indexmid;
			}
			indexmid=(index2+index1)/2;//index2-index1+1;----------------------这里index2-index1+1产生了致命的错误,在某个样例中，陷入了无限循环
			//犯傻了，index2-index1+1根本就不是求中间坐标的公式，我怎么想的呢？？？？ 
		} 
		
		return rotateArray[index2];
    }
};

int main(){
	Solution s;
	vector<int> A{3,4,5,1,2};
	cout<<s.minNumberInRotateArray(A)<<endl;
	
	vector<int> B{1,2,3,4,5};
	cout<<s.minNumberInRotateArray(B)<<endl;
	
	vector<int> C{1,0,1,1,1};
	cout<<s.minNumberInRotateArray(C)<<endl;
	
	return 0;
}
