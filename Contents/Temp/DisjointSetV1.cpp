int n=1000; //假設共有n個點
int dsu[1000]; //建一個紀錄集合編號的陣列，若dsu[n]==n，代表為根

///初始化集合
void initt(){
    for(int i=0;i<=n;i++){
        //初始每個集合只有自己
        dsu[i]=i;
    }
}
///查詢
//傳入要找尋的目標
int findd(int x){
    if(x!=dsu[x]){
        //往上尋找祖先，再遞迴更新路上遇到的節點
        dsu[x]=Find(dsu[x]);
    }
    return dsu[x];
}

///合併
void unionn(int x,int y){
    int a=findd(x);
    int b=findd(y);
    //若集合編號不相同，則進行合併，
    if(a!=b){
        dsu[a]=b;
    }
}