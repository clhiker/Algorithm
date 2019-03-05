/*
* 归并排序
* 2019,3,5
* by 陈乐
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 自下而上归并排序
void mergeQuery(int*a, int n){
    for (int j=0;j<n;j++){
        int min_index = j;
        for(int i=j+1;i<n;i++){
            if (a[i] < a[min_index]){
                min_index = i;
            }
        }
        int temp = a[j];
        a[j] = a[min_index];
        a[min_index] = temp;
    }
}
int* merge(int *temp1, int n1, int *temp2, int n2) {
    int *temp = (int *) malloc(sizeof(n1 + n2));

    int i=0,j=0,k = 0;

    while (1) {
        if(i == n1){
            for(;j<n2;j++){
                temp[k] = temp2[j];
                printf("%d\t", temp2[j]);
                k++;
            }
            break;
        }
        if(j == n2){
            for(;i<n1;i++){
                temp[k] = temp1[i];
                printf("%d\t", temp1[i]);
                k++;
            }
            break;
        }
        if (temp1[i] < temp2[j]) {
            temp[k] = temp1[i];
            printf("%d\t", temp1[i]);
            i++;
            k++;
        } else {
            temp[k] = temp2[j];
            printf("%d\t", temp2[j]);
            j++;
            k++;
        }
    }
}


int main() {

//    int n = 10;
//    int *a = (int*)malloc(sizeof(int) * n);
//    srand(time(NULL));
//    for (int i = 0; i< n; i++){
//        a[i] = rand()%100;
//    }
//    for(int i=0; i<n; i++){
//        printf("%d\t", a[i]);
//    }
//    printf("\n");
//
//    chooseQuery(a, n);
//
//    for(int i=0; i<n; i++){
//        printf("%d\t", a[i]);
//    }
//    free(a);

    int a1[5] = {1,3,4,5,10};
    int a2[4] = {2,4,5,8};
    int *a = merge(a1, 5, a2, 4);
    for(int i=0;i< 9;i++){
        printf("%d\t", a[i]);
    }
    free(a);
    return 0;
}