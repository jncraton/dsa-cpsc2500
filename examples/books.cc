#include <print>

struct Book {
  char title[100];
  char author[100];
  float price;
};

int main() {
  Book library[3] = {
    {"The Great Gatsby", "F. Scott Fitzgerald", 10.99},
    {"1984", "George Orwell", 8.50},
    {"Brave New World", "Aldous Huxley", 12.00}
  };

  for (int i = 0; i < 3; i++) {
    std::println("Book {}: {} by {}, ${:.2f}", i, library[i].title, library[i].author, library[i].price);
  }

  return 0;
}
