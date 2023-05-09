#pragma once
#define FILENAME "empFile.txt"
#include<iostream>
#include<fstream>
#include<string>
#include"worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
class WorkerManager
{
public:
	void Clean_File();
	void Sort_Emp();
	void find_Emp();
	void Mod_Emp();
	int IsExist(int id);
	void Del_Emp();
	void show_Emp();
	void init_Emp();
	int get_EmpNum();
	WorkerManager();
	void show_menu();
	void exit_system();
	~WorkerManager();
	void Add_Emp();
	void save();
	int m_EmpNum;
	Worker ** m_EmpArray;
	bool m_FileIsEmpty;
};