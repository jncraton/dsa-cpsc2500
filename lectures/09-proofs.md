---
reading: '[OpenDSA Proofs](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/Proofs.html)'
teaching_goal: Students will learn the structure and use of mathematical proof techniques to support algorithmic reasoning
learning_objectives:
  - Describe direct proof, proof by contradiction, and mathematical induction
  - Apply each proof technique to statements about sums, integers, and recurrences
  - Compare proof methods and choose the most effective structure for a claim
---

# Proof Techniques

## Mathematical reasoning

## Investigation and argument

- Solving a problem has two parts: investigate then argue
- Writing a proof makes reasoning clear and convincing
- Proofs are central to correctness and algorithm design

## What is a proof?

- A proof is a logical argument that establishes truth
- It explains why a statement must hold in every case
- Good proofs use standard structure and clear steps

## Direct proof

- A [direct proof](https://en.wikipedia.org/wiki/Mathematical_proof#Direct_proof) deduces the conclusion from assumptions
- Use known facts, algebra, and logic rules
- Works well when the path from premise to conclusion is obvious

## Example direct proof

- Claim: $\sum_{i=1}^n i = \frac{n(n+1)}2$
- Pair first and last terms: $1 + n = n+1$
- There are $n/2$ such pairs when $n$ is even
- The same idea holds when $n$ is odd

---

How does a direct proof make the structure of a formula more visible?

## Proof by contradiction

- Assume the statement is false and derive a contradiction
- If the assumption leads to impossibility, the statement is true
- This is a common tool when direct proof is hard

## Contradiction example

- Theorem: there is no largest integer
- Assume a largest integer $B$ exists
- Then $B+1$ is an integer and $B+1 > B$
- Contradiction: $B$ was not largest

## Contrapositive

- Instead of proving $P \Rightarrow Q$, prove $\neg Q \Rightarrow \neg P$
- The contrapositive is logically equivalent to the original claim
- It can simplify proofs about functions, sets, and order

## Exercise

Show that if $n^2$ is even, then $n$ is even using a proof by contradiction or contrapositive.

## Mathematical induction

- [Mathematical induction](https://en.wikipedia.org/wiki/Mathematical_induction) proves a claim for all integers $n \ge c$
- Base case: verify the claim for the smallest value
- Induction step: assume it holds for $n-1$, then prove it for $n$

## Induction hypothesis

- The induction hypothesis assumes the claim is true for smaller values
- Use that assumption to build the argument for the next value
- This mirrors recursion in algorithm design

## Strong induction

- Strong induction assumes the claim holds for all values below $n$
- Often easier for existence proofs or claims with multiple predecessors
- It is logically equivalent to ordinary induction

## Sum formula by induction

- Claim: $\sum_{i=1}^n i = n(n+1)/2$
- Base case: $n=1$ gives $1 = 1$
- Induction: assume $\sum_{i=1}^{n-1} i = (n-1)n/2$
- Add $n$ and simplify to get $n(n+1)/2$

## Odd numbers by induction

- Claim: $\sum_{i=1}^n (2i-1) = n^2$
- Base case: $1 = 1^2$
- Assume the first $n-1$ odd numbers sum to $(n-1)^2$
- Add the $n$th odd number $2n-1$ and simplify

## Recurrence proof

- Claim: $T(n) = T(n-1)+1$ with $T(1)=0$ gives $T(n)=n-1$
- Base case: $T(2)=1$
- Assume $T(n-1)=n-2$
- Then $T(n)=n-1$

## Strong induction example

- Claim: any integer $n>1$ is divisible by some prime
- Base case: $2$ is prime
- Induction: if $n$ is composite, factor $n = ab$
- A factor less than $n$ has a prime divisor by hypothesis

---

![Domino Effect](https://upload.wikimedia.org/wikipedia/commons/9/92/Dominoeffect.png){height=540px}

## Compare method

- Direct proof: follow the claim straight to the conclusion
- Contradiction: assume the opposite and expose impossibility
- Induction: step from one case to the next
- Choose the method that fits the claim and the available structure

## Faith and structure

- Proofs exercise honesty and care in reasoning
- Clear argumentation honors truth and good stewardship
- Mathematical structure supports disciplined thinking

How can proof techniques help you build more reliable algorithms?
