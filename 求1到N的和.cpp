#include <cstdio>
#include <iostream>
using namespace std;
//***************************************************
//解法一：构造函数与静态成员函数 
//class Temp{
//	public:
//		Temp(){n++;sum+=n;
//		}
//		static int getn(){
//			return n;
//		}
//		static int getSum(){
//			return sum;
//		}
//		void Reset(){
//			n=0;
//			sum=0;
//		}
//	
//	private:
//		static unsigned int sum;
//		static unsigned int n;
//};
//
//unsigned int Temp::sum = 0;
//unsigned int Temp::n = 0;
//
//int main(){
//	int N=100;
//	Temp *a = new Temp[N];
//	delete[] a;
//	cout<<Temp::getSum()<<endl;
//	return 0;
//}
//*************************************************** 
//解法2：虚函数
// class A;
// A* Array[2];
// 
// class A{
// 	public:
// 		virtual int sum(int n){
// 			return 0;
//		 }
// }; 
// 
// class B:public A{
// 	public:
// 		int sum(int n){
// 			return Array[!!n]->sum(n-1) + n; 
//		 }
// };
// 
// int main(){
// 	A a;
// 	B b;
// 	Array[0]=&a;
// 	Array[1]=&b;
// 	cout<<Array[1]->sum(100);
// 	return 0;
// }
 //*************************************************** 
 //解法3：函数指针
//普通函数写法 
// 	typedef int (*func)(int);
//	int Sum_end_0(int n){
//		return 0;
//	}
//    int Sum_Solution(int n) {
//        static func f[2]={Sum_end_0,Sum_Solution};
//        return f[!!n](n-1) + n;
//    }
//  
//剑指offer提交写法 
// class Solution{
//public:
//	typedef int (Solution::*func)(int);
//	Solution(){
//		f[0] = &Solution::Sum_end_0; //类的非静态成员函数指针，要用引用赋值 
//		f[1] = &Solution::Sum_Solution;
//	}
//	
//	int Sum_end_0(int n){
//		return 0;
//	}
//    int Sum_Solution(int n) {
//        return (this->*f[!!n])(n-1) + n;
//    }
//
//private:
//	func f[2];
// }; 
//  
// 
// int main(){
// 	Solution s;
// 	cout<<s.Sum_Solution(100);
// 	
// 	return 0;
// }

//解法4：模板
template<unsigned int n>
struct Sum_Solution4
{
	enum Value {
		N = Sum_Solution4<n-1>::N + n
	};
 
}; 
 
 template<>
 struct Sum_Solution4<1>
 {
 	enum Value{N=1
	 };
 };
 
 int main(){
 	struct Sum_Solution4<10> s;
 	cout<< s.N;
 	return 0;
 }
