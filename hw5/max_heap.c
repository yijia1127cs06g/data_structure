#include<stdio.h>
#include<stdlib.h>

void adjustHeap(int *, int, int);
void createHeap(int*, int);
int deleteMax(int *, int *);
void insertHeap(int *, int*, int);


int main(){
    
    int T;

    scanf("%d", &T);

    while(T--){
        int M;
        int N;
        int *X;

        scanf("%d %d", &M, &N);
        X = (int *)malloc(sizeof(int)*M);
        for (int i = 0; i<M; i++)
            scanf("%d", &X[i]);
        
        createHeap(X, M);
        
        int total = 0;
        // output max n time
        for (int j = 0; j<N; j++){
            int item = deleteMax(X, &M);
            total += item;
            item--;
            if (item>0)
                insertHeap(X, &M, item);
        }

        printf("%d\n", total);
        free(X);

    }

    return 0;
}

void adjustHeap(int *ary, int i, int n){
    int k = ary[i];
    int j = 2*i+1;

    while(j<=(n-1)){
        if (j<(n-1))
            j=ary[j]<ary[j+1]?j+1:j;
        if (k>=ary[j])
            break;
        else{
            ary[(j-1)/2] = ary[j];
            j = j*2+1;
        }
    }
    ary[(j-1)/2] = k;
}


void createHeap(int *ary, int n){
    for(int j=((n-1)-1)/2; j>=0; j--)
        adjustHeap(ary, j, n);
}


int deleteMax(int *ary, int *n){
    int item = ary[0];
    ary[0] = ary[*n-1];
    (*n)--;
    adjustHeap(ary, 0, *n);
    return item;
}


void insertHeap(int *ary, int *n, int item){
    ary[*n] = item;
    (*n)++;
    adjustHeap(ary, 0, *n);
}


