#include <cstdio>
#include <iostream>
#include <algorithm> 
using namespace std;

class Solution{
	public:
		Solution(int value=6):g_maxValue(value){
		}
		void PrintProbability(int number){//利用动态规划求概率 
			if(number < 1) return;
			int sumArray[number+1][g_maxValue*number + 1] ={0};//col 代表 和 
			for(int i = 1;i<=g_maxValue;i++ ){
				sumArray[1][i] = 1;
			} 
			
			for(int i = 2;i<=number;i++){//锁定横坐标 
				for(int j = i;j<=g_maxValue*i;j++){	//遍历纵坐标				
					for(int k = j-1, times = 1; k>= (i-1) && times <=6 ; k--,times++ ){ //约束k的起始位置的同时，约束只能加k-1,...,k-6，这六个 
						sumArray[i][j]+=sumArray[i-1][k];
					} 
				}
			}
			
			for(int j = number;j<=g_maxValue*number;j++){
				cout<<j<<" "<<sumArray[number][j]<<endl;
			}			
		}

        void ReverseProbability(int number){//利用递归求概率 
        	if(number<1) return;
        	
        	//n个骰子的和，最小是n,最大数6n 
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
	
		void Reversetouz(int number, int no_n, int sum, int *array){ //再传个数组进去 
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
