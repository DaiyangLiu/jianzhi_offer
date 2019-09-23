#include <cstdio>
#include <iostream>
using namespace std;


class Solution {
public:
    int jumpFloor(int number) {
		if(number==1) return 1;
		if(number==2) return 2; 
		int fibminone=2;
		int fibmintwo=1;
		int floornum=0;
		for(int i=3;i<=number;i++){
		    floornum=fibminone+	fibmintwo;
		    fibmintwo=fibminone;
		    fibminone=floornum;
		}  
		return floornum;
    }
};
