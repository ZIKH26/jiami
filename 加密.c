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
	printf("����������Ҫ���ܵ��ļ�����:");
	scanf("%s",fname);
	fp=fopen(fname,"r");  
	if(fp==NULL){
		printf("��������ļ����ƴ���!");
		exit(1);
	}
	while((ch=getc(fp))!=EOF){
		w[i]=ch-'\0';
		i++;
	}
	
	int i1=i;
	time_t t;int rtime1=0;int rtime=0;/*���ɵ���ʱ��*/ 
    struct tm * lt;
    time (&t);//��ȡUnixʱ�����
    lt = localtime (&t);//תΪʱ��ṹ��
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
