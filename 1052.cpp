//假装在链表排序。。

//#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define maxn 100005
struct Node
{
    int address;
    int key;
    int next;
    int flag;
};
Node nodes[maxn];
int N,startAddress;
bool smaller(Node a, Node b)
{
    return a.key < b.key;
}
int main() {
    memset(nodes,0,sizeof(Node)*maxn);
    int tempAddress;
    scanf("%d",&N);
    scanf("%d",&startAddress);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d",&tempAddress);
        nodes[tempAddress].address = tempAddress;
        scanf("%d",&nodes[tempAddress].key);
        scanf("%d",&nodes[tempAddress].next);
    }
    //delete node not in the list
    int count = 0,curAddress = startAddress;
    if (nodes[startAddress].next == 0)
    {
        printf("0 -1\n");
        return 0;
    }
    while(1)
    {
        nodes[curAddress].flag = 1;
        count++;
        curAddress = nodes[curAddress].next;
        if (curAddress == -1)
            break;
    }
    for (int i = 1; i < maxn; i++)
    {
        if (nodes[i].flag==0)
        {
            nodes[i].address = 0;
            nodes[i].key = 0x7fffffff;
            nodes[i].next = -1;
        }
    }
    sort(nodes+1,nodes+maxn,smaller);
    printf("%d %05d\n", count, nodes[1].address);
    for (int i = 1; i <= count; i++)
    {
        if (i < count)
        {
            printf("%05d %d %05d\n", nodes[i].address, nodes[i].key, nodes[i+1].address);
        }
        else
        {
            printf("%05d %d %d\n", nodes[i].address, nodes[i].key, -1);
        }
    }
}

//不止一个链表，或者一个链表都没有，两种特殊情况要考虑
