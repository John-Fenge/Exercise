//对用户名大于两个字符的输入，作出响应，用两种方式实现：char，string
#include <iostream>
#include<string>
using namespace std;

int main()
{
    char user_name[128];
    cout<<"Please enter your name: ";
    bool name_leagel=false;
    while(!name_leagel){
        cin>>user_name;
        int name_length=0;
        for(;user_name[name_length]!='\0';name_length++);
        if (name_length>2){
            cout<<"This name "<<user_name<<" is good.\n"<<endl;
            name_leagel=true;}
        else
            cout<<"Illegal name. Try again: ";
    }

    cout<<"Please enter your another name: ";
    string user_name2;
    bool name_leagel2=false;
    while(!name_leagel2){
        cin>>user_name2;
        if(user_name2.size()>2){
            cout<<"This name "<<user_name2<<" is good.\n"<<endl;
            name_leagel2=true;
        }
        else
            cout<<"Illegal name. Try again: ";
    }
    return 0;
}

