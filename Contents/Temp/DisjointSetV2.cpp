int Find(int a){
    return (anc[a] == a ? a : anc[a] = Find(anc[a]));
}
bool merge(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a, b);
    anc[b] = a;
    sz[a] += sz[b];
    return true;
}