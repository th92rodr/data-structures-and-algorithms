
## Hash Table (Map) Data Structure

Is a data structure which implements an associative array abstract data type, a structure that can map keys to values. A hash table uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

Ideally, the hash function will assign each key to a unique bucket, but most hash table designs employ an imperfect hash function, which might cause hash collisions where the hash function generates the same index for more than one key. Such collisions were treated using chaining, meaning that in each slot there is a linked list with all the values correspondents to that key.

Hash Table:

![][hash]

Hash Table with chaining:

![][hash-collision]


### Algorithms:

- Find all symmetric pairs in an array of pairs 
- Find whether an array is subset of another array


### References:

https://www.geeksforgeeks.org/hashing-data-structure/

https://www.youtube.com/watch?v=nvzVHwrrub0&t=791s


[hash]:https://upload.wikimedia.org/wikipedia/commons/7/7d/Hash_table_3_1_1_0_1_0_0_SP.svg
[hash-collision]:https://upload.wikimedia.org/wikipedia/commons/d/d0/Hash_table_5_0_1_1_1_1_1_LL.svg
