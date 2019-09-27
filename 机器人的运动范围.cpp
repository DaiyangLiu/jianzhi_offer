#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std; 

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
    {
    	if(rows<1 || cols<1||threshold<0) return 0;
    	int count;
    	bool *visited = new bool[rows*cols];
    	memset(visited,0,rows*cols);
    	cout<<"dealing..."<<endl;
    	moving(count,visited,threshold,rows,cols,0,0);
    	cout<<"count: "<<count<<endl;
        delete[] visited;
        return count;
    }
    
    int moving(int& count, bool *visited,int threshold, int rows,int cols,int x, int y){
    	//结束条件是什么？
    	cout<<"getSum(x,y)" <<getSum(x,y)<<endl;
		if(getSum(x,y)<=threshold && visited[x*cols + y]==false){
			//满足条件，继续遍历 
			cout<<x<<" "<<y<<endl;

			visited[x*cols + y]=true;
		    count += 1;
		    cout<<"count: "<<count<<endl;
		
			//继续遍历它上下左右的格子 
			if(x-1 >= 0){
				moving(count,visited,threshold,rows,cols,x-1,y);
			}
			if(x+1<rows){
			    moving(count,visited,threshold,rows,cols,x+1,y);
			}
			if(y-1>=0){
				moving(count,visited,threshold,rows,cols,x,y-1);
			}
			if(y+1<cols){
				moving(count,visited,threshold,rows,cols,x,y+1);
			}
			
			return count;
		} else{
			return count;
		}
	}
    
    int getSum(int x,int y){
    	int sum=0;
        while(x>0){
        	sum += x%10;
        	x = x/10; 
		}
		while(y>0){
        	sum += y%10;
        	y = y/10; 
		}
		return sum;
	}
};

int main(){
	int rows,cols;
	
	Solution s;
	cout<<s.movingCount(15,20,20)<<endl;

	return 0;
}
