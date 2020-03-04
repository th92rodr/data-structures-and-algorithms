
'''
Using only recursion to calculate the result
'''
def num_ways_1(n):
    if n == 0 or n == 1:
        return 1
    else:
        return num_ways_1(n-1) + num_ways_1(n-2)

#print(num_ways_1(4))


'''
Using a hash table to store the values
to avoid calling num_ways with the same value of n multiple times
'''
hash = {}
hash[0] = 1
hash[1] = 1
def num_ways(n):
    if n-1 not in hash:
        hash[n-1] = num_ways(n-1)
    if n-2 not in hash:
        hash[n-2] = num_ways(n-2)

    hash[n] = hash[n-1] + hash[n-2]
    return hash[n]

#print(num_ways(10))


'''
Using a hash table to store the values in a for loop
without using recursion
'''
def num_ways_without_recursion(n):
    res = {}
    res[0] = 1
    res[1] = 1
    for i in range(2, n+1):
        res[i] = res[i-1] + res[i-2]
    return res[n]

#print(num_ways_without_recursion(10))


'''
Passing a set of possible steps
'''
def num_ways_steps_set(n, step_op):
    res = {}
    res[0] = 1
    res[1] = 1
    for i in range(2, n+1):
        res[i] = 0
        for step in step_op:
            if i - step >= 0:
                res[i] += res[i-step]
    return res[n]

print('Staircase height: 4 | Set of possible steps: (1, 3, 5) | Number of ways: ', num_ways_steps_set(4, [1, 3, 5]))
print('Staircase height: 10 | Set of possible steps: (1, 2) | Number of ways: ', num_ways_steps_set(10, [1, 2]))
