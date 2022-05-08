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
extern int TOTAL_STATION;
extern int STRATEGY;
extern int DISTANCE;

typedef struct array{
	int *arr;
	//size:已有元素数量，也是当前空闲的第一个下标 
	int size,maxCount;
}array;
typedef struct query{
	array *stationRequest,*noStopRequest,*busRequest;
}query;
typedef struct busInfo{
	int direction;
	int position;
	bool isLocked;
}busInfo;

array* initialArr(int size);
query* initialQuery(int size);
void grow(array* a);
int get(array* a,int index);
void add(array* a,int num);
void set(array *a,int index,int num);
void removeByIndex(array *a,int index);
void freeArray(array* a);
void freeQuery(query* q);
