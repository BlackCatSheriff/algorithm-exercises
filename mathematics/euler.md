# 欧拉函数总结

一、 性质

- $\phi(n) = n(1-\frac{1}{p_1})(1-\frac{1}{p_2})(1-\frac{1}{p_3})...(1-\frac{1}{p_n})$

- $gcd(a,b)=1$    $\phi(ab)=\phi(a)\phi(b)$

- 若 p 为素数， $\phi(p) = p-1$

- 若 p 为素数，$n=p^k$  则 $\phi(n)=(p-1)p^{k-1}$

- 若 p 为素数，对任意数字 n,    $\phi(np)$ 可以如下求解

  - 当 p 可以整除 n  时： $\phi(np)=\phi(n)p$

  - 当 p 不可以整除 n  时： $\phi(np)=\phi(n)\phi(p)$

  - > 证明如下：
    >     可以对n进行分解质因数：n = p1 * p2 * ... * pm，此时n*p的分解质因数的结果就是：
    >             n*p = p1 * p2 * ... * pm * p
    > 式子右边的每一项都是素数，显然，任意两个素数都是互质的，因此如果：p1, p2, ... pm 中的没有一个数字等于p，那么结合引理2，p一定就和n是互质的，此时n一定不能被p整除，此时根据定理3，就可以得到：φ(n*p) = φ(n)*φ(p)
    >     如果 p1, p2, ... pm 中有k项和p是相同的，此时n是p的倍数，p可以整除n。单独将这k想抽取出来，剩余的数字的乘积记为n',那么：n = n' * p^k, n*p = n' * p^(k+1) 此时，可以知道：n'和p^k, p^(k+1)一定都是互质的，根据定理3，可得：
    >      φ(n) = φ(n') * φ(p^k) =  φ(n') * (p-1)*p^(k-1)
    >      φ(n*p) = φ(n' * p^(k+1)) = φ(n') *  φ(p^(k+1)) =  φ(n') * (p-1)*p^k
    >              = φ(n') * (p-1)*p^(k-1) * p
    > 因此：
    >      φ(n*p) = φ(n) * p
    > 证毕。


- 当 n 为奇数时， $\phi(2n)=\phi(n)$   (因为， $gcd(2, n)=1$)
- 小于n的与n互质的数的和可以表示为 $\phi(n)*n/2$
- 求取最小的m(m > 1)，使φ(m) >= n，得到的m应为从n + 1开始的第一个素数。此条是我从欧拉函数表中观察得出的，或许有用，可以参考LightOJ1370。

