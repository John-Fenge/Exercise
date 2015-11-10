//输入一串整数，依次存入array和vector，并计算总和，平均值两个字符
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    const int array_size=5;
    int list1[array_size];
    int sum1=0,sum2=0;
    double average1=0,average2=0;
    vector<int> list2;
    cout<<"Please enter 5 numbers:"<<endl;
    int value;
    int length=0;
    while(length <array_size &&cin>>value){ //此处&&左右顺序别有洞天，如果判断是否出界在右，需要输入6个数
        list2.push_back(value);
        list1[length++]=value;
        sum1+=value;
    }
    average1=double(sum1)/double(length);
    cout<<"The sum: "<<sum1<<"\t The average : "<<average1<<endl;


    for(int i=0;i<list2.size();i++)
        sum2+=list2[i];
    average2=double(sum2)/list2.size();
    cout<<"The sum: "<<sum2<<"\t The average : "<<average2<<endl;


    return 0;
}

