#include <iostream>
#include <regex>
#include <string>

std::vector<std::string> parseString(std::string const &strRef) {
  std::vector<std::string> ret;

  std::string last = strRef;
  std::string::size_type pos = std::string::npos;
  do {
    pos = last.find(' ');
    if (pos == std::string::npos) {
      break;
    }

    if (pos == 0) {
      last = std::string(last.begin() + 1, last.end());
      continue;
    }

    ret.push_back(std::string(last.begin(), last.begin() + pos));
    auto lsz = last.size();

    // this will catch if there is a single space at the end
    if (lsz == pos + 1) {
      return ret;
    }

    last = std::string(last.begin() + pos + 1, last.end());
  } while (pos != std::string::npos);

  if (last.size()) {
    ret.push_back(last);
  }

  return ret;
}

int main() {
  {
    std::string str1{"World "};
    std::string::size_type pos = str1.find(' ');
    std::string::size_type sz = str1.size();
  }

  {
    std::string str1{" World "};
    std::string::size_type pos = str1.find(' ');
    std::string::size_type sz = str1.size();
  }

  {
    std::string str1{"Hello%20World!"};

    std::string::size_type pos = str1.find("o");

    std::string str2 = std::regex_replace(str1, std::regex("%([0-9]*)"), "$1");

    // str1.replace(5, 2, "G");
  }

  {
    std::string str1{"Hello World!"};

    std::string::size_type pos = str1.find(" ");

    std::string::iterator str1it = str1.begin() + pos;

    std::string str2{str1it + 1, str1.end()};

    std::string str3{str1.begin(), str1.begin() + pos};
  }

  {
    auto v = parseString("    Hello World! Another word     ");
    auto s = v.size();
  }

  {
    using namespace std;
    auto v = string("this_text_q");
    string::size_type pos = v.find_last_of('_');
    string::size_type size = 0;
    auto subs = v.substr(pos);
    if (string::npos != pos) {
      size = v.size();
    } else {
      return 10;
    }
    return 0;
  }

  return 0;
}
