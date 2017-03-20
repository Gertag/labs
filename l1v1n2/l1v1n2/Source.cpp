/*---------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
/*---------------------------------------------*/
typedef struct str 
{
	int i1;
	char *ch1;
	struct
	{
		float fl1;
		char ch2[20];
	}str2;
}str1;
/*---------------------------------------------*/
void new_el (str *p,int n);
void poisk (str *p,int n);
void output_str(str *p,int n);
int del (str *p,int n);
int menu(str *p,int n);
int add(str *p,int n);
/*---------------------------------------------*/
int main()
{
	setlocale(LC_ALL,"Russian");
	str *st;
	int n;
	printf("¬ведите размер структуры\n");
	scanf("%d",&n);
	if(!(st =(str *)calloc(n,sizeof(str)))){printf("EOM!!");getch();return 0;};
	n=menu(st,n);
	for (int i = 0;i<n;i++)
	{
		free(&st->ch1);
	}
	free(st);
	return 0;
}
/*-------------------------------------------*/
int menu(str *p,int n)
{
	printf("\n1 - ¬вод структуры\n2 - ¬ывод структуры\n3 - удаление элемента структуры по заданному параметру\n");
	printf("4 - добавление элемента\n");
	printf("0 - Exit\n");
	switch (getch())
	{
	case '1':new_el(p,n);break;
	case '2':output_str(p,n);break;
	case '3':n=del(p,n);break;
	case '4':n=add(p,n);break;
	case '0':return n;break;
	default:printf("Error!!");break;
	}
	system("cls");
	menu(p,n);
}
/*---------------------------------------------*/
void new_el(str *p,int n)
{
	for (int i = 0;i<n;i++)
	{
		printf("\n¬ведите i1\n");
		scanf("%d",&p[i].i1);
		fflush(stdin);
		if(!(p[i].ch1 = (char *)calloc(20,sizeof(char)))){printf("EOM!!");getch();return;};
		printf("¬ведите ch1\n");
		scanf("%s",&p[i].ch1);
		fflush(stdin);
		//gets(p[i].ch1);
		printf("¬ведите fl1\n");
		scanf("%f",&p[i].str2.fl1);
		fflush(stdin);
		printf("¬ведите ch2\n");
		scanf("%s",&p[i].str2.ch2);
		fflush(stdin);
		//gets(p[i].str2.ch2);
	}
	system("cls");
}
/*--------------------------------------*/
void output_str(str *p,int n)
{
	if (!(p[0].ch1)){printf("\nStruct is empty\n");getch();return;}
	for (int i = 0;i<n;i++)
	{
		printf("\nstr є%d\n",i+1);
		printf("i1 - %d\n",p[i].i1);
		printf("ch1 - %s\n",&p[i].ch1);
		printf("fl1 - %f\n",p[i].str2.fl1);
		printf("ch2 - %s\n",&p[i].str2.ch2);
	}
	getch();
	system("cls");
}
/*-------------------------------------*/
int del(str *p,int n)
{
	if (!(p[0].ch1)){printf("\nStruct is empty\n");getch();return n;};
	int j;
	printf ("¬ведите i1 дл€ удалени€\n");
	scanf("%d",&j);
	for (int i =0;i<n;i++)
	{
		if (p[i].i1<j)
		{
		p[i].i1=p[n-1].i1;
		p[i].str2.fl1=p[n-1].str2.fl1;
		strcpy(p[i].ch1,p[n-1].ch1);
		strcpy(p[i].str2.ch2,p[n-1].str2.ch2);
		n--;
		realloc(p,n*sizeof(str));
		}
	}
	return n;
}
/*---------------------------*/
int add (str *p,int n)
{
	if (!(p[0].ch1)){printf("\nStruct is empty\n");getch();return n;};
	int m;
	int k =n;
	printf("\n¬ведите количество добавл€емых элементов\n");
	scanf("%d",&m);
	p=(str *)realloc(p,(m+n)*sizeof(str));
	for (int i = k;i<m;i++)
	{
		printf("\n¬ведите i1\n");
		scanf("%d",&p[i].i1);
		fflush(stdin);
		if(!(p[i].ch1 = (char *)calloc(20,sizeof(char)))){printf("EOM!!");getch();return n;};
		printf("¬ведите ch1\n");
		scanf("%s",&p[i].ch1);
		fflush(stdin);
		//gets(p[i].ch1);
		printf("¬ведите fl1\n");
		scanf("%f",&p[i].str2.fl1);
		fflush(stdin);
		printf("¬ведите ch2\n");
		scanf("%s",&p[i].str2.ch2);
		fflush(stdin);
		//gets(p[i].str2.ch2);
	}
	system ("cls");
	return(m+n);
}
/*--------------------------------------*/
void poisk(str *p,int n)
{
	if (!(p[0].ch1)){printf("\nStruct is empty\n");getch();return;
	int k;
	printf("¬ведите элемент дл€ сравнени€");
	scanf("%d",&k);
	for (int i = 0;i<n;i++)
		{
		if(p[i].i1==k)
			{
			printf("\n—овпадение найдено:\n");
			printf("str є%d\n",i+1);
			printf("i1 - %d\n",p[i].i1);
			printf("ch1 - %s\n",&p[i].ch1);
			printf("fl1 - %f\n",p[i].str2.fl1);
			printf("ch2 - %s\n",&p[i].str2.ch2);
			}
		}
	}
}