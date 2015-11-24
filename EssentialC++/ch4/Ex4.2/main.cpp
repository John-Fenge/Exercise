//实现4.1节及课后4.1，4.2，Stack类增加find(),count()成员函数
#include <iostream>
#include "stack.h"


using namespace std;

void fill_stack(Stack &stack, istream &in = cin){
    string str;
    while(cin>>str && !stack.full())
        stack.push(str);
    cout<<"Read in "<<stack.size()<<" elements"<<endl;
}

int main()
{

    Stack stack;
    string str;
    cout<<"Input: ";
    fill_stack(stack);
    cout<<"Number of elements: "<<stack.size()<<endl;
    stack.print_stack();


    stack.push("qqw");
    stack.print_stack();

    stack.pop(str);
    cout<<"pop: "<<str<<endl;
    stack.print_stack();

    stack.pop(str);
    cout<<"pop: "<<str<<endl;
    stack.print_stack();

    stack.push("po0");
    stack.peek(str);
    cout<<"peek: "<<str<<endl;
    stack.print_stack();

    if(stack.find("we"))
        cout<<"Find the word: we"<<endl;
    else
        cout<<"No word: we"<<endl;

    cout<<"There is "<<stack.count("is")<<" \"is\" in this sentence!"<<endl;

    return 0;
}

