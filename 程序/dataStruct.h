#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long 
#define null NULL
#define eof EOF 
#define e97 10000007
#define maxint 0x7fffffff; 
extern int TOTAL_STATION;
extern int STRATEGY;
extern int DISTANCE;
typedef struct node node;

typedef struct node{
	//链表下一个节点
	node* next;
	//本节点的值
	int value;
}node;
 
typedef struct query{
	//所存的数字x为x站点有顺时针请求；-y为y站点有逆时针请求
	node*  stationRequest;
	//最近一秒内，无法停下去满足的上车请求
	node*  noStopRequest;
	//车内的到站请求
	node*  busRequest;
	//三者对应的结束节点，便于插入新节点时使用
	node *lasts,*lastn,*lastb;
}query;

typedef struct busInfo{
	//当前时间
	int time;
	//公交车当前运行方向
	int direction;
	//公交车当前位置
	int position;
	//公交车是否可以转向
	bool isLocked;
}busInfo;

node* newNode(int value);
query* newQuery();
node* get(node* a,int index);
void add(node* a,int index,int num);
void set(node *a,int index,int num);
void removeNode(node *a,int index);
void freeNode(node* a);
void freeQuery(query* q);
