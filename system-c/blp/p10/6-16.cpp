#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1("Hello"),s2,s3,s4;			
    //定义string对象s1、s2、s3、s4,并对s1初始化
    //string对象的赋值与测长
    s2=s1;		//用"="号进行赋值
    s3.assign(s1);	//调用成员函数assign()进行赋值 
    cout<<"s1="<<s1.data()<<",s2="<<s2.data()<<",s3="<<s3.data()<<endl; 
    cout<<"s1的长度="<<s1.length()<<endl;	
    //调用成员函数length()，
    //输出字符串长度
    //string对象与字符数组
    char a[]="China!",b[6];
    s1=a;						
    //string对象s1接收字符数组a的赋值
    cout<<"s1="<<s1.data()<<endl;
    for(int i=0;i<5;i++)
        b[i]=s2[i];		//此语句也可表示为:b[i]=s2.at(i);
    b[5]='\0';
    cout<<"字符数组b="<<b<<endl;
    //字符串的连接
    s4=s2+""+s1;	//用"+"进行字符串的连接(重载运算符+)
    s3=s2.append(s1);//s2与s1连接并赋给s3,注意连接后的s2结果
    cout<<"s2="<<s2.data()<<",s3="<<s3.data()<<",s4="<<s4.data()<<endl;
    //字符串的比较
    int f=s3.compare(6,5,s4,7,5);
    //将s3的第6个开始的5个字符与s4的第7个开始的5个字符进行比较
    if(f==0)
        cout<<"s3与s4比较的部分相等"<<"\n";
    else
        cout<<"s3与s4比较的部分不相等"<<"\n";
    //取子字符串操作
    string sz=s2.substr(5,5);			
    //取s2的第5个开始的5个字符
    cout<<"子字符串sz="<<sz.data()<<endl;
    //字符串的交换与查找
    s1.swap(s4);//交换s1与s4
    cout<<"s1="<<s1.data()<<",s4="<<s4.data()<<endl;
    cout<<"字符串China在s1中的位置为："<<s1.find("China")<<endl;
    //在s1中查找字符串"China"的位置(找不到为0)
    //string字符串与char*型指针的转换
    int len=s1.length();
    char *pt=new char[len+1];		
    //定义一个字符型指针变量并动态分配空间
    s1.copy(pt,len,0);			
    //将s1复制到pt所指的数组(相当于pt=&s1[0];)
    pt[len]='\0';
    cout<<pt<<endl;
    s2=pt;						
    //string类对象s2接收字符型指针的赋值
    cout<<s2.data()<<endl;
}
