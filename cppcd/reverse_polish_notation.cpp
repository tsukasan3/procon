#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

int top, S[1000];

void push(int x){
  S[++top] = x;
}

int pop(){
  top--;
  return S[top+1];
}

int main(){
  int a,b;
  top = 0;
  string s;
  while(cin >> s){
    if(s == "+"){
      a = pop();
      b = pop();
      push(a + b);
    }else if(s == "-"){
      a = pop();
      b = pop();
      push(b - a);
    }else if(s == "*"){
      a = pop();
      b = pop();
      push(a * b);
    }else{
      push(atoi(s.c_str()));
    }
    if(getchar()=='\n'){
      cout << pop() << endl;
      return 0;
  }
}
}
