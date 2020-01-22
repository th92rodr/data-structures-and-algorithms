
# Algorithms


## Tower of Hanoi Problem

[Solution \o/](https://github.com/Thiago92Rodrigues/algorithms/blob/master/tower_of_hanoi.py)

The Tower of Hanoi (also called the Tower of Brahma or Lucas' Tower and sometimes pluralized as Towers) is a mathematical game or puzzle. It consists of three rods and a number of disks of different sizes, which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape.

The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

- Only one disk can be moved at a time.
- Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
- No larger disk may be placed on top of a smaller disk.

With `3 disks`, the puzzle can be solved in `7 moves`. The minimal number of moves required to solve a Tower of Hanoi puzzle is `2^n − 1`, where `n` is the number of disks.

![Alt Text](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/Iterative_algorithm_solving_a_6_disks_Tower_of_Hanoi.gif/220px-Iterative_algorithm_solving_a_6_disks_Tower_of_Hanoi.gif)

### References

- [Wikipedia](https://en.wikipedia.org/wiki/Tower_of_Hanoi)
- [HackerEarth](https://www.hackerearth.com/blog/developers/tower-hanoi-recursion-game-algorithm-explained)

*****

## Recursive Staircase

[Solution \o/](https://github.com/Thiago92Rodrigues/algorithms/blob/master/recursive_staircase.py)

There are `n` stairs, a person standing at the bottom wants to reach the top. The person can climb either `1` or `2` stairs at a time. Count the number of ways, the person can reach the top.

In a second version of this problem is passed a set with all the possible stairs climb the person can climb at a time, for example: `[1, 3, 5]` the person can climb `1` or `3` or `5` stairs at a time.

### References

- [GeeksForGeeks](https://www.geeksforgeeks.org/count-ways-reach-nth-stair/)
- [Youtube]()

*****

## First recurring character

Find the first recurring character in a given string

*****

## Conflicting Appointments

[Solution \o/](https://github.com/Thiago92Rodrigues/algorithms/blob/master/find_conflicting_appointments.py)

Given `n` appointments, find all the conflicting ones.

Examples:
```
Input - Appointments: 
[ 10 to 11 ]
[ 8 to 9 ]
[ 12 to 13 ]
[ 12.2 to 12.5 ]
[ 8.5 to 9.5 ]
[ 2 to 4 ]
[ 10.5 to 12.5 ]
[ 3.5 to 8.5 ]

Output - Conflicting appointments: 
[ 12.2 to 12.5 ] with [ 12 to 13 ]
[ 8.5 to 9.5 ] with [ 8 to 9 ]
[ 10.5 to 12.5 ] with [ 10 to 11 ]
[ 10.5 to 12.5 ] with [ 12 to 13 ]
[ 3.5 to 8.5 ] with [ 8 to 9 ]
[ 3.5 to 8.5 ] with [ 2 to 4 ]
```

### References

- [GeeksForGeeks](https://www.geeksforgeeks.org/given-n-appointments-find-conflicting-appointments/)

*****

## Dictionary implementation

*****
