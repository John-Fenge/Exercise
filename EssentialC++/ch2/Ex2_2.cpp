//pentagonal公式Pn=n*(3n-1)/2，输入用户指定大小的vector中，并输出此vector
#include <iostream>
#include<vector>

using namespace std;
bool size_is_ok(int pos){
    if(pos<1||pos>1024){
        cout<<"Invalid position: "<<pos<<endl;
        return false;
    }
    return true;
}

bool pen_elem(vector<int> &pen, int pos){
    if(size_is_ok(pos)){
        pen.erase(pen.begin(),pen.end());
        for(int i=0;i<pos;i++){
            pen.push_back((i+1)*(3*(i+1)-1)/2);
        }
        return true;
    }
    return false;
}

void pen_print(vector<int> &pen, string info, ostream &os=cout){
    os<<info<<endl;
    for(int i=0;i<pen.size();i++){
        cout<<pen[i]<<" ";
        if(!((i+1)%10))
            cout<<endl;
    }
    cout<<endl;
}

int main()
{   
    int seq_size;//矩阵大小
    vector<int> pen;
    const string info="Pentagonal sequence: ";
    while(1){
        cout<<"Please input the size of Pentagonal sequence: ";
        cin>>seq_size;
        if(pen_elem(pen,seq_size))
            pen_print(pen,info);
        cout<<endl;
    }

    return 0;
}
