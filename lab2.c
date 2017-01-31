# include <stdio.h>
# include <stdlib.h>

int check_MAX_heap(int *,int,int);
void build_MAX_heap(int *,int, int);
int extract_MAX(int *,int, int);
void insert(int *,int,int,int);
void change(int *,int,int,int,int);
void maxheap(int *, int ,int , int);
void revheap(int *, int, int);

int main()
{
  char ch=' ';
  int *arr,n,k,i,new;
  scanf("%d",&k);
  scanf("%d",&n); /* To have anything non-trivial, n should be >2*n*k*/
  arr = (int *)malloc(2*n*sizeof(int));
  for(i=0;i<n;i++)
    {
      scanf("%d",&arr[i]);
    }
  if(!check_MAX_heap(arr,n,k))
    build_MAX_heap(arr,n,k);
	for(i=0;i<n;i++)printf("%d ",arr[i]); 
  do
    {
      while(getchar()!='\n');  //To clear the buffer of any leftover characters
      ch=getchar();
      switch(ch)
	{
	case 'i':
	  scanf("%d",&new);
	  insert(arr,n,k,new);
	  n++;
	  break;
	case 'd':
	  printf("%d",extract_MAX(arr,n,k));
	  n--;
	  break;
	case 'c':
	  scanf("%d",&i);
	  scanf("%d",&new);
	  change(arr,n,k,i,new);
	  break;
	}
    }while(ch!='q');
	//printf("%d %d", arr[1], check_MAX_heap(arr,n,k));
  return 0;
}

int check_MAX_heap(int arr[],int n,int k)
{
	int i,j,fl=1;
	for(i=(n-1)/k;i>=0;i--) {
		for(j=1;j<=k;j++) {
			if((k*i)+j<=n){
				if(arr[(k*i)+j]>arr[i])fl=0;
			}
		}
	}
	return fl;
}
void revheap(int arr[], int index, int k)
{
    int parent = (index-1)/k;
    while (parent>=0)
    {
        if (arr[index] > arr[parent])
        {
	    int temp = arr[index];
	    arr[index] = arr[parent];
	    arr[parent] = temp;
            index = parent;
            parent = (index -1)/k;
        }
        else
            break;
    }
} 
void maxheap(int arr[], int len, int index, int k)
{
    int child[k+1],i;
 
    while (1)
    {
        for (i=1; i<=k; i++){
		if((k*index + i) < len) child[i] = k*index + i;
		else child[i]=-1;
	}
 
        int max_child = -1, max_child_index ;
 
        for (i=1; i<=k; i++)
        {
            if (child[i] != -1 && arr[child[i]] > max_child)
            {
                max_child_index = child[i];
                max_child = arr[child[i]];
            }
        }
 
        if (max_child == -1)
            break;
 
        if (arr[index] < arr[max_child_index]){
		int temp = arr[index];
		arr[index] = arr[max_child_index];
		arr[max_child_index] = temp;
 	}
        index = max_child_index;
    }
}

void build_MAX_heap(int arr[],int n,int k)
{
	int i;
	for (i= (n-1)/k; i>=0; i--)
        maxheap(arr, n, i, k);
	//int i1,i;
  /* This function shuffle the elements of arr till it is a k-ary MAX-heap*/
	/*for (i=(n-1)/k; i>=0; i--) {
		int child[k+1];
		int index = i;
    	while (1)
    	{
		printf("p");
        	for (i1=1; i1<=k; i++) {
			if((k*index + i1) < n) child[i] = k*index + i1;
			else child[i1] = -1;
          	}
        int max_child = -1, max_child_index;
 
        for (i1=1; i1<=k; i++)
        {
            if (child[i1] != -1 && arr[child[i1]] > max_child) {   
                max_child_index = child[i1];
                max_child = arr[child[i1]];
            }
        }
        if (max_child == -1)
            break;
        // swap only if the key of max_child_index
        // is greater than the key of node
        if (arr[index] < arr[max_child_index]) {
		int temp = arr[index];
		arr[index] = arr[max_child_index];
		arr[max_child_index] = temp;
        index = max_child_index;
	
    	}
	}
	}*/
}

void insert(int arr[],int n,int k,int new)
{
  arr[n] = new;
  revheap(arr, n, k);
}

int extract_MAX(int arr[],int n,int k)
{
	int ans  = arr[0];
	arr[0] = arr[n-1];
	build_MAX_heap(arr,n-1,k);
	return ans;
}

void change(int arr[],int n,int k,int i,int new)
{
  if(new>arr[i]) {
		arr[i] = new;
		revheap(arr,i,k);
  }
	else {
		arr[i] = new;
		maxheap(arr,n,i,k);
	}
		
}

