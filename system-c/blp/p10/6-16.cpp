#include<iostream>
#include<string>
using namespace std;

int main() {
    string s1("Hello"),s2,s3,s4;			
    //����string����s1��s2��s3��s4,����s1��ʼ��
    //string����ĸ�ֵ��ⳤ
    s2=s1;		//��"="�Ž��и�ֵ
    s3.assign(s1);	//���ó�Ա����assign()���и�ֵ 
    cout<<"s1="<<s1.data()<<",s2="<<s2.data()<<",s3="<<s3.data()<<endl; 
    cout<<"s1�ĳ���="<<s1.length()<<endl;	
    //���ó�Ա����length()��
    //����ַ�������
    //string�������ַ�����
    char a[]="China!",b[6];
    s1=a;						
    //string����s1�����ַ�����a�ĸ�ֵ
    cout<<"s1="<<s1.data()<<endl;
    for(int i=0;i<5;i++)
        b[i]=s2[i];		//�����Ҳ�ɱ�ʾΪ:b[i]=s2.at(i);
    b[5]='\0';
    cout<<"�ַ�����b="<<b<<endl;
    //�ַ���������
    s4=s2+""+s1;	//��"+"�����ַ���������(���������+)
    s3=s2.append(s1);//s2��s1���Ӳ�����s3,ע�����Ӻ��s2���
    cout<<"s2="<<s2.data()<<",s3="<<s3.data()<<",s4="<<s4.data()<<endl;
    //�ַ����ıȽ�
    int f=s3.compare(6,5,s4,7,5);
    //��s3�ĵ�6����ʼ��5���ַ���s4�ĵ�7����ʼ��5���ַ����бȽ�
    if(f==0)
        cout<<"s3��s4�ȽϵĲ������"<<"\n";
    else
        cout<<"s3��s4�ȽϵĲ��ֲ����"<<"\n";
    //ȡ���ַ�������
    string sz=s2.substr(5,5);			
    //ȡs2�ĵ�5����ʼ��5���ַ�
    cout<<"���ַ���sz="<<sz.data()<<endl;
    //�ַ����Ľ��������
    s1.swap(s4);//����s1��s4
    cout<<"s1="<<s1.data()<<",s4="<<s4.data()<<endl;
    cout<<"�ַ���China��s1�е�λ��Ϊ��"<<s1.find("China")<<endl;
    //��s1�в����ַ���"China"��λ��(�Ҳ���Ϊ0)
    //string�ַ�����char*��ָ���ת��
    int len=s1.length();
    char *pt=new char[len+1];		
    //����һ���ַ���ָ���������̬����ռ�
    s1.copy(pt,len,0);			
    //��s1���Ƶ�pt��ָ������(�൱��pt=&s1[0];)
    pt[len]='\0';
    cout<<pt<<endl;
    s2=pt;						
    //string�����s2�����ַ���ָ��ĸ�ֵ
    cout<<s2.data()<<endl;
}
