
#include<stdio.h>
#include<conio.h>
int n,i; 
int a[100];

void kq(){
     printf("\n");
     for(i=0;i<n;i++) printf("%d",a[i]);
     }
     
void Try(int i){
     int j,k,n;
     for(j=0;j<=1;j++)
        {
             a[i]=j;
             if(i==n-1)  kq();
               else Try(i+1);
        }
}
int main(){
    printf("Nhap do dai day hoan vi:");
    scanf("%d",&n);
    Try(0);
    getch();
}
    
