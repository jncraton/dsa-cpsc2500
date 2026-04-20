---
reading: '[OpenDSA Summations](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/Summations.html),[OpenDSA Recurrence Relations](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/RecurrenceIntro.html)'
teaching_goal: Students will connect summation notation and recurrence relations to algorithm analysis and closed-form reasoning
learning_objectives:
  - Interpret sigma notation and translate summations into expanded sums
  - Identify standard summation formulas and use them to derive closed forms
  - Define recurrence relations and solve simple recurrences by expansion
---

# Summations and Recurrences

## Counting cost

- Loops add repeated work
- Summations express total cost over iterations
- Recurrences express cost of recursive calls

## Sigma notation

- $\sum_{i=1}^{n} f(i)$ means $f(1) + f(2) + \cdots + f(n)$
- Lower limit shows start index
- Upper limit shows end index
- Common in loop cost analysis

## Closed form

- A closed form does not use summation notation
- It is a direct algebraic expression in $n$
- Closed forms make growth easier to compare

---

How does replacing a summation with a closed form simplify algorithm reasoning?

## Basic summations

- $\sum_{i=1}^{n} 1 = n$
- $\sum_{i=1}^{n} i = \frac{n(n+1)}{2}$
- $\sum_{i=1}^{n} i^2 = \frac{n(n+1)(2n+1)}{6}$

## Exercise

Convert the loop cost below into a summation and then into closed form.

```python
for i from 1 to $n$:
    do constant work
```

## Recurrence relation

- Defines a function using smaller values of itself
- Useful for recursive algorithms
- Requires base cases and a recursive clause

## Example recurrence

- $T(n) = T(n-1) + 1$ for $n>1$
- $T(1) = 0$
- The recurrence counts work for a linear recursion

## Expansion method

- Replace $T(n-1)$ with its definition
- Continue until base case appears
- Look for a pattern in the expanded terms

## Expansion example

- $T(n) = T(n-1) + 1$
- $T(n-1) = T(n-2) + 1$
- $T(n) = T(n-2) + 2$
- $T(n) = T(n-k) + k$

## Closed form from expansion

- Stop when $n-k = 1$
- Then $k = n-1$
- So $T(n) = T(1) + (n-1) = n-1$

---

What does the expansion method reveal about the shape of recursive cost?

## Another example

- $T(n) = T(n-1) + n$ with $T(1) = 1$
- Expansion gives $T(n) = 1 + 2 + \cdots + n$
- Closed form is $\frac{n(n+1)}{2}$

## Recurrence and summation

- Many recurrences unfold into summations
- The recurrence $T(n)=T(n-1)+n$ becomes $\sum_{i=1}^{n} i$
- This links recursive and iterative cost models

## Exercise

Solve the recurrence $T(n)=T(n-1)+2$ with $T(1)=3$.

- Write the expanded form
- Derive the closed form

## Growth classes

- Constant work gives $O(1)$
- Linear recurrence gives $O(n)$
- Quadratic summation gives $O(n^2)$
- Geometric summation can give $O(2^n)$ or $O(n)$ depending on bounds
