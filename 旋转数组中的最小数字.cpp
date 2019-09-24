#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
 

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int length = rotateArray.size();
		//�ж��Ƿ�Ϊ��
        if(length==0) return 0; 
		//�ж��Ƿ�Ϊδ����˳�������
		if(rotateArray[0] < rotateArray[length-1]){
			return rotateArray[0];
		}
		
		int index1=0,index2=length-1,indexmid=length/2;
		
		while(index2-index1>1){
			//����ҲҪע�⣬�Ұ����д����whileѭ������ ��д��whileѭ����������涼���� ������д����������߼��������� 
			//����������1��1��1��1��2��0��1����0+6��/2 =3,�м�Ԫ��Ϊ1���Ӷ� Ҳ�޷��ж�����ָ���� 
		    //�ж��Ƿ��޷��жϵ�������ķָ���������� 1��0��1��1��1 �� 1��1��1��0��1
			if(rotateArray[index1] == rotateArray[index2] && rotateArray[index1] == rotateArray[indexmid]){
				//ֻ��˳�����
				int min=rotateArray[index1] ;
				for(int i=index1+1;i<=index2;i++){
					if(min>rotateArray[i]){
						min=rotateArray[i];
					}
				}
				return min; 
			}
			//������ת����
			if(rotateArray[index1]<=rotateArray[indexmid]){
				index1=indexmid;				
			}else{
				index2=indexmid;
			}
			indexmid=(index2+index1)/2;//index2-index1+1;----------------------����index2-index1+1�����������Ĵ���,��ĳ�������У�����������ѭ��
			//��ɵ�ˣ�index2-index1+1�����Ͳ������м�����Ĺ�ʽ������ô����أ������� 
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
