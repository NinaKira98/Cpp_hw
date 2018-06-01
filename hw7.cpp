#include <iostream>
using namespace std;

class Employee {
  public:
  int getID() {return id;};
  void setSal(int sal) {salary = sal;};
  double getSal() {return salary;};
  virtual double calcSal() = 0;

  protected:
  double salary;
  int id;
};


class Permanent: public Employee {
  public:
  Permanent(int id) {this->id = id;}
  double getRate() {return workRate;};
  void setRate(double rate) { //default will be 1
    if((rate <= 1) && (rate > 0) && ((int(rate)*100)%25 == 0)) {workRate = rate;}
    else workRate = 1;
  };
  double calcSal() {return workRate * salary;}; //calculating salary for the current month

  private:
  double workRate;
};


class Contractor: public Employee {
  public:
  Contractor(int id) {this->id = id;};
  void setDays(int d) { //default zero days
    if(d >= 0 && d <= 30) numDays = d;
    else numDays = 0;
  };
  int getDays() {return numDays;};
  double calcSal() {return salary/(30.0)*numDays;};

  private:
  int numDays;
};


int main() {
  cout << "Hello!\n";
  Employee** empArray = new Employee*[6];

  Permanent* p1 = new Permanent(10);
  p1->setSal(100000);
  p1->setRate(1);
  empArray[0] = p1;

  Contractor* c1 = new Contractor(50);
  c1->setSal(500000);
  c1->setDays(13);
  empArray[1] = c1;

  Permanent* p2 = new Permanent(20);
  p2->setSal(400000);
  p2->setRate(0.5);
  empArray[2] = p2;

  Permanent* p3 = new Permanent(30);
  p3->setSal(100000);
  p3->setRate(0.75);
  empArray[3] = p3;

  Contractor* c2 = new Contractor(60);
  c2->setSal(500000);
  c2->setDays(5);
  empArray[4] = c2;

  Permanent* p4 = new Permanent(40);
  p4->setSal(100000);
  p4->setRate(0.5);
  empArray[5] = p4;

  for(int i = 0; i < 6; i++) {
    double thisSal = empArray[i]->calcSal();
    cout << "Salary for employee" << " ID-" << empArray[i]->getID() << " is: " << thisSal << endl;
  }
}