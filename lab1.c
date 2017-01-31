#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void hybridSort(int *, int);
void bs(int, int , int *);
void quickSort(int, int, int *, int);
void swap(int, int, int *);
int partition(int, int, int, int *);
int main()
{
	int *a, n;
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	hybridSort(a, n);
	return 0;
}

void hybridSort(int *a, int n) 
{
	time_t ti,start,end;
	int b[10001],k,i;
	srand((unsigned int)time(NULL));
	for(i=0;i<n;i++){
                b[i]=rand()%289000;}
	FILE *fp=fopen("new2.dat","w+");
	for(k=1;k<=100;k++){
		for(i=0;i<=n;i++) a[i] = b[i];
        	start=clock();
        	quickSort(0, n-1, a, k); 
        	end=clock();
       double cpu_time_used =((double) (end - start))/CLOCKS_PER_SEC;
        fprintf(fp,"%d %lf\n",k,cpu_time_used);
    	}
    	fclose(fp);

     //For random input use the following code

     //arr[i] = rand();


     //output should be printed in the following way for each k.

     //printf("%d,%d",k,end-begin);



}



void bs(int left, int right, int *a){
	int i,j,temp;
	for(i=left;i<=right;i++)
        	{
                for(j=left;j<i;j++)
                        if(a[i]<a[j])
                        {
                                temp=a[i];
                                a[i]=a[i+1];
                                a[i+1]=temp;
                        }
        	}
	}
void quickSort(int left, int right, int *a, int k) {
   if(right-left <= 0) {
      return;   
   }
   else if(right - left <=k)  {
	bs(left,right, a);
   }
   else {
      int pivot = a[right];
      int partitionPoint = partition(left, right, pivot,a);
      quickSort(left,partitionPoint-1,a,k);
      quickSort(partitionPoint+1,right,a,k);
   }      
}
void swap(int num1, int num2, int *a) {
   int temp = a[num1];
   a[num1] = a[num2];
   a[num2] = temp;
}
int partition(int left, int right, int pivot, int *a) {
   int leftPointer = left;
   int rightPointer = right;

   while(1) {
      while(a[++leftPointer] < pivot) {
      }
		
      while(rightPointer > 0 && a[--rightPointer] > pivot) {
      }

      if(leftPointer >= rightPointer) {
         break;
      } else {
         //printf(" item swapped :%d,%d\n", a[leftPointer],a[rightPointer]);
         swap(leftPointer,rightPointer,a);
      }
   }
   swap(leftPointer,right,a); 
   return leftPointer;
}
