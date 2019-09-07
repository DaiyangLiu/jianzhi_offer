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
					arr[i][j] = arr[i][j-1] + rand()%5;
				}else if(j==0 && i>0){
					arr[i][j] = arr[i-1][j] + rand()%5;
				}else{
					arr[i][j] = max(arr[i-1][j]+rand()%5,arr[i][j-1]+rand()%5);
				}
				
			}
		}
		
		return arr;
}

int main(){
	//vector<vector<int>> arr(4,vector<int>(4));
	int rows = 4,cols = 4;
	vector<vector<int>> arr = init_vector(4,4);
	
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}

	
	return 0;
}
