#include <iostream>
#include<vector>
#include <fstream>
using namespace std;

bool is_pos_ok(int pos){
    if(pos<1||pos>1024){
        cout<<"Illegel Position!"<<endl;
        return false;
    }
    return true;
}

const vector<int>* fibon_seq(int pos){
    static vector<int> elem;
    if(!is_pos_ok(pos))
        return 0;
    for(int i=elem.size();i<pos;i++){
        if(i==0||i==1)
            elem.push_back(1);
        else
            elem.push_back(elem[i-1]+elem[i-2]);
    }
    return &elem;
}

const vector<int>* squ_seq(int pos){
    static vector<int> elem;
    if(!is_pos_ok(pos))
        return 0;
    for(int i=elem.size();i<pos;i++){
        elem.push_back((i+1)*(i+1));
    }
    return &elem;
}


const int fun_num=2;
const vector<int>* (*fun_arry[fun_num])(int)={fibon_seq,squ_seq};

//void print_elem(const vector<int> *pseq, ofstream *os=0){//此处是ofstream，目的是利用指针选择是否输出信息
//    (*os)<<"The sequec is: "<<endl;
//    for(int i=0;i<(*pseq).size();i++){
//        (*os)<<(*pseq)[i]<<" ";
//        if((i+1)%10==0)
//            (*os)<<endl;
//    }
//}

void print_elem(const vector<int> *pseq, ostream &os=cout){//此处是ostream，目的是使cout成为ostream的默认参数
    (os)<<"The sequec is: "<<endl;
    for(int i=0;i<(*pseq).size();i++){
        (os)<<(*pseq)[i]<<" ";
        if((i+1)%10==0)
            (os)<<endl;
    }
}

bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int)){
    const vector<int>* pseq = seq_ptr(pos);
    if(!pseq){
        cerr<<"Internal Error: seq_ptr is set to null!"<<endl;
        return false;
    }
    else{
        elem = (*pseq)[pos-1];

        char user_output;
        cout<<"Write into a file named \"text.txt\"(Y/N)? : ";
        cin>>user_output;
        if(user_output=='Y'||user_output=='y'){
            ofstream outfile("data.txt");
            if(!outfile){
                cerr<<"No such file! Show on screen!"<<endl;
                print_elem(pseq);
            }
            else
//                print_elem(pseq,&outfile);
                print_elem(pseq,outfile);
        }
        else
            print_elem(pseq);
        return true;
    }
}


int main()
{
    int pos;
    int element;
    bool user_try=true;
    char user_choose;

    while(user_try){
        cout<<"Please enter a position(1~1024): ";
        cin>>pos;
        if(seq_elem(pos,element,fun_arry[1])){
            cout<<"element # "<<pos<<" is "<<element<<endl;"\n";
        }
        cout<<"Do  you want to try again? (Y/N)"<<endl;
        cin>>user_choose;
        if(user_choose!='Y'&& user_choose!='y')
            user_try=false;
    }
    return 0;
}
