#include "dataStruct.h"
int TOTAL_STATION=5;
int STRATEGY=1;
int DISTANCE=2;
int main(){
	//读入配置文件 
	FILE *fp = NULL;
	char buff[255];
	memset(buff,0,255);
	fp = fopen("dict.dic", "r");
	
	while(fgets(buff,255,fp)!=null){
	   	if(buff[0]=='#') continue;//注释行，忽略 
	   	else if(buff[0]=='T'){//total station 
		   	int temp=0;
		   	while(buff[temp]!='=') temp++;
		   	TOTAL_STATION=atoi(buff+temp+1);
		}else if(buff[0]=='D'){//distance 
			int temp=0;
			while(buff[temp]!='=') temp++;
			DISTANCE=atoi(buff+temp+1);
		}else if(buff[0]=='S'){///mod 
			int temp=254;
			while(buff[temp]!=0) temp--;//从后往前，判断模式的最后一个字符更方便 
			switch (buff[temp]) {
				case 'N':
					STRATEGY=3;//scan模式，为3 
					break;
				case 'F':
					STRATEGY=2;//sstf模式，为2 
					break;
				default:
					STRATEGY=1;//fcfs模式，为1 
					break;
			}
		}
	}
	
	//初始化request和info 
	busInfo* info=null;
	node* request=newNode(0);
	info = (busInfo*)malloc(sizeof(busInfo));
	info->direction=0;
	info->time=0;
	info->target=0;
	info->position=0;
	output(request,info);
	
	//公交车开始运行 
	while(input(request)){
		run(request,info);
	}
	
	return 0;
}
