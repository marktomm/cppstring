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

template <class Char> struct ichar_traits : public std::char_traits<Char> {
  static bool eq(Char c, Char d) { return std::toupper(c) == std::toupper(d); }

  static bool lt(Char c, Char d) { return std::toupper(c) < std::toupper(d); }

  static int compare(Char const *p, Char const *q, std::size_t n) {
    for (std::size_t i = 0; i < n; i++) {
      if (lt(p[i], q[i])) {
        return -1;
      } else if (lt(q[i], p[i])) {
        return 1;
      }
    }
    return 0;
  }

  static typename std::char_traits<Char>::char_type const *
  find(Char const *p, std::size_t n, Char c) {
    for (; n-- != 0; ++p) {
      if (!eq(c, *p)) {
        return p;
      }
    }
    return 0;
  }
};

template <class Char>
using lbasic_string = std::basic_string<Char, lchar_traits<Char>>;

using lstring = lbasic_string<char>;
using lwstring = lbasic_string<wchar_t>;

template <class Char>
using ibasic_string = std::basic_string<Char, ichar_traits<Char>>;

using istring = ibasic_string<char>;
using iwstring = ibasic_string<wchar_t>;

int test_lstring() {
  lstring str1{"Hello"};
  lstring str2{"HeLLO"};

  return str1 == str2 ? 0 : 1;
}

int test_istring() {
  istring str1{"Hello"};
  istring str2{"HeLLo"};

  return str1 == str2 ? 0 : 1;
}

template <class Char, class Traits, class Char2>
std::basic_ostream<Char, Traits> &
operator<<(std::basic_ostream<Char, Traits> &os,
           lbasic_string<Char2> const &str) {
  return os.write(str.data(), str.size());
}

// all ok if this compiles
void stdout_lstring() { std::cout << lstring("Hello") << '\n'; }

int main() {
  using namespace std;
  return test_lstring() || test_istring();
}
