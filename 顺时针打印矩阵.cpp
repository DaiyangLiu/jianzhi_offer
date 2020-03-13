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
    	//��ӡ������һ��,�����䣬�������� 
		for(int col = start;col<cols-start; col++){
			printmatrix.push_back(matrix[start][col]);
		} 
		
		//��ӡ���ϵ���һ�У������䣬��������
		for(int row = start+1;row<rows-start;row++){
			printmatrix.push_back(matrix[row][cols-start-1]);
		} 
		
		//��ӡ���ҵ���һ�У��������䣬������
		if(start<rows-start-1){ // ���ʣ�µ�ֻ��һ�У�����Ҫ���д��ҵ���ı��� ------������Ҫע�⣬��Ϊ�����ﷸ���� 
			for(int col = cols-start-2;col>start;col--){
				printmatrix.push_back(matrix[rows-start-1][col]);
			} 		
		}
		
		//��ӡ���µ���һ�У������䣬��������
		if(start< cols-start-1){ //���ʣ�µ�ֻ��һ�У�����Ҫ���д��µ��ϵı��� ------������Ҫע�⣬��Ϊ�����ﷸ���� 
			for(int row= rows-start-1;row>start;row--){
				printmatrix.push_back(matrix[row][start]);
			} 
		}
		
		
		return;
	}
    
};

int main(){
	int rows,cols;
	cout<<"����������������������"<<endl;
	 
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
		cout<<"ԭʼ�����ӡ��"<<endl; 
		for(int i =0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		
		Solution s;
		
		vector<int> printmatrix = s.printMatrix(matrix);
		vector<int>::iterator iter = printmatrix.begin();
		cout<<"˳ʱ���ӡ��"<<endl;
		for(;iter!=printmatrix.end();iter++){
			cout<<*iter<<" ";
		}
		cout<<endl;
	}
	return 0;
}
