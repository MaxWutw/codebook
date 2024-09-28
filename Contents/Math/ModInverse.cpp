// 求 a 在模 m 下的模反元素，m 必須是質數
ll modInverse(ll a, ll m) {
    ll res = 1, exp = m - 2;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        exp /= 2;
    }
    return res;
}