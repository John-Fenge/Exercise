//读入数列位置，输出该位置上数字，并输出数列
#include <iostream>
#include<vector>

using namespace std;

bool calcuate_seq(int pos, unsigned int &element, vector<unsigned int> &sequence){
    if(pos<1||pos>1024)
        return false;

    int seq_size=sequence.size();
    while(seq_size<pos){
        sequence.push_back(sequence[seq_size-1]+sequence[seq_size-2]);
        seq_size++;
    }
    element=sequence[pos-1];
    return true;
}
void print_seq(int pos, vector<unsigned int> sequence){
    for(int i=0; i<pos; i++){
        cout<<sequence[i]<<" ";
        if(!((i+1)%10))
            cout<<endl;
    }
}

int main()
{
    int pos;
    unsigned int element;
    vector<unsigned int> sequence;
    bool user_try=true;
    char user_choose;
    sequence.push_back(1);//数列第一个数
    sequence.push_back(1);//数列第二个数
    while(user_try){
        cout<<"Please enter a position(1~1024): ";
        cin>>pos;
        if(!calcuate_seq(pos, element, sequence))
            cout<<"Illegel position!"<<endl;
        else{
            cout<<"element # "<<pos<<" is "<<element<<"\nThe sequec is: \n";
            print_seq(pos,sequence);
            cout<<endl;
        }
        cout<<"Do  you want to try again? (Y/N)"<<endl;
        cin>>user_choose;
        if(user_choose!='Y'&& user_choose!='y')
            user_try=false;
    }
    return 0;
}
