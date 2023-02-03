#include <stdio.h>

int comp=0;
void merge(int *arr,int low,int avg,int high){
	int n=avg-low+1,left[n];
	int m=high-avg,right[m];
	for(int i=0;i<n;i++){
		left[i]=arr[low+i];
	}
	for(int i=0;i<m;i++){
		right[i]=arr[avg+i+1];
	}
	int i=0,j=0,k=low;
	while (i<n&&j<m) {
		if(left[i]<right[j]){
			arr[k]=left[i];
			i++;
		}
		else {
			comp++;
		arr[k]=right[j];
		j++;
		}
		k++;
	}
	while (i<n) {
		arr[k]=left[i];
		i++;
		k++;
	}
	while (j<m) {
		arr[k]=right[j];
		j++;
		k++;
	}
}

void mergeSort(int *arr,int left,int right){
	if(left<right){
		int mid=left+(right-left)/2;
		mergeSort(arr,left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr,left,mid,right);
	}

}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d ",&arr[i]);
	mergeSort(arr,0,n-1);
	// for(int i=0;i<n;i++){
	// 	printf("%d ",arr[i]);
	// }
	printf("%d",comp);
}
