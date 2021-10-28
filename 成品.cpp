#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int i1=0;
	int jiami=0;
	int jiemi=0;
	char u;
	char fname2[11]="miwen.txt";
    int my=0;
	int my1=0;
	int judge=0;
	char fname[50];
	char w[1000000];
	
	int i=0;
	char ch=' ';
	printf("这个程序可以为您进行代码的加密和解密\n");
	printf("如果是加密请按数字1，如果是解密请按数字2\n");
	scanf("%d",&judge);
	if(judge==1){
		jiami++;
	}
	else if(judge==2){
		jiemi++;
	}
	else {printf("您的输入不符合要求,程序将关闭\n");
	return 0;
	}
	if(jiami==1){
	
	FILE *fp=NULL;
	printf("请输入您需要加密的文件名称:\n");
	scanf("%s",fname);
	fp=fopen(fname,"r");  
	if(fp==NULL){
		printf("您输入的文件名称错误!\n");
		exit(1);
	}
	while((ch=getc(fp))!=EOF){
		w[i]=ch-'\0';
		i++;
	}fclose(fp);
	
	 i1=i;char b[i1];
    for(i=0;i<=i1;i++){
    	if (w[i]==32){
    		printf(" ");
    		b[i]=' ';
    		continue;
    	} 
    	if (w[i]==10) {
    		printf("\n");
    		b[i]='\n';
    		continue;
    	}
    	else if(i%5==0){
    		b[i]=w[i]+1;
    		printf("%c",b[i]);
    		continue;
    	}
    	else if(i%2==0){
    		b[i]=w[i]+3;
    		printf("%c",b[i]);
    		continue;
    	}
    	else{
    		b[i]=w[i]+2;
    		printf("%c",b[i]);
    		continue;
    	}
    	
    }
    if((fp=fopen("miwen.txt","wb"))==NULL)
    {
    	printf("不能打开文件\n");
    	exit(0);
    }
    fwrite(b,sizeof(b),1,fp);
    fclose(fp);
    printf("您的秘钥为%d\n",sizeof(b)^25);
    if((fp=fopen("fujian.txt","wb"))==NULL){
    	printf("不能打开文件\n");
    	exit(0);
    }
    return 0;}

if(jiemi==1){
ch=' ';
printf("请输入您的秘钥\n");
scanf("%d",&my1);
FILE *fp=NULL;
my=my1^25; 
  char w2[my];
	
	fp=fopen(fname2,"r");  
	if(fp==NULL){
		printf("您输入的文件名称错误!\n");
		exit(1);
	}
	while((ch=getc(fp))!=EOF){
		w2[i]=ch-'\0';
		i++;
		
		if(i==my) break; 
	}
	int h=0;
	for(i=0;i<my;i++){
		if(w2[i]==32){
			printf(" ");
			continue;
		} 
	else	if(w2[i]==10){
			printf("\n");
			continue;
		}
	
	else  if(i%5==0){
		
		h=w2[i]-1;
			printf("%c",h);
		}
		
		else if(i%2==0){
			h=w2[i]-3;
			
		 printf("%c",h);
		}
		else{
			h=w2[i]-2;
			
			printf("%c",h);
		}
	}
return 0;
} }
