#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>

namespace {
constexpr auto ticks {100ULL};
std::int64_t pos {50LL};
};

int main() {
  std::uint64_t zeroes {0};
  auto floordivision = [](const std::int64_t lhs, const std::int64_t rhs) { return (lhs / rhs) - (lhs % rhs < 0); };
  std::ifstream stream {std::filesystem::path {"/home/user/Documents/Projects/input.txt"}};
  char side {};
  std::int64_t turn {};
  while (stream >> side >> turn) {
    const std::int64_t old = pos; 
    switch (side) {
      case 'L': { 
        pos -= turn;
        zeroes += floordivision(old - 1, ticks) - floordivision(pos - 1, ticks);
        break;
      }
      case 'R': {
        pos += turn;
        zeroes += floordivision(pos, ticks) - floordivision(old, ticks);
        break;
      }
      default:
        break;
    }
  }
  std::print("{}\n", zeroes);
}
