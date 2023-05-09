#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}

void Boss::showInfo()
{
	cout << "职工编号： " << left << setw(6) << this->m_Id
		<< " \t职工姓名： " << left << setw(6) << this->m_Name
		<< " \t岗位：" << left << setw(6) << this->getDeptName()
		<< " \t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName()
{
	return string("老板");
}