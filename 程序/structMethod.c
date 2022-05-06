#include "dataStruct.h"
int main(){
	query* q=initialQuery(50);
	add(q->noStopRequest,5);
	add(q->noStopRequest,2);
	add(q->noStopRequest,3);
	removeByIndex(q->noStopRequest,1);
	printf("%d ",get(q->noStopRequest,0));
	printf("%d ",get(q->noStopRequest,1));
	printf("%d ",get(q->noStopRequest,2));
	printf("%d ",q->noStopRequest->size);
	int size=q->stationRequest->size;
	printf("%d \n",size);
	for(int i=0;i<2;i++){
		printf("%d 1   ",get(q->noStopRequest,i));
	}
} 

array* initialArr(int size){
	array *a;
	size=max(32,size); 
	//a=(array*)malloc(sizeof(int)*size*2);
	a->arr=(int*)malloc(sizeof(int)*size);
	memset(a->arr,0,size);
	a->size=0;
	a->maxCount=size;
	return a;
}
query* initialQuery(int size) {
	query* q;
	size=max(32,size); 
	//q=(query*)malloc(sizeof(int)*size*8);
	q->busRequest=initialArr(size);
	q->noStopRequest=initialArr(size);
	q->stationRequest=initialArr(size);
	return q; 
}

//On
void grow(array* a){
	int* temp=(int*)malloc(sizeof(int)*(a->maxCount*2));
	memcpy(temp,a->arr,sizeof(int)*(a->maxCount));
	free(a->arr);
	a->arr=temp;
}
int get(array* a,int index){
	return a->arr[index];
}
void add(array* a,int num){
	if(a->size >= a->maxCount){
		grow(a);
	}
	a->arr[a->size]=num;
	a->size++;
}
void set(array *a,int index,int num){
	a->arr[index]=num;
}
void removeLast(array *a){
	a->arr[a->size]=0;
	a->size--;
}
//On
void removeByIndex(array *a,int index){
	if(index>=a->size-1){
		removeLast(a);
		return;
	}
	memmove(a->arr+index,a->arr+index+1,a->size-index-1);
	a->size--;
	a->arr[a->size]=0;
	
}
void freeArray(array* a){
	free(a->arr);
	free(a);
}
void freeQuery(query* q){
	freeArray(q->stationRequest);
	freeArray(q->noStopRequest);
	freeArray(q->busRequest);
	free(q);
}
