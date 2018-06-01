#include <iostream>
using namespace std;
//Write a program which allows user to input an array of 10 integers, finds the average of the elements and calculate the number of items greater than the average.  The average calculation should be implemented in a separate function.

double average(int a[], int size);

int main() {
  cout << "Hello User!\n";
  int array[10];
  
  for(int i = 0; i < 10; i++) {
    int val;
    cout << "Input element " << i+1 << ": ";
    cin >> val;
    array[i] = val;
  }
  double avg = average(array, 10);
  cout <<"The average is: " << avg << endl;
  int greater = 0;
  for(int j = 0; j < 10; j++) {
    if(array[j] > avg) greater++;
  }
  cout << "The number of greater than average items is: "<<greater<<endl;
}

double average(int a[], int size) {
  double sum = 0;
  for(int i = 0; i < size; i++) {
    sum += a[i];
  }
  double av = sum/size;
  return av;
}