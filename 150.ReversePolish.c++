#include <stack>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
long evalRPN(vector<string>& tokens) {
        stack<long> stk;
        long ans;
        int size = tokens.size();
        for(int i = 0; i<size;i++){
            int n;
            if(tokens[i].size() == 1 && tokens[i][0] < 48){
            char c = tokens[i][0];
            n = c;
            }
            // if(n>=48 && n<=57){
            //     stk.push(stol(tokens[i]));
            // }
            if(tokens[i].size() == 1 && tokens[i][0] < 48){
                long num1 = stk.top();
                stk.pop();
                long num2 = stk.top();
                stk.pop();
                switch(n){
                    case 42:
                        //Multiply
                        ans = num2*num1;
                        break;
                    case 43:
                        //Add
                        ans = num2+num1;
                        break;
                    case 45:
                        //subtract
                        ans = num2-num1;
                        break;
                    case 47:
                        //Divide
                        ans = num2/num1;
                        break;
                }
                stk.push(ans);
            }
            else{
                 stk.push(stol(tokens[i]));
            }
        }
        return stk.top();
    }



int main()
{
    vector<string> token{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    long ans = evalRPN(token);
    cout << ans;
    return 0;
}
