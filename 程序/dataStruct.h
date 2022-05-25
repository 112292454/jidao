#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define ll long long
#define null NULL
#define eof EOF
#define e97 10000007
#define maxint 0x7fffffff
extern int TOTAL_STATION;
extern int STRATEGY;
extern int DISTANCE;
typedef struct node node;

typedef struct node {
    //链表下一个节点
    node* next;
    //本节点的值
    int value;
    //该节点请求的方向，1为顺时针，-1为逆时针，0为乘客到站请求（即顺逆都可以停） 
    int  direct;
} node;

typedef struct busInfo {
    //当前时间
    int time;
    //公交车当前运行方向，1为顺时针，-1为逆时针，0为停站，仅当0可以转向 
    int direction;
    //公交车当前位置
    int position;
    //目标站点，仅当到达此点之后direct变为0，随策略不同，设置不同的标识含义 
    int target;
} busInfo;

int main();
bool input(node*);
void output(node*,busInfo*);
void run(node*,busInfo*);
void fcfs(node*, busInfo*);
void sstf(node*, busInfo*);
void scan(node*, busInfo*);
node* newNode(int);
node* get(node*, int);
void add(node*, int, node*);
void set(node*, int, int);
void removeNode(node*, int);
void freeNode(node*);
