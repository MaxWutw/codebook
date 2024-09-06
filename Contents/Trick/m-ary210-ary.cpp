string num = "0123456789ABCDE";

int mToTen(string n, int m){
    int multi = 1;
    int result = 0;
    
    for(int i = n.size() - 1;i >= 0;i--){
        result += num.find(n[i]) * multi;
        multi *= m;
    }
    return result;
}