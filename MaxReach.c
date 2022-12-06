#include <stdbool.h>
#include "stdio.h"

int main(){
    printf("Enter the no.of people and no.of connections: ");
    int v=0,e=0;
    scanf("%d %d",&v,&e);
    int mat[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            mat[i][j]=0;
        }
    }
    for(int i=0;i<e;i++) {
        int r,c;
        printf("Enter %d connection: ",i);
        scanf("%d %d",&r,&c);
        mat[r][c]=1;
    }
    printf("Enter root person: ");
    int root;
    scanf("%d",&root);
    int max=0,share;
    bool flag=false;
    for(int i=0;i<v;i++){
        if(mat[root][i]==1){
            int t=0;
            for(int j=0;j<v;j++){
                t+=mat[i][j];
            }
            if(max<t){
                max=t;
                share=i;
                flag=true;
            }
        }
    }
    if(flag){
        printf("Share with %d.It will be shared with %d people.",share,max+1);
    }
    else{
        printf("Root person doesn't have any connections.");
    }
}
