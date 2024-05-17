#include<string.h>
#include<stdlib.h>
#include<stdio.h>

// void selectionSort(char *a, int n);
// void insertionSort(char *a, int n);
// void swap(char *a, char *b);
// void quikSort(char *a, int loLimit, int hiLimit);

int main()
{
	char test[80];
	char choice;
	int n;
	printf("String to sort>> ");
	gets(test);
	n=strlen(test);
	puts("Sort by...");
	puts("\t[S]election");
	puts("\t[I]nsertion");
	puts("\t[Q]uick");
	printf("Choice>> ");
	choice=getchar();

	printf("%s (input string)\n",test);


	switch(choice)
	{
		case 'S' : selectionSort(test,n);
					  puts(test);
					  break;

		case 'I' : insertionSort(test,n);
					  puts(test);
					  break;
        default:
            printf("Invalid Input");
            break;
	}
	return(0);
}

void selectionSort(char *a, int n)
{
	int min;
	int j,k;
	char curr;

	for(j=0;j<n;j++)
	{
		min=j;
		for(k=j;k<n;k++)
			if(a[k]<a[min])min=k;
			curr=a[min];
			a[min]=a[j];
			a[j]=curr;
			printf("%2d: %s\n",j,a);
	}
}

void insertionSort(char *a, int n)
{
	char curr;
	int j,k;
	for(j=0;j<n;j++)
	{
		curr=a[j];
		for(k=j;k>0;k--)
		{
			if(a[k-1]<=curr)break;
			a[k]=a[k-1];
		}
		a[k]=curr;
		printf("%2d: %s\n",j,a);
	}
}

void swap(char *a, char *b)
{
	char tmp=*a;
	*a=*b;
	*b=tmp;
	return;
}


