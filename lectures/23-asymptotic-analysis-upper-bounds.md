# Asymptotic Analysis and Upper Bounds

## Asymptotic Analysis

- Studies algorithm behavior as input size $n$ "gets big"
- Ignores constant factors to focus on growth rates
- Faster hardware/compilers change the constant, not the growth rate
- Constants matter only for small $n$ or specific performance requirements

## Big-Oh Notation

- Represents an upper bound on the growth rate
- $T(n)$ is in $O(f(n))$ if there exist positive constants $c$ and $n_0$ such that $T(n) \leq cf(n)$ for all $n > n_0$
- $n_0$ is the point where the bound begins to hold
- $c$ is a constant that scales the bound

## Examples

- Sequential Search
  - Average case: $T(n) = c_s n / 2$
  - Since $c_s n / 2 \leq c_s n$ for $n > 1$, $T(n) \in O(n)$
- Quadratic Growth
  - $T(n) = c_1 n^2 + c_2 n$
  - $T(n) \leq (c_1 + c_2)n^2$ for $n > 1$
  - $T(n) \in O(n^2)$
- Constant Time
  - $T(n) = c$
  - Traditionally expressed as $O(1)$

## Context Matters

- Growth rates must be specified for a context
  - Best case
  - Average case
  - Worst case
- Example: "Sequential search is $O(n)$ in the worst case"
- $O(n)$ is in $O(n^2)$, but $O(n^2)$ is not in $O(n)$
- We seek the tightest (lowest) possible upper bound

## Simplifying Rules

1. Transitivity: If $f(n) \in O(g(n))$ and $g(n) \in O(h(n))$, then $f(n) \in O(h(n))$
2. Constant Multiples: If $f(n) \in O(kg(n))$ for $k > 0$, then $f(n) \in O(g(n))$
3. Addition: If $f_1(n) \in O(g_1(n))$ and $f_2(n) \in O(g_2(n))$, then $f_1(n) + f_2(n) \in O(\max(g_1(n), g_2(n)))$
4. Multiplication: If $f_1(n) \in O(g_1(n))$ and $f_2(n) \in O(g_2(n))$, then $f_1(n)f_2(n) \in O(g_1(n)g_2(n))$

## Summary

- Ignore constants and lower-order terms
- Example: $T(n) = 3n^4 + 5n^2 \in O(n^4)$
- Higher-order terms dominate as $n \to \infty$
