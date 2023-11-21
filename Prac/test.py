import sys

def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

sys.set_int_max_str_digits()

print(factorial(2000) / (factorial(1000) * factorial(1000)))