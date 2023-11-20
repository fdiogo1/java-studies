#include <cs50.h>
#include <stdio.h>

/*
    Week 3: Algorithms

    Analysis


    [BIG-O-notation] O() - worst cases

    * The Big-O notation is to study the performance of an algorithm

        -> A developer uses the Big-O to the upper bound (limite superior), the worst cases
        -> It's a good way to measure the WORST cases -> upper bound
        -> Commons: (lowest to fastest)
            - O(n^2) -> tends to be slow
            - O(NlogN) - linearitimica
            - O(n) -> linear
            - O(log n) -> logaritmic
            - O(1) -> constant


    [OMEGA-notation] Ω() - best cases

    * The Ω (omega)-notation -> the bests cases, not necessarily -> lower bound
        -> A developer uses the Ω-notation to the lower bound cases (limite inferior), the best cases
        -> Commons: (lowest to fastest)
            - Ω(n^2) -> tends to be slow
            - Ω(NlogN) - linearitimica
            - Ω(n) -> linear
            - Ω(log n) -> logaritmic
            - Ω(1) -> constant


    [THETA-notation] θ() -> coincidences

    * When an algorith has the same UPPER BOUND and LOWER BOUND, we use the θ (theta)
        -> The greek θ (Theta) indicates the coincidence between the lower bound and the upper bound
        -> Commons: (lowest to fastest)
            - θ(n^2) -> tends to be slow
            - θ(NlogN) - linearitimica
            - θ(n) -> linear
            - θ(log n) -> logaritmic
            - θ(1) -> constant

    Examples:
    - linear search - worst case: O(n); best case: Ω(1) -> θ it's not the case
    - binary search -> the array must be sorted; worst case: O(logn); best case: Ω(1) -> θ it's not the case




    RECURSION -> refers to the ability of a function to call itself




*/