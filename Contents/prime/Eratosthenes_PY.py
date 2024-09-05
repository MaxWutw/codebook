is_prime = n * [1] 
is_prime[0] = is_prime[1] = 0
        
for i in range(2, n):
    if is_prime[i]:
        for j in range(2, n):
            if i * j >= n: 
                break
            is_prime[i * j] = 0