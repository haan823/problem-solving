#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class node{
public:
    bool is_num;
    int num;
    char c;
};

stack<node> s;

int main(){
    string tmp;
    node n;
    cin >> tmp;
    for(int i=0; i<tmp.size(); i++){
        char command = tmp[i];
        if(command == '(' || command == '['){
            n.is_num = false;
            n.c = command;
            s.push(n);
        }
        else if(command == ')'){
            int sum = 0;
            bool flag = true;
            while(!s.empty()){
                node tmp_n = s.top();
                s.pop();
                if(tmp_n.is_num){
                    sum += tmp_n.num;
                }
                else if(tmp_n.c == '('){
                    if(sum == 0){
                        n.is_num = true;
                        n.num = 2;
                        s.push(n);
                    }
                    else{
                        n.is_num = true;
                        n.num = sum * 2;
                        s.push(n);
                    }
                    flag = false;
                    break;
                }
                else{
                    flag = true;
                    break;
                }
            }
            if(flag){
                cout << 0;
                return 0;
            }
        }
        else if(command == ']'){
            int sum = 0;
            bool flag = true;
            while(!s.empty()){
                node tmp_n = s.top();
                s.pop();
                if(tmp_n.is_num){
                    sum += tmp_n.num;
                }
                else if(tmp_n.c == '['){
                    if(sum == 0){
                        n.is_num = true;
                        n.num = 3;
                        s.push(n);
                    }
                    else{
                        n.is_num = true;
                        n.num = sum * 3;
                        s.push(n);
                    }
                    flag = false;
                    break;
                }
                else{
                    flag = true;
                    break;
                }
            }
            if(flag){
                cout << 0;
                return 0;
            }
        }
        else{
            cout << 0;
            return 0;
        }
    }
    int sum = 0;
    while(!s.empty()){
        node n = s.top();
        s.pop();
        if(n.is_num){
            sum += n.num;
        }
        else{
            cout << 0;
            return 0;
        }
    }
    cout << sum;
}