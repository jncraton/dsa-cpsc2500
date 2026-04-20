---
reading: '[OpenDSA Logarithms](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/Logarithms.html)'
teaching_goal: Students will understand logarithm definitions, properties, and why logs shape common algorithms
learning_objectives:
  - Explain logarithms as inverses of exponentiation
---

# Logarithms

## Logarithm definition

- $\log_b y = x$ means base $b$ raised to $x$ equals $y$
- inverse of exponentiation
- if $\log_b y = x$ then $b^x = y$

---

## Exponent connection
- log answers the question what power
- example: $\log_2 8 = 3$ because $2^3 = 8$
- example: $\log_{10} 100 = 2$

## Base independence

- $\log_a n = \frac{\log_b n}{\log_b a}$
- Change of base is a constant factor
- Asymptotic analysis ignores constants

## Bits and codes

- Minimum bits for $n$ distinct values is $\lceil \log_2 n \rceil$
- 1000 codes require $\lceil \log_2 1000 \rceil = 10$ bits
- 10 bits give 1024 values

## Binary search

- Binary search splits an array in half repeatedly
- Number of splits is $\lceil \log_2 n \rceil$
- This is why binary search is logarithmic time

---

How does the log scale make large problems manageable?

## Logarithm properties

- $\log (nm) = \log n + \log m$
- $\log (n/m) = \log n - \log m$
- $\log (n^r) = r \log n$
- $\log_a n = \frac{\log_b n}{\log_b a}$

## Natural log and $e$
- $e \approx 2.71828$ is the base of natural logs
- $\ln n$ is $\log_e n$
- $e$ appears in Stirling's approximation for $n!$

## Growth intuition

- Logs grow much slower than polynomials
- $n^c$ outpaces $\log n$ for any constant $c$
- Algorithms with log cost scale well

---

Which algorithmic patterns naturally leads to log cost?

---

Why are log bases irrelevant in asymptotic analysis?

---

How does repeated halving connect to everyday decisions?
