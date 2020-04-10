#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		int Maxdiff(vector<int> data){
			if(data.size()<=1) return 0;
			int min = data[0];
			int diff=data[1]-min;
			for(int i =2;i<data.size();i++){
				if(data[i-1]<min){
					min = data[i-1];
				}
				if((data[i]-min) >diff){
					diff = data[i]-min;
				}
			}
			return diff;  
		}
}; 
