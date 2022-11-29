#pragma once;
#include <graphics.h>
#include <stdio.h>
#include<iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include<iomanip>
#include<string>
using namespace std;
struct student
{
	char id[20];//学号
	char name[20];//姓名
	char age[5];//年龄
	char sex[5];//性别
	char thought[6];
	char academic[6];
	char style[6];
	char total[6];
	student* next;//指向下一个结点的指针
};
student* head = new student;//头结点,不存储信息
void Help_message();//帮助界面
void refresh_message();//刷新界面
void my_delete();//删除链表
void Main_interface();//主界面函数
void Sort_interface();//排序界面
void browse_interface();//浏览信息界面
void serch_interface(); //查询界面
void Set_message();//建立学生信息
void browse_message();//浏览信息
void read_file();//读取文件
void Input_file();//录入文件
void No_interface();//没有找到信息界面
void Sort_message();//排序
void Serch_message();//查询信息
void sort_id();//学号排序
void sort_name();//姓名排序
void sort_total();//综测排序
void funish_sort();//排序完成界面
void funish_change();//修改完成界面
void funish_delete();//删除完成界面
void no_sortinterface();//无需排序界面
void id_error_interface();//学号错误界面
void age_error_interface();//年龄错误界面
int judge_id(char id[]);//判断学号是否重复
char* extract_num(char* s);//从字符串中提取数字函数
void change_message();//修改信息
void delete_message();//删除信息
void sub_list();//处理链表空元素
student* serch(char str[]);//查找
void funish_delete()//删除完成界面
{
	BeginBatchDraw();//开始作图
	IMAGE img;
	loadimage(&img, "./123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "楷体");
	settextcolor(GREEN);
	outtextxy(495, 150, "已删除成功");
	EndBatchDraw();//作图完成
	Sleep(1000);
}
student* serch(char str[])//查找相同的学号或姓名
{
	student* p = head;
	while (p->next)
	{
		if (strcmp(p->next->id, str) == 0)//比较下一结点的if是否相同
			return p->next;//相同则返回下一个结点的地址
		if (strcmp(p->next->name, str) == 0)
			return p->next;
		p = p->next;
	}
	return nullptr;//学号和姓名均未找到则返回空地址
}
void delete_message()//删除信息
{
	char str[20];
	InputBox(str, 20, "请输入要删除的学生学号");
	student* p = head;//指向链表头结点
	student* t = nullptr;//用来释放结点
	while (p->next)//循环链表
	{
		if (strcmp(p->next->id, str) == 0)//与p指向的结点的下一个结点的id对比
		{
			HWND wnd;
			wnd = GetHWnd();
			int a = MessageBox(wnd, "确定删除该数据吗?", "我是窗口", MB_OKCANCEL);
			if (a == IDOK)
			{
				t = p->next;//让t指向p的下一个结点，也就是需要删除的结点
				p->next = p->next->next;//更新p指向结点的next指针域，改为下下应该结点地址
				delete(t);
				funish_delete();//删除完成界面
				Main_interface();
				return;
			}
			if (a == IDCANCEL)
			{
				Main_interface();
				return;
			}
		}
		p = p->next;
	}
	No_interface();
	Main_interface();
}
void change_message()//修改信息
{
	char str[20];
	InputBox(str, 20, "请输入要修改的学生姓名或学号");
	student* t = serch(str);
	if (t == nullptr)
	{
		No_interface();//没有找到信息界面
		Main_interface();
		return;
	}
	InputBox(t->id, 20, "请输入修改后学号");
	InputBox(t->name, 20, "请输入修改后姓名");
	InputBox(t->age, 5, "请输入修改后年龄");
	InputBox(t->sex, 5, "请输入修改后性别");
	InputBox(t->thought, 6, "请输入修改后学业分");
	InputBox(t->academic, 6, "请输入修改后思想分");
	InputBox(t->style, 6, "请输入修改后文体分");
	InputBox(t->total, 6, "请输入修改后综测分");
	funish_change();//修改完成界面
	Main_interface();
}
void sub_list()//处理链表
{
	student* p = head;//p指向头结点
	while (p->next)//循环处理每一个结点
	{
		if (strcmp(p->next->name, "") == 0)//比较，若为控则为真
			strcpy_s(p->next->name, "未知");//为空，则将其标为未知
		if (strcmp(p->next->age, "") == 0)
			strcpy_s(p->next->age, "未知");
		if (strcmp(p->next->id, "") == 0)
			strcpy_s(p->next->id, "未知");
		if (strcmp(p->next->sex, "") == 0)
			strcpy_s(p->next->sex, "未知");
		if (strcmp(p->next->thought, "") == 0)
			strcpy_s(p->next->thought, "未知");
		if (strcmp(p->next->academic, "") == 0)
			strcpy_s(p->next->academic, "未知");
		if (strcmp(p->next->style, "") == 0)
			strcpy_s(p->next->style, "未知");
		if (strcmp(p->next->total, "") == 0)
			strcpy_s(p->next->total, "未知");
		p = p->next;
	}
}
void id_error_interface()//学号错误界面
{
	BeginBatchDraw();//开始作图
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "楷体");
	settextcolor(RED);
	outtextxy(345, 150, "学号重复，请重新输入！");
	EndBatchDraw();
	Sleep(1000);//执行挂起一段时间，也就是等待一段时间在继续执行，windows下为1000毫秒，即2秒
	putimage(0, 0, &img);
}
void age_error_interface()//年龄错误界面
{
	BeginBatchDraw();//开始作图
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "楷体");
	settextcolor(RED);
	outtextxy(345, 150, "年龄错误，请重新输入！");
	EndBatchDraw();
	Sleep(1000);
	putimage(0, 0, &img);
}
int judge_id(char id[])//判断学号是否重复
{
	student* p = head;
	while (p->next)
	{
		if (strcmp(p->next->id, id) == 0)
			return 1;//找到重复返回1
		p = p->next;
	}
	return 0;
}
char* extract_num(char* s)//从字符串中提取数字函数
{
	int length = strlen(s);
	//cout << length << endl;
	char* str = new char[length];
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')//只有0-9的数字会被记录下来。
		{
			str[j++] = s[i];
		}
	}
	return str;
}
void no_sortinterface()//无需排序界面
{
	BeginBatchDraw();//开始作图
	settextstyle(50, 0, "楷体");
	settextcolor(GREEN);
	outtextxy(395, 150, "数据太少，无需排序");
	EndBatchDraw();
	Sleep(1000);
}
void funish_sort()//排序完成界面
{
	BeginBatchDraw();//开始作图
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "楷体");
	settextcolor(GREEN);
	outtextxy(495, 150, "已完成排序");
	EndBatchDraw();//作图完成
	Sleep(1000);
}
void funish_change()//修改完成界面
{
	BeginBatchDraw();//开始作图
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "楷体");
	settextcolor(GREEN);
	outtextxy(495, 150, "已修改完成");
	EndBatchDraw();//作图完成
	Sleep(1000);
}
void sort_id()//学号排序
{
	student* p = head;
	int count = 0;
	while (1)
	{
		p = head;
		count = 0;//用来记录在一次遍历过程中元素交换的次数
		while (p->next->next)
		{
			if (atol(p->next->id) > atol(p->next->next->id))
			{
				student* t1 = p->next;
				student* t2 = p->next->next;
				p->next = p->next->next;
				t1->next = t2->next;
				p->next->next = t1;
				count++;//每交换一次+1
			}
			p = p->next;
		}
		if (count == 0)//如果在一次遍历后没有交换元素，表示已经排好，退出循环
			break;
	}
}
void sort_name()//姓名排序
{
	student* p = head;
	int count = 0;
	while (1)
	{
		count = 0;//用来记录在一次遍历过程中元素交换的次数
		p = head;
		while (p->next->next)
		{
			if (strcmp(p->next->name, p->next->next->name) > 0)
			{
				student* t1 = p->next;
				student* t2 = p->next->next;
				p->next = p->next->next;
				t1->next = t2->next;
				p->next->next = t1;
				count++;//每交换一次+1
			}
			p = p->next;
		}
		if (count == 0)//如果在一次遍历后没有交换元素，表示已经排好，退出循环
			break;
	}
}
void sort_total()//按综测成绩排序
{
	student* p = head;
	int count = 0;
	while (1)
	{
		p = head;
		count = 0;//用来记录在一次遍历过程中元素交换的次数
		while (p->next->next)
		{
			if (atol(p->next->total) < atol(p->next->next->total))
			{
				student* t1 = p->next;
				student* t2 = p->next->next;
				p->next = p->next->next;
				t1->next = t2->next;
				p->next->next = t1;
				count++;//每交换一次+1
			}
			p = p->next;
		}
		if (count == 0)//如果在一次遍历后没有交换元素，表示已经排好，退出循环
			break;
	}
}
void No_interface()//没有找到信息界面函数
{
	BeginBatchDraw();//开始作图
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "楷体");
	settextcolor(RED);
	outtextxy(445, 150, "没有查到该信息");
	EndBatchDraw();
	Sleep(2000);
}
void read_file()//读取文件
{
	head->next = nullptr;//初始化链表，刚开始为空表
	ifstream in("student_message1.txt", ios::in);
	if (!in)
	{
		cout << "打开文件失败" << endl;
		exit(0);
	}
	student* p = head;//p指向头结点，p是指针
	while (!in.eof())//判断文件是否为空
	{
		student* t = new student;//申请一个新节点t，t是指针
		in >> t->id;
		in >> t->name;
		in >> t->age;
		in >> t->sex;
		in >> t->thought;
		in >> t->academic;
		in >> t->style;
		in >> t->total;
		if (in.eof())//如果文件读取到末尾，退出循环
			break;
		t->next = nullptr;
		p->next = t;//让头结点的指针域指向新生成的结点t
		p = p->next;//让p指向尾结点
	}
	in.close();
}
void Input_file()//写入文件
{
	ofstream out("student_message1.txt", ios::out);
	if (!out)
	{
		cout << "文件打开失败" << endl;
		exit(0);
	}
	sub_list();//处理链表空元素
	student* p = head;
	while (p->next)
	{
		out << p->next->id << "\t"
			<< p->next->name << "\t"
			<< p->next->age << "\t"
			<< p->next->sex << "\t"
			<< p->next->thought << "\t"
			<< p->next->academic << "\t"
			<< p->next->style << "\t"
			<< p->next->total << "\t"
			<< endl;
		p = p->next;
	}
	out.close();
}
void serch_interface()//查询界面
{
	BeginBatchDraw();//开始绘图
	//第一个按钮
	setcolor(WHITE);
	fillrectangle(470, 150, 770, 200);
	settextstyle(40, 0, "楷体");
	setcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 155, "学号查询");
	//第二个按钮
	setcolor(WHITE);
	fillrectangle(470, 210, 770, 260);
	settextstyle(40, 0, "楷体");
	setcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 215, "姓名查询");
	//第三个按钮
	setcolor(WHITE);
	fillrectangle(470, 270, 770, 320);
	settextstyle(40, 0, "楷体");
	setbkmode(TRANSPARENT);
	setcolor(GREEN);
	outtextxy(580, 275, "返回");
	EndBatchDraw();
}
void browse_interface()//浏览信息界面
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(30, 0, "黑体");
	settextcolor(BLACK);
	outtextxy(40, 0, "按ESC键返回");
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	//画表格
	line(40, 40, 40, 640);//画竖线
	line(120, 40, 120, 640);//姓名右
	line(180, 40, 180, 640);//性别右
	line(240, 40, 240, 640);//年龄右
	line(380, 40, 380, 640);//学号右
	line(540, 40, 540, 640);//思想右
	line(700, 40, 700, 640);//学业右
	line(860, 40, 860, 640);//文体右
	line(1020, 40, 1020, 640);//综测右
	EndBatchDraw();

	for (int y = 40; y <= 640; y += 30)
	{
		line(40, y, 1020, y);
	}
	settextstyle(20, 0, "楷体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(45, 45, "姓名");
	outtextxy(125, 45, "性别");
	outtextxy(185, 45, "年龄");
	outtextxy(245, 45, "学号");
	outtextxy(385, 45, "思想分");
	outtextxy(545, 45, "学业分");
	outtextxy(705, 45, "文体分");
	outtextxy(865, 45, "综测分");
}
void Sort_interface()//排序界面
{

	BeginBatchDraw();
	//第一个按钮
	setcolor(WHITE);
	fillrectangle(470, 150, 770, 200);
	settextstyle(40, 0, "楷体");
	setcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(520, 155, "按学号排序");
	//第二个按钮
	setcolor(WHITE);
	fillrectangle(470, 210, 770, 260);
	settextstyle(40, 0, "楷体");
	setcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(520, 215, "按姓名排序");
	//第三个按钮
	setcolor(WHITE);
	fillrectangle(470, 270, 770, 320);
	settextstyle(40, 0, "楷体");
	setbkmode(TRANSPARENT);
	setcolor(GREEN);
	outtextxy(480, 275, "按综测成绩排序");
	//第四个按钮
	setcolor(WHITE);
	fillrectangle(470, 330, 770, 380);
	settextstyle(40, 0, "楷体");
	setbkmode(TRANSPARENT);
	setcolor(GREEN);
	outtextxy(580, 335, "返回");
	EndBatchDraw();
}
void Main_interface()//主界面
{
	IMAGE img;
	loadimage(&img, "./123.jpg", 1240, 680);//加载图片
	putimage(0, 0, &img);//设置图片背景
	BeginBatchDraw();//这个函数用于开始批量绘图。执行后，任何绘图操作都将暂时不输出到绘图窗口上
	//直到执行 FlushBatchDraw 或 EndBatchDraw 才将之前的绘图输出。
	//设置标题
	settextstyle(50, 0, "微软黑体");//设置文本高度、宽度、字体
	settextcolor(BLUE);//设置文字颜色
	setbkmode(TRANSPARENT);//这个函数用于设置当前设备图案填充和文字输出时的背景模式，这里的设置是透明的
	outtextxy(440, 20, "学生信息管理系统");//用于在指定位置输出字符串
	//设置第零个按钮
	setcolor(WHITE);//这个函数用于设置当前绘图前景色为白色
	fillrectangle(520, 90, 720, 140);//这个函数用于画有边框的填充矩形。
	settextstyle(40, 0, "楷体");
	settextcolor(GREEN);//当前文字颜色
	setbkmode(TRANSPARENT);
	outtextxy(540, 95, "刷新信息");
	//设置第一个按钮
	setcolor(WHITE);//这个函数用于设置当前绘图前景色为白色
	fillrectangle(520, 150, 720, 200);//这个函数用于画有边框的填充矩形。
	settextstyle(40, 0, "楷体");
	settextcolor(GREEN);//当前文字颜色
	setbkmode(TRANSPARENT);
	outtextxy(540, 155, "录入信息");
	//设置第二个按钮
	setcolor(WHITE);
	fillrectangle(520, 210, 720, 260);
	settextstyle(40, 0, "楷体");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 215, "浏览信息");
	//设置第三个按钮
	setcolor(WHITE);
	fillrectangle(520, 270, 720, 320);
	settextstyle(40, 0, "楷体");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 275, "查询信息");
	//设置第四个按钮
	setcolor(WHITE);
	fillrectangle(520, 330, 720, 380);
	settextstyle(40, 0, "楷体");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(580, 335, "排序");
	//设置第五个按钮
	setcolor(WHITE);
	fillrectangle(520, 390, 720, 440);
	settextstyle(40, 0, "楷体");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 395, "修改信息");
	//设置第五个按钮
	setcolor(WHITE);
	fillrectangle(520, 450, 720, 500);
	settextstyle(40, 0, "楷体");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 455, "删除信息");
	//设置第六个按钮
	setcolor(WHITE);
	fillrectangle(520, 510, 720, 560);
	settextstyle(40, 0, "楷体");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(580, 515, "退出");
	//设置第七个按钮
	setcolor(WHITE);
	fillrectangle(520, 570, 720, 620);
	settextstyle(40, 0, "楷体");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(580, 575, "帮助");

	EndBatchDraw();
}
void Set_message()//建立学生信息
{
	student* p = head;//定义结构体指针p指向头结点
	while (p->next)//循环体实现让p指向尾结点
	{
		p = p->next;
	}
	while (1)
	{
		student* t = new student;//申请一个结点，并让t指向
		while (1)
		{
			InputBox(t->id, 20, "请输入学号");//这个函数用于以对话框形式获取用户输入。
			int a = judge_id(t->id);//函数判断学号是否重复，重复返回1，没有返回0
			if (a == 0)//没有重复退出while语句体
				break;
			id_error_interface();//有重复则执行错误界面
		}
		InputBox(t->name, 20, "请输入姓名");
		while (1)
		{
			InputBox(t->age, 5, "请输入年龄");
			if (atoi(t->age) >= 10 && atoi(t->age) <= 100)//在 stdlib.h 中 atoi 函数,可用于将 char 字符串转为 int 整数类型
				break;
			age_error_interface();//若年龄不在10到100报错
		}
		InputBox(t->sex, 5, "请输入性别");
		InputBox(t->thought, 6, "请输入思想分");
		InputBox(t->academic, 6, "请输入学业分");
		InputBox(t->style, 6, "请输入思想分");
		InputBox(t->total, 6, "请输入综测分");
		t->next = nullptr;//使新结点的指针域为空
		p->next = t;
		p = p->next;//p指向新生成的结点，即尾结点
		HWND hwnd = GetHWnd();//这个函数用于获取绘图窗口句柄。
		int is_ok = MessageBox(hwnd, "是否继续创建?", "我是窗口", MB_OKCANCEL);//确定取消
		if (is_ok == IDCANCEL)//取消被选
		{
			Main_interface();//返回主界面
			break;
		}
	}
}
void browse_message()//浏览信息
{
	browse_interface();//浏览信息界面
	student* p = head;
	int y = 80;
	while (p->next)
	{
		settextstyle(20, 0, "楷体");
		settextcolor(BLACK);
		outtextxy(45, y, p->next->name);
		outtextxy(125, y, p->next->sex);
		outtextxy(185, y, p->next->age);
		outtextxy(245, y, p->next->id);
		outtextxy(385, y, p->next->thought);
		outtextxy(545, y, p->next->academic);
		outtextxy(705, y, p->next->style);
		outtextxy(865, y, p->next->total);
		y += 30;
		p = p->next;
	}
	while (1)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			Main_interface();//退出前调用主界面函数
			break;
		}
	}
}
void Serch_message()//查询信息
{
	serch_interface();//查询界面
	char str[20];
	student* t = nullptr;//定义对象t为空
	ExMessage ma;//这个结构体用于保存鼠标消息
	while (1)
	{
		ma = getmessage(EM_MOUSE);//获取一个鼠标信息
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 150 && ma.y <= 200)//学号查询按钮
		{
			setlinecolor(RED);
			rectangle(470, 150, 770, 200);
			if (ma.message == WM_LBUTTONDOWN)
			{
				InputBox(str, 20, "请输入要查找的学生学号");
				t = serch(str);//查找相同学号或姓名，返回该结点的地址给t
				break;//退出
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 150, 770, 200);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 210 && ma.y <= 260)//名字查询按钮
		{
			setlinecolor(RED);
			rectangle(470, 210, 770, 260);
			if (ma.message == WM_LBUTTONDOWN)
			{
				InputBox(str, 20, "请输入要查找的学生姓名");
				t = serch(str);//查找相同学号或姓名，返回该结点的地址给t
				break;//退出
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 210, 770, 260);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 270 && ma.y <= 320)//返回按钮
		{
			setlinecolor(RED);
			rectangle(470, 270, 770, 320);
			if (ma.message == WM_LBUTTONDOWN)
			{
				Main_interface();//返回主函数前调用主函数界面
				return;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 270, 770, 320);
		}

	}
	if (t != nullptr)//为真则说明找到了学生信息
	{
		browse_interface();//浏览信息界面
		settextstyle(20, 0, "楷体");
		settextcolor(BLACK);
		outtextxy(60, 80, t->name);
		outtextxy(130, 80, t->sex);
		outtextxy(190, 80, t->age);
		outtextxy(250, 80, t->id);
		outtextxy(390, 80, t->thought);
		outtextxy(505, 80, t->academic);
		outtextxy(885, 80, t->style);
		outtextxy(1010, 80, t->total);
		while (1)
		{
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)//等待按键ESC，否则一直sleep（处于暂停状态）
			{
				Main_interface();//返回主函数前调用主函数界面
				return;
			}
		}
	}
	No_interface();//没有查到信息界面	
	Main_interface();//返回主函数前调用主函数界面

}
void Sort_message()//排序
{
	student* t = head;
	if (t->next == nullptr)//无需排序，直接返回
	{
		no_sortinterface();//无需排序界面
		Main_interface();//返回前调用主界面函数
		return;
	}
	if (t->next->next == nullptr)//无需排序，直接返回
	{
		no_sortinterface();//无需排序完成界面
		Main_interface();//返回前调用主界面函数
		return;
	}
	Sort_interface();//打印排序界面	
	ExMessage ma;//保存鼠标信息
	while (1)
	{
		ma = getmessage(EM_MOUSE);//获取鼠标信息
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 150 && ma.y <= 200)//学号排序
		{
			setlinecolor(RED);
			rectangle(470, 150, 770, 200);
			if (ma.message == WM_LBUTTONDOWN)//左键按下
			{
				sort_id();//学号排序
				break;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 150, 770, 200);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 210 && ma.y <= 260)//姓名排序
		{
			setlinecolor(RED);
			rectangle(470, 210, 770, 260);
			if (ma.message == WM_LBUTTONDOWN)//左键按下
			{
				sort_name();//姓名排序
				break;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 210, 770, 260);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 270 && ma.y <= 320)//综测成绩排序
		{
			setlinecolor(RED);
			rectangle(470, 270, 770, 320);
			if (ma.message == WM_LBUTTONDOWN)//左键按下
			{
				sort_total();//综测成绩排序
				break;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 270, 770, 320);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 330 && ma.y <= 380)//返回键
		{
			setlinecolor(RED);
			rectangle(470, 330, 770, 380);
			if (ma.message == WM_LBUTTONDOWN)
			{
				Main_interface();//返回前调用主界面函数
				return;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 330, 770, 380);
		}
	}
	funish_sort();//排序完成界面
	browse_interface();//浏览界面
	int y = 80;
	student* p = head;
	while (p->next)//while循环显示信息
	{
		settextstyle(20, 0, "楷体");
		settextcolor(BLACK);
		outtextxy(60, y, p->next->name);
		outtextxy(130, y, p->next->sex);
		outtextxy(190, y, p->next->age);
		outtextxy(250, y, p->next->id);
		outtextxy(390, y, p->next->thought);
		outtextxy(505, y, p->next->academic);
		outtextxy(885, y, p->next->style);
		outtextxy(1010, y, p->next->total);
		y += 30;
		p = p->next;
	}
	if (ma.x >= 470 && ma.x <= 770 && ma.y >= 330 && ma.y <= 380)//返回键
	{
		setlinecolor(RED);
		rectangle(470, 330, 770, 380);
		if (ma.message == WM_LBUTTONDOWN)
		{
			Main_interface();//返回前调用主界面函数
			return;
		}
	}
	else
	{
		setlinecolor(GREEN);
		rectangle(470, 330, 770, 380);
	}
	Main_interface();//返回前调用主界面函数
}
void Help_message()
{
	
	BeginBatchDraw();//开始作图
	IMAGE img;
	loadimage(&img, "./123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(30, 0, "黑体");
	settextcolor(BLACK);
	outtextxy(40, 0, "按ESC键返回");
	setlinecolor(GREEN);
	rectangle(320, 100, 920, 500);
	settextstyle(50, 25, "楷体");//高度、字符宽度、字体
	settextcolor(WHITE);
	outtextxy(495, 122, "关于此程序");//高度、字符宽度、字体
	settextstyle(35, 20, "楷体");
	outtextxy(420, 170, "代码开源网址github：");
	outtextxy(395, 210, "账号名：yanxiaoxia456");
	EndBatchDraw();//作图完成
	while (1)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)//等待按键ESC，否则一直sleep（处于暂停状态）
		{
			Main_interface();//返回主函数前调用主函数界面
			return;
		}
	}
	Main_interface();//返回前调用主界面函数
}
void refresh_message()
{
	my_delete();
	BeginBatchDraw();//开始作图
	IMAGE img;
	loadimage(&img, "./123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "楷体");
	settextcolor(GREEN);
	outtextxy(495, 150, "已刷新成功");
	EndBatchDraw();//作图完成
	Sleep(1000);
	while (1)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)//等待按键ESC，否则一直sleep（处于暂停状态）
		{
			Main_interface();//返回主函数前调用主函数界面
			return;
		}
	}
	Main_interface();//返回前调用主界面函数
}
void my_delete()
{
	student* p = head->next; //p指向头结点后的第一个结点
	student* t = nullptr; //用来释放结点
	if (!head->next)  return;
	while (p->next)
	{
		t = p;
		p = p->next;
		delete(t);
	}
	delete(p);
	head->next = NULL;
}
int main()
{
	initgraph(1240, 680, EW_NOCLOSE);//设置画布
	IMAGE img;//定义IMAGE类对象
	loadimage(&img, "123.jpg", 1240, 680);//加载图片，宽1240，高680
	putimage(0, 0, &img);//输出图片，左上角原点
	HWND hn = GetHWnd();//hn获得窗口句柄
	SetWindowText(hn, "学生信息管理系统");//该函数改变指定窗口hn的标题栏的文本内容
	Main_interface();//主界面函数
	read_file();//读取文件
	ExMessage ms;//定义一个保存鼠标信息的结构体对象
	while (1)
	{
		ms = getmessage(EM_MOUSE);//这个函数用于获取一个鼠标消息。如果当前消息队列中没有，就一直等待。
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 90 && ms.y <= 140)//点击刷新信息
		{
			setlinecolor(RED);//设置当前设备划线颜色为红色
			rectangle(520, 90, 720, 140);//画无填充矩形
			if (ms.message == WM_LBUTTONDOWN)//当用户在光标位于窗口的工作区时按下鼠标左键时发布
			{
				putimage(0, 0, &img);
				refresh_message();
				Input_file();//录入文件
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 90, 720, 140);

		}

		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 150 && ms.y <= 200)//点击录入信息
		{
			setlinecolor(RED);//设置当前设备划线颜色为红色
			rectangle(520, 150, 720, 200);//画无填充矩形
			if (ms.message == WM_LBUTTONDOWN)//当用户在光标位于窗口的工作区时按下鼠标左键时发布
			{
				putimage(0, 0, &img);
				Set_message();//建立学生信息
				Input_file();//录入文件
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 150, 720, 200);

		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 210 && ms.y <= 260)//点击浏览信息
		{
			setlinecolor(RED);
			rectangle(520, 210, 720, 260);
			if (ms.message == WM_LBUTTONDOWN)//当用户在光标位于窗口的工作区时按下鼠标左键时发布
			{
				putimage(0, 0, &img);
				browse_message();//浏览信息函数，显示浏览界面
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 210, 720, 260);

		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 270 && ms.y <= 320)//查询信息
		{
			setlinecolor(RED);
			rectangle(520, 270, 720, 320);
			if (ms.message == WM_LBUTTONDOWN)
			{
				putimage(0, 0, &img);
				Serch_message();//查询信息
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 270, 720, 320);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 330 && ms.y <= 380)//排序
		{
			setlinecolor(RED);
			rectangle(520, 330, 720, 380);
			if (ms.message == WM_LBUTTONDOWN)//该消息当用户在window客户区域点击鼠标左键的时候发送
			{
				putimage(0, 0, &img);
				Sort_message();//排序
				Input_file();//录入文件
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 330, 720, 380);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 390 && ms.y <= 440)//修改信息
		{
			setlinecolor(RED);
			rectangle(520, 390, 720, 440);
			if (ms.message == WM_LBUTTONDOWN)
			{
				putimage(0, 0, &img);
				change_message();//修改
				Input_file();//录入文件
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 390, 720, 440);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 450 && ms.y <= 500)//删除信息
		{
			setlinecolor(RED);
			rectangle(520, 450, 720, 500);
			if (ms.message == WM_LBUTTONDOWN)
			{
				putimage(0, 0, &img);
				delete_message();//删除
				Input_file();//录入文件
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 450, 720, 500);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 510 && ms.y <= 560)//退出
		{
			setlinecolor(RED);
			rectangle(520, 510, 720, 560);
			if (ms.message == WM_LBUTTONDOWN)
				break;//退出循环
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 510, 720, 560);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 570 && ms.y <= 620)//帮助
		{
			setlinecolor(RED);
			rectangle(520, 570, 720, 620);
			if (ms.message == WM_LBUTTONDOWN)
			{
				putimage(0, 0, &img);
				Help_message();
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 570, 720, 620);
		}
	}
	closegraph();
	return 0;
}
