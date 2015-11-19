//pentagonal公式Pn=n*(3n-1)/2，输出用户指定位置数据
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

const vector<int>  *pen_seq(int pos){
    static vector<int> pen_calcuated;
    if(!size_is_ok(pos))
        return 0;
    for(int i=pen_calcuated.size();i<pos;i++){
        pen_calcuated.push_back((i+1)*(3*(i+1)-1)/2);
    }
    return &pen_calcuated;
}

inline bool pen_elem(int pos, int &elem){
    const vector<int> *pen = pen_seq(pos);
    if(pen){
        elem=(*pen)[pos-1];
        return true;
    }
    elem=-1;
    return false;
}

int main()
{   
    int pos;
    int elem;
    while(1){
        cout<<"Please input the position of Pentagonal sequence: ";
        cin>>pos;
        if(pen_elem(pos,elem)){
            cout<<elem<<endl;
        }
    }

    return 0;
}
