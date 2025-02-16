#line 1 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\common.h"
#include <bits/stdc++.h>

using s32 = int32_t;
using u32 = uint32_t;
using s64 = int64_t;
using u64 = uint64_t;

using namespace std;
#line 2 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\union_find_tree.h"
#include <concepts>
#line 5 "C:\\Users\\takan\\Documents\\Program\\AtCoder\\util\\union_find_tree.h"

namespace util {
class union_find_tree {
 public:
  using parent_or_size_type = std::make_signed_t<size_t>;

 public:
  union_find_tree(size_t n) : m_parent_or_size(n, -1) {}

 public:
  size_t unite(size_t idx0, size_t idx1) {
    assert(idx0 < m_parent_or_size.size());
    assert(idx1 < m_parent_or_size.size());
    size_t l0 = leader(idx0), l1 = leader(idx1);
    if (l0 == l1) return l0;
    if (l0 > l1) std::swap(l0, l1);
    m_parent_or_size[l0] += m_parent_or_size[l1];
    m_parent_or_size[l1] = l0;
    return l0;
  }
  size_t leader(size_t idx) {
    assert(idx < m_parent_or_size.size());
    if (m_parent_or_size[idx] < 0) return idx;
    return m_parent_or_size[idx] = leader(m_parent_or_size[idx]);
  }
  bool same(size_t idx0, size_t idx1) {
    assert(idx0 < m_parent_or_size.size());
    assert(idx1 < m_parent_or_size.size());
    return leader(idx0) == leader(idx1);
  }

  size_t union_size(size_t idx) {
    assert(idx < m_parent_or_size.size());
    return -m_parent_or_size[leader(idx)];
  }

 private:
  std::vector<parent_or_size_type> m_parent_or_size;
};
}  // namespace util
#line 3 "main.cpp"

int main() {
  s64 N, M;
  cin >> N >> M;

  util::union_find_tree uft(N + 1);
  struct cable {
    size_t cbl_idx;
    size_t svr_idx_0;
    size_t svr_idx_1;
  };
  vector<cable> cbls(M + 1);
  vector<vector<size_t>> cbl_idxs_per_svr(N + 1);
  vector<size_t> cand_cbl_idxs;
  for (size_t i = 1; i <= M; ++i) {
    size_t A, B;
    cin >> A >> B;
    cbls[i] = cable{i, A, B};
    cbl_idxs_per_svr[A].push_back(i);
    auto ldr_a = uft.leader(A);
    auto ldr_b = uft.leader(B);
    if (ldr_a == ldr_b) {
      cand_cbl_idxs.push_back(i);
    } else {
      uft.unite(A, B);
    }
  }

  set<size_t> svr_ldr_idxs;
  for (size_t i = 1; i <= N; ++i) {
    svr_ldr_idxs.emplace(uft.leader(i));
  }

  struct change {
    size_t cbl_idx;
    size_t svr_old_idx;
    size_t svr_new_idx;
  };
  vector<change> changes;

  while (svr_ldr_idxs.size() > 1) {
    auto cand_cbl_idx = cand_cbl_idxs.back();
    cand_cbl_idxs.pop_back();
    auto& cand_cbl = cbls[cand_cbl_idx];
    auto svr_old_idx = cand_cbl.svr_idx_0;
    auto svr_new_idx = *svr_ldr_idxs.begin();
    if (uft.leader(svr_old_idx) == uft.leader(svr_new_idx))
      svr_new_idx = *next(svr_ldr_idxs.begin());
    changes.push_back(change{cand_cbl_idx, svr_old_idx, svr_new_idx});

    svr_ldr_idxs.erase(uft.leader(svr_old_idx));
    svr_ldr_idxs.erase(uft.leader(svr_new_idx));
    svr_ldr_idxs.emplace(uft.unite(svr_old_idx, svr_new_idx));
  }

  cout << changes.size() << endl;
  for (const auto& change : changes) {
    cout << change.cbl_idx << " " << change.svr_old_idx << " "
         << change.svr_new_idx << endl;
  }
}
