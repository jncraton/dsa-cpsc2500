#include <print>
#include <sys/resource.h>

long peak_memory_kb() {
  rusage usage{};
  getrusage(RUSAGE_SELF, &usage);
  return usage.ru_maxrss;
}

void leakMemory() { int *ptr = new int(42); }

int main() {
  for (int i = 0; i <= 10000000; ++i) {
    leakMemory();

    if (i % 1000000 == 0) {
      std::println("After {} calls: {} kB peak memory", i, peak_memory_kb());
    }
  }

  return 0;
}
