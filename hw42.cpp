#include <iostream>
using namespace std;
//Write a program which inputs an integer N and prints the first prime and perfect numbers following to it. The detection of prime/perfect number should be implemented in a separate function.

int prime(int n);
int perfect(int n);

int main() {
  cout << "Hello User!\n";
  int n;
  while(true) {
    cout << "Input an integer or press -1 to exit: ";
    cin >> n;
    if(n == -1) break;
    int prm = prime(n);
    int perf = perfect(n);
    cout << "The next prime number is: "<< prm <<endl;
    cout << "The next perfect number is: "<< perf << endl << endl;
  }
  cout << "Goog Bye!\n";
}

int perfect(int n) {
  int j = n + 1, p;
  while(true) {
    int sum = 0;
    for(int k = 1; k < j; k++) {
      if(j % k == 0) {
        sum += k;
      }
    }
    if(sum == j) {
      p = j;
      break;
    }
    j++;
  }
  return p;
}

int prime(int n) {
  int i = n + 1, p;
  while(true) {
    int divs = 0;
    for(int k = 2; k < i; k++) {
      if(i % k == 0) {
        divs++;
      }
    }
    if(divs == 0) {
      p = i;
      break;
    }
    i++;
  }
  return p;
}