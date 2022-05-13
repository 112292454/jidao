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
#define maxint 0x7fffffff;
extern int TOTAL_STATION;
extern int STRATEGY;
extern int DISTANCE;
typedef struct node node;

//策略3=策略2+
//“可以接不同方向的途中”+
//“选定一个方向，每次按这个方向去找，只有该方向最短的距离都太长才会掉头” 
//“而策略二每次到达之后直接看距离最近的” 
typedef struct node {
    //链表下一个节点
    node* next;
    //本节点的值
    int value;
    //该节点请求的方向，1为顺时针，-1为逆时针，0为乘客到站请求（即顺逆都可以停） 
    int  direct;
} node;

typedef struct query {
    //所存的数字x
    node* stationRequest;
    //最近一秒内，无法停下去满足的上车请求
    node* noStopRequest;
    //三者对应的结束节点，便于插入新节点时使用
    node *lasts, *lastn;
} query;

typedef struct busInfo {
    //当前时间
    int time;
    //公交车当前运行方向，1为顺时针，-1为逆时针，0为停站，仅当0可以转向 
    int direction;
    //公交车当前位置
    int position;
    //目标站点，仅当到达此点之后direct变为-1
    int target;
} busInfo;

node* newNode(int value);
query* newQuery();
node* get(node* a, int index);
void add(node* a, int index, int num);
void set(node* a, int index, int num);
void removeNode(node* a, int index);
void freeNode(node* a);
void freeQuery(query* q);
