#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

vector<vector<int>> init_vector(int rows, int cols){
	
		vector<vector<int>> arr(rows,vector<int>(cols));
		
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(i==0&&j==0){
					arr[i][j] = 1;
				}else if(i==0 && j>0){
					arr[i][j] = arr[i][j-1] + 1 + rand()%5;
				}else if(j==0 && i>0){
					arr[i][j] = arr[i-1][j] + 1 + rand()%5;
				}else{
					arr[i][j] = max(arr[i-1][j]+1+rand()%5,arr[i][j-1]+1+rand()%5);
				}
				
			}
		}	
		return arr;
}

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
    	//确保输入array有效 
         if(array.size() == 0 ){
         	return false;
		 }else if(array[0].size() == 0){
		 	return false;
		 }
		 
		 int i=0,j=array[0].size()-1;
		 while(i<array.size() && j>=0){
		 	if(array[i][j]==target){
		 		return true;
			 }else if(array[i][j]>target){ //向左移动 
			 	j--;
			 }else{//向下移动 
			 	i++;
			 }
		 }
		 return false;
    }
};

int main(){
	int rows = 4,cols = 4;
	//生成指定数组 
	vector<vector<int>> arr(4,vector<int>(4));
	for(int i=0;i<4;i++){
			if(i==0){
				arr[i][0]=1;arr[i][1]=2;arr[i][2]=8;arr[i][3]=9;
			}else if(i==1){
				arr[i][0]=2;arr[i][1]=4;arr[i][2]=9;arr[i][3]=12;
			}else if(i==2){
				arr[i][0]=4;arr[i][1]=7;arr[i][2]=10;arr[i][3]=13;
			}else if(i==3){
				arr[i][0]=6;arr[i][1]=8;arr[i][2]=11;arr[i][3]=15;
			}
		}	
	
	
// 随机生成二维数组	
//	vector<vector<int>> arr = init_vector(rows,cols);
//	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}	
	
	Solution s;
	int target;
	while(cin>>target){
			cout<<s.Find(target,arr)<<endl;
	}


	
	return 0;
}
