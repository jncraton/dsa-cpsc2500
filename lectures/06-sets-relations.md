---
reading: '[Sets and Relations](https://opendsa-server.cs.vt.edu/OpenDSA/Books/CS3/html/SetDef.html)'
teaching_goal: Students will understand set notation and the structure of relations for equivalence classes and partial orders
learning_objectives:
  - Identify set notation, cardinality, and basic set operations
  - Determine relation properties and recognize equivalence relations
  - Distinguish partial orders, total orders, and comparability
---

# Sets and Relations

---

## Set Definition

- A set is a collection of distinguishable elements
- No duplicates
- Order does not matter

---

## Membership

- $x \in S$ means $x$ belongs to set $S$
- $x \notin S$ means $x$ is outside $S$
- Each element is either in or out

---

## Common Notation

- $\{1, 4\}$ a set with 1 and 4
- $\emptyset$ or $\{\}$ the empty set
- $|S|$ cardinality, number of members

---

## Example Sets

- $P = \{2, 3, 5\}$
- $Q = \{5, 10\}$
- $P$ and $\{5, 3, 2\}$ are the same set

---

## Set Operations

- $P \cup Q$ union of all elements
- $P \cap Q$ intersection of common elements
- $P - Q$ elements in $P$ not in $Q$

---

## Products and Powersets

- $Q \times P$ yields ordered pairs
- $2^S$ is the powerset of $S$
- Powerset of $\{a,b,c\}$ has 8 subsets

---

![Sets of numbers](https://upload.wikimedia.org/wikipedia/commons/thumb/4/4c/Sets_of_numbers-ar.svg/960px-Sets_of_numbers-ar.svg.png){height=540px}

---

## Relations

- A relation $R$ over $S$ is a set of ordered pairs
- Each pair is $\langle x, y \rangle$
- If $\langle x, y \rangle \in R$, write $xRy$

---

## Relation Example

- For $S = \{a, b, c\}$
- Relation can be $\{\langle a, c\rangle, \langle b, c\rangle, \langle c, b\rangle\}$
- Another relation can be $\{\langle a, a\rangle, \langle a, c\rangle, \langle b, b\rangle, \langle b, c\rangle, \langle c, c\rangle\}$

---

## Infix Relations

- $<$ on natural numbers is a relation
- Includes $\langle 1, 3 \rangle$ and $\langle 2, 23 \rangle$
- Excludes $\langle 3, 2 \rangle$ and $\langle 2, 2 \rangle$

---

## Reflexive and Irreflexive

- $R$ is reflexive if $aRa$ for every $a \in S$
- $R$ is irreflexive if no $aRa$ holds
- Example: $<$ is irreflexive on naturals

---

## Symmetric and Antisymmetric

- Symmetric: if $aRb$ then $bRa$
- Antisymmetric: if $aRb$ and $bRa$ then $a = b$
- $=$ is both symmetric and antisymmetric

---

## Transitive

- Transitive: if $aRb$ and $bRc$ then $aRc$
- $<$ and $=$ are transitive
- Transitivity links chain relationships

---

How does understanding relation properties improve algorithm design?

---

## Equivalence Relations

- Reflexive, symmetric, and transitive
- Partition a set into equivalence classes
- Equivalent elements behave as a group

---

## Equivalence Example

- $=$ on integers is an equivalence relation
- $a = b$ implies $b = a$
- $a = b$ and $b = c$ imply $a = c$

---

## Modular Equivalence

- $x \equiv y \pmod m$ when $x \bmod m = y \bmod m$
- $m = 4$ groups integers by remainder
- This defines $m$ equivalence classes

---

## Exercise

Classify each relation on $\{1,2,3\}$ as reflexive, symmetric, antisymmetric, or transitive.

- $R_1 = \{\langle 1,1 \rangle, \langle 2,2 \rangle, \langle 3,3 \rangle\}$
- $R_2 = \{\langle 1,2 \rangle, \langle 2,1 \rangle\}$
- $R_3 = \{\langle 1,2 \rangle, \langle 2,3 \rangle, \langle 1,3 \rangle\}$

---

## Partial Orders

- Antisymmetric and transitive
- If also reflexive, non-strict partial order
- If irreflexive, strict partial order

---

## Posets

- A partially ordered set is a poset
- Comparability means $xRy$ or $yRx$
- Not all pairs need be comparable

---

## Total Orders

- A total order compares every distinct pair
- $<$ and $\leq$ on integers are total orders
- Subset order on power sets is not total

---

## Order Example

- $\{1,2\} \subseteq \{1,2,3\}$
- $\{1,2\}$ and $\{1,3\}$ are not comparable
- Subset order is a partial order

---

## Exercise

For each relation, decide whether it is a partial order, total order, or neither.

- $\leq$ on integers
- $\subseteq$ on subsets of $\{1,2,3\}$
- $\text{is sibling of}$ among people

---

How can the structure of relations shape how we organize communities and resources?

---

## Bags and Sequences

- A bag may contain duplicates
- A sequence has order and duplicates
- A set has neither order nor duplicates

---

How does ordered structure in data reflect the care we bring to creation?
