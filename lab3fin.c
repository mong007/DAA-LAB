# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
int main()
{
  char **input;
  char ch=' ';
  int n,k,i,j;
  srand(time(NULL));
  scanf("%d",&n);
  scanf("%d",&k);
  input = (char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++)
    {
      input[i]=(char *)malloc((k+1)*sizeof(char));
      for(j=0;j<k;j++)
	input[i][j]=(rand()%95)+32;
      input[i][k]='\0';
    }
  radix_sort(input,n,k);
	printf("\n\noutput\n");
  for(i=0;i<n;i++)
    {
      printf("%s\n",input[i]);
    }
  
  return 0;
}
void count1(char **input, int n, int c) {
	int i,j;
	char **out = (char **)malloc(n*sizeof(char *));
	int count[100];
	for(i=0;i<100;i++)count[i] = 0;
	for(i=0;i<n;i++){
		count[input[i][c]-32]++;
	}
	for(i=33;i<=126;i++){
		count[i-32] += count[i-1-32];
	}
	for(i=0;i<n;i++){
		out[count[input[i][c]-32]-1] = input[i];
		count[input[i][c]-32]--;
	}
	for(i=n-1;i>=0;i--){
		input[i] = out[i];
	}
}
void count2(char **input, int n, int c) {
	int i,j,k;
	int count[100];
	for(i=0;i<100;i++)count[i] = 0;
	for(i=0;i<n;i++){
		count[input[i][c]-32]++;
	}
	int ind = n-1;
	for(i=126;i>=32;i--) {
		while(count[i-32]--){
			//printf("yes %d %d %d %c\n", c, ind,i,i);
			int j;
			if(input[ind][c] != i){
			for(j=ind-1;j>=0;j--){
				if(input[j][c] == i) {
					char temp[100];
					strcpy(temp,input[j]);
					strcpy(input[j],input[ind]);
					strcpy(input[ind],temp);
				 ind--;break;}
			}
			}
			else ind--;
			/*for(k=0;k<n;k++)
    {
      printf("%s\n",input[k]);
    }*/
		}
	}
}

void radix_sort(char **input,int n,int k)
{
	int i;
	for(i=k-1;i>=0;i--) {
		//count1(input,n,i);
		count2(input,n,i);
	}

}
