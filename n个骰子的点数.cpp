#include <cstdio>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution{
	public:
		Solution(int value=6):g_maxValue(value){
		}
		void PrintProbability(int number){//���ö�̬�滮����� 
			if(number < 1) return;
			int sumArray[number+1][g_maxValue*number + 1] ={0};//col ���� �� 
			for(int i = 1;i<=g_maxValue;i++ ){
				sumArray[1][i] = 1;
			} 
			
			for(int i = 2;i<=number;i++){//���������� 
				for(int j = i;j<=g_maxValue*i;j++){	//����������				
					for(int k = j-1, times = 1; k>= (i-1) && times <=6 ; k--,times++ ){ //Լ��k����ʼλ�õ�ͬʱ��Լ��ֻ�ܼ�k-1,...,k-6�������� 
						sumArray[i][j]+=sumArray[i-1][k];
					} 
				}
			}
			
			for(int j = number;j<=g_maxValue*number;j++){
				cout<<j<<" "<<sumArray[number][j]<<endl;
			}			
		}

        void ReverseProbability(int number){//���õݹ������ 
        	if(number<1) return;
        	
        	//n�����ӵĺͣ���С��n,�����6n 
        	int *sumArray= new int[g_maxValue*number-number+1];
			for(int i =0;i<g_maxValue*number-number+1;i++){
				sumArray[i] = 0;
			}
			for(int i =1;i<=g_maxValue;++i){
				Reversetouz(number, number, i, sumArray); 
			}
			double times = pow(g_maxValue,number);
			for(int i =0;i<g_maxValue*number-number+1;i++){
				double ratio =  sumArray[i]/times;
				cout<<i+number<<": "<<sumArray[i]<<" "<<ratio<<endl; 
			}			 
		}
	
		void Reversetouz(int number, int no_n, int sum, int *array){ //�ٴ��������ȥ 
			if(no_n == 1){
				array[sum-number]++;
				return;
			}
			for(int value_i = 1; value_i<=g_maxValue;value_i++){
				Reversetouz(number, no_n-1,value_i+sum,  array ); 
			}		
		} 		
	
	private:
		int g_maxValue;
};
int main(){
	Solution s;
	s.ReverseProbability(2);
	cout<<"-------------------"<<endl;
	s.PrintProbability(2);
	return 0;
} 
