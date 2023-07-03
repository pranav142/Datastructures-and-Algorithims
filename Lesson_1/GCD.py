import time

""" 
Two Numbers a, b. Want to find largest denomitor d such that a/d and b/d has no remainder
"""
def GCD_naive(a: int, b: int) -> int:
    """
    Ineffecient implementation O(n) time
    """
    best = 0
    for d in range(1, a+b+1):
        if a % d == 0 and b % d == 0:
            best = d

    return best

def GCD_effecient(a: int, b: int) -> int:
    """
    Effecient implementation O(log(n)) time
    """
    if  b == 0:
        return a
    
    return GCD_effecient(b, a % b)

if __name__ == "__main__":

    a = 12039000
    b = 1239870
    
    naive_start = time.time()
    naive_GCD = GCD_naive(a, b)
    naive_end = time.time()

    effecient_start=time.time()
    effecient_GCD = GCD_effecient(a, b)
    effecient_end=time.time()
    
    print(f"Effecient solution calculated: {effecient_GCD} in {effecient_end - effecient_start} seconds, Naive solution calculated: {naive_GCD} in {naive_end - naive_start} seconds")