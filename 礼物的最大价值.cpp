#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
using namespace std;

class Solution{
	public:
		int MaxGift(int* values,int rows,int cols){
		    if(values== nullptr) return 0;			
			int f[rows][cols] = {0};
			for(int i = 0;i<rows;i++){
				for(int j = 0;j<cols;j++){
					cout<<*(values+i*cols + j)<<" ";
					if((i-1)>=0 && (j-1)>=0){
						f[i][j] = max(f[i-1][j],f[i][j-1]) + *(values+i*cols+j);
					}else if((i-1)>=0){
						f[i][j] = f[i-1][j]+ *(values+i*cols+j);
					}else if((j-1)>=0){
						f[i][j] = f[i][j-1]+ *(values+i*cols+j);
					}else{
						f[i][j] = *(values+i*cols+j);
					}
				}
				cout<<endl;
			}
			int result = f[rows-1][cols-1];
			return result;
		}
};

int main(){
	Solution s;
	int values[4][4] ={{1,10,3,8},
	                   {12,2,9,6},
					   {5,7,4,11},
					   {3,7,16,5}}; 
	cout<<s.MaxGift((int*)values,4,4);
	return 0;
}
