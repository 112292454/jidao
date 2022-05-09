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
	//������һ���ڵ�
	node* next;
	//���ڵ��ֵ
	int value;
}node;
 
typedef struct query{
	//���������xΪxվ����˳ʱ������-yΪyվ������ʱ������
	node*  stationRequest;
	//���һ���ڣ��޷�ͣ��ȥ������ϳ�����
	node*  noStopRequest;
	//���ڵĵ�վ����
	node*  busRequest;
	//���߶�Ӧ�Ľ����ڵ㣬���ڲ����½ڵ�ʱʹ��
	node *lasts,*lastn,*lastb;
}query;

typedef struct busInfo{
	//��ǰʱ��
	int time;
	//��������ǰ���з���
	int direction;
	//��������ǰλ��
	int position;
	//�������Ƿ����ת��
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
