#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void nhap(int a[], int n){
     int i;
     for(i=0;i<n;i++)
     {
         a[i]=i+1;
     }
}
void copy(int a[][100], int i, int j, int length){
     int k;
     for(k=0;k<length;k++)
     {
          a[k][j]=a[k][i];
     }
}
void doixung(int a[][100], int j, int length){
     int i;
     for(i=0;i<length;i++)
     {
          a[i+length][j]=a[length-i-1][j];
     }
}
void in(int a[][100], int n){
     int i,j;
     for(j=0;j<(int) pow(2,n);j++)
     {
          for(i=0;i<n;i++)
          {
               printf("%2d", a[j][i]);
          }
          
          printf("\n");
           
     }
    
    
}
void Gray(int n){
     int a[100][100];
     a[0][0]=0;
     a[1][0]=1;
     int i,j;
     for(i=1;i<n;i++)
     {
         for(j=i;j>0;j--)
         {
             copy(a,j-1,j,(int) pow(2,i));
             doixung(a,j,(int) pow(2,i));
         }
         for(j=0;j<(int) pow(2,i);j++)
         {
             a[j][0]=0;
             a[j+(int)pow(2,i)][0]=1;
         }
     
     
     }
     in(a,n);
}
int main(){
    int a[100],n;
    printf("nhap n:");
    scanf("%d", &n);
    nhap(a,n);
    Gray(n);
    getch();
    return 0;
}