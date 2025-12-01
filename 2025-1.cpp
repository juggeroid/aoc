#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>

namespace {
constexpr auto kMod {100};
};

int main() {
  std::int64_t position {50LL};
  std::uint64_t zeroes {0};
  auto floordivision = [](const std::int64_t lhs, const std::int64_t rhs) { return (lhs / rhs) - ((lhs % rhs < 0) ? 1 : 0); };
  const std::filesystem::path path {"/home/user/Documents/Projects/input.txt"};
  std::ifstream stream {path};
  char side {};
  std::int64_t turn {};
  while (stream >> side >> turn) {
    std::int64_t old = position; 
    switch (side) {
      case 'L': { 
        position -= turn;
        zeroes += floordivision(old - 1, kMod) - floordivision(position - 1, kMod);
        break;
      }
      case 'R': {
        position += turn;
        zeroes += floordivision(position, kMod) - floordivision(old, kMod);
        break;
      }
      default:
        break;
    }
  }
  std::print("{}\n", zeroes);
}