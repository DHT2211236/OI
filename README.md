# OI

状态设计
令 $f(\mathbf{h}, t)$ 表示还有 $t$ 轮，当前各怪物 HP 为 $\mathbf{h} = (h_1, h_2, ..., h_n)$ 时，最终成功的最大概率。

$f(\mathbf{h}, 0) = 1$ 若所有 $h_i = 1$，否则 $0$。
状态数：每个 $h_i$ 最多 $h_i^{\text{init}}$ 种，$n$ 只怪物，$m$ 轮，状态数为 $O(\prod h_i \cdot m)$，$n$ 不大时可行。
状态转移
对于 $f(\mathbf{h}, t)$：

剑闪耀（概率 $p$）
你可以选择：

不操作：$f(\mathbf{h}, t-1)$
全体-1（前提：所有 $h_i > 1$）：$f(\mathbf{h}-1, t-1)$
取最大值
剑不闪耀（概率 $1-p$）
你可以选择：

不操作：$f(\mathbf{h}, t-1)$
单体-1（任选 $i$，且 $h_i > 1$）：$f(\mathbf{h}'_i, t-1)$，其中 $\mathbf{h}'_i$ 是第 $i$ 个怪物 HP-1
取最大值
所以：

 $$ f(\mathbf{h}, t) = p \cdot \max\left(f(\mathbf{h}, t-1), \text{if } \min h_i > 1: f(\mathbf{h}-1, t-1)\right) + (1-p) \cdot \max\left(f(\mathbf{h}, t-1), \max_{i: h_i > 1} f(\mathbf{h}'_i, t-1)\right) $$