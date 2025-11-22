#pragma once

#include <cstdint>
#include <functional>
#include <queue>
#include <span>
#include <stack>
#include <type_traits>
#include <vector>

namespace util {

namespace rerooting_dp {

using graph = std::vector<std::vector<int64_t>>;

template <typename TIn, typename TOut, TOut Invalid,
          auto MergeOutput /*TOut(TOut, TOut)*/,       //
          auto GetOutput /*TOut(int64_t, TIn, TOut)*/  //
          >
inline std::vector<TOut> solve(const graph& g, const std::span<TIn>& inputs) {
  static_assert(std::is_invocable_r_v<TOut, decltype(MergeOutput), TOut, TOut>);
  static_assert(std::is_invocable_r_v<TOut, decltype(GetOutput), TIn, TOut>);

  const size_t n = g.size();

  constexpr int64_t kIdx_Invalid = -1LL;
  constexpr int64_t kIdx_Unset = -2LL;

  struct node_t {
    int64_t parent_gidx{kIdx_Unset};
    std::vector<int64_t> child_gidxs;
    int64_t self_lidx{kIdx_Unset};

    TOut out_parent{Invalid};
    std::vector<TOut> out_children_asc;
    std::vector<TOut> out_children_desc;

    TOut get_children_output(int64_t except = -1) {
      TOut ret = out_parent;
      if (except != kIdx_Invalid) {
        if (except > 0) ret = MergeOutput(ret, out_children_asc[except - 1]);
        if (except < out_children_desc.size() - 1)
          ret = MergeOutput(ret, out_children_desc[except + 1]);
      } else if (!out_children_asc.empty()) {
        ret = MergeOutput(ret, out_children_asc.back());
      }
      return ret;
    }
  };

  std::vector<node_t> nodes(n);
  {
    std::queue<int64_t> que;
    que.push(0);

    node_t& node_root = nodes[0];
    node_root.parent_gidx = kIdx_Invalid;
    node_root.self_lidx = kIdx_Invalid;

    while (!que.empty()) {
      const int64_t cur = que.front();
      que.pop();

      node_t& node_cur = nodes[cur];

      int64_t child_num = 0;
      for (auto nxt : g[cur]) {
        node_t& node_nxt = nodes[nxt];
        if (node_nxt.parent_gidx != kIdx_Unset) continue;
        node_nxt.parent_gidx = cur;
        node_nxt.self_lidx = child_num++;
        node_cur.child_gidxs.push_back(nxt);
        que.push(nxt);
      }

      node_cur.out_children_asc.resize(child_num, Invalid);
      node_cur.out_children_desc.resize(child_num, Invalid);
    }
  }

  {
    std::vector<bool> opened(n);
    std::stack<int64_t> stk;
    stk.push(0);
    while (!stk.empty()) {
      const auto cur = stk.top();
      node_t& node_cur = nodes[cur];
      if (opened[cur]) {
        stk.pop();
        const auto parent_gidx = node_cur.parent_gidx;
        const auto self_lidx = node_cur.self_lidx;
        const auto child_num = node_cur.out_children_asc.size();
        for (size_t i = 1; i < child_num; ++i) {
          node_cur.out_children_asc[i] = MergeOutput(
              node_cur.out_children_asc[i], node_cur.out_children_asc[i - 1]);
          node_cur.out_children_desc[child_num - 1 - i] =
              MergeOutput(node_cur.out_children_desc[child_num - 1 - i],
                          node_cur.out_children_desc[child_num - i]);
        }
        if (parent_gidx != kIdx_Invalid) {
          node_t& node_parent = nodes[parent_gidx];
          node_parent.out_children_asc[self_lidx] =
              node_parent.out_children_desc[self_lidx] =
                  GetOutput(inputs[cur], node_cur.get_children_output());
        }
      } else {
        opened[cur] = true;
        for (auto nxt : node_cur.child_gidxs) stk.push(nxt);
      }
    }
  }

  {
    std::vector<TOut> ret(n);
    std::stack<int64_t> stk;
    stk.push(0);
    while (!stk.empty()) {
      const auto cur = stk.top();
      node_t& node_cur = nodes[cur];
      stk.pop();

      const auto parent_gidx = node_cur.parent_gidx;
      if (parent_gidx != kIdx_Invalid) {
        node_t& node_parent = nodes[parent_gidx];
        node_cur.out_parent =
            GetOutput(inputs[parent_gidx],
                      node_parent.get_children_output(node_cur.self_lidx));
      }

      ret[cur] = node_cur.get_children_output();

      for (auto nxt : node_cur.child_gidxs) stk.push(nxt);
    }

    return ret;
  }
}

}  // namespace rerooting_dp
}  // namespace util