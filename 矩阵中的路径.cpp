#include <cstdio> 
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        //判断输入参数有效性,指针，判断是否为空指针，数值，判断是否构成一个矩阵 ，这里有点疑惑 rows<1||cols<1 ---->? rows<1&&clos<1 
		if(matrix==nullptr || rows<1||cols<1|| str==nullptr){
			return false;
		} 
		
		//回溯法
		//flag 访问检测矩阵 
	    //bool flag[rows*cols] = {false};
	    bool *flag = new bool[rows*cols];
	    memset(flag,0,rows*cols);
	    bool find = false; 
	    char *p=str;
	    for(int i = 0;i<rows;i++){
        	for(int j=0;j<cols;j++){
        		cout<<matrix[i*cols + j]<<" ";
			}
			cout<<endl;
		}
		
	    for(int i = 0;i<rows;i++){
        	for(int j=0;j<cols;j++){
        		flag[rows*cols] = {false};//每次切换起始字符，都要对访问检测矩阵进行刷新 
        		p=str;
        		//寻找起始字符
				 if(matrix[i*cols + j] == *p){ //如何确定str的长度呢 
				 	flag[i*cols + j] =true;
				 	//开始进行搜索
				 	p++;//第一个字符已经匹配，将字符指针向后移动一位，进行第二个字符的匹配 
					find = findNext(matrix,rows,cols,i,j,p,flag);
					if(find == true) return find;
					flag[i*cols + j] =false;
				 }
        		
			}
			cout<<endl;
		}
		delete[] flag;
		return find;
		 
    }
    
    bool findNext(char* matrix, int rows, int cols,int i,int j, char* str, bool* flag){
    	//左下右上
    	int current_coor = i*cols + j;
    	int length = rows*cols;
    	bool find;
    	char *p = str;
    	if(*p=='\0') return true;
    	cout<<"now "<<matrix[current_coor]<<"------------------"<<endl;
		if((current_coor - 1) >= 0 && j-1>=0){//左  省略 &&(current_coor - 1) <rows*cols
		    cout<<"left "<<matrix[current_coor -1] <<" "<<*p<<endl;
			if(matrix[current_coor -1] == *p && flag[current_coor -1]==false){
				flag[current_coor -1]=true;
				p++;
				find = findNext(matrix,rows,cols,i,j-1,p,flag);
				if(find == true) return find;
				p--;
				flag[current_coor -1]=true;
			} 
		}
		if((current_coor + 1) <length && j+1<cols) {//右 省略(current_coor + 1) >= 0 &&
		    cout<<"right "<<matrix[current_coor +1] <<" "<<*p<<endl;
			if(matrix[current_coor +1] == *p && flag[current_coor +1]==false){
				flag[current_coor +1]=true;
				p++;
				find= findNext(matrix,rows,cols,i,j+1,p,flag);
				if(find == true) return find;
				p--;
				flag[current_coor +1]=true;
			}
		}
		if((current_coor+cols) <length && i+1<rows){ //下 
	     	cout<<"down "<<matrix[current_coor+cols] <<" "<<*p<<endl;
			if(matrix[current_coor+cols] == *p && flag[current_coor +cols]==false){
				//cout<<"dealing"<<endl;
				flag[current_coor+cols]=true;
				p++;
				find = findNext(matrix,rows,cols,i+1,j,p,flag);
				if(find == true) return find;
				p--;
				flag[current_coor+cols]=true;
			}
		}
		if((current_coor-cols)>=0 && i-1>=0){//上 
		    cout<<"up "<<matrix[current_coor-cols] <<" "<<*p<<endl;
		    if(matrix[current_coor-cols] == *p && flag[current_coor -cols]==false){
				cout<<"dealing...."<<endl;
				flag[current_coor-cols]=true;
				p++;
				find = findNext(matrix,rows,cols,i-1,j,p,flag);
				if(find == true) return find;
				p--;
				flag[current_coor-cols]=true;
			}
		} 
		cout<<"end "<<matrix[current_coor]<<"------------------"<<endl;
		
		return false;
	}
    

};

int main(){
//	int rows = 3;
//	int cols = 4;
//	char m[]="abtgcfcsjdeh";
//	char str[]="bfce";
	int rows = 5;
	int cols = 8;
	char m[]="ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
	char str[]="SGGFIECVAASABCEHJIGQEM";
	char *strptr=str;
	Solution s;
	cout<<s.hasPath(m,rows,cols,str); 
//	while((*strptr) != '\0'){
//		cout<< *strptr  <<endl;
//		strptr++;
//	} 
	return 0;
}
