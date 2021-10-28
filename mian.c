#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
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
	time_t t;int rtime1=0;int rtime=0;/*生成当下时间*/ 
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。
    rtime=lt->tm_sec;
    rtime1=rtime-10;
    while(rtime1>10){
    	rtime1=rtime1-10;
    }
	
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
    int key1=0;
    key1=sizeof(b)*10+rtime1;
    printf("您的秘钥为%d\n",key1^25);
    if((fp=fopen("fujian.txt","wb"))==NULL){
    	printf("不能打开文件\n");
    	exit(0);
    }
    int js=key1^25;
    js=js^77;
    fprintf(fp,"%d",js);
    fclose(fp);
    return 0;}

if(jiemi==1){
ch=' ';
int my2=0;
int key2=0;
FILE *fp=NULL;
int key=0;
fp=fopen("fujian.txt","r");
fscanf(fp,"%d",&key);
key=key^77;
key=key^25;
key2=key%10;
key=key-key2;
key=key/10;
fclose(fp);
printf("请输入您的秘钥\n");
for(i=0;i<3;i++){
scanf("%d",&my1);
my=my1^25; 
my2=my%10;
my=my-my2;
my=my/10;
if(my!=key&&i==0){
	printf("秘钥错误,您还有两次机会\n");
	continue;
}
if(my!=key&&i==1){
	printf("秘钥错误,您还有一次机会\n");
	continue;
}
if(my!=key&&i==2){
	printf("秘钥错误,程序结束\n");
	return 0;
}
if(my==key){
	printf("秘钥正确\n");
	break;
}}
  char w2[my];
	i=0; 
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
	char f[my];
	printf("解密后的代码已经为您保存到了out.txt文档，感谢您使用该程序");
	freopen("out.txt","w",stdout);
	for(i=0;i<my;i++){
		if(w2[i]==32){
			printf(" ");
			f[i]=' ';
			continue;
		} 
	else	if(w2[i]==10){
			printf("\n");
			f[i]='\n';
			continue;
		}
	
	else  if(i%5==0){
		
		h=w2[i]-1;
		f[i]=h;
			printf("%c",h);
		}
		
		else if(i%2==0){
			h=w2[i]-3;
			f[i]=h;
		 printf("%c",h);
		}
		else{
			h=w2[i]-2;
			f[i]=h;
			printf("%c",h);
		}
	}
	
	
return 0;
} }
