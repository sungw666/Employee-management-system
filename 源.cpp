#include"workermanager.h"
#include<string>
void test()
{
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}
int main()
{
	//test();
	WorkerManager wm;
	while (true)
	{
		wm.show_menu();
		cout << "请输入你的选择：" << endl;
		int choice;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 0: wm.exit_system();//退出系统
			break;
		case 1: wm.Add_Emp();//添加职工
			break;
		case 2: wm.show_Emp();//显示职工
			break;
		case 3:wm.Del_Emp(); //删除职工
			break;
		case 4:wm.Mod_Emp(); //修改职工
			break;
		case 5: wm.find_Emp();//查找职工
			break;
		case 6: wm.Sort_Emp();//排序职工
			break;
		case 7: wm.Clean_File();//清空文件
			break;
		default:
			system("cls");
			break;
		}
	} 
	return 0;
}