#include <cstdio>
#include <iostream>
#include <vector> 
using namespace std;
 

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
    	vector<int> printMatrix;
    	int start = 0;
    	int rows = matrix.size();
    	if(rows==0) return printMatrix;
    	int cols = matrix[0].size();
    	if(cols==0) return printMatrix;
    	if(matrix.empty()) return printMatrix;
    	
    	cout<<"rows: " << rows<<" cols: "<<cols<<endl;
    	while(rows>start*2 && cols>start*2){
    		
    		printCircle(printMatrix,matrix,start,rows,cols);
    		++start;
		}
		return printMatrix; 
    }
    
    void printCircle(vector<int> &printmatrix,vector<vector<int> > matrix,int start,int rows, int cols){
    	//打印从左到右一行,列数变，行数不变 
		for(int col = start;col<cols-start; col++){
			printmatrix.push_back(matrix[start][col]);
		} 
		
		//打印从上到下一列，行数变，列数不变
		for(int row = start+1;row<rows-start;row++){
			printmatrix.push_back(matrix[row][cols-start-1]);
		} 
		
		//打印从右到左一行，行数不变，列数变
		if(start<rows-start-1){ // 如果剩下的只有一行，则不需要进行从右到左的遍历 ------这里需要注意，因为在这里犯过错 
			for(int col = cols-start-2;col>start;col--){
				printmatrix.push_back(matrix[rows-start-1][col]);
			} 		
		}
		
		//打印从下到上一列，行数变，列数不变
		if(start< cols-start-1){ //如果剩下的只有一列，则不需要进行从下到上的遍历 ------这里需要注意，因为在这里犯过错 
			for(int row= rows-start-1;row>start;row--){
				printmatrix.push_back(matrix[row][start]);
			} 
		}
		
		
		return;
	}
    
};

int main(){
	int rows,cols;
	cout<<"请输入矩阵的行数及列数："<<endl;
	 
	while(cin>>rows>>cols){
		vector<vector<int> > matrix; 
		int value = 0;
		for(int i =0;i<rows;i++){
			vector<int> temp;
			for(int j=0;j<cols;j++){	
				temp.push_back(++value);
			}		
			matrix.push_back(temp);
		}
		cout<<"原始矩阵打印："<<endl; 
		for(int i =0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		
		Solution s;
		
		vector<int> printmatrix = s.printMatrix(matrix);
		vector<int>::iterator iter = printmatrix.begin();
		cout<<"顺时针打印："<<endl;
		for(;iter!=printmatrix.end();iter++){
			cout<<*iter<<" ";
		}
		cout<<endl;
	}
	return 0;
}
