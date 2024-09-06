bool isLeap(int n){
    if(n % 100 == 0)
        if(n % 400 == 0) return true;
        else return false;
    if(n % 4 == 0) return true;
    else return false;
}