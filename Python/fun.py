# Get the nth number of fibonacci sequence
def nth_fib_num(n):
    if n == 0 or n == 1:
        return n

    return nth_fib_num(n - 1) + nth_fib_num(n - 2)

# Appends the given element to the front of the given list
def append_front(lst, elem):
    lst.insert(0, elem)
    return lst

# Gets the list of fuzzbuzz values from 0 to n
def fizzbuzz_collector(n, accum):
    if n < 0:
        return accum

    word = ''
    if n % 3 == 0:
        word += 'fizz'
    if n % 5 == 0:
        word += 'buzz'
    return fizzbuzz_collector(n - 1, append_front(accum, n if not word else word))

def fizzbuzz(n):
    return fizzbuzz_collector(n, []);

if __name__ == '__main__':
    print(nth_fib_num(0))
    print(nth_fib_num(1))
    print(nth_fib_num(7))
    print()
    print(fizzbuzz(10))
