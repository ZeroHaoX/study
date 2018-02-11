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
						cout << "��ѡ����ҷ�ʽ(��0�˳�)" << endl;
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
									cout << "������Ҫ����ѧ����ѧ��:(��0���˳�)" << endl;
									while (cin >> sno1)
									{
										cout << "***********************************************************************************************************************" << endl;
										if (sno1 == 0)
											break;
										int index = searchbysno(ss, sno1);
										if (index != -1)
										{
											output(ss, index);
											cout << "������ѧ��ѧ��:(��0�˳�)" << endl;
										}
										else
										{
											cout << "���޴�ѧ��" << endl;
											cout << "���������룺����0���˳���" << endl;
										}
									}
								}break;
								case 2:
								{
									char name1[20];
									cout << "������Ҫ����ѧ������(��0�˳�)" << endl;
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
												cout << "���޴�ѧ��" << endl;
												cout << "����������:(��0�˳�)" << endl;
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
								cout << "��ѡ����ҷ�ʽ(��0�˳�)" << endl;
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
								cout << "��ӳɹ�" << endl;
								cout << "***********************************************************************************************************************" << endl;
								cout << "��0�˳�����1�������" << endl;
								cin >> k;
							}
							else
							{
								cout << "��ӳ��ִ���" << endl;
								cout << "***********************************************************************************************************************" << endl;
								cout << "��0�˳�����1�������" << endl;
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
									cout << "������Ҫ�޸�ѧ��ѧ�ţ�(��0�˳�)" << endl;
									int sno2;
									while (cin >> sno2)
									{
										if (sno2 != 0)
										{
											if (searchbysno(ss, sno2) != -1)
											{
												update(ss, sno2);
												cout << "�޸ĳɹ�������0�˳���" << endl;
											}
											else
											{
												cout << "���޴�ѧ����Ϣ" << endl;
												cout << "����������(��0�˳�)��";
											}
										}
										else break;
									}
								}break;
								case 2:
								{
									cout << "������Ҫɾ��ѧ����ѧ��(��0�˳�)" << endl;
									int sno2;
									while (cin >> sno2)
									{
										if (sno2 != 0)
										{
											if (searchbysno(ss, sno2) != -1)
											{
												cout << "�Ƿ�ȷ��ɾ����(1.ȷ��  2.ȡ��)" << endl;
												int c;
												cin >> c;
												if (c == 1)
												{
													sdelete(ss, sno2);
													cout << "ɾ���ɹ�" << endl;
												}
												cout << "***********************************************************************************************************************" << endl;
												cout << "������Ҫɾ��ѧ����ѧ��(��0�˳�)" << endl;
											}
											else
											{
												cout << "���޴�ѧ����Ϣ(��0�˳�)" << endl;
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
							cout << "����ɹ���" << endl;
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
	cout << "��ӭʹ��ѧ���ɼ�����ϵͳ��" << endl << "��ѡ�����²�����" << endl;
	cout << "1-->ѧ����Ϣ��ѯ" << endl << "2-->���ѧ����Ϣ" << endl << "3-->�޸�/ɾ��ѧ����Ϣ" << endl << "4-->��ʾ����ѧ��ƽ���ɼ�" << endl << "5-->���ɼ��ӵ͵�������" << endl << "0-->�˳�ϵͳ" << endl;
	
}

void searchtip()
{
	cout << "1.��ѧ�Ų���" << endl << "2.����������" << endl << "3.�������ѧ����Ϣ" << endl;
}

void updatetip()
{
	cout << "(��0�˳�)" << endl << "1.�޸���Ϣ" << endl << "2.ɾ����Ϣ" << endl;
}

void sorttip()
{
	cout << "1.�Ӹߵ�������" << endl << "2.�ӵ͵�������" << endl << "(��0�˳�)" << endl;
}

void logintip()
{
	cout << "------------------------------------------------------����Ա��¼-------------------------------------------------------" << endl;
	cout << "1-->�˺ŵ�¼" << endl << "2-->�˺�ע��" << endl;
}

void output(stu&ss,int n)
{
	cout << "����:" << ss.st[n].name << "   ";
	cout << "ѧ��:" << ss.st[n].sno << "   ";
	cout << "�Ա�:" << ss.st[n].sex << "   ";
	cout << "���ģ�" << ss.st[n].score[0] << "   ��ѧ��" << ss.st[n].score[1] << "   Ӣ�" << ss.st[n].score[2] << "   ";
	cout << "������" << ss.st[n].lever << endl;
}

void input(STU&st)
{
	cout << "������ѧ������:" << endl;
	cin>> st.name;
	cout << "������ѧ��ѧ��:" << endl;
	cin >> st.sno;
	cout << "������ѧ���Ա�:(��/Ů)" << endl;
	cin>>st.sex;
	cout << "��ֱ�����ѧ������Ӣ���Ƴɼ�:" << endl;
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
		cout << "�޸ĳɹ�!" << endl;
	}
	else
		cout << "���޴�ѧ��" << endl;
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

//ÿ���޸��Զ���������
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

//�Զ��Ӵ�С����
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

//��¼
int login(Managerlist manager)
{
	Manager menber;
	cout << "***********************************************************************************************************************" << endl;
	cout << "(��0�˳�)" << endl;
	cout << "�������˺ţ�";
	cin >> menber.manager;
	if (strcmp(menber.manager, "0") == 0)
		return 0;
	cout << "���������룺";
	cin >> menber.secret;
	if (menber.secret == 0)
		return 0;
	for (int i = 0; i < manager.count; i++)
	{
		if (strcmp( menber.manager ,manager.menber[i].manager)==0)
		{
			if (menber.secret == manager.menber[i].secret)
			{
				cout << "��¼�ɹ���" << endl;
				cout << "***********************************************************************************************************************" << endl;
				return 1;
			}
			else
			{
				cout << "����������������룡" << endl;
				return login(manager);
			}
		}
	}
		cout << "�޴��˺�!����������!" << endl;
		return login(manager);
}
//ע��
int registermenber(Managerlist&manager)
{
	int s;
	Manager menber;
	cout << "***********************************************************************************************************************" << endl;
	cout << "�û���:";
	cin >> menber.manager;
	for (int i = 0; i < manager.count; i++)
	{
		if (strcmp(menber.manager, manager.menber[i].manager) == 0)
		{
			cout << "�û����Ѵ���!���������룡" << endl;
			return registermenber(manager);
		}
	}
	cout << "����(6λ��)��";
	cin >> menber.secret;
	cout << "�ٴ���������:";
	cin >> s;
	if (s != menber.secret)
	{
		cout << "�������!" << endl;
		return registermenber(manager);
	}
	else
	{
		cout << "ע��ɹ�!" << endl;
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


