#include<stdio.h>
#include<stdlib.h>
int main(){int i1=0;int i=0;char u;char ch=' ';char fname[11]="miwen.txt"; int my=0;
int my1=0;
printf("请输入您的秘钥");
scanf("%d",&my1);
my=my1^25; 
  char w[my];
	FILE *fp=NULL;
	fp=fopen(fname,"r");  
	if(fp==NULL){
		printf("您输入的文件名称错误!");
		exit(1);
	}
	while((ch=getc(fp))!=EOF){
		w[i]=ch-'\0';
		i++;
		if(i==my) break; 
	}
	
	for(i=0;i<my;i++){
		if(w[i]==32){
			printf(" ");
			continue;
		} 
		if(w[i]==10){
			printf("\n");
			continue;
		}
	printf("%c",w[i]-2);
}
return 0;
} 
