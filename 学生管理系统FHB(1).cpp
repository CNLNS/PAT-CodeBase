#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
struct student//����һ��ѧ���Ľṹ�� 
{
	int num;//ѧ�� 
	char name[20];//���� 
	float score1;
	float score2;
	float score3;
	float score4;
	float score5;
	float score6;
	float score7;
	float aver;
	int count;
}stu[N],f;


void cin(struct student stu[]);//����ѧ����Ϣ
void ssum(struct student stu[]);//��ѧ���ܷ�
void aver(struct student stu[]);//���ѧ��ƽ����
void aversort(struct student stu[]);//ƽ����������� 
void numsort(struct student stu[]);//��ѧ���������ѧ����Ϣ 
void search(struct student stu[]);//��ѧ������ѧ����Ϣ
void search1(struct student stu[]);//����������ѧ����Ϣ 
void allsum(struct student stu[]);//���ÿ�Ź����ܷ���ƽ����
void quit(struct student stu[]);//�˳�����


int main()
{
	int menu;
	system("cls"); 
	printf("\tѧ���ɼ�����ϵͳ\n");
	printf("\t----���˵�----\n");
	printf("\t1.����ѧ����Ϣ\n");
	printf("\t2.����ѧ���ܷ�\n");
	printf("\t3.���ѧ��ƽ����\n");
	printf("\t4.��ѧ�Ų���ѧ��������Ϣ\n");
	printf("\t5.��ƽ�����������ѧ����Ϣ\n");
	printf("\t6.��ѧ���������ѧ����Ϣ\n");
	printf("\t7.����������ѧ��������Ϣ\n");
	printf("\t8.���ÿ�Ź����ܷ���ƽ����\n");
	printf("\t0.�˳�ϵͳ\n"); 
	printf("\t������ѡ��\n");
	scanf("%d",&menu);//����ѡ�� 
	switch(menu)
	{
		case 1:cin(stu);break;
		case 2:ssum(stu);break;
		case 3:aver(stu);break;
		case 4:search(stu);break;
		case 5:aversort(stu);break;
		case 6:numsort(stu);break;
		case 7:search1(stu);break;
		case 8:allsum(stu);break;
		case 0:quit(stu);break;
		default:printf("ʧ��\n");break;//���ʧ�ܵ���� 
	 } 
}

void cin(struct student stu[])//����ѧ����Ϣ 
{
	int i,n;
	char c;
	printf("������ѧ��������"); 
	scanf("%d",&n); 
	f.count=n;
	system("cls");//����
	for(i=1;i<=n;i++)
	{
		printf("����ѧ��:");
		scanf("%d",&stu[i].num);
		printf("��������:");
		scanf("%s",&stu[i].name);
		printf("�ɼ�һ��");
		scanf("%f",&f.score1);
		stu[i].score1=f.score1;
		printf("�ɼ�����");
		scanf("%f",&f.score2);
		stu[i].score2=f.score2;
		printf("�ɼ�����");
		scanf("%f",&f.score3);
		stu[i].score3=f.score3;
		printf("�ɼ��ģ�");
		scanf("%f",&f.score4);
		stu[i].score4=f.score4;
		printf("�ɼ��壺");
		scanf("%f",&f.score5);
		stu[i].score5=f.score5;
		printf("�ɼ�����");
		scanf("%f",&f.score6);
		stu[i].score6=f.score6;
		printf("�ɼ��ߣ�");
		scanf("%f",&f.score7);
		stu[i].score7=f.score7;
	    }
		printf("�������,����Y�������˵�\n");
		scanf("%c",&c);//�ж��Ƿ�������� 
		c=getchar();//�����ո�Ӱ�� 
		printf("\n");
		if(c=='Y'||c=='y')
		main(); //�������˵� 
	
}

void ssum(struct student stu[])//���ܷ� 
{
	int i;
	char c;
	float zf;
	system("cls");
	for(i=1;i<=f.count;i++)
	{
		zf=0;
		printf("������%s ",stu[i].name);
		zf=stu[i].score1+stu[i].score2+stu[i].score3+stu[i].score4+stu[i].score5+stu[i].score6+stu[i].score7;
		printf("�ܷ֣�%.2f\n",zf);
		if(stu[i].num=0) break;
	}
	printf("�����ɣ�����Y���ز˵�");
	scanf("%c",&c);
	c=getchar();
	printf("\n"); 
	if(c=='Y'||c=='y')
	main(); 
}

void aver(struct student stu[])//ƽ���� 
{
	int i;
	char c;
	float aver[55];
	system("cls");
	for(i=1;i<=f.count;i++)
	{
		printf("������%s :",stu[i].name);
		aver[i]=(stu[i].score1+stu[i].score2+stu[i].score3+stu[i].score4+stu[i].score5+stu[i].score6+stu[i].score7)/7;
	    printf("ƽ���֣�%.2f\n",aver[i]);
	}
	printf("�����ɣ�����Y���ز˵�"); 
	scanf("%c",&c);
	c=getchar();
	printf("\n");
	if(c=='y'||c=='Y')
	main();
}

void aversort(struct student stu[])
{
	int i,j;
	struct student temp;
	char c;
	int aver[55];
	system("cls");
	for(i=1;i<=f.count;i++)
	{
	
		stu[i].aver=(stu[i].score1+stu[i].score2+stu[i].score3+stu[i].score4+stu[i].score5+stu[i].score6+stu[i].score7)/7;
	}
	for(i=1;i<=f.count;i++)
	for(j=1+i;j<=f.count;j++)
	{
		if(stu[i].aver<stu[j].aver)
		{
			temp=stu[i];
			stu[i]=stu[j];
			stu[j]=temp;
		}
	}
	printf("\tƽ��������\n");
	for(i=1;i<=f.count;i++)
	{
		printf("������%s ",stu[i].name);
		printf("ƽ���֣�%f\n",stu[i].aver); 
	}
	printf("������Y�������˵�\n") ;
	scanf("%c",&c);
	c=getchar();
	printf("\n");
	if(c=='y'||c=='Y')
	main();
}

void numsort(struct student stu[])
{
	typedef struct student str;
	str t;
	int  i,j;
	char c;
	system("cls");
	for(i=1;i<=f.count;i++)
	for(j=1+i;j<=f.count;j++)
	{
		if(stu[i].num>stu[j].num)
		{
			t=stu[i];
			stu[i]=stu[j];
			stu[j]=t;
		}
	}
	printf("\tѧ������\n");
	for(i=1;i<=f.count;i++)
	{
		printf("ѧ��:%d\\ ����:%s\\ �ɼ���%.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].score4,stu[i].score5,stu[i].score6,stu[i].score7);
	}
	printf("�����ɣ�������Y�������˵�\n");
	scanf("%c",&c);
	c=getchar();
	printf("\n");
	if(c=='y'||c=='Y')
	main();
} 


void search(struct student stu[])//��ѧ��������Ϣ 
{
	int i,u;
	char c;
	system("cls");
	printf("����ѧ��ѧ��:");
	scanf ("%d",&u);
	for(i=1;i<=f.count;i++)
	{
		if(u==stu[i].num)
		{
			printf("ѧ�ţ�%d\\ ������%s\\�ɼ��� %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].score4,stu[i].score5,stu[i].score6,stu[i].score7);
           break;
		}
	}
	printf("������ɣ��Ƿ��������y/n)");
	scanf("%c",&c);
		c=getchar();
		printf("\n");
		if(c=='Y'||c=='y')
		search(stu);
		else
		main();
 } 
 
 void search1(struct student stu[]) 
 {
 	int i;
	 char c,k[30];
	 system("cls");
	 printf("����ѧ������:");
	 scanf("%s",k);
	 for(i=1;i<=f.count;i++)
	 {
	 	if(strcmp(stu[i].name,k)==0)
	 	{
	 		printf("ѧ�ţ�%d\\ ������%s\\�ɼ��� %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].score4,stu[i].score5,stu[i].score6,stu[i].score7);
           break;
		 }
	 }
	 printf("������ɣ��Ƿ��������y/n)");
	scanf("%c",&c);
		c=getchar();
		printf("\n");
		if(c=='Y'||c=='y')
		search1(stu);
		else
		main();
 }
 
 void allsum(struct student stu[])
 {
 	int i;
 	int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0,sum6=0,sum7=0;
 	int aver1,aver2,aver3,aver4,aver5,aver6,aver7;
 	char c;
 	system("cls");
 	for(i=1;i<=f.count;i++)
 	{
 		sum1=sum1+stu[i].score1;
 		sum2=sum2+stu[i].score2;
 		sum3=sum3+stu[i].score3;
 		sum4=sum4+stu[i].score4;
 		sum5=sum5+stu[i].score5;
 		sum6=sum6+stu[i].score6;
 		sum7=sum7+stu[i].score7;
	 }
	 printf("ÿ�Ƴɼ��ܷ֣��ɼ�1: %d �ɼ�2: %d �ɼ�3: %d �ɼ�4: %d �ɼ�5: %d �ɼ�6: %d �ɼ�7: %d\n",sum1,sum2,sum3,sum4,sum5,sum6,sum7);
	 aver1=sum1/f.count;
	 aver2=sum2/f.count;
	 aver3=sum3/f.count;
	 aver4=sum4/f.count;
     aver5=sum5/f.count;
    aver6=sum6/f.count;
	 aver7=sum7/f.count;
	 printf("ÿ�Ƴɼ�ƽ���֣��ɼ�1: %d �ɼ�2: %d �ɼ�3: %d �ɼ�4: %d �ɼ�5: %d �ɼ�6: %d �ɼ�7: %d\n",aver1,aver2,aver3,aver4,aver5,aver6,aver7);
	 printf("�����ɣ�������Y�������˵�\n");
	 scanf("%c",&c);
	c=getchar();
	printf("\n");
	if(c=='y'||c=='Y')
	main();
	 
  } 
 
 void quit(struct student stu[])//�˳����� 
 {
 	char c;
 	system("cls");
 	printf("ȷ���˳�����y/n)");
	 scanf("%c",&c);
	 c=getchar();
	printf("\n");
	 if(c=='Y'||c=='y')
	 exit(0);//�˳� 
	 else main(); 
 }
