#include <stdio.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

int partition(int arr[], int low, int high){
    int pivot=arr[high], i=low-1;
    for(int j=low;j<high;j++) if(arr[j]<=pivot){i++;swap(&arr[i],&arr[j]);}
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int prices[]={999,2500,499,1799,899,1299,3200};
    int n=7;

    printf("Before Sorting: ");
    for(int i=0;i<n;i++) printf("%d ",prices[i]);
    printf("\n");

    quickSort(prices,0,n-1);

    printf("After Quick Sort: ");
    for(int i=0;i<n;i++) printf("%d ",prices[i]);
    printf("\n");

    return 0;
}
