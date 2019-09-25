#include <cstdio> 
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        //�ж����������Ч��,ָ�룬�ж��Ƿ�Ϊ��ָ�룬��ֵ���ж��Ƿ񹹳�һ������ �������е��ɻ� rows<1||cols<1 ---->? rows<1&&clos<1 
		if(matrix==nullptr || rows<1||cols<1|| str==nullptr){
			return false;
		} 
		
		//���ݷ�
		//flag ���ʼ����� 
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
        		flag[rows*cols] = {false};//ÿ���л���ʼ�ַ�����Ҫ�Է��ʼ��������ˢ�� 
        		p=str;
        		//Ѱ����ʼ�ַ�
				 if(matrix[i*cols + j] == *p){ //���ȷ��str�ĳ����� 
				 	flag[i*cols + j] =true;
				 	//��ʼ��������
				 	p++;//��һ���ַ��Ѿ�ƥ�䣬���ַ�ָ������ƶ�һλ�����еڶ����ַ���ƥ�� 
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
    	//��������
    	int current_coor = i*cols + j;
    	int length = rows*cols;
    	bool find;
    	char *p = str;
    	if(*p=='\0') return true;
    	cout<<"now "<<matrix[current_coor]<<"------------------"<<endl;
		if((current_coor - 1) >= 0 && j-1>=0){//��  ʡ�� &&(current_coor - 1) <rows*cols
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
		if((current_coor + 1) <length && j+1<cols) {//�� ʡ��(current_coor + 1) >= 0 &&
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
		if((current_coor+cols) <length && i+1<rows){ //�� 
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
		if((current_coor-cols)>=0 && i-1>=0){//�� 
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
