---
reading: '[Lower Bounds and Theta Notation](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/AnalLower.html)'
teaching_goal: Students will understand lower bounds (Omega) and tight bounds (Theta) in asymptotic analysis.
learning_objectives:
  - Define Big-Omega notation as a lower bound
  - Distinguish between the two definitions of Omega
  - Define Theta notation as a tight bound
  - Use limits to compare growth rates of functions
---

# Lower Bounds and Theta

## Big-Omega Notation

- Big-Oh describes upper bounds
- Big-Omega ($\Omega$) describes lower bounds
- Measures the least amount of resource required
- Describes growth rate of an algorithm

## Formal Definition

- For a non-negative function $T(n)$
- $T(n)$ is in $\Omega(g(n))$ if:
- There exist positive constants $c$ and $n_0$
- $T(n) \geq c \cdot g(n)$ for all $n > n_0$

## Example Analysis

- Assume $T(n) = c_1 n^2 + c_2 n$ ($c_1, c_2 > 0$)
- $c_1 n^2 + c_2 n \geq c_1 n^2$ for $n > 1$
- Therefore, $T(n)$ is in $\Omega(n^2)$
- We prefer the "tightest" lower bound

## Sequential Search

- Finding value $K$ in array of size $n$
- Average case: examine $n/2$ values
- Worst case: examine $n$ values
- Both are in $\Omega(n)$
- We must examine at least $cn$ values

## Alternate Omega Definition

- $T(n)$ is in $\Omega(g(n))$ if:
- There exists a positive constant $c$
- $T(n) \geq c \cdot g(n)$ for an infinite number of values of $n$
- Not symmetric with Big-Oh definition
- Useful for pathological behaviors

## Pathological Example

- $T(n) = n$ for odd $n$
- $T(n) = n^2/100$ for even $n$
- Alternate definition: $\Omega(n^2)$ (true for infinite even $n$)
- Standard definition: $\Omega(n)$ (cannot find $c, n_0$ for all $n > n_0$)

## Theta Notation

- Used when upper and lower bounds match
- $f(n)$ is $\Theta(g(n))$ if:
- $f(n)$ is in $O(g(n))$
- $f(n)$ is in $\Omega(g(n))$
- Indicates a "tight" bound within a constant factor
- Drop the word "in" for $\Theta$ notation

## Theta vs Big-Oh

- Use $\Theta$ whenever possible
- Big-Oh is used when bounds are unknown
- $\Theta$ implies we know the exact growth rate

## Comparing Functions

- Use limits to determine growth rates
- $\lim_{n \rightarrow \infty} \frac{f(n)}{g(n)}$
- Limit is $\infty$: $f(n)$ is $\Omega(g(n))$
- Limit is $0$: $f(n)$ is $O(g(n))$
- Limit is constant: $f(n)$ is $\Theta(g(n))$

## Example Comparison

- $f(n) = n^2$
- $g(n) = 2n \log n$
- $\frac{n^2}{2n \log n} = \frac{n}{2 \log n}$
- Limit as $n \rightarrow \infty$ is $\infty$
- Therefore, $n^2$ is in $\Omega(2n \log n)$

## Exercise

Determine if $f(n) = 3n^2 + 5n$ is $\Theta(n^2)$

## Exercise

Compare $f(n) = n^3$ and $g(n) = n^4$ using limits
