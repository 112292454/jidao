#include "dataStruct.h"
extern int TOTAL_STATION;
extern int STRATEGY;
extern int DISTANCE;
bool input(node* n){
	char buff[255];
	int num=0;
	scanf("%s",buff);
	while(!strcmp(buff,"clock")){
		//到下一个clock之前为止的数据全部读入 
		if(strcmp(buff,"end")){
			//特殊地，如果是end则返回false，使程序整个停止 
			return false;
		}
		scanf("%d",&num);
		node* newRequest=newNode(num);
		//读取请求发生的站点 
		
		//为请求设置方向 
		if(strcmp(buff,"clockwise")){
			newRequest->direct=1;
		}else if(strcmp(buff,"counterclockwise")){
			newRequest->direct=-1;
		}else if(strcmp(buff,"target")){
			newRequest->direct=0;
		}
		add(n,maxint,newRequest);
		//将新的请求加入request链表中 
		scanf("%s",buff);
	}
	return true;
}
void fcfs(node* n, busInfo* info){
	info->time++;
	//每次调用都是新的一秒 
	node* tar=get(n,0);
	int tarPos=(info->target-1)*DISTANCE;
	//目标站点的位置
	
	if(tar->value==0) {
		//不存在请求，则输出当前位置直接返回 
		output(n,info);
	}else if(info->target==-1){
		//刚刚到目标站点，还没有停止一秒；则停一秒，输出信息，返回 
		output(n,info);
		info->target=0;
	}else if(info->target==0){
		/*
		 *可以直接选择目标执行新的请求
		 *即最开始的状态，和到目标站且已停够一秒的状态 
		 */
		while((tar->value-1)*DISTANCE==info->position){
			//如果时间顺序上的下一个/多个请求也在现在停的位置，则一次性执行完毕 
			removeNode(n,0);
			tar=get(n,0);
		}
		info->target=tar->value;
		tarPos=(info->target-1)*DISTANCE;
		//确定目标站点，及其坐标 
		int distance=tarPos-info->position;
		//distance为目标站点坐标与当前坐标的距离 
		if(distance<0) distance=-distance;
		int vice=TOTAL_STATION*DISTANCE-distance;
		//vice为如果反向行驶，到达目标站点的距离 
		if(vice>=distance){
			//确定行驶方向，无需反向 
			if(tarPos>info->position) info->direction=1;
			else info->direction=-1;
		}else{
			//确定行驶方向，需反向 
			if(tarPos>info->position) info->direction=-1;
			else info->direction=1;
		}
		//信息均确定完毕，则走过上一秒到当前秒应该行驶的路程，并输出 
		info->position+=info->direction;
		output(n,info);
	}else{
		//还在向目标站点的行驶路途中 
		info->position+=info->direction;
		output(n,info);
		if(info->position==tarPos){
			//特殊的，如果走了这一秒之后到达目标站点，则设置标识信息，用于下次调用时处理 
			removeNode(n,0);
			info->direction=0;
			info->target=-1;
		}
	}
}
