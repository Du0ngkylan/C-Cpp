#include<stdio.h> 
#include<conio.h> 


void minmax(int a[],int dau, int cuoi,int &min, int &max) 
{ 
     int min1,min2,max1,max2; 
     if(dau==cuoi) 
     { 
                  min=a[dau]; 
                  max=a[dau]; 
     } 
     else 
     { 
         
         minmax(a,dau,(dau+cuoi)/2,min1,max1); 
         minmax(a,(dau+cuoi)/2+1,cuoi,min2,max2); 
         if(min1 < min2) 
         min=min1; 
         else 
         min=min2; 
         if(max1 > max2) 
         max=max1; 
         else 
         max=max2; 
     } 
} 

void in(int a[], int n)
{
     int i;
     for(i=0;i<n;i++)
     {
      printf(" %d ",a[i]);                
     }     
}

int main() 
{ 
    int a[10]={2, 7, 1, 5, 3, 8, 6, 4, 9, 10}; 
    int min=a[0]; 
    int max=a[9]; 
    in(a,10);
    minmax(a,0,9,min,max); 
    printf("\nPhan tu nho nhat cua day la : %d",min); 
    printf("\nPhan tu lon nhat trong day la :%d",max); 
    getch(); 
    return 0 ; 
}  
