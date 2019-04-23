#include<iostream>
#include<stack>
#include<string>

using namespace std;

string reversestring(string str){
    stack<char> s;
    string revstring = "";
    std::string::iterator it;

    for(it = str.begin(); it!=str.end(); it++){
        s.push(*it);
    }

    while (! s.empty()){
        revstring.push_back(s.top());
        s.pop();
    }

    return revstring;
}

bool checkvalidnestedexpression(string s){
    return true;
}

int main(){

    string s = "adarsh";
    string rev = reversestring(s);
    cout<<rev;

    return 1;
}
