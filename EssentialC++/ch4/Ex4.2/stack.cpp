#include "stack.h"

Stack::Stack()
{

}

bool Stack::push(const string &elem){
    if(full()){
        cout<<"stack is full!"<<endl;
        return false;
    }
    stack.push_back(elem);
    return true;
}

bool Stack::pop(string &elem){
    if(empty()){
        cout<<"stack is empty!"<<endl;
        return false;
    }
    elem=stack.back();
    stack.pop_back();
    return true;
}

bool Stack::peek(string &elem){
    if(empty())
        return false;
    elem=stack.back();
    return true;
}

bool Stack::empty(){
    return stack.empty();
}

bool Stack::full(){
    if(stack.size()<max_size)
        return false;
    else
        return true;
}

bool Stack::find(const string &elem){
    bool flag=false;
    for(int i=0;i<stack.size();i++){
        if(elem==stack[i]){
            flag=true;
            break;
        }
    }
    return flag;
}

int Stack::count(const string &elem){
    int num=0;
    for(int i=0;i<stack.size();i++){
        if(elem==stack[i]){
            num++;
        }
    }
    return num;
}

void Stack::print_stack(){
    cout<<"Existing elements: ";
    for(int i=0; i<stack.size();i++)
        cout<<stack[i]<<" ";
    cout<<endl;
}
