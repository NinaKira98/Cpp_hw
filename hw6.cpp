#include <iostream>
#include <string>
using namespace std;

class Date {
  public: 
  int day, year;
  string month;
};


class Student {
  private:
  string first_n, last_n, faculty;
  Date birth_date;
  
  public:
  Student() {}
  Student(string first, string last, string fac) : first_n(first), last_n(last), faculty(fac) {}
  Student(const Student &st) { //I assume by non-personal you meant the faculty :/ Please, be more clear in the instructions, thank you
    faculty = st.faculty;
  }
  void set_birth_date(int day, string month, int year);
  void set_name(string first_name, string last_name);
  void set_faculty(string fac);
  string get_birth_date();
  string get_first_name();
  string get_last_name();
  string get_faculty();
};


void Student::set_birth_date(int day, string month, int year) {
  birth_date.day = day;
  birth_date.month = month;
  birth_date.year = year;
}
void Student::set_name(string first_name, string last_name) {
  first_n = first_name;
  last_n = last_name;
}
void Student::set_faculty(string fac) {
  faculty = fac;
}
string Student::get_birth_date() {
  string bd = to_string(birth_date.year) + ", " + birth_date.month + " - " + to_string(birth_date.day);
  return bd;
}
string Student::get_first_name() {
  return first_n;
}
string Student:: get_last_name() {
  return last_n;
}
string Student:: get_faculty() {
  return faculty;
}


int main() {
  cout << "Hello World!\n";
  Student s1("Nina", "Kirakosyan", "CS");
  s1.set_birth_date(9, "January", 1998);
  cout << "Name: " << s1.get_first_name() << " " << s1.get_last_name() <<endl;
  cout << "Faculty: " << s1.get_faculty() << endl;
  cout << "Date of Birth: " << s1.get_birth_date() << endl << endl;
  
  //copy constructor
  Student copy = s1;
  cout << "The copy - " << endl;
  copy.set_name("CopyNina", "CopyKirakosyan");
  copy.set_birth_date(1, "January", 1111);
  cout << "Name: " << copy.get_first_name() << " " << copy.get_last_name() <<endl;
  cout << "Faculty: " << copy.get_faculty() << endl;
  cout << "Date of Birth: " << copy.get_birth_date() << endl << endl;
  
  //default constructor
  Student s2;
  s2.set_name("Jane", "Doe");
  s2.set_birth_date(22, "April", 2018);
  s2.set_faculty("EC");
  cout << "With default construstor -" << endl;
  cout << "Name: " << s2.get_first_name() << " " << s2.get_last_name() <<endl;
  cout << "Faculty: " << s2.get_faculty() << endl;
  cout << "Date of Birth: " << s2.get_birth_date() << endl;
}