#include<stdio.h>
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
	}fclose(fp);
	
	int i1=i;char b[i1];
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
    	b[i]=w[i]+2;
    	printf("%c",w[i]+2);
    }
    
    if((fp=fopen("miwen.txt","wb"))==NULL)
    {
    	printf("不能打开文件");
    	exit(0);
    }
    fwrite(b,sizeof(b),1,fp);
    printf("您的秘钥为%d",sizeof(b)^25);
    fclose(fp);
	return 0;
}
