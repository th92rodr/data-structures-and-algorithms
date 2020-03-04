'''
Find the first recurring character in a given string

O(n)
'''

def first_recurring_character(string):
    hash = set()
    for ch in string:
        if ch in hash:
            return ch
        hash.add(ch)
    return None


print('string:\t first recurring character:')
print('ACBAB\t', first_recurring_character('ACBAB'))
print('ABC\t', first_recurring_character('ABC'))
print('ABCBA\t', first_recurring_character('ABCBA'))
print('DBCABA\t', first_recurring_character('DBCABA'))

