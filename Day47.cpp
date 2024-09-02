//Q1. Convert the infix expression to postfix expression

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // for non-operators
}
string func(string s){
    int n = s.length();
    string ans = "";
    stack<char>st;
    for(int i=0;i<n;i++){
        int ch = s[i];
        if(ch == '('){
            st.push(ch);
        }
        else if (ch >= 'a' && ch<='z'){
            ans+=ch;
        }
        else if(ch==')'){
            while(st.top()!='(' ){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
         else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s = "a-b*c/d*e+f";
    string ans= func(s);
    cout<<ans<<endl;

    return 0;
}

//Q2. Convert the infix expression to postfix expression
// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
using namespace std;


int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; // for non-operators
}
string itop(string s){
    int n = s.length();
    string ans = "";
    stack<char>st;
    for(int i=0;i<n;i++){
        int ch = s[i];
        if(ch == '('){
            st.push(ch);
        }
        else if (ch >= 'a' && ch<='z'){
            ans+=ch;
        }
        else if(ch==')'){
            while(st.top()!='(' ){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
         else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

string func(string s){
    int st =0;
    int end = s.length()-1;
    //reverse the infix expression
    while(st<end){
          swap(s[st], s[end]);

        // Adjust parentheses after swapping
        if (s[st] == '(') s[st] = ')';
        else if (s[st] == ')') s[st] = '(';

        if (s[end] == '(') s[end] = ')';
        else if (s[end] == ')') s[end] = '(';

        st++;
        end--;
        
    }
     if (st == end) {
        if (s[st] == '(') s[st] = ')';
        else if (s[st] == ')') s[st] = '(';
    }
    //covert the reversed expression to postfix expression
    
    string ans = itop(s);
        
    //reverse the postfix expression
    st=0;
    end=ans.length()-1;
    while(st<end){
        swap(ans[st],ans[end]);
        st++;
        end--;
    }
    
    return ans;
    
}
int main() {
    
   string s = "a+b*(c+d)";
    string ans= func(s);
    cout<<ans<<endl;

    return 0;

}

//Q3. Evaluate the postfix expression  using stack

// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

int evaluate(std::string s) {
    std::stack<int> st;
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            st.push(s[i]-'0');  // Convert character digit to integer
        } else {
            int num1, num2, result;

            switch (s[i]) {
                case '+':
                    num1 = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    result = num2 + num1;
                    st.push(result);
                    break;

                case '-':
                    num1 = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    result = num2 - num1;
                    st.push(result);
                    break;

                case '*':
                    num1 = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    result = num2 * num1;
                    st.push(result);
                    break;

                case '/':
                    num1 = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    if (num1 != 0) {
                        result = num2 / num1;
                        st.push(result);
                    } else {
                        std::cout << "Error: Division by zero is undefined." << std::endl;
                    }
                    break;

                default:
                    std::cout << "Error: Invalid operator." << std::endl;
                    break;
            }
        }
    }

    return st.top();
}

int main() {
    
    string s = "13+";
    int ans = evaluate(s);
    cout<<ans<<endl;
    return 0;
}

//Q4. Evaluate the prefix Expression using stack

// Online C++ compiler to run C++ program online
#include <iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

int evaluate(std::string s) {
    std::stack<int> st;
    int n = s.length();

    for (int i = n-1; i >= 0; i--) {
        if (isdigit(s[i])) {
            st.push(s[i]-'0');  // Convert character digit to integer
        } else {
            int num1, num2, result;
            if (st.size() < 2) {
                cout << "Error: Not enough operands for the operator " << s[i] << "." << endl;
                return 0;  // Return 0 or an appropriate error code
            }
            switch (s[i]) {
                case '+':
                    num1 = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    result = num2 + num1;
                    st.push(result);
                    break;

                case '-':
                    num1 = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    result = num1 - num2;
                    st.push(result);
                    break;

                case '*':
                    num1 = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    result = num2 * num1;
                    st.push(result);
                    break;

                case '/':
                    num1 = st.top();
                    st.pop();
                    num2 = st.top();
                    st.pop();
                    if (num1 != 0) {
                        result = num1 / num2;
                        st.push(result);
                    } else {
                        std::cout << "Error: Division by zero is undefined." << std::endl;
                    }
                    break;

                default:
                    std::cout << "Error: Invalid operator." << std::endl;
                    break;
            }
        }
    }
    
    
    return st.top();
}

int main() {
    
    string s = "++8/*231/*412";
    int ans = evaluate(s);
    cout<<ans<<endl;
    return 0;
}
