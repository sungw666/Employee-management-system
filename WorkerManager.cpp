#include"workermanager.h"
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if(this->m_EmpArray[i]!=NULL)
				delete this->m_EmpArray[i];
			}
		}
		this->m_EmpNum = 0;
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在！" << endl;
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		Worker* p;
		if (select == 1)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				for (int j = i+1; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[i]->m_Id)
					{
						p = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[i];
						this->m_EmpArray[i] = p;
					}
				}
			}
			cout << "排序成功！排序结果为：" << endl;
			this->save();
			this->show_Emp();
		}
		else if (select == 2)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				for (int j = i+1; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[i]->m_Id)
					{
						p = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[i];
						this->m_EmpArray[i] = p;
					}
				}
			}
			cout << "排序成功！排序结果为：" << endl;
			this->save();
			this->show_Emp();
		}
		else
		{
			cout << "输入有误！" << endl;
			system("pause");
			system("cls");
		}
	}
}
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在！" << endl;
	}
	else
	{
		cout << "请选择查找方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select = 0;
		cin >>select;
		if (select == 1)
		{
			cout << "请输入职工号：" << endl;
			int id;
			cin >> id;
			int index=this->IsExist(id);
			if (index == -1)
			{
				cout << "没有找到此人！" << endl;
			}
			else
			{
				cout << "查找成功！该员工信息如下：" << endl;
				this->m_EmpArray[index]->showInfo();
			}
		}
		else if (select == 2)
		{
			cout << "请输入该员工姓名：" << endl;
			string name;
			cin >> name;
			bool flag=false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功！该员工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "没有找到此人" << endl;
			}
		}
		else
		{
			cout << "输入有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件为空或不存在！" << endl;
	}
	else
	{
		cout << "请输入要修改的职工的职工号：" << endl;
		int id;
		cin >> id;
		int index=this->IsExist(id);
		if (index == -1)
		{
			cout << "没有找到该员工！" << endl;
		}
		else
		{
			cout << "请输入修改后的职工信息：" << endl;
			int id2; string name; int dep;
			cout << "请输入职工号:" << endl;
			cin >> id2;
			cout << "请输入职工姓名:" << endl;
			cin >> name;
			cout << "请选择职工岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dep;
			Worker* worker = NULL;
			if (dep == 1)
			{
				worker = new Employee(id2, name, 1);
			}
			else if (dep == 2)
			{
				worker = new Manager(id2, name, 2);
			}
			else
			{
				worker = new Boss(id2, name, 3);
			}
			delete this->m_EmpArray[index];
			this->m_EmpArray[index] = worker;
			this->save();
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id)
{
	int flag = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			flag = i;
			break;
		}
	}
	return flag;
}
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "输入想要删除的员工的职工号" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "删除失败，此人不存在" << endl;
		}
		else
		{
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i+1];
			}
			delete this->m_EmpArray[this->m_EmpNum-1];
			this->m_EmpArray[this->m_EmpNum-1] = NULL;
			this->m_EmpNum--;
			this->save();
			cout << "删除成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;

	}
	else
	{
		for (int i = 0; i <this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker=NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while(ifs >> id && ifs>> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name << " " << this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	//文件不存在情况
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在但被清空
	char ch;
	ifs >> ch;
	//eof()是判断ifs是否读取到了文件结束符，读取到为true。创建ch，让ifs进行一次输出到临时变量ch，若ch读取的字符为空，那么ifs接下来就指向文件结束符。eof()为true
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	cout << "职工数量为：" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [num];
	this->init_Emp();
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}
void WorkerManager::Add_Emp()
{
	cout << "请输入增加员工数量" << endl;
	int add_num = 0;
	cin >>add_num;
	if (add_num > 0)
	{
		int newSize = this->m_EmpNum + add_num;
		Worker ** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL)
		{
			for (int i=0;i<this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		for (int i = this->m_EmpNum; i < newSize; i++)
		{
			int id;
			string name;
			int dselect;
			cout << "请输入第" << i + 1 << "个员工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >>dselect;
			Worker *worker=NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id,name,2);
				break;
			case 3:
				worker = new Boss(id,name,3);
				break;
			default:
				break;
			}
			newSpace[i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		cout << "成功添加" << add_num << "名员工" << endl;
		this->save();
		this->m_FileIsEmpty = false;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager:: show_menu()
{
	cout << "*********欢迎使用员工管理系统！*************" << endl;
	cout << "************0.退出管理程序******************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void WorkerManager::exit_system()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}