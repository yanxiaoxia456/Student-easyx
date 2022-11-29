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
	char id[20];//ѧ��
	char name[20];//����
	char age[5];//����
	char sex[5];//�Ա�
	char thought[6];
	char academic[6];
	char style[6];
	char total[6];
	student* next;//ָ����һ������ָ��
};
student* head = new student;//ͷ���,���洢��Ϣ
void Help_message();//��������
void refresh_message();//ˢ�½���
void my_delete();//ɾ������
void Main_interface();//�����溯��
void Sort_interface();//�������
void browse_interface();//�����Ϣ����
void serch_interface(); //��ѯ����
void Set_message();//����ѧ����Ϣ
void browse_message();//�����Ϣ
void read_file();//��ȡ�ļ�
void Input_file();//¼���ļ�
void No_interface();//û���ҵ���Ϣ����
void Sort_message();//����
void Serch_message();//��ѯ��Ϣ
void sort_id();//ѧ������
void sort_name();//��������
void sort_total();//�۲�����
void funish_sort();//������ɽ���
void funish_change();//�޸���ɽ���
void funish_delete();//ɾ����ɽ���
void no_sortinterface();//�����������
void id_error_interface();//ѧ�Ŵ������
void age_error_interface();//����������
int judge_id(char id[]);//�ж�ѧ���Ƿ��ظ�
char* extract_num(char* s);//���ַ�������ȡ���ֺ���
void change_message();//�޸���Ϣ
void delete_message();//ɾ����Ϣ
void sub_list();//���������Ԫ��
student* serch(char str[]);//����
void funish_delete()//ɾ����ɽ���
{
	BeginBatchDraw();//��ʼ��ͼ
	IMAGE img;
	loadimage(&img, "./123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "����");
	settextcolor(GREEN);
	outtextxy(495, 150, "��ɾ���ɹ�");
	EndBatchDraw();//��ͼ���
	Sleep(1000);
}
student* serch(char str[])//������ͬ��ѧ�Ż�����
{
	student* p = head;
	while (p->next)
	{
		if (strcmp(p->next->id, str) == 0)//�Ƚ���һ����if�Ƿ���ͬ
			return p->next;//��ͬ�򷵻���һ�����ĵ�ַ
		if (strcmp(p->next->name, str) == 0)
			return p->next;
		p = p->next;
	}
	return nullptr;//ѧ�ź�������δ�ҵ��򷵻ؿյ�ַ
}
void delete_message()//ɾ����Ϣ
{
	char str[20];
	InputBox(str, 20, "������Ҫɾ����ѧ��ѧ��");
	student* p = head;//ָ������ͷ���
	student* t = nullptr;//�����ͷŽ��
	while (p->next)//ѭ������
	{
		if (strcmp(p->next->id, str) == 0)//��pָ��Ľ�����һ������id�Ա�
		{
			HWND wnd;
			wnd = GetHWnd();
			int a = MessageBox(wnd, "ȷ��ɾ����������?", "���Ǵ���", MB_OKCANCEL);
			if (a == IDOK)
			{
				t = p->next;//��tָ��p����һ����㣬Ҳ������Ҫɾ���Ľ��
				p->next = p->next->next;//����pָ�����nextָ���򣬸�Ϊ����Ӧ�ý���ַ
				delete(t);
				funish_delete();//ɾ����ɽ���
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
void change_message()//�޸���Ϣ
{
	char str[20];
	InputBox(str, 20, "������Ҫ�޸ĵ�ѧ��������ѧ��");
	student* t = serch(str);
	if (t == nullptr)
	{
		No_interface();//û���ҵ���Ϣ����
		Main_interface();
		return;
	}
	InputBox(t->id, 20, "�������޸ĺ�ѧ��");
	InputBox(t->name, 20, "�������޸ĺ�����");
	InputBox(t->age, 5, "�������޸ĺ�����");
	InputBox(t->sex, 5, "�������޸ĺ��Ա�");
	InputBox(t->thought, 6, "�������޸ĺ�ѧҵ��");
	InputBox(t->academic, 6, "�������޸ĺ�˼���");
	InputBox(t->style, 6, "�������޸ĺ������");
	InputBox(t->total, 6, "�������޸ĺ��۲��");
	funish_change();//�޸���ɽ���
	Main_interface();
}
void sub_list()//��������
{
	student* p = head;//pָ��ͷ���
	while (p->next)//ѭ������ÿһ�����
	{
		if (strcmp(p->next->name, "") == 0)//�Ƚϣ���Ϊ����Ϊ��
			strcpy_s(p->next->name, "δ֪");//Ϊ�գ������Ϊδ֪
		if (strcmp(p->next->age, "") == 0)
			strcpy_s(p->next->age, "δ֪");
		if (strcmp(p->next->id, "") == 0)
			strcpy_s(p->next->id, "δ֪");
		if (strcmp(p->next->sex, "") == 0)
			strcpy_s(p->next->sex, "δ֪");
		if (strcmp(p->next->thought, "") == 0)
			strcpy_s(p->next->thought, "δ֪");
		if (strcmp(p->next->academic, "") == 0)
			strcpy_s(p->next->academic, "δ֪");
		if (strcmp(p->next->style, "") == 0)
			strcpy_s(p->next->style, "δ֪");
		if (strcmp(p->next->total, "") == 0)
			strcpy_s(p->next->total, "δ֪");
		p = p->next;
	}
}
void id_error_interface()//ѧ�Ŵ������
{
	BeginBatchDraw();//��ʼ��ͼ
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "����");
	settextcolor(RED);
	outtextxy(345, 150, "ѧ���ظ������������룡");
	EndBatchDraw();
	Sleep(1000);//ִ�й���һ��ʱ�䣬Ҳ���ǵȴ�һ��ʱ���ڼ���ִ�У�windows��Ϊ1000���룬��2��
	putimage(0, 0, &img);
}
void age_error_interface()//����������
{
	BeginBatchDraw();//��ʼ��ͼ
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "����");
	settextcolor(RED);
	outtextxy(345, 150, "����������������룡");
	EndBatchDraw();
	Sleep(1000);
	putimage(0, 0, &img);
}
int judge_id(char id[])//�ж�ѧ���Ƿ��ظ�
{
	student* p = head;
	while (p->next)
	{
		if (strcmp(p->next->id, id) == 0)
			return 1;//�ҵ��ظ�����1
		p = p->next;
	}
	return 0;
}
char* extract_num(char* s)//���ַ�������ȡ���ֺ���
{
	int length = strlen(s);
	//cout << length << endl;
	char* str = new char[length];
	int j = 0;
	for (int i = 0; i < length; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')//ֻ��0-9�����ֻᱻ��¼������
		{
			str[j++] = s[i];
		}
	}
	return str;
}
void no_sortinterface()//�����������
{
	BeginBatchDraw();//��ʼ��ͼ
	settextstyle(50, 0, "����");
	settextcolor(GREEN);
	outtextxy(395, 150, "����̫�٣���������");
	EndBatchDraw();
	Sleep(1000);
}
void funish_sort()//������ɽ���
{
	BeginBatchDraw();//��ʼ��ͼ
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "����");
	settextcolor(GREEN);
	outtextxy(495, 150, "���������");
	EndBatchDraw();//��ͼ���
	Sleep(1000);
}
void funish_change()//�޸���ɽ���
{
	BeginBatchDraw();//��ʼ��ͼ
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "����");
	settextcolor(GREEN);
	outtextxy(495, 150, "���޸����");
	EndBatchDraw();//��ͼ���
	Sleep(1000);
}
void sort_id()//ѧ������
{
	student* p = head;
	int count = 0;
	while (1)
	{
		p = head;
		count = 0;//������¼��һ�α���������Ԫ�ؽ����Ĵ���
		while (p->next->next)
		{
			if (atol(p->next->id) > atol(p->next->next->id))
			{
				student* t1 = p->next;
				student* t2 = p->next->next;
				p->next = p->next->next;
				t1->next = t2->next;
				p->next->next = t1;
				count++;//ÿ����һ��+1
			}
			p = p->next;
		}
		if (count == 0)//�����һ�α�����û�н���Ԫ�أ���ʾ�Ѿ��źã��˳�ѭ��
			break;
	}
}
void sort_name()//��������
{
	student* p = head;
	int count = 0;
	while (1)
	{
		count = 0;//������¼��һ�α���������Ԫ�ؽ����Ĵ���
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
				count++;//ÿ����һ��+1
			}
			p = p->next;
		}
		if (count == 0)//�����һ�α�����û�н���Ԫ�أ���ʾ�Ѿ��źã��˳�ѭ��
			break;
	}
}
void sort_total()//���۲�ɼ�����
{
	student* p = head;
	int count = 0;
	while (1)
	{
		p = head;
		count = 0;//������¼��һ�α���������Ԫ�ؽ����Ĵ���
		while (p->next->next)
		{
			if (atol(p->next->total) < atol(p->next->next->total))
			{
				student* t1 = p->next;
				student* t2 = p->next->next;
				p->next = p->next->next;
				t1->next = t2->next;
				p->next->next = t1;
				count++;//ÿ����һ��+1
			}
			p = p->next;
		}
		if (count == 0)//�����һ�α�����û�н���Ԫ�أ���ʾ�Ѿ��źã��˳�ѭ��
			break;
	}
}
void No_interface()//û���ҵ���Ϣ���溯��
{
	BeginBatchDraw();//��ʼ��ͼ
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "����");
	settextcolor(RED);
	outtextxy(445, 150, "û�в鵽����Ϣ");
	EndBatchDraw();
	Sleep(2000);
}
void read_file()//��ȡ�ļ�
{
	head->next = nullptr;//��ʼ�������տ�ʼΪ�ձ�
	ifstream in("student_message1.txt", ios::in);
	if (!in)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(0);
	}
	student* p = head;//pָ��ͷ��㣬p��ָ��
	while (!in.eof())//�ж��ļ��Ƿ�Ϊ��
	{
		student* t = new student;//����һ���½ڵ�t��t��ָ��
		in >> t->id;
		in >> t->name;
		in >> t->age;
		in >> t->sex;
		in >> t->thought;
		in >> t->academic;
		in >> t->style;
		in >> t->total;
		if (in.eof())//����ļ���ȡ��ĩβ���˳�ѭ��
			break;
		t->next = nullptr;
		p->next = t;//��ͷ����ָ����ָ�������ɵĽ��t
		p = p->next;//��pָ��β���
	}
	in.close();
}
void Input_file()//д���ļ�
{
	ofstream out("student_message1.txt", ios::out);
	if (!out)
	{
		cout << "�ļ���ʧ��" << endl;
		exit(0);
	}
	sub_list();//���������Ԫ��
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
void serch_interface()//��ѯ����
{
	BeginBatchDraw();//��ʼ��ͼ
	//��һ����ť
	setcolor(WHITE);
	fillrectangle(470, 150, 770, 200);
	settextstyle(40, 0, "����");
	setcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 155, "ѧ�Ų�ѯ");
	//�ڶ�����ť
	setcolor(WHITE);
	fillrectangle(470, 210, 770, 260);
	settextstyle(40, 0, "����");
	setcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 215, "������ѯ");
	//��������ť
	setcolor(WHITE);
	fillrectangle(470, 270, 770, 320);
	settextstyle(40, 0, "����");
	setbkmode(TRANSPARENT);
	setcolor(GREEN);
	outtextxy(580, 275, "����");
	EndBatchDraw();
}
void browse_interface()//�����Ϣ����
{
	BeginBatchDraw();
	IMAGE img;
	loadimage(&img, "123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(30, 0, "����");
	settextcolor(BLACK);
	outtextxy(40, 0, "��ESC������");
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 2);
	//�����
	line(40, 40, 40, 640);//������
	line(120, 40, 120, 640);//������
	line(180, 40, 180, 640);//�Ա���
	line(240, 40, 240, 640);//������
	line(380, 40, 380, 640);//ѧ����
	line(540, 40, 540, 640);//˼����
	line(700, 40, 700, 640);//ѧҵ��
	line(860, 40, 860, 640);//������
	line(1020, 40, 1020, 640);//�۲���
	EndBatchDraw();

	for (int y = 40; y <= 640; y += 30)
	{
		line(40, y, 1020, y);
	}
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(45, 45, "����");
	outtextxy(125, 45, "�Ա�");
	outtextxy(185, 45, "����");
	outtextxy(245, 45, "ѧ��");
	outtextxy(385, 45, "˼���");
	outtextxy(545, 45, "ѧҵ��");
	outtextxy(705, 45, "�����");
	outtextxy(865, 45, "�۲��");
}
void Sort_interface()//�������
{

	BeginBatchDraw();
	//��һ����ť
	setcolor(WHITE);
	fillrectangle(470, 150, 770, 200);
	settextstyle(40, 0, "����");
	setcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(520, 155, "��ѧ������");
	//�ڶ�����ť
	setcolor(WHITE);
	fillrectangle(470, 210, 770, 260);
	settextstyle(40, 0, "����");
	setcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(520, 215, "����������");
	//��������ť
	setcolor(WHITE);
	fillrectangle(470, 270, 770, 320);
	settextstyle(40, 0, "����");
	setbkmode(TRANSPARENT);
	setcolor(GREEN);
	outtextxy(480, 275, "���۲�ɼ�����");
	//���ĸ���ť
	setcolor(WHITE);
	fillrectangle(470, 330, 770, 380);
	settextstyle(40, 0, "����");
	setbkmode(TRANSPARENT);
	setcolor(GREEN);
	outtextxy(580, 335, "����");
	EndBatchDraw();
}
void Main_interface()//������
{
	IMAGE img;
	loadimage(&img, "./123.jpg", 1240, 680);//����ͼƬ
	putimage(0, 0, &img);//����ͼƬ����
	BeginBatchDraw();//����������ڿ�ʼ������ͼ��ִ�к��κλ�ͼ����������ʱ���������ͼ������
	//ֱ��ִ�� FlushBatchDraw �� EndBatchDraw �Ž�֮ǰ�Ļ�ͼ�����
	//���ñ���
	settextstyle(50, 0, "΢�����");//�����ı��߶ȡ���ȡ�����
	settextcolor(BLUE);//����������ɫ
	setbkmode(TRANSPARENT);//��������������õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ�������������͸����
	outtextxy(440, 20, "ѧ����Ϣ����ϵͳ");//������ָ��λ������ַ���
	//���õ������ť
	setcolor(WHITE);//��������������õ�ǰ��ͼǰ��ɫΪ��ɫ
	fillrectangle(520, 90, 720, 140);//����������ڻ��б߿�������Ρ�
	settextstyle(40, 0, "����");
	settextcolor(GREEN);//��ǰ������ɫ
	setbkmode(TRANSPARENT);
	outtextxy(540, 95, "ˢ����Ϣ");
	//���õ�һ����ť
	setcolor(WHITE);//��������������õ�ǰ��ͼǰ��ɫΪ��ɫ
	fillrectangle(520, 150, 720, 200);//����������ڻ��б߿�������Ρ�
	settextstyle(40, 0, "����");
	settextcolor(GREEN);//��ǰ������ɫ
	setbkmode(TRANSPARENT);
	outtextxy(540, 155, "¼����Ϣ");
	//���õڶ�����ť
	setcolor(WHITE);
	fillrectangle(520, 210, 720, 260);
	settextstyle(40, 0, "����");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 215, "�����Ϣ");
	//���õ�������ť
	setcolor(WHITE);
	fillrectangle(520, 270, 720, 320);
	settextstyle(40, 0, "����");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 275, "��ѯ��Ϣ");
	//���õ��ĸ���ť
	setcolor(WHITE);
	fillrectangle(520, 330, 720, 380);
	settextstyle(40, 0, "����");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(580, 335, "����");
	//���õ������ť
	setcolor(WHITE);
	fillrectangle(520, 390, 720, 440);
	settextstyle(40, 0, "����");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 395, "�޸���Ϣ");
	//���õ������ť
	setcolor(WHITE);
	fillrectangle(520, 450, 720, 500);
	settextstyle(40, 0, "����");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(540, 455, "ɾ����Ϣ");
	//���õ�������ť
	setcolor(WHITE);
	fillrectangle(520, 510, 720, 560);
	settextstyle(40, 0, "����");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(580, 515, "�˳�");
	//���õ��߸���ť
	setcolor(WHITE);
	fillrectangle(520, 570, 720, 620);
	settextstyle(40, 0, "����");
	settextcolor(GREEN);
	setbkmode(TRANSPARENT);
	outtextxy(580, 575, "����");

	EndBatchDraw();
}
void Set_message()//����ѧ����Ϣ
{
	student* p = head;//����ṹ��ָ��pָ��ͷ���
	while (p->next)//ѭ����ʵ����pָ��β���
	{
		p = p->next;
	}
	while (1)
	{
		student* t = new student;//����һ����㣬����tָ��
		while (1)
		{
			InputBox(t->id, 20, "������ѧ��");//������������ԶԻ�����ʽ��ȡ�û����롣
			int a = judge_id(t->id);//�����ж�ѧ���Ƿ��ظ����ظ�����1��û�з���0
			if (a == 0)//û���ظ��˳�while�����
				break;
			id_error_interface();//���ظ���ִ�д������
		}
		InputBox(t->name, 20, "����������");
		while (1)
		{
			InputBox(t->age, 5, "����������");
			if (atoi(t->age) >= 10 && atoi(t->age) <= 100)//�� stdlib.h �� atoi ����,�����ڽ� char �ַ���תΪ int ��������
				break;
			age_error_interface();//�����䲻��10��100����
		}
		InputBox(t->sex, 5, "�������Ա�");
		InputBox(t->thought, 6, "������˼���");
		InputBox(t->academic, 6, "������ѧҵ��");
		InputBox(t->style, 6, "������˼���");
		InputBox(t->total, 6, "�������۲��");
		t->next = nullptr;//ʹ�½���ָ����Ϊ��
		p->next = t;
		p = p->next;//pָ�������ɵĽ�㣬��β���
		HWND hwnd = GetHWnd();//����������ڻ�ȡ��ͼ���ھ����
		int is_ok = MessageBox(hwnd, "�Ƿ��������?", "���Ǵ���", MB_OKCANCEL);//ȷ��ȡ��
		if (is_ok == IDCANCEL)//ȡ����ѡ
		{
			Main_interface();//����������
			break;
		}
	}
}
void browse_message()//�����Ϣ
{
	browse_interface();//�����Ϣ����
	student* p = head;
	int y = 80;
	while (p->next)
	{
		settextstyle(20, 0, "����");
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
			Main_interface();//�˳�ǰ���������溯��
			break;
		}
	}
}
void Serch_message()//��ѯ��Ϣ
{
	serch_interface();//��ѯ����
	char str[20];
	student* t = nullptr;//�������tΪ��
	ExMessage ma;//����ṹ�����ڱ��������Ϣ
	while (1)
	{
		ma = getmessage(EM_MOUSE);//��ȡһ�������Ϣ
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 150 && ma.y <= 200)//ѧ�Ų�ѯ��ť
		{
			setlinecolor(RED);
			rectangle(470, 150, 770, 200);
			if (ma.message == WM_LBUTTONDOWN)
			{
				InputBox(str, 20, "������Ҫ���ҵ�ѧ��ѧ��");
				t = serch(str);//������ͬѧ�Ż����������ظý��ĵ�ַ��t
				break;//�˳�
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 150, 770, 200);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 210 && ma.y <= 260)//���ֲ�ѯ��ť
		{
			setlinecolor(RED);
			rectangle(470, 210, 770, 260);
			if (ma.message == WM_LBUTTONDOWN)
			{
				InputBox(str, 20, "������Ҫ���ҵ�ѧ������");
				t = serch(str);//������ͬѧ�Ż����������ظý��ĵ�ַ��t
				break;//�˳�
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 210, 770, 260);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 270 && ma.y <= 320)//���ذ�ť
		{
			setlinecolor(RED);
			rectangle(470, 270, 770, 320);
			if (ma.message == WM_LBUTTONDOWN)
			{
				Main_interface();//����������ǰ��������������
				return;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 270, 770, 320);
		}

	}
	if (t != nullptr)//Ϊ����˵���ҵ���ѧ����Ϣ
	{
		browse_interface();//�����Ϣ����
		settextstyle(20, 0, "����");
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
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)//�ȴ�����ESC������һֱsleep��������ͣ״̬��
			{
				Main_interface();//����������ǰ��������������
				return;
			}
		}
	}
	No_interface();//û�в鵽��Ϣ����	
	Main_interface();//����������ǰ��������������

}
void Sort_message()//����
{
	student* t = head;
	if (t->next == nullptr)//��������ֱ�ӷ���
	{
		no_sortinterface();//�����������
		Main_interface();//����ǰ���������溯��
		return;
	}
	if (t->next->next == nullptr)//��������ֱ�ӷ���
	{
		no_sortinterface();//����������ɽ���
		Main_interface();//����ǰ���������溯��
		return;
	}
	Sort_interface();//��ӡ�������	
	ExMessage ma;//���������Ϣ
	while (1)
	{
		ma = getmessage(EM_MOUSE);//��ȡ�����Ϣ
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 150 && ma.y <= 200)//ѧ������
		{
			setlinecolor(RED);
			rectangle(470, 150, 770, 200);
			if (ma.message == WM_LBUTTONDOWN)//�������
			{
				sort_id();//ѧ������
				break;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 150, 770, 200);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 210 && ma.y <= 260)//��������
		{
			setlinecolor(RED);
			rectangle(470, 210, 770, 260);
			if (ma.message == WM_LBUTTONDOWN)//�������
			{
				sort_name();//��������
				break;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 210, 770, 260);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 270 && ma.y <= 320)//�۲�ɼ�����
		{
			setlinecolor(RED);
			rectangle(470, 270, 770, 320);
			if (ma.message == WM_LBUTTONDOWN)//�������
			{
				sort_total();//�۲�ɼ�����
				break;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 270, 770, 320);
		}
		if (ma.x >= 470 && ma.x <= 770 && ma.y >= 330 && ma.y <= 380)//���ؼ�
		{
			setlinecolor(RED);
			rectangle(470, 330, 770, 380);
			if (ma.message == WM_LBUTTONDOWN)
			{
				Main_interface();//����ǰ���������溯��
				return;
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(470, 330, 770, 380);
		}
	}
	funish_sort();//������ɽ���
	browse_interface();//�������
	int y = 80;
	student* p = head;
	while (p->next)//whileѭ����ʾ��Ϣ
	{
		settextstyle(20, 0, "����");
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
	if (ma.x >= 470 && ma.x <= 770 && ma.y >= 330 && ma.y <= 380)//���ؼ�
	{
		setlinecolor(RED);
		rectangle(470, 330, 770, 380);
		if (ma.message == WM_LBUTTONDOWN)
		{
			Main_interface();//����ǰ���������溯��
			return;
		}
	}
	else
	{
		setlinecolor(GREEN);
		rectangle(470, 330, 770, 380);
	}
	Main_interface();//����ǰ���������溯��
}
void Help_message()
{
	
	BeginBatchDraw();//��ʼ��ͼ
	IMAGE img;
	loadimage(&img, "./123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(30, 0, "����");
	settextcolor(BLACK);
	outtextxy(40, 0, "��ESC������");
	setlinecolor(GREEN);
	rectangle(320, 100, 920, 500);
	settextstyle(50, 25, "����");//�߶ȡ��ַ���ȡ�����
	settextcolor(WHITE);
	outtextxy(495, 122, "���ڴ˳���");//�߶ȡ��ַ���ȡ�����
	settextstyle(35, 20, "����");
	outtextxy(420, 170, "���뿪Դ��ַgithub��");
	outtextxy(395, 210, "�˺�����yanxiaoxia456");
	EndBatchDraw();//��ͼ���
	while (1)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)//�ȴ�����ESC������һֱsleep��������ͣ״̬��
		{
			Main_interface();//����������ǰ��������������
			return;
		}
	}
	Main_interface();//����ǰ���������溯��
}
void refresh_message()
{
	my_delete();
	BeginBatchDraw();//��ʼ��ͼ
	IMAGE img;
	loadimage(&img, "./123.jpg", 1240, 680);
	putimage(0, 0, &img);
	settextstyle(50, 0, "����");
	settextcolor(GREEN);
	outtextxy(495, 150, "��ˢ�³ɹ�");
	EndBatchDraw();//��ͼ���
	Sleep(1000);
	while (1)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)//�ȴ�����ESC������һֱsleep��������ͣ״̬��
		{
			Main_interface();//����������ǰ��������������
			return;
		}
	}
	Main_interface();//����ǰ���������溯��
}
void my_delete()
{
	student* p = head->next; //pָ��ͷ����ĵ�һ�����
	student* t = nullptr; //�����ͷŽ��
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
	initgraph(1240, 680, EW_NOCLOSE);//���û���
	IMAGE img;//����IMAGE�����
	loadimage(&img, "123.jpg", 1240, 680);//����ͼƬ����1240����680
	putimage(0, 0, &img);//���ͼƬ�����Ͻ�ԭ��
	HWND hn = GetHWnd();//hn��ô��ھ��
	SetWindowText(hn, "ѧ����Ϣ����ϵͳ");//�ú����ı�ָ������hn�ı��������ı�����
	Main_interface();//�����溯��
	read_file();//��ȡ�ļ�
	ExMessage ms;//����һ�����������Ϣ�Ľṹ�����
	while (1)
	{
		ms = getmessage(EM_MOUSE);//����������ڻ�ȡһ�������Ϣ�������ǰ��Ϣ������û�У���һֱ�ȴ���
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 90 && ms.y <= 140)//���ˢ����Ϣ
		{
			setlinecolor(RED);//���õ�ǰ�豸������ɫΪ��ɫ
			rectangle(520, 90, 720, 140);//����������
			if (ms.message == WM_LBUTTONDOWN)//���û��ڹ��λ�ڴ��ڵĹ�����ʱ����������ʱ����
			{
				putimage(0, 0, &img);
				refresh_message();
				Input_file();//¼���ļ�
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 90, 720, 140);

		}

		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 150 && ms.y <= 200)//���¼����Ϣ
		{
			setlinecolor(RED);//���õ�ǰ�豸������ɫΪ��ɫ
			rectangle(520, 150, 720, 200);//����������
			if (ms.message == WM_LBUTTONDOWN)//���û��ڹ��λ�ڴ��ڵĹ�����ʱ����������ʱ����
			{
				putimage(0, 0, &img);
				Set_message();//����ѧ����Ϣ
				Input_file();//¼���ļ�
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 150, 720, 200);

		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 210 && ms.y <= 260)//��������Ϣ
		{
			setlinecolor(RED);
			rectangle(520, 210, 720, 260);
			if (ms.message == WM_LBUTTONDOWN)//���û��ڹ��λ�ڴ��ڵĹ�����ʱ����������ʱ����
			{
				putimage(0, 0, &img);
				browse_message();//�����Ϣ��������ʾ�������
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 210, 720, 260);

		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 270 && ms.y <= 320)//��ѯ��Ϣ
		{
			setlinecolor(RED);
			rectangle(520, 270, 720, 320);
			if (ms.message == WM_LBUTTONDOWN)
			{
				putimage(0, 0, &img);
				Serch_message();//��ѯ��Ϣ
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 270, 720, 320);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 330 && ms.y <= 380)//����
		{
			setlinecolor(RED);
			rectangle(520, 330, 720, 380);
			if (ms.message == WM_LBUTTONDOWN)//����Ϣ���û���window�ͻ���������������ʱ����
			{
				putimage(0, 0, &img);
				Sort_message();//����
				Input_file();//¼���ļ�
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 330, 720, 380);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 390 && ms.y <= 440)//�޸���Ϣ
		{
			setlinecolor(RED);
			rectangle(520, 390, 720, 440);
			if (ms.message == WM_LBUTTONDOWN)
			{
				putimage(0, 0, &img);
				change_message();//�޸�
				Input_file();//¼���ļ�
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 390, 720, 440);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 450 && ms.y <= 500)//ɾ����Ϣ
		{
			setlinecolor(RED);
			rectangle(520, 450, 720, 500);
			if (ms.message == WM_LBUTTONDOWN)
			{
				putimage(0, 0, &img);
				delete_message();//ɾ��
				Input_file();//¼���ļ�
			}
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 450, 720, 500);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 510 && ms.y <= 560)//�˳�
		{
			setlinecolor(RED);
			rectangle(520, 510, 720, 560);
			if (ms.message == WM_LBUTTONDOWN)
				break;//�˳�ѭ��
		}
		else
		{
			setlinecolor(GREEN);
			rectangle(520, 510, 720, 560);
		}
		if (ms.x >= 520 && ms.x <= 720 && ms.y >= 570 && ms.y <= 620)//����
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
