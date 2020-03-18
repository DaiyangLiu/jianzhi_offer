#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

 
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	vector<int>::iterator iter;
    	for(iter=sequence.begin();iter!=sequence.end();iter++){
    		cout<<*iter<<" ";
		}
		cout<<endl;
		if(sequence.empty())  return false; //�������Ҫע�� 
    	
    	if(sequence.size()==1){
    		return true;
	    }

	    int length = sequence.size();
	    int root = sequence[length - 1];
	    int boundary = -1;//!!!!!!!!!!!!!!!!!
	    //���û����������ô�죬�������ڵ�ǰ��������û�б������
		 
	    for(int i = 0;i<length-1;i++){
	    	if(sequence[i]>root){
	    		boundary = i;
	    		break;
			}
		}
		if(boundary==-1){  //4,6,7,5������� !!!!!!!!!!!
			boundary = length-1;
		} 
		
		for(int i = boundary;i<length-1;i++){
			if(sequence[i]<root){
		        return false;
			}
		}
		
		bool left = true;
		if(boundary>0){
			vector<int> leftside(sequence.begin(),sequence.begin()+boundary);
			left = VerifySquenceOfBST(leftside );
		}
		bool right = true;
		if(boundary<length-1){
			vector<int> rightside(sequence.begin()+boundary,sequence.end()-1);
			right = VerifySquenceOfBST(rightside);
		}
		
		return left && right;
	
    }
};

int main(){
	vector<int> seq = {5,7,6,9,11,10,8};
//	vector<int> seq = {7,4,6,5};
//vector<int> seq = {7,6,9,11,10,8};
//vector<int> seq = {4,6,7,5};
	Solution s;
	cout<<"�Ƿ��Ǻ���������У� "<<s.VerifySquenceOfBST(seq)<<endl;
	return 0;
}
