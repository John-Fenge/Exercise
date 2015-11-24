#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Stack
{
public:
    Stack();    
    bool push(const string&);
    bool pop(string &elem);
    bool peek(string &elem);
    bool empty();
    bool full();

    int size(){
        return stack.size();
    }

    bool find(const string&);
    int count(const string &);
    void print_stack();
private:
    vector<string> stack;
    const int max_size=20;
//    stack.max_size()//max_size() 函数返回当前vector所能容纳元素数量的最大值

};

#endif // STACK_H
