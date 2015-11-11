//读入文件中文字，对其排序，并输出到另一个文件中
#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ifstream infile("data.txt");
    if(!infile){
        cerr<<"No such a file. Please add input file and try again."<<endl;
    }
    ofstream outfile("output.txt");
    if(!outfile){
        cerr<<"No shuch a file. Please add output file and try again."<<endl;
    }
    vector<string> data;
    string word;
    while(infile>>word)
        data.push_back(word);
    sort(data.begin(),data.end());//包含头文件algorithm
//    outfile<<data<<endl;//不能这样直接输出
    for(int i=0; i<data.size();i++)
        outfile<<data[i]<<" ";
    outfile<<endl;
    cout<<"Having sorted!";
    return 0;
}

