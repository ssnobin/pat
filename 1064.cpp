// 完全二叉树。。。
#include <cstdio>
#include <cstdlib>


const int maxx = 1005;
int node[maxx];
int tree[maxx];
int pos,n;

int cmp(const void *a,const void *b){
    int *pa = (int *)a;
    int *pb = (int *)b;
    return *pa-*pb;
}

void build(int root){
    if(root>n)return;
    int lson = root<<1,rson = (root<<1)+1;
    build(lson);
    tree[root] = node[pos++];
    build(rson);
}

void print(int *a,int n){
    int i;
    for(i=0;i<n;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&node[i]);
    }
    
    qsort(node,n,sizeof(int),cmp);
    
    //	print(node,n);
    
    pos = 0;
    build(1);
    
    printf("%d",tree[1]);
    for(i=2;i<=n;++i){
        printf(" %d",tree[i]);
    }
    printf("\n");
    return 0;
}