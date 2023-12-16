# Set
**You may use any function or library discussed in class or in the chapters we covered from your textbook. Do not use any other libraries or functions.**

Design a C++ class that stores a mathematical set of integers called ***MySet*** **(do not use a different name)**. The class should be stored in "myset.h" and include the following functions:

- A default constructor that initializes a set to the empty set.
- Overload the "^" operator to implement the set membership. Returns true if an element is in the set.
- Overload the "+" operator to add an element to the set. Return the original set with the new element added.
- Overload the "-" operator to remove an element from the set. Return the original set with the new element removed.
- Overload the "+" operator to implement the union of two sets. Returns a new set that contains all the elements of both sets.
- Overload the "*" operator to implement the intersection of two sets. Returns a new set that contains all the elements that are in both sets.
- Overload the "-" operator to implement the set difference. Returns a new set that contains all the elements that are in the first set but not in the second.
- Overload the "<=" operator to implement the subset. Returns true if all the elements of the first set are in the second.
- Overload the ">=" operator to implement the superset. Returns true if all the elements of the second set are in the first.
- Overload the "==" operator to implement the set equality. Returns true if both sets contain the same elements (in any order).
- A function called ***toString*** that returns a set string in the format "{1, 2, 3, 4}"). The set elements must be sorted.
- A function to return the number of elements in the set (***size***).
- A function to clear the set by removing all the elements (***clear***).

Write a main program to test your code or use the unit tests provided.

`make run_tests`
