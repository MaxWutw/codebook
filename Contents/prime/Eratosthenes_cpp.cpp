bitset<MAXN> prime_bool;
vector<ll> prime;
void find_prime(){
    prime_bool.set();
    for(int i=2;i<MAXN;i++){
        if(prime_bool[i]){
            prime.push_back(i);
        }
        for(auto j:prime){
            if(j*i>=MAXN)
                break;
            prime_bool[j*i]=0;
            if(i%j==0)
                break;
        }
    }
}