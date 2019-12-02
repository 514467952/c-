#include<stdio.h>
int main(void){
	int data[12]={2,2,2,3,3,4,4,4,4,5,5,6};
	int key, i,n;
	int deletkey(int a[],int n,int key);
	printf("请输入要删除的数:\n");
	scanf("%d",&key);
	n=deletkey(data,12,key);
	for(i=0;i<n;i++){
		printf(" %d",data[i]);
	}
	printf("\n");

}
int deletkey(int a[],int n,int key){
	int i,j;
	i=0;
	while(i<n){
		if(a[i]-key)
		   i++;
	    else{
	    	for(j=i;j<n-1;j++)
	    		a[j]=a[j+1];
	    		
			
			n--;
		}
	}
	  return n;
}

