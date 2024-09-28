struct Node{
    int left; // 左邊邊界
    int right; //右邊邊界
    int value; //儲存的值
    int z; //區間修改用，如果沒有區間修改就不需要
}node[4 * N ];

#define Lson(x) (x << 1) //左子樹
#define Rson(x) ((x << 1) +1) //右子樹

void question(){
    for(int i = 1; i <= 10; i++) num[i] = i * 123 % 5; 
    // num 為題目產生的一段數列
    // hash 函數，讓 num 的 i 被隨機打亂
}

void build(int left , int right , int x = 1 ){ 
    // left 為題目最大左邊界，right 為題目最大右邊界，圖片最上面的 root 為第一個節點
    node[x].left = left ; //給 x 節點左右邊界
    node[x].right = right ;
    if(left == right){ //如果左右邊界節點相同，表示這裡是葉節點
        node[x].value = num[left] ;  //把 num 值給 node[x]
        //這裡的 num 值表示，我們要在 value 要放的值
        return ; //向前返回
    }
    int mid = (left + right ) / 2 ; //切半，產生二元樹

    //debug
    //cout << mid << '\n' ;
    //cout << x << ' ' << node[x].left << ' ' << node[x].right << ' ' << '\n' ;

    build(left , mid , Lson(x)) ; //將區間改為 [left, mid] 然後帶給左子樹
    build(mid + 1 , right , Rson(x)) ; //將區間改為 [mid+1, right] 然後帶給右子樹
    node[x].value = min(node[Lson(x)].value  , node[Rson(x)].value ) ;
    //查詢左右子樹哪個數值最小，並讓左右子樹最小值表示此區間最小數值。
}

void modify(int position , int value , int x = 1 ){ //修改數字
    if(node[x].left == position && node[x].right == position ){ //找到葉節點
       node[x].value = value ; //修改
       return ; //傳回
    }
    int mid = (node[x].left + node[x].right ) / 2 ; //切半，向下修改
    if(position <= mid ) //如果要修改的點在左邊，就往左下角追蹤
        modify(position , value , Lson(x) );
    if(mid < position ) //如果要修改的點在右邊，就往右下角追蹤
        modify(position , value , Rson(x)) ;
    node[x].value = min(node[Lson(x)].value , node[Rson(x)].value );
    //比較左右子樹哪個值比較小，較小值為此節點的 value

}

void push_down(int x, int add){ //將懶人標記往下推，讓下一層子樹進行區間修改
    int lson = Lson(x), rson = Rson(x);
    node[lson].z += add;  //給予懶人標記，表示子樹如果要給子樹的子樹區間修改時，
    node[rson].z += add;  //數值要是多少，左右子樹都需要做

    node[lson].v += add; //更新左右子樹的值
    node[rson].v += add;
}

void update(int a, int b, int cmd, int x = 1){ 
//a, b 為區間修改的 left and right, cmd 為要增加的數值 
    if(a <= node[x].l && b >= node[x].r){ 
        //如果節點的 left and right，跟 a, b 區間是相等，或更小就，只要在這邊修改 cmd，
        //就可以讓 node[x].v 的值直接變為區間修改後的數值，
        //之後如果要讓這查詢向子樹進行區間修改，就用 push_down，
        //我們這邊的懶人標記就會告訴左右子樹要修改的值為多少

        node[x].v += cmd; //區間修改後的 v
        node[x].z = cmd; //區間修改是要增加多少數值
        return; 
    }
    push_down(x);//先將之前的區間查詢修改值，往下給子樹以避免上次的查詢值被忽略
    //假如當前的 node[x].z 原本是 3，如果沒有 push_down(x)，那下面的子樹都沒有被 +3，
    //導致答案不正確。

    int mid = (node[x].l+node[x].r) / 2;  //切半，向下修改
    if(a <= mid) update(a, b, cmd, Lson(x)); //如果要修改的點在左邊，就往左下角追蹤
    if(b > mid) update(a, b, cmd, Rson(x)); //如果要修改的點在右邊，就往右下角追蹤
    node[x].v = node[Lson(x)].v + node[Rson(x)].v;
    //比較左右子樹哪個值比較小，較小值為此節點的 value
}
#define INF 0x3f3f3f

int query(int left , int right , int x = 1 ){
    if(node[x].left >= left && node[x].right <= right) 
        return node[x].Min_Value ;
    //如果我們要查詢的區間比當前節點的區間大，那我們不需再向下查詢直接輸出此答案就好。
    // 例如我們要查詢 [2, 8]，我們只需要查詢 [3, 4]，不須查詢 [3, 3]、[4, 4]，
    // [3, 4] 已經做到最小值查詢

    push_down(x);//有區間修改時才需要寫    
    int mid = (node[x].left + node[x].right ) / 2 ; //切半，向下修改
    int ans = INF ; //一開始先假設答案為最大值

    if( left <= mid ) //如果切半後，我們要查詢的區間有在左子樹就向下查詢
        ans = min(ans , query(left , right , Lson(x))) ; //更新答案，比較誰比較小
    if(mid < right ) //如果切半後，我們要查詢的區間有在右子樹就向下查詢
        ans = min(ans , query(left , right , Rson(x))) ; //更新答案，比較誰比較小
    return ans ; //回傳答案
}