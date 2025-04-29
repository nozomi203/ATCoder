#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
class trie {
 public:
  s64 push_x(const string& s) {
    node* p_node{&m_root};
    bool has_end_x{false};
    for (s64 i{0}; i < s.size(); ++i) {
      p_node = &p_node->get_child(s[i]);
      if (p_node->end_x) has_end_x = true;
    };
    if (!has_end_x) {
      p_node->end_x = true;
      const auto cnt_y = p_node->cnt_y;
      p_node->cnt_y = 0;
      p_node = p_node->parent;
      while (p_node != nullptr) {
        p_node->cnt_y -= cnt_y;
        p_node = p_node->parent;
      }
      return cnt_y;
    }
    return 0;
  }

  s64 push_y(const string& s) {
    node* p_node{&m_root};
    for (s64 i{0}; i < s.size(); ++i) {
      p_node = &p_node->get_child(s[i]);
      if (p_node->end_x) {
        p_node = p_node->parent;
        while (p_node != nullptr) {
          --p_node->cnt_y;
          p_node = p_node->parent;
        }
        return 0;
      }
      ++p_node->cnt_y;
    };
    return 1;
  }

 private:
  struct node {
    node* parent{nullptr};
    map<char, node> childs;
    bool end_x{false};
    s64 cnt_y{0};
    node& get_child(char c) {
      if (auto it = childs.find(c); it != childs.end()) {
        return it->second;
      } else {
        auto& child = childs[c];
        child.parent = this;
        return child;
      }
    }
  };
  node m_root;
};

int main() {
  s64 q;
  cin >> q;

  trie trie;
  vector<s64> answers;
  s64 ans{0};
  for (s64 i{0}; i < q; ++i) {
    s64 t;
    string s;
    cin >> t >> s;
    if (t == 1) {
      ans -= trie.push_x(s);
    } else {
      ans += trie.push_y(s);
    }
    answers.push_back(ans);
  }

  for (auto ans : answers) cout << ans << endl;
}
