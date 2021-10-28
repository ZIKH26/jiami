#include<stdio.h>
int main(){int i1=0;int rtime=0;int rtime1=0;int i=0;int u=0;
	scanf("%d %d",&rtime,&rtime1);
	char v=getchar();
	char a[1000000];
	for(i=0;i<=1000000;i++){
		
		scanf("%c",&u);
		if(u=='$') break;
		a[i]=u-'\0';
		
	}
	i1=i;
	for(i=0;i<i1;i++){
		if(a[i]==32||a[13]) continue;
		if(i%2==0){
			a[i]=a[i]^rtime;
		}
		if(i%2==1){
			a[i]=a[i]^rtime1;
		}
	}
	for(i=0;i<i1;i++){
	printf("%c",a[i]);
}
return 0;
} 
