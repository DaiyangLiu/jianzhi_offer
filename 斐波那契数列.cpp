#include <cstdio>
#include <iostream>
using namespace std;


class Solution {
public:
    int Fibonacci(int n) {
        int fibone = 1; // 命名为fibminusone 更明确 
        int fibtwo = 0;
        int fibn = 0;
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=2;i<=n;i++){
        	fibn = fibone + fibtwo;
        	fibtwo = fibone;
			fibone = fibn; 
		}
		return fibn;
    }
};

//class Solution {
//public:
//    int Fibonacci(int n) {
//        if(n==0) return 0;
//		if(n==1) return 1;
//		return Fibnacci(n-1) + Fibnacci(n-2); 
//    }
//};

int main(){
	Solution s;
	
	cout<<s.Fibonacci(3);
	return 0;
}

