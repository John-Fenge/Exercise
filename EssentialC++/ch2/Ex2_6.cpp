//template实现max（）函数
#include <iostream>
#include<vector>

using namespace std;
template <typename eletype>
eletype MAX(eletype a, eletype b){
    return (a>b)? a:b;
}

template <typename eletype>
eletype MAX_array(eletype seq[], int size){
    eletype max_value=seq[0];
    for(int i=1;i<size;i++){
        if(max_value<seq[i])
            max_value=seq[i];
    }
    return max_value;
}

template <typename eletype>
eletype MAX_vector(vector <eletype> seq){
    eletype max_value=seq[0];
    for(int i=1;i<seq.size();i++){
        if(max_value<seq[i])
            max_value=seq[i];
    }
    return max_value;
}

int main()
{   
    int a=5,b=6;
    double c=2.6,d=8.4;
    string e="we are", f="the first";
    cout<<MAX(a,b)<<"\n"<<MAX(c,d)<<"\n"<<MAX(e,f)<<endl;

    int int_arr[]={1, 2, 10, 3, 4};
    double double_arr[]={1.4, 2.3, 2.2, 5.2, 2.4};
    string str_arr[]={"we", "are", "the", "first", "!"};
    cout<<MAX_array(int_arr,5)<<"\n"<<MAX_array(double_arr,5)<<"\n"<<MAX_array(str_arr,5)<<endl;

    vector<int> int_vec(int_arr,int_arr+5);
    vector<double> double_vec(double_arr,double_arr+5);
    vector<string> str_vec(str_arr, str_arr+5);
    cout<<MAX_vector(int_vec)<<"\n"<<MAX_vector(double_vec)<<"\n"<<MAX_vector(str_vec)<<endl;

    return 0;
}
