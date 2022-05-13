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

//����3=����2+
//�����ԽӲ�ͬ�����;�С�+
//��ѡ��һ������ÿ�ΰ��������ȥ�ң�ֻ�и÷�����̵ľ��붼̫���Ż��ͷ�� 
//�������Զ�ÿ�ε���֮��ֱ�ӿ���������ġ� 
typedef struct node {
    //������һ���ڵ�
    node* next;
    //���ڵ��ֵ
    int value;
    //�ýڵ�����ķ���1Ϊ˳ʱ�룬-1Ϊ��ʱ�룬0Ϊ�˿͵�վ���󣨼�˳�涼����ͣ�� 
    int  direct;
} node;

typedef struct query {
    //���������x
    node* stationRequest;
    //���һ���ڣ��޷�ͣ��ȥ������ϳ�����
    node* noStopRequest;
    //���߶�Ӧ�Ľ����ڵ㣬���ڲ����½ڵ�ʱʹ��
    node *lasts, *lastn;
} query;

typedef struct busInfo {
    //��ǰʱ��
    int time;
    //��������ǰ���з���1Ϊ˳ʱ�룬-1Ϊ��ʱ�룬0Ϊͣվ������0����ת�� 
    int direction;
    //��������ǰλ��
    int position;
    //Ŀ��վ�㣬��������˵�֮��direct��Ϊ-1
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
