#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int arr[]={1,2,3,4,5,6,1,4,5,10,1,2,3,4,5,6,7,8,9,11,1,2,3,4,5};
	int **ar2=(int **)malloc(sizeof(int*)*100);
	int index=0;
	int n_index=0;
	for(int a=0;a<100;a++)
	{
		ar2[a]=(int*)malloc(sizeof(int)*100);
	}
	for(int a=0;a<100;a++)
	{
		for(int b=0;b<100;b++)
		{
			ar2[a][b]='\0';
		}
	}
	for(int a=0;a<(int)((sizeof(arr)/4)-1);a++)
	{
		if(arr[a]<arr[a+1])
		{
			ar2[n_index][index]=arr[a];
			index++;
		}
		else
		{
			n_index++;
			ar2[n_index-1][index]=arr[a];
			index=0;	
		}
	
	}
	int *lar=(int*)malloc(sizeof(int)*100);
	int largest_index=0;
	for(int a=0;a<100;a++)
	{
		int b=0;
		
		while(ar2[a][b]!='\0')
		{
			b++;
			if(a!=0)
			{
				if(lar[a]>lar[a-1])
				{
					largest_index=a;
				}	
			}
			if(a==0)
			{
				largest_index=a;	
			}
			lar[a]=b;	
		}
	}
	printf("Largest Sequence: ");
	for(int b=0;ar2[largest_index][b]!='\0';b++)
	{
		printf("%d ",ar2[largest_index][b]);
	}
	printf("\n");
}
