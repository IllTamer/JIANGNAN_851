## 排序算法比较

> 关于：算法复杂度描述中为什么用$\log n$，而不用$\log_2 n$、$\ln n$或$\lg n$`

假如有logaB（a为底数），由换底公式可得
$$
\log_a b = \frac{log_c b}{log_c a}
$$
其中$log_c a$（c为底数）为常数，由复杂度的运算规则$O(C \times f(N))=O(f(N))$，因为C是一个正的常数，得$O(\log_a B) = O(\log_c B)$。可知算法的时间复杂度与不同底数只有常数的关系，均可以省略，自然可以用$logN$代替。

// TODO