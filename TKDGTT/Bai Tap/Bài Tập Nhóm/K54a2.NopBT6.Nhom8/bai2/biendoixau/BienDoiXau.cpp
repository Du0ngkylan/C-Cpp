
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define INPUT_FILE "BienDoiXau.txt"

char x[100], y[100], x1[100], y1[100];
int m, n, c[100][100];

void dichPhai(char *xauNguon, char *xauDich){
    int doDaiXau = strlen(xauNguon);
    xauDich[0]=' ';
    for(int i=0; i<=doDaiXau; i++){
        xauDich[i+1] = xauNguon[i];    
    }
}

void docDuLieu(){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    
    if(file != NULL){
        //Doc du lieu        
        fgets(x1, 255, file);
        fflush(stdin);
        fgets(y1, 255, file);
        
        m=strlen(x1)-1;
        n=strlen(y1);
        
        dichPhai(x1, x);
        dichPhai(y1, y);
        
    }
    else{
        puts("Khong tim thay file!");    
        getch();
        exit(0);
    }
}

void inDuLieu(){
    printf("M=%d, N=%d\n", m, n);
    printf("X=%s", x);
    printf("Y=%s\n", y);
}

int min(int a, int b, int c){
    int min=a;
    if(min>b)
        min=b;
    if(min>c)
        min=c;
    return min;    
}

void dungBangPhuongAn(){
    /*Co so*/    
    for(int i=0; i<=m; i++)
        c[i][0] = i;
    for(int j=0; j<=n; j++)
        c[0][j] = j;
        
    /*Dung bang*/        
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++){
            if(x[i]==y[j])
                c[i][j] = c[i-1][j-1];
            else{
                c[i][j] = min(c[i-1][j-1], c[i-1][j], c[i][j-1])+1;         
            }    
        }
      
    /*  
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++)
            printf("%d ", c[i][j]);    
        puts("");
    }
    */
}

void truyVet(){
    int i=m, j=n;
    while(i>0 || j>0){
        if(x[i]==y[j]){
            i--;
            j--;
        }    
        else{
            if(i>0){
                if(j>0){
                    if(c[i][j]==c[i-1][j-1]+1){
                        printf("su dung phep thay the ky tu tai vi tri %d bang ky tu %c\n", i, y[j]);    
                        i--;
                    }                                        
                    else
                        printf("Su dung phep chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                    j--;
                }   
                else{
                    printf("Su dung phep xoa ky tu tai vi tri %d\n", i);    
                    i--;
                }
            }else if(j>0){
                printf("Su dung phep chen ky tu %c vao sau vi tri %d\n", y[j], i);    
                j--;
            }    
        }
    }    
}

int main(){
    docDuLieu();
    inDuLieu();
    dungBangPhuongAn();
    truyVet();   
    
    puts("Hoan thanh!");
    getch();
    return 0;
}
/*
Chu y:
    Ly thuyet chi ban ve cach xu ly doi voi xau bat dau tu vi tri 1.
    Ma trong C, xau lai bat dau tu 0.
    Do do, truoc khi xay dung bang phuong an phai copy xau sang 1 mang khac
    de bat dau tu vi tri so 1.
    O day co the dung ham dichPhai() viet san.
*/
