ll solveLinearCongruence(ll a, ll b, ll m){
    ll x, y;
    ll g = extendedGCD(a, m, x, y); // Solve a * x + m * y = gcd(a, m)
    if (b % g != 0) return -1; // No solution if gcd(a, m) does not divide b

    x = (x * (b / g)) % m;
    if (x < 0) x += m; // Ensure the result is positive
    return x;
}