#include <iostream>
using namespace std;

struct Card { char suit, value;};

void bubble(struct Card a[], int n){
  for(int i=0;i<n;i++){
    for(int j=n-1;j>=i+1;j--){
      if(a[j].value < a[j-1].value){
        Card t = a[j];
        a[j] = a[j-1];
        a[j-1] = t;
      }
    }
  }
}

void selection(struct Card a[], int n){
  for(int i=0;i<n;i++){
    int minj = i;
    for(int j=i;j<n;j++){
      if(a[j].value < a[minj].value) minj = j;
    }
    Card t = a[i];
    a[i] = a[minj];
    a[minj] = t;
  }
}

void print(struct Card a[], int n){
  for(int i=0;i<n;i++){
    cout << a[i].suit << a[i].value << (i==n-1?"\n":" ");
  }
}

bool isStable(struct Card C1[], struct Card C2[], int n){
  for(int i=0;i<n;i++){
    if(C1[i].suit != C2[i].suit) return false;
  }
  return true;
}

int main(){
  Card C1[100], C2[100];
  int N;
  char ch;

  cin >> N;
  for (int i = 0; i < N; i++) {
    /* code */
    cin >> C1[i].suit >> C1[i].value;
  }

  for (int i = 0; i < N; i++) {
    /* code */
    C2[i] = C1[i];
  }

  bubble(C1, N);
  selection(C2, N);

  print(C1, N);
  cout << "Stable" << endl;
  print(C2, N);
  if(isStable(C1, C2, N)){
    cout << "Stable" << endl;
  }else{
    cout << "Not stable" << endl;
  }

  return 0;
}
