#include <iostream>
using namespace std;

void reverse(int *ar, int size);

int main() {
  cout << "Hi! Input the size of the array >>";
  int num;
  cin >> num;
  int* array = new int[num];
  
  cout << endl << "Input the values: " << endl;
  for(int i = 0; i < num; i++) {
    cout << ">>";
    cin >> array[i];
  }
  
  reverse(array, num);
  
  cout << endl << "Reversed array is: " << endl << "[ ";
  for(int i = 0; i < num; i++) {
    cout << array[i] << " ";
  }
  cout << "]" << endl;
  cout << "Bye-bye!" << endl;
  
  delete array;
}

void reverse(int *ar, int size) {
  for(int i = 0; i < size/2; i++) {
    int temp = *(ar + i);
    *(ar + i) = *(ar + size - i - 1);
    *(ar + size - i - 1) = temp;
  }
}