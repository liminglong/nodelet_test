#include <boost/make_shared.hpp> 
#include <ros/ros.h>
#include <iostream>
#include <vector>
using namespace std;
int main()  
{      
	typedef vector<boost::shared_ptr<int> > vs;    //一个持有shared_ptr的标准容器类型      
	vs v(10);                               //声明一个拥有10个元素的容器，元素被初始化为空指针       
	int i = 0;      
	for (vs::iterator pos = v.begin(); pos != v.end(); ++pos)      
	{          
		(*pos) = boost::make_shared<int>(++i);     //使用工厂函数赋值          
		cout << *(*pos) << ", ";            //输出值      
	}      
	cout << endl;       
	boost::shared_ptr<int> p = v[9];      
	*p = 100;      
	cout << *v[9] << endl;  
} 
