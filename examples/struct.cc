#include <print>

struct Student {
  int id;
  float gpa;
  char grade;
};

int main() {
  Student s1 = {101, 3.8, 'A'};
  std::println("Student {} has a GPA of {}", s1.id, s1.gpa);
  return 0;
}
