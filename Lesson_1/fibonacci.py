import time

def fibrecurs(n):
    """
    naive solution to find nth fibinocci number o(2^n)
    """
    if n <= 1:
        return n
    else:
        return fibrecurs(n-1) + fibrecurs(n-2)

def effecient_solution(n):
    """
    effecient solution to find nth fibinocci number o(n^2)
    """
    array = []
    array.append(0)
    array.append(1)

    for i in range(2,n + 1):
        array.append(array[i-1] + array[i-2])
    
    return array[n]

if __name__ == "__main__":

    naive_start = time.time()
    print(fibrecurs(10))
    naive_end = time.time()

    effecient_start = time.time()
    print(effecient_solution(331))
    effecient_end = time.time()

    # Naive solution took 0.112 seconds, Effecient solution took 0.000 seconds
    print(f"Naive solution took {naive_end - naive_start :.03f} seconds, Effecient solution took {effecient_end-effecient_start :.03f} seconds")
