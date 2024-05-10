#include <cctype>
#include <iostream>
#include <string>

template <class Char> struct lchar_traits : public std::char_traits<Char> {
  static void assign(Char &c1, Char const &c2) { c1 = std::tolower(c2); }

  static Char *move(Char *s1, Char const *s2, std::size_t n) {
    for (std::size_t it = 0; it < n; it++) {
      assign(s1[it], s2[it]);
    }
    return s1;
  }

  static Char *copy(Char *s, Char const *p, std::size_t n) {
    return move(s, p, n);
  }
};

template <class Char>
using lbasic_string = std::basic_string<Char, lchar_traits<Char>>;

using lstring = lbasic_string<char>;
using lwstring = lbasic_string<wchar_t>;

bool test_lstring() {
  lstring str1{"Hello"};
  lstring str2{"HeLLO"};

  return str1 == str2 ? 0 : 1;
}

int main() {
  using namespace std;
  return test_lstring();
}
