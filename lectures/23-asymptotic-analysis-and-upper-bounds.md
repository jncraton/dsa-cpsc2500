---
reading: '[Asymptotic Analysis and Upper Bounds](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/AnalAsymptotic.html)'
teaching_goal: Students will understand asymptotic analysis and big-Oh notation for algorithm complexity.
learning_objectives:
  - Define asymptotic analysis and its purpose
  - Explain big-Oh notation and its formal definition
  - Apply simplifying rules to determine big-Oh bounds
  - Identify the importance of growth rates over constant factors
---

# Asymptotic Analysis

## Growth Rates

- Constants matter for small inputs
- Growth rates matter for large inputs
- Faster hardware doesn't change growth rates
- Asymptotic analysis focuses on "getting big"

## Ignoring Constants

- $T(n) = 10n$ vs $T(n) = 2n^2$
- $2n^2$ eventually surpasses $10n$
- Constant factors only shift intersection points
- We ignore constants to simplify analysis

## Asymptotic Analysis

- Study of algorithms as $n$ reaches a limit
- Simplifies comparison of different algorithms
- Provides "back of the envelope" estimation
- Useful for understanding general behavior

## When Constants Matter

- Small input sizes (e.g., sorting 5 records)
- Large constant factors (e.g., 1000x difference)
- Practicality vs. theoretical growth rate
- Be aware of limitations in specific cases

## Upper Bounds

- Describes the highest growth rate
- Indicates "worst-case" behavior
- Notation: $O(f(n))$
- "In $O(f(n))$ in the worst case"

## Formal Definition

- $T(n)$ is in $O(f(n))$ if:
- $\exists$ positive constants $c$ and $n_0$
- $T(n) \leq cf(n)$ for all $n > n_0$
- $n_0$ is the smallest value where it holds
- $c$ can be any valid constant

## Example 1

- Sequential search: $T(n) = c_s n / 2$
- For $n > 1$, $c_s n / 2 \leq c_s n$
- Therefore, $T(n)$ is in $O(n)$
- $n_0 = 1, c = c_s$

## Example 2

- $T(n) = c_1 n^2 + c_2 n$
- $c_1 n^2 + c_2 n \leq c_1 n^2 + c_2 n^2$
- $T(n) \leq (c_1 + c_2)n^2$
- Therefore, $T(n)$ is in $O(n^2)$
- $c = c_1 + c_2, n_0 = 1$

## Example 3

- Array access: $T(n) = c$
- Technically $O(c)$
- Traditionally $O(1)$
- Constant time regardless of size

## Context Matters

- "Best at what?"
- Growth rate depends on input class
- Best case, average case, or worst case
- Statements must specify the context

## Tightness

- $O(n)$ is in $O(n^2)$
- $O(n^2)$ is NOT in $O(n)$
- We seek the tightest (lowest) upper bound
- Use $\in O(f(n))$ to show membership

## Simplifying Rule 1

- If $f(n) \in O(g(n))$ and $g(n) \in O(h(n))$
- Then $f(n) \in O(h(n))$
- Transitive property of bounds

## Simplifying Rule 2

- If $f(n) \in O(k \cdot g(n))$ for $k > 0$
- Then $f(n) \in O(g(n))$
- Ignore multiplicative constants

## Simplifying Rule 3

- If $f_1(n) \in O(g_1(n))$ and $f_2(n) \in O(g_2(n))$
- Then $f_1(n) + f_2(n) \in O(\max(g_1(n), g_2(n)))$
- Sequence of operations: keep the most expensive

## Simplifying Rule 4

- If $f_1(n) \in O(g_1(n))$ and $f_2(n) \in O(g_2(n))$
- Then $f_1(n) \cdot f_2(n) \in O(g_1(n) \cdot g_2(n))$
- Used for nested loops

## Summary Rules

- Ignore constants
- Ignore lower-order terms
- $T(n) = 3n^4 + 5n^2$ is $O(n^4)$
- Higher-order terms swamp lower-order terms
- Focus on the dominant term

## Exercise

Determine the big-Oh bound for $T(n) = 5n^2 + 10n + 100$

## Exercise

Compare $T(n) = 100n$ and $T(n) = n^2$. Which is better for $n=1000$?
