#include <iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

int main()
{
    string user_name;
    cout << "Please enter your name: " << endl;
    cin>>user_name;

    vector<string> seq_name={"Fibonacci","Lucas","Pell","Triangular","Square","Pentagonal"};
    vector<int> ele_seq={1,2,3,
                         3,4,7,
                         2,5,12,
                         3,6,10,
                         4,9,16,
                         5,12,22};

    int user_val;
    int user_try=0,user_right=0;
    double user_score=0;
    bool try_again=true;
    char user_choose;

//=========================顺序读取序列=================================================
//    int cur_tuple=0;
//    while(try_again&&(cur_tuple<ele_seq.size())){
//        cout<<"The first two elemnet of the sequence are: "<<ele_seq[cur_tuple]<<", "
//           <<ele_seq[cur_tuple+1]<<"\nWhat is the next element?"<<endl;
//        int right_val=ele_seq[cur_tuple+2];

//        cin>>user_val;
//        user_try++;
//        if(user_val==right_val){
//            user_right++;
//            cout<<"Yes, "<<ele_seq[cur_tuple+2]<<" is the elment in the "<< seq_name[cur_tuple/3]
//               <<" sequence.\n"<<endl;
//        }
//        else{
//            bool go_for_it;

//            cout<<"Try again? Y/N :";
//            cin>>user_choose;
//            go_for_it=(user_choose=='Y')? true:false;//判断语句书写
//            while(go_for_it){
//                cin>>user_val;
//                user_try++;
//                if(user_val==right_val){
//                    user_right++;
//                    go_for_it=false;
//                    cout<<"Yes, "<<ele_seq[cur_tuple+2]<<" is the elment in the "<< seq_name[cur_tuple/3]
//                       <<" sequence.\n"<<endl;
//                }
//                else{
//                    cout<<"Not right. Try again? Y/N :";
//                    cin>>user_choose;
//                    go_for_it=(user_choose=='Y')? true:false;
//                }
//            }
//        }

//        cout<<"Try another sequence? Y/N :";
//        cin>>user_choose;
//        try_again=(user_choose=='Y')? true:false;
//        cur_tuple+=3;
//    }

//========================================随机读取======================================

    while(try_again){
        srand((unsigned)time(0));
        int seq_index=rand()%6;
        int cur_tuple=seq_index*3;
        cout<<"The first two elemnet of the sequence are: "<<ele_seq[cur_tuple]<<", "
           <<ele_seq[cur_tuple+1]<<"\nWhat is the next element?"<<endl;
        int right_val=ele_seq[cur_tuple+2];

        cin>>user_val;
        user_try++;
        if(user_val==right_val){
            user_right++;
            cout<<"Yes, "<<ele_seq[cur_tuple+2]<<" is the elment in the "<< seq_name[seq_index]
               <<" sequence.\n"<<endl;
        }
        else{
            bool go_for_it;

            cout<<"Not right. Try again? Y/N :";
            cin>>user_choose;
            go_for_it=(user_choose=='Y')? true:false;//判断语句书写
            while(go_for_it){
                cin>>user_val;
                user_try++;
                if(user_val==right_val){
                    user_right++;
                    go_for_it=false;
                    cout<<"Yes, "<<ele_seq[cur_tuple+2]<<" is the elment in the "<< seq_name[seq_index]
                       <<" sequence.\n"<<endl;
                }
                else{
                    cout<<"Not right. Try again? Y/N :";
                    cin>>user_choose;
                    go_for_it=(user_choose=='Y')? true:false;
                }
            }
        }

        cout<<"Try another sequence? Y/N :";
        cin>>user_choose;
        try_again=(user_choose=='Y')? true:false;
    }



    user_score=double(user_right)/double(user_try);
    cout<<"\nThe score of "<<user_name<<" is "<<user_score<<endl;
    return 0;
}

