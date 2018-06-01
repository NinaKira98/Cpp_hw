#include <iostream>
using namespace std;

void reverseInt(int& n);

int main() {
  cout << "Hello, Mr. Voskanyan! Input the size of the array >>";
  int num;
  cin >> num;
  
  int* array = new int[num];
  cout << endl << "Input the values: " << endl;
  for(int i = 0; i < num; i++) {
    int val;
    cout << ">>";
    cin >> val;
    array[i] = val;
  }
  
  cout << endl << "Your array with reversed integers is: " << endl;
  cout << "[ ";
  for(int j = 0; j < num; j++) {
    reverseInt(array[j]);
    cout << array[j] << " ";
  }
  cout << "]\n";
  cout << "Thank You!" << endl;
  
  delete array;
}

void reverseInt(int& n) {
  int revnum = 0;
  while(n != 0) {
    revnum = (revnum * 10) + (n % 10);
    n /= 10;
  }
  n = revnum;
}
