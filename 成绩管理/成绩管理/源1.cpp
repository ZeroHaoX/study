#include<iostream>
using namespace std;
struct STU 
{
	char name[20];
	int old;
	int sno;
	double score[3];
	char sex[2];
	double sumscore=0;
	int lever = 1;
};
struct stu
{
	STU*st;
	int length;
	int count;
};
struct Manager
{
	int secret;
	char manager[20];
};
struct Managerlist
{
	Manager*menber;
	int count = 0;
	int length = 5;
};

void star(stu&ss,Managerlist&manager);
void tip();
void searchtip();
void updatetip();
void logintip();
void destory(stu&ss, Managerlist&manager);
void output(stu&ss, int n);
void input(STU&st);
int searchbysno(stu ss, int sno);
int searchbyname(stu ss, char*name1);
void inserch(stu&ss, STU student);
void sdelete(stu&ss, int sno);
void update(stu&ss, int sno);
void sum(STU&st);
double severage(stu&ss);
void inserchsort(stu&ss, int c);
void autosort(stu&ss);
void sorttip();
int login(Managerlist manager);
int registermenber(Managerlist&manager);
void inserchmenber(Managerlist&menber);

void main()
{
	stu ss;
	Managerlist manager;
	star(ss,manager);
	while (true)
	{
		logintip();
		int c;
		cin >> c;
		if (c == 1)
		{
			if (login(manager) == 1)
			{
				int x;
				do
				{
					tip();
					cin >> x;
					cout << "***********************************************************************************************************************" << endl;
					switch (x)
					{
					case 1:
					{
						int n;
						cout << "请选择查找方式(按0退出)" << endl;
						searchtip();
						while (cin >> n)
						{
							cout << "***********************************************************************************************************************" << endl;
							if (n != 0)
							{
								switch (n)
								{
								case 1:
								{
									int sno1;
									cout << "请输入要查找学生的学号:(按0键退出)" << endl;
									while (cin >> sno1)
									{
										cout << "***********************************************************************************************************************" << endl;
										if (sno1 == 0)
											break;
										int index = searchbysno(ss, sno1);
										if (index != -1)
										{
											output(ss, index);
											cout << "请输入学生学号:(按0退出)" << endl;
										}
										else
										{
											cout << "查无此学生" << endl;
											cout << "请重新输入：（按0键退出）" << endl;
										}
									}
								}break;
								case 2:
								{
									char name1[20];
									cout << "请输入要查找学生姓名(按0退出)" << endl;
									while (cin >> name1)
									{
										if (strcmp(name1, "0") != 0)
										{
											int index = searchbyname(ss, name1);
											if (index != -1)
											{
												output(ss, index);
											}
											else
											{
												cout << "查无此学生" << endl;
												cout << "请重新输入:(按0退出)" << endl;
											}
										}
										else break;
									}
								}
								case 3:
								{
									for (int i = 0; i < ss.count; i++)
									{
										output(ss, i);
										cout << endl;
									}
									cout << "***********************************************************************************************************************" << endl;
								}
								}
								cout << "请选择查找方式(按0退出)" << endl;
								searchtip();
							}
							else if (n == 0)
								break;
						}
					}break;
					case 2:
					{
						int k = 1;
						while (k)
						{
							STU student;
							input(student);
							if (searchbysno(ss, student.sno) == -1)
							{
								inserch(ss, student);
								autosort(ss);
								cout << "添加成功" << endl;
								cout << "***********************************************************************************************************************" << endl;
								cout << "按0退出，按1继续添加" << endl;
								cin >> k;
							}
							else
							{
								cout << "添加出现错误" << endl;
								cout << "***********************************************************************************************************************" << endl;
								cout << "按0退出，按1继续添加" << endl;
								cin >> k;
							}
						}
					}break;
					case 3:
					{
						updatetip();
						int m;
						while (cin >> m)
						{
							if (m == 1 || m == 2)
							{
								switch (m)
								{
								case 1:
								{
									cout << "请输入要修改学生学号：(按0退出)" << endl;
									int sno2;
									while (cin >> sno2)
									{
										if (sno2 != 0)
										{
											if (searchbysno(ss, sno2) != -1)
											{
												update(ss, sno2);
												cout << "修改成功！（按0退出）" << endl;
											}
											else
											{
												cout << "查无此学生信息" << endl;
												cout << "请重新输入(按0退出)：";
											}
										}
										else break;
									}
								}break;
								case 2:
								{
									cout << "请输入要删除学生的学号(按0退出)" << endl;
									int sno2;
									while (cin >> sno2)
									{
										if (sno2 != 0)
										{
											if (searchbysno(ss, sno2) != -1)
											{
												cout << "是否确定删除？(1.确定  2.取消)" << endl;
												int c;
												cin >> c;
												if (c == 1)
												{
													sdelete(ss, sno2);
													cout << "删除成功" << endl;
												}
												cout << "***********************************************************************************************************************" << endl;
												cout << "请输入要删除学生的学号(按0退出)" << endl;
											}
											else
											{
												cout << "查无此学生信息(按0退出)" << endl;
											}
										}
										else
											break;
									}
									updatetip();
								}
								}
							}
							else break;
						}
					}break;
					case 4:
					{
						double average = 0;
						for (int i = 0; i < ss.count; i++)
							sum(ss.st[i]);
						cout << severage(ss) << endl;
					}
					case 5:
					{
						sorttip();
						int c;
						cin >> c;
						if (c != 0)
						{
							inserchsort(ss, c);
							cout << "排序成功！" << endl;
						}
						else if (c == 0)
							break;
					}
					}
					cout << "***********************************************************************************************************************" << endl;
				}while (x != 0);
			}
		}
		else if (c == 2)
		{
			inserchmenber(manager);
			registermenber(manager);
		}
	}
	destory(ss,manager);
}

void star(stu&ss,Managerlist&manager)
{
	ss.st = new STU[5];
	ss.count = 0;
	ss.length = 5;
	manager.menber = new Manager[5];
	manager.count = 0;
	manager.length = 5;
}

void destory(stu&ss,Managerlist&manager)
{
	delete[]ss.st;
	delete[]manager.menber;
}

void tip()
{
	cout << "欢迎使用学生成绩管理系统！" << endl << "请选择以下操作：" << endl;
	cout << "1-->学生信息查询" << endl << "2-->添加学生信息" << endl << "3-->修改/删除学生信息" << endl << "4-->显示总体学生平均成绩" << endl << "5-->按成绩从低到高排序" << endl << "0-->退出系统" << endl;
	
}

void searchtip()
{
	cout << "1.按学号查找" << endl << "2.按姓名查找" << endl << "3.输出所有学生信息" << endl;
}

void updatetip()
{
	cout << "(按0退出)" << endl << "1.修改信息" << endl << "2.删除信息" << endl;
}

void sorttip()
{
	cout << "1.从高到低排序" << endl << "2.从低到高排序" << endl << "(按0退出)" << endl;
}

void logintip()
{
	cout << "------------------------------------------------------管理员登录-------------------------------------------------------" << endl;
	cout << "1-->账号登录" << endl << "2-->账号注册" << endl;
}

void output(stu&ss,int n)
{
	cout << "姓名:" << ss.st[n].name << "   ";
	cout << "学号:" << ss.st[n].sno << "   ";
	cout << "性别:" << ss.st[n].sex << "   ";
	cout << "语文：" << ss.st[n].score[0] << "   数学：" << ss.st[n].score[1] << "   英语：" << ss.st[n].score[2] << "   ";
	cout << "排名：" << ss.st[n].lever << endl;
}

void input(STU&st)
{
	cout << "请输入学生姓名:" << endl;
	cin>> st.name;
	cout << "请输入学生学号:" << endl;
	cin >> st.sno;
	cout << "请输入学生性别:(男/女)" << endl;
	cin>>st.sex;
	cout << "请分别输入学生语数英三科成绩:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> st.score[i];
		st.sumscore += st.score[i];
	}
}


int searchbysno(stu ss,int sno)
{
	for (int i = 0; i < ss.count; i++)
	{
		if (sno == ss.st[i].sno)
		{
			return i;
		}
	}
	return -1;
}

int searchbyname(stu ss, char*name1)
{
	for (int i = 0; i < ss.count; i++)
	{
		if (strcmp(ss.st[i].name, name1))
		{
			return i;
		}
	}
	return -1;
}

void inserch(stu&ss,STU student)
{
	if (ss.count == ss.length)
	{
		STU*p = new STU[ss.length + 5];
		for (int i = 0; i < ss.length + 5; i++)
		{
			p[i] = ss.st[i];
		}
		delete[]ss.st;
		ss.st = p;
		ss.length += 5;
	}
	ss.st[ss.count] = student;
	ss.count++;
}

void sdelete(stu&ss,int sno)
{
	int i = searchbysno(ss, sno);
	for (int j = i; j < ss.count; j++)
	{
		ss.st[j] = ss.st[j + 1];
	}
	ss.count--;
}

void update(stu&ss, int sno)
{
	int i = searchbysno(ss, sno);
	if (i != -1)
	{
		input(ss.st[i]);
		cout << "修改成功!" << endl;
	}
	else
		cout << "查无此学生" << endl;
}

void sum(STU&st)
{
	for (int i = 0; i < 3; i++)
		st.sumscore += st.score[i];
}
double severage(stu&ss)
{
	double sumx = 0;
	for (int i = 0; i < ss.count; i++)
		sumx += ss.st[i].sumscore;
	return sumx / ss.count;
}

//每次修改自动排名待做
void inserchsort(stu&ss,int c)
{
	if (c == 1)
	{
		for (int i = 1; i > ss.count; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (ss.st[j].sumscore < ss.st[j - 1].sumscore)
				{
					STU t = ss.st[j];
					ss.st[j] = ss.st[j - 1];
					ss.st[j].lever = j;
					ss.st[j - 1] = t;
					ss.st[j - 1].lever = j + 1;
				}
			}
		}
	}
	else if (c == 2)
	{
		for (int i = 1; i < ss.count; i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (ss.st[j].sumscore < ss.st[j - 1].sumscore)
				{
					STU t = ss.st[j];
					ss.st[j] = ss.st[j - 1];
					ss.st[j].lever = j;
					ss.st[j - 1] = t;
					ss.st[j - 1].lever = j + 1;
				}
			}
		}
	}
}

//自动从大到小排序
void autosort(stu&ss)
{
	{
		for (int i = ss.count - 1; i > 0; i--)
		{
			if (ss.st[i].sumscore > ss.st[i - 1].sumscore)
			{
				STU t = ss.st[i];
				ss.st[i] = ss.st[i - 1];
				ss.st[i].lever = i + 1;
				ss.st[i - 1] = t;
				ss.st[i - 1].lever = i;
			}
		}
	}
}

//登录
int login(Managerlist manager)
{
	Manager menber;
	cout << "***********************************************************************************************************************" << endl;
	cout << "(按0退出)" << endl;
	cout << "请输入账号：";
	cin >> menber.manager;
	if (strcmp(menber.manager, "0") == 0)
		return 0;
	cout << "请输入密码：";
	cin >> menber.secret;
	if (menber.secret == 0)
		return 0;
	for (int i = 0; i < manager.count; i++)
	{
		if (strcmp( menber.manager ,manager.menber[i].manager)==0)
		{
			if (menber.secret == manager.menber[i].secret)
			{
				cout << "登录成功！" << endl;
				cout << "***********************************************************************************************************************" << endl;
				return 1;
			}
			else
			{
				cout << "密码错误！请重新输入！" << endl;
				return login(manager);
			}
		}
	}
		cout << "无此账号!请重新输入!" << endl;
		return login(manager);
}
//注册
int registermenber(Managerlist&manager)
{
	int s;
	Manager menber;
	cout << "***********************************************************************************************************************" << endl;
	cout << "用户名:";
	cin >> menber.manager;
	for (int i = 0; i < manager.count; i++)
	{
		if (strcmp(menber.manager, manager.menber[i].manager) == 0)
		{
			cout << "用户名已存在!请重新输入！" << endl;
			return registermenber(manager);
		}
	}
	cout << "密码(6位数)：";
	cin >> menber.secret;
	cout << "再次输入密码:";
	cin >> s;
	if (s != menber.secret)
	{
		cout << "密码错误!" << endl;
		return registermenber(manager);
	}
	else
	{
		cout << "注册成功!" << endl;
		cout << "***********************************************************************************************************************" << endl;
		manager.menber[manager.count] = menber;
		manager.count += 1;
		return 1;
	}
}

void inserchmenber(Managerlist&menber)
{
	if (menber.count == menber.length)
	{
		Manager*p = new Manager[menber.length + 5];
		for (int i=0;i<menber.length;i++)
		{
			p[i] = menber.menber[i];
		}
		delete[]menber.menber;
		menber.menber = p;
	}
}


