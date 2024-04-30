#include<stdio.h>
#include<string.h>
#include<windows.h>
int n = 2, m = 21, m0 = 19;//n为表格内的位置，m为表格外的位置,m0为表格最底层位置
int pi[10] = { 0 }, n2 = 0;//判断是否添加新课程和增加的新课程数目
int pi1 = 0;//用于判断只有第一次填表n才加3
int m1 = 0;//用于统计新增学生人数
int option;//用于选择操作编号
void Delete()//刷新操作界面
{
	void gotoxy(int i, int j);
	int x, y;
	for (y = m; y < 50; y++)
	{
		for (x = 0; x < 110; x++)
		{
			gotoxy(x, y);
			printf(" ");
		}
	}
}
struct Course
{
public:
	char c1[30];
	char b1[10];

}pt[3] = { "高数","1001","英语","1002","程序设计","1003" }, pt1[5];
struct Student
{
public:
	char name[15];
	char num1[10];
	char Class[10];
	char major[30];
	/*char c1[30],c2[30],c3[30];*/
	/*char num2[15];*///课程编号
	float a1, a2, a3;
	/*char c4[30],c5[30];*/
	float a4, a5;
	float adds;
	/*char add1[20],add2[20],add[30];*/
}k1[3] = { {"张铭","001","一(4)","计算机",80,78,93,0,0,251},{"孙亿","002","一(4)","计算机",98,24,99,0,0,221},{"彭新","003","一(4)","计算机",80,88,50,0,0,218} }, k[50] = { 0 };
void chart(int t)//表格t表示行数
{
	printf("学生成绩管理系统\n");
	int i, j, k;
	for (i = 0; ; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("+—————");
		}
		printf("+\n");
		if (i == t)
		{
			break;
		}
		for (k = 0; k < 10; k++)
		{
			printf("|          ");
		}
		printf("|\n");
		if (i == 0)
		{
			for (k = 0; k < 10; k++)
			{
				printf("|          ");
			}
			printf("|\n");

		}
	}

}
void gotoxy(int i, int j)//移动
{
	COORD piot = { i,j };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), piot);

}
void show()//填表
{
	int i, j = 3;
	for (i = 0; i < 110; i++)
	{
		if (i == j)
		{
			switch (i)
			{
			case 3:gotoxy(i, 2); printf("姓名"); gotoxy(i, m0); printf("平均分"); break;
			case 14:gotoxy(i, 2); printf("学号"); gotoxy(i, m0); printf("———"); break;
			case 25:gotoxy(i, 2); printf("班级"); gotoxy(i, m0); printf("———"); break;
			case 36:gotoxy(i, 2); printf("专业"); gotoxy(i, m0); printf("———"); break;
			case 47:gotoxy(i, 2); printf("%s", pt[0].c1); gotoxy(i, 3); printf("%s", pt[0].b1); break;
			case 58:gotoxy(i, 2); printf("%s", pt[1].c1); gotoxy(i, 3); printf("%s", pt[1].b1); break;
			case 69:gotoxy(i, 2); printf("%s", pt[2].c1); gotoxy(i, 3); printf("%s", pt[2].b1); break;
			case 80:gotoxy(i, 2); printf("%s", pt1[0].c1); gotoxy(i, 3); printf("%s", pt1[0].b1); break;
			case 91:gotoxy(i, 2); printf("%s", pt1[1].c1); gotoxy(i, 3); printf("%s", pt1[1].b1); break;
			case 102:gotoxy(i, 2); printf("总分"); break;

			}
			j = j + 11;
		}
	}
	if (pi1 == 0)
	{
		n = n + 3;
	}//只有第一次运行才加3 
	pi1 = 1;
}
void put(struct Student* p, int t)//输出单个学生数据
{
	(p + t)->adds = (p + t)->a1 + (p + t)->a2 + (p + t)->a3 + (p + t)->a4 + (p + t)->a5;
	int i, j = 3;
	for (i = 0; i < 110; i++)
	{
		if (i == j)
		{
			switch (i)
			{
			case 3:gotoxy(i, n); printf("%s", (p + t)->name); break;
			case 14:gotoxy(i, n); printf("%s", (p + t)->num1); break;
			case 25:gotoxy(i, n); printf("%s", (p + t)->Class); break;
			case 36:gotoxy(i, n); printf("%s", (p + t)->major); break;
			case 47:gotoxy(i, n); printf("%.2f", (p + t)->a1); break;
			case 58:gotoxy(i, n); printf("%.2f", (p + t)->a2); break;
			case 69:gotoxy(i, n); printf("%.2f", (p + t)->a3); break;
			case 80:gotoxy(i, n); printf("%.2f", (p + t)->a4); break;
			case 91:gotoxy(i, n); printf("%.2f", (p + t)->a5); break;
			case 102:gotoxy(i, n); printf("%.2f", (p + t)->adds); break;

			}
			j = j + 11;
		}
	}
	n = n + 2;
	(p + t)->adds = (p + t)->a1 + (p + t)->a2 + (p + t)->a3 + (p + t)->a4 + (p + t)->a5;
}
void add1(struct Course* p)//增加课程
{
	void add2();
	void ave();
	void operate();
	pi[n2] = 1;//标志新增课程
	int j, ft = m1, i;
	printf("请输入要增加的课程:");
	scanf("%s", (p + n2)->c1);
	printf("请输入%s的课程编码:", (p + n2)->c1);
	scanf("%s", (p + n2)->b1);
	printf("请按学号输入学生成绩:\n");
	if (n2 == 0)
	{
		for (j = 0; j < 3; j++)
		{
			printf("请输入%s %s的%s分数:", (k1 + j)->num1, (k1 + j)->name, (p + n2)->c1);
			scanf("%f", &(k1 + j)->a4);
		}
		j = 0;
		while (ft)
		{
			printf("请输入%s %s的%s分数:", (k + j)->num1, (k + j)->name, (p + n2)->c1);
			scanf("%f", &(k + j)->a4);
			j++; ft--;
		}
	}
	if (n2 == 1)
	{
		for (j = 0; j < 3; j++)
		{
			printf("请输入%s %s的%s分数:", (k1 + j)->num1, (k1 + j)->name, (p + n2)->c1);
			scanf("%f", &(k1 + j)->a5);
		}
		j = 0;
		while (ft)
		{
			printf("请输入%s %s的%s分数:", (k + j)->num1, (k + j)->name, (p + n2)->c1);
			scanf("%f", &(k + j)->a5);
			j++; ft--;
		}
	}
	show();
	n = 5;
	for (int i = 0; i < 3; i++)
	{
		put(k1, i);
	}//输出初始化
	ft = m1; i = 0;
	while (ft)
	{
		put(k, i);
		i++; ft--;
	}
	n2 = n2 + 1;//记录新增课程数目
	ave();
	Delete(); gotoxy(0, m);
	printf("\n操作完毕\n");
	operate();
}
void add2()//增加学生人数
{
	void ave();
	void operate();
	int t = 0, p, i;
	printf("学生姓名:");
	scanf("%s", (k + m1)->name);
	printf("学生学号:");
	scanf("%s", (k + m1)->num1);
	for (i = -3; i < m1; i++)
	{
		if (i < 0)
		{
			if (strcmp(k1[i + 3].num1, (k + m1)->num1) == 0)
			{
				Delete(); gotoxy(0, m);
				printf("学生学号出现重复,请重新输入学生信息\n***********************\n");
				gotoxy(0, m + 3);
				add2();
			}
		}
		else
		{
			if (strcmp(k[i].num1, (k + m1)->num1) == 0)
			{
				Delete(); gotoxy(0, m);
				printf("学生学号出现重复,请重新输入学生信息\n***********************\n");
				gotoxy(0, m + 3);
				add2();
			}
		}
	}
	printf("学生班级:");
	scanf("%s", (k + m1)->Class);
	printf("学生专业:");
	scanf("%s", (k + m1)->major);
	printf("高数分数:");
	scanf("%f", &(k + m1)->a1);
	printf("英语分数:");
	scanf("%f", &(k + m1)->a2);
	printf("程序设计分数:");
	scanf("%f", &(k + m1)->a3);
	p = 0;
	for (t = 0;; t++)
	{
		if (pi[t] == 1 && p == 0)
		{
			printf("%s分数:", (pt1 + t)->c1); scanf("%f", &(k + m1)->a4); p = 1;
		}
		else if (pi[t] == 1 && p == 1)
		{
			printf("%s分数:", (pt1 + t)->c1); scanf("%f", &(k + m1)->a5); p = 2;
		}
		else
		{
			break;
		}
	}
	(k + m1)->adds = (k + m1)->a1 + (k + m1)->a2 + (k + m1)->a3 + (k + m1)->a4 + (k + m1)->a5;
	put(k, m1);
	m1 = m1 + 1;//新增学生人数
	ave();
	Delete(); gotoxy(0, m);
	printf("\n操作完毕\n");
	operate();
}
void ave()//求平均数
{
	float mean[10] = { 0 };//mean[1]高数,mean[2]英语,mean[3]程序设计,mean[4]新增1,mean[5]新增2,mean[0]总分;
	int i;
	for (i = -3; i < m1; i++)
	{
		if (i < 0)
		{
			mean[1] = mean[1] + (k1 + i + 3)->a1; mean[2] = mean[2] + (k1 + i + 3)->a2; mean[3] = mean[3] + (k1 + i + 3)->a3; mean[4] = mean[4] + (k1 + i + 3)->a4; mean[5] = mean[5] + (k1 + i + 3)->a5;
		}
		else
		{
			mean[1] = mean[1] + (k + i)->a1; mean[2] = mean[2] + (k + i)->a2; mean[3] = mean[3] + (k + i)->a3; mean[4] = mean[4] + (k + i)->a4; mean[5] = mean[5] + (k + i)->a5;
		}

	}
	mean[0] = mean[1] + mean[2] + mean[3] + mean[4] + mean[5];
	gotoxy(47, m0);
	printf("%.2f", mean[1] / (m1 + 3));
	gotoxy(58, m0);
	printf("%.2f", mean[2] / (m1 + 3));
	gotoxy(69, m0);
	printf("%.2f", mean[3] / (m1 + 3));
	gotoxy(80, m0);
	printf("%.2f", mean[4] / (m1 + 3));
	gotoxy(91, m0);
	printf("%.2f", mean[5] / (m1 + 3));
	gotoxy(102, m0);
	printf("%.2f", mean[0] / (m1 + 3));

}
void M()
{
	void operate();
	float max = k1[0].adds, min = k1[2].adds;
	int M0[10], M1[10];
	int i, j = 0, t = 0;
	int p = 0, p1 = 0;
	for (i = 0; i < m1; i++)
	{
		if ((k + i)->adds > max)
		{
			max = (k + i)->adds; p = 1;
		}
		if ((k + i)->adds < min)
		{
			min = (k + i)->adds; p1 = 1;
		}
	}
	printf("最高分:%.2f\n最低分:%.2f\n", max, min);
	printf("******************************\n");
	operate();



}
void change()//通过学号修改学生信息
{
	void operate();
	char str[10];
	char str1[10];
	int i, num;
	int option2;
	int ft = m1;
	printf("请输入要修改的学生学号:");
	scanf("%s", str);
	for (i = -3; i < m1; i++)
	{
		if (i < 0)
		{
			if (strcmp(k1[i + 3].num1, str) == 0)
			{
				num = i; break;
			}
		}
		else
		{
			if (strcmp(k[i].num1, str) == 0)
			{
				num = i; break;
			}
		}
	}
	printf("请选择要修改的信息(输入以下信息前编号即可):\n1、姓名\n2、学号\n3、班级\n4、专业\n5、高数分数\n6、英语分数\n7、程序设计分数\n");
	for (i = 0; i < n2; i++)
	{
		if (i == 0)
		{
			printf("8、");
		}
		else
		{
			printf("9、");
		}
		printf("%s分数\n", (pt1 + i)->c1);
	}
	printf("**************************\n");
	printf("请输入编号:");
	scanf("%d", &option2);
	printf("**************************\n");
	printf("请输入修改后的信息:");
	float nn;
	switch (option2)
	{
	case 1:if (num < 0) { scanf("%s", (k1 + num + 3)->name); }
		  else { scanf("%s", (k + num)->name); }break;
	case 2:scanf("%s", str1);
		for (i = -3; i < m1; i++)
		{
			if (i < 0)
			{
				if (strcmp((k1 + i + 3)->num1, str1) == 0 && i != num)
				{
					Delete(); gotoxy(0, m);
					printf("学生学号出现重复,请重新修改学生信息\n***********************\n");
					gotoxy(0, m + 3);
					change();
				}
			}
			else
			{
				if (strcmp((k + i)->num1, str1) == 0 && i != num)
				{
					Delete(); gotoxy(0, m);
					printf("学生学号出现重复,请重新修改学生信息\n***********************\n");
					gotoxy(0, m + 3);
					change();
				}
			}
		}if (num < 0) { strcpy((k1 + num + 3)->num1, str1); }
		else { strcpy((k + num)->num1, str1); }break;
	case 3:if (num < 0) { scanf("%s", (k1 + num + 3)->Class); }
		  else { scanf("%s", (k + num)->Class); }break;
	case 4:if (num < 0) { scanf("%s", (k1 + num + 3)->major); }
		  else { scanf("%s", (k + num)->major); }break;
	case 5:scanf("%f", &nn); if (num < 0) { (k1 + num + 3)->a1 = nn; }
		  else { (k + num)->a1 = nn; }break;
	case 6:scanf("%f", &nn); if (num < 0) { (k1 + num + 3)->a2 = nn; }
		  else { (k + num)->a2 = nn; }break;
	case 7:scanf("%f", &nn); if (num < 0) { (k1 + num + 3)->a3 = nn; }
		  else { (k + num)->a3 = nn; }break;
	case 8:scanf("%f", &nn); if (num < 0) { (k1 + num + 3)->a4 = nn; }
		  else { (k + num)->a4 = nn; }break;
	case 9:scanf("%f", &nn); if (num < 0) { (k1 + num + 3)->a5 = nn; }
		  else { (k + num)->a5 = nn; }break;
	}
	n = 5;
	for (i = 0; i < 3; i++)
	{
		put(k1, i);
	}//输出初始化
	ft = m1; i = 0;
	while (ft)
	{
		put(k, i);
		i++; ft--;
	}
	ave();
	Delete(); gotoxy(0, m);
	printf("\n操作完毕\n");
	operate();
}
//void cancel()
//{
//	void operate();
//	gotoxy(0,m);
//	operate();
//
//}
void get()//获取学生信息
{
	void operate();
	char str[10];
	int i, j = 3, num;
	int option2;
	printf("请输入要查询的学生学号:");
	scanf("%s", str);
	for (i = -3; i < m1; i++)
	{
		if (i < 0)
		{
			if (strcmp(k1[i + 3].num1, str) == 0)
			{
				num = i; break;
			}
		}
		else
		{
			if (strcmp(k[i].num1, str) == 0)
			{
				num = i; break;
			}
		}
	}
	printf("学生信息如下:");
	gotoxy(0, m + 2);
	chart(2);
	for (i = 0; i < 110; i++)
	{
		if (i == j)
		{
			switch (i)
			{
			case 3:gotoxy(i, m + 4); printf("姓名"); gotoxy(i, m0); break;
			case 14:gotoxy(i, m + 4); printf("学号"); gotoxy(i, m0); break;
			case 25:gotoxy(i, m + 4); printf("班级"); gotoxy(i, m0); break;
			case 36:gotoxy(i, m + 4); printf("专业"); gotoxy(i, m0); break;
			case 47:gotoxy(i, m + 4); printf("%s", pt[0].c1); gotoxy(i, m + 5); printf("%s", pt[0].b1); break;
			case 58:gotoxy(i, m + 4); printf("%s", pt[1].c1); gotoxy(i, m + 5); printf("%s", pt[1].b1); break;
			case 69:gotoxy(i, m + 4); printf("%s", pt[2].c1); gotoxy(i, m + 5); printf("%s", pt[2].b1); break;
			case 80:gotoxy(i, m + 4); printf("%s", pt1[0].c1); gotoxy(i, m + 5); printf("%s", pt1[0].b1); break;
			case 91:gotoxy(i, m + 4); printf("%s", pt1[1].c1); gotoxy(i, m + 5); printf("%s", pt1[1].b1); break;
			case 102:gotoxy(i, m + 4); printf("总分"); break;

			}
			j = j + 11;
		}
	}

	gotoxy(3, m + 7); if (num < 0) { printf("%s", (k1 + num + 3)->name); }
	else { printf("%s", (k + num)->name); }
	gotoxy(14, m + 7); if (num < 0) { printf("%s", (k1 + num + 3)->num1); }
	else { printf("%s", (k + num)->num1); }
	gotoxy(25, m + 7); if (num < 0) { printf("%s", (k1 + num + 3)->Class); }
	else { printf("%s", (k + num)->Class); }
	gotoxy(36, m + 7); if (num < 0) { printf("%s", (k1 + num + 3)->major); }
	else { printf("%s", (k + num)->major); }
	gotoxy(47, m + 7); if (num < 0) { printf("%.2f", (k1 + num + 3)->a1); }
	else { printf("%.2f", (k + num)->a1); }
	gotoxy(58, m + 7); if (num < 0) { printf("%.2f", (k1 + num + 3)->a2); }
	else { printf("%.2f", (k + num)->a2); }
	gotoxy(69, m + 7); if (num < 0) { printf("%.2f", (k1 + num + 3)->a3); }
	else { printf("%.2f", (k + num)->a3); }
	gotoxy(80, m + 7); if (num < 0) { printf("%.2f", (k1 + num + 3)->a4); }
	else { printf("%.2f", (k + num)->a4); }
	gotoxy(91, m + 7); if (num < 0) { printf("%.2f", (k1 + num + 3)->a5); }
	else { printf("%.2f", (k + num)->a5); }
	gotoxy(102, m + 7); if (num < 0) { printf("%.2f", (k1 + num + 3)->adds); }
	else { printf("%.2f", (k + num)->adds); }
	printf("\n\n******************************\n");
	operate();







}
void operate()//操作函数
{
	printf("(输入操作编号按下Enter即可进行操作)\n请选择接下来的操作:\n0、关闭成绩管理系统\n1、增加一门课程\n2、增加一名学生的信息\n3、查看最高分和最低分信息\n4、修改学生信息\n5、查询学生个人信息\n请输入操作编号:");
	scanf("%d", &option);
	switch (option)
	{
	case 0:exit(0); break;
	case 1:Delete(); gotoxy(0, m); add1(pt1); break;
	case 2:Delete(); gotoxy(0, m); add2(); break;
	case 3:Delete(); gotoxy(0, m); M(); break;
	case 4:Delete(); gotoxy(0, m); change(); break;
	case 5:Delete(); gotoxy(0, m); get(); break;
	default:Delete(); gotoxy(0, m); printf("操作代码有误,请检查后重新输入\n"); operate();

	}

}
int main()
{
	chart(9);
	show();
	for (int i = 0; i < 3; i++)
	{
		put(k1, i);
	}//输出3个已初始化的学生数据
	ave();
	gotoxy(0, m);
	operate();
	getchar(); getchar();
	return 0;
}