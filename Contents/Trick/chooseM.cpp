// n >=m choose m number from 1 ~ n
void combination(int n, int m){
    if (n<m) return;
    
    int a[50] = {0};
    int k = 0;
    
    for(int i=1;i<=m;i++) a[i] = i;
    while(1){
        for(int i=1;i<=m;i++)
            cout << a[i] << " ";
        cout << endl;
        
        k = m;
        while((k>0) && (n-a[k] == m-k)) k --;
        if(k == 0) break;
        a[k] ++;
        for(int i=)
    }

        
        
}