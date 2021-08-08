# generator zwracający kolejne wyrazy ciągu Fibonacciego 
def fibonacci(n):
    first, second = 0, 1
    for _ in range(n):
        yield first 
        first, second = second, first + second

# wykorzystanie generatora - zapis stu pierwszych 
# elementów ciągu Fibonacciego do pliku tekstowego
with open('data.txt', 'w') as file:
    for elem in fibonacci(100):
        file.write(str(elem) + '\n')
