#include <bits/stdc++.h>

using namespace std;
int prio(char c)
{
    if(c=='*' || c=='/')return 3;
    if(c=='+' || c=='-')return 2;
    if(c=='(')return 1;
    if(c==')')return 0;
    return -1;
}
int cale(int a,int b,char c)
{
    if(c=='+')return a+b;
    if(c=='-')return a-b;
    if(c=='*')return a*b;
    return a/b;
}
stack<int> num;
stack<char> opst;
int main()
{
    int br=0;
    string s;
    cin>>s;
    s+="p";
    for(int i=0; i<s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            br=br*10+(s[i]-'0');
            continue;
        }
        else if(br!=0)
        {
            num.push(br);
            br=0;
        }
        if(s[i]=='(')opst.push('(');
        else
        {
            while(opst.size()>0 && prio(opst.top())>=prio(s[i]))
            {
                if(opst.top()=='(')
                {
                    opst.pop();
                    continue;
                }
                int second=num.top();
                num.pop();
                int first=num.top();
                num.pop();
                int newn=cale(first,second,opst.top());
                opst.pop();
                num.push(newn);
            }
            if(s[i]==')')continue;
            opst.push(s[i]);
        }
    }
    cout<<num.top();
    return 0;
}
