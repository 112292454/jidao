#include "dataStruct.h"
int main(){
	query* q=newQuery();
	add(q->noStopRequest,0,1);
	add(q->noStopRequest,99,555);
	printf("%d",get(q->noStopRequest,998)->value);
	
} 

node* newNode(int value){
	node *a;
	a=(node*)malloc(sizeof(node));
	a->next=null; 
	a->value=value;
	return a;
}
query* newQuery() {
	query* q;
	q=(query*)malloc(sizeof(int)*32);
	q->busRequest=newNode(0);
	q->noStopRequest=newNode(0);
	q->stationRequest=newNode(0);
	return q; 
}

//下标从0开始 ,get(0)为首个元素，get(maxint)为最后一个元素 
node* get(node* a,int index){
	for(int i=0;i<=index;i++){
		if(a->next==null){
			break;
		}
		if(i>=10000){
			printf("链表长度过万，可能存在环，请检查");
			return a;
		}
		a=a->next;
	}
	return a;
}
//在index后插入 num 
void add(node* a,int index,int num){
	a=get(a,index-1);
	node* temp=newNode(num);
	temp->next=a->next;
	a->next=temp;
}
void set(node *a,int index,int value){
	node* temp=get(a,index);
	temp->value=value;
}

void removeNode(node *a,int index){
	//todo
	
}
void freeNode(node* a){
	node* temp;
	while(a->next!=null){
		temp=a->next;
		free(a);
		a=temp;
	}
	free(a);
}
void freeQuery(query* q){
	freeNode(q->stationRequest);
	freeNode(q->noStopRequest);
	freeNode(q->busRequest);
	free(q);
}
