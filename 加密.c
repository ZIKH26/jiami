#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h> 
int main(){
	char fname[50];
	char w[1000000];
	int i=0;
	char ch=' ';
	FILE *fp=NULL;
	printf("请输入您需要加密的文件名称:");
	scanf("%s",fname);
	fp=fopen(fname,"r");  
	if(fp==NULL){
		printf("您输入的文件名称错误!");
		exit(1);
	}
	while((ch=getc(fp))!=EOF){
		w[i]=ch-'\0';
		i++;
	}
	
	int i1=i;
	time_t t;int rtime1=0;int rtime=0;/*生成当下时间*/ 
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。
    rtime=lt->tm_sec;
    rtime1=rtime-10;
    
    char ch=
    
    for(i=0;i<i1;i++){
    	if(w[i]==32||w[i]==13) continue;
    	
    		
    		if(i%2==0){
    		w[i]=w[i]^rtime;
    	} 
    	    if(i%2==1){
    	    w[i]=w[i]^rtime1;	
    	    }
    	
    	} 
    printf("%d %d\n",rtime,rtime1);	
    for(i=0;i<=i1;i++){
    	if (w[i]==13) {
    		printf("\n");
    		continue;
    	}
    	printf("%c",w[i]);
    }
    
	return 0;
}
