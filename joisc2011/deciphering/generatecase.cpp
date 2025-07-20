#include "util/common.h"

int main() {
  constexpr size_t case_num = 10;

  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());

  std::uniform_int_distribution<char> dist('A', 'Z');

  for (size_t i = 0; i < case_num; ++i) {
    const auto name_in = format("tests/sample_random_{}.in", i);
    const auto name_out = format("tests/sample_random_{}.out", i);
    ofstream fin(name_in), fout(name_out);
    constexpr size_t l = 10;
    constexpr size_t rule_num = 200;
    string s;
    s.resize(l);
    for (size_t j = 0; j < l; ++j) s[j] = dist(engine);
    map<char, map<char, bool>> map;
    for (size_t j = 0; j < rule_num; ++j)
      map[dist(engine)][dist(engine)] = true;

    fin << l << endl;
    fin << s << endl;
    size_t msize = 0;
    for (const auto& [c1, m] : map) msize += m.size();
    fin << msize << endl;
    for (const auto& [c1, m] : map) {
      for (const auto& [c2, b] : m) {
        fin << c1 << " " << c2 << endl;
      }
    }

    set<string> set;
    for (size_t b = 1; b < (1 << l); ++b) {
      string stmp;
      for (size_t j = 0; j < l; ++j) {
        if (b & (1 << j)) {
          stmp.push_back(s[j]);
        }
      }
      bool valid = true;
      for (size_t j = 0; j < stmp.size() - 1; ++j) {
        if (map[stmp[j]][stmp[j + 1]]) {
          valid = false;
          break;
        }
      }
      if (valid) set.emplace(stmp);
    }

    fout << set.size() << endl;
  }
}
