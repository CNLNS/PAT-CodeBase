#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
struct student//定义一个学生的结构体 
{
	int num;//学号 
	char name[20];//姓名 
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


void cin(struct student stu[]);//输入学生信息
void ssum(struct student stu[]);//求学生总分
void aver(struct student stu[]);//输出学生平均分
void aversort(struct student stu[]);//平均分排序输出 
void numsort(struct student stu[]);//按学号排序输出学生信息 
void search(struct student stu[]);//按学号搜索学生信息
void search1(struct student stu[]);//按姓名搜索学生信息 
void allsum(struct student stu[]);//输出每门功课总分与平均分
void quit(struct student stu[]);//退出程序


int main()
{
	int menu;
	system("cls"); 
	printf("\t学生成绩管理系统\n");
	printf("\t----主菜单----\n");
	printf("\t1.输入学生信息\n");
	printf("\t2.计算学生总分\n");
	printf("\t3.输出学生平均分\n");
	printf("\t4.按学号查找学生个人信息\n");
	printf("\t5.按平均分排序输出学生信息\n");
	printf("\t6.按学号排序输出学生信息\n");
	printf("\t7.按姓名查找学生个人信息\n");
	printf("\t8.输出每门功课总分与平均分\n");
	printf("\t0.退出系统\n"); 
	printf("\t请输入选项\n");
	scanf("%d",&menu);//输入选项 
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
		default:printf("失败\n");break;//输出失败的情况 
	 } 
}

void cin(struct student stu[])//输入学生信息 
{
	int i,n;
	char c;
	printf("请输入学生数量："); 
	scanf("%d",&n); 
	f.count=n;
	system("cls");//清屏
	for(i=1;i<=n;i++)
	{
		printf("输入学号:");
		scanf("%d",&stu[i].num);
		printf("输入姓名:");
		scanf("%s",&stu[i].name);
		printf("成绩一：");
		scanf("%f",&f.score1);
		stu[i].score1=f.score1;
		printf("成绩二：");
		scanf("%f",&f.score2);
		stu[i].score2=f.score2;
		printf("成绩三：");
		scanf("%f",&f.score3);
		stu[i].score3=f.score3;
		printf("成绩四：");
		scanf("%f",&f.score4);
		stu[i].score4=f.score4;
		printf("成绩五：");
		scanf("%f",&f.score5);
		stu[i].score5=f.score5;
		printf("成绩六：");
		scanf("%f",&f.score6);
		stu[i].score6=f.score6;
		printf("成绩七：");
		scanf("%f",&f.score7);
		stu[i].score7=f.score7;
	    }
		printf("输入完成,输入Y返回主菜单\n");
		scanf("%c",&c);//判断是否输出结束 
		c=getchar();//抵消空格影响 
		printf("\n");
		if(c=='Y'||c=='y')
		main(); //返回主菜单 
	
}

void ssum(struct student stu[])//求总分 
{
	int i;
	char c;
	float zf;
	system("cls");
	for(i=1;i<=f.count;i++)
	{
		zf=0;
		printf("姓名：%s ",stu[i].name);
		zf=stu[i].score1+stu[i].score2+stu[i].score3+stu[i].score4+stu[i].score5+stu[i].score6+stu[i].score7;
		printf("总分：%.2f\n",zf);
		if(stu[i].num=0) break;
	}
	printf("输出完成，输入Y返回菜单");
	scanf("%c",&c);
	c=getchar();
	printf("\n"); 
	if(c=='Y'||c=='y')
	main(); 
}

void aver(struct student stu[])//平均分 
{
	int i;
	char c;
	float aver[55];
	system("cls");
	for(i=1;i<=f.count;i++)
	{
		printf("姓名：%s :",stu[i].name);
		aver[i]=(stu[i].score1+stu[i].score2+stu[i].score3+stu[i].score4+stu[i].score5+stu[i].score6+stu[i].score7)/7;
	    printf("平均分：%.2f\n",aver[i]);
	}
	printf("输出完成，输入Y返回菜单"); 
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
	printf("\t平均分排名\n");
	for(i=1;i<=f.count;i++)
	{
		printf("姓名：%s ",stu[i].name);
		printf("平均分：%f\n",stu[i].aver); 
	}
	printf("请输入Y返回主菜单\n") ;
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
	printf("\t学号排序\n");
	for(i=1;i<=f.count;i++)
	{
		printf("学号:%d\\ 姓名:%s\\ 成绩：%.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].score4,stu[i].score5,stu[i].score6,stu[i].score7);
	}
	printf("输出完成，请输入Y返回主菜单\n");
	scanf("%c",&c);
	c=getchar();
	printf("\n");
	if(c=='y'||c=='Y')
	main();
} 


void search(struct student stu[])//按学号搜索信息 
{
	int i,u;
	char c;
	system("cls");
	printf("输入学生学号:");
	scanf ("%d",&u);
	for(i=1;i<=f.count;i++)
	{
		if(u==stu[i].num)
		{
			printf("学号：%d\\ 姓名：%s\\成绩： %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].score4,stu[i].score5,stu[i].score6,stu[i].score7);
           break;
		}
	}
	printf("搜索完成，是否继续？（y/n)");
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
	 printf("输入学生姓名:");
	 scanf("%s",k);
	 for(i=1;i<=f.count;i++)
	 {
	 	if(strcmp(stu[i].name,k)==0)
	 	{
	 		printf("学号：%d\\ 姓名：%s\\成绩： %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\\ %.2f\n",stu[i].num,stu[i].name,stu[i].score1,stu[i].score2,stu[i].score3,stu[i].score4,stu[i].score5,stu[i].score6,stu[i].score7);
           break;
		 }
	 }
	 printf("搜索完成，是否继续？（y/n)");
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
	 printf("每科成绩总分：成绩1: %d 成绩2: %d 成绩3: %d 成绩4: %d 成绩5: %d 成绩6: %d 成绩7: %d\n",sum1,sum2,sum3,sum4,sum5,sum6,sum7);
	 aver1=sum1/f.count;
	 aver2=sum2/f.count;
	 aver3=sum3/f.count;
	 aver4=sum4/f.count;
     aver5=sum5/f.count;
    aver6=sum6/f.count;
	 aver7=sum7/f.count;
	 printf("每科成绩平均分：成绩1: %d 成绩2: %d 成绩3: %d 成绩4: %d 成绩5: %d 成绩6: %d 成绩7: %d\n",aver1,aver2,aver3,aver4,aver5,aver6,aver7);
	 printf("输出完成，请输入Y返回主菜单\n");
	 scanf("%c",&c);
	c=getchar();
	printf("\n");
	if(c=='y'||c=='Y')
	main();
	 
  } 
 
 void quit(struct student stu[])//退出程序 
 {
 	char c;
 	system("cls");
 	printf("确定退出？（y/n)");
	 scanf("%c",&c);
	 c=getchar();
	printf("\n");
	 if(c=='Y'||c=='y')
	 exit(0);//退出 
	 else main(); 
 }
