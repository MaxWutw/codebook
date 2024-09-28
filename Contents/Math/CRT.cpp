ll extendedGCD(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll chineseRemainder(vector<ll> &n, vector<ll> &a){
    ll prod = 1;
    for(ll num : n) prod *= num; // Calculate the product of all moduli

    ll result = 0;
    for(int i = 0; i < n.size(); i++){
        ll p = prod / n[i]; // Product divided by current modulus
        ll x, y;
        extendedGCD(p, n[i], x, y); // Solve p * x ≡ 1 (mod n[i])
        result = (result + a[i] * x * p) % prod; // Add current term to result
    }
    return (result + prod) % prod; // Return the result modulo the product
}