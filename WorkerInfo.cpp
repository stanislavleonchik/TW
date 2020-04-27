#include "stdafx.h"
#include "TUserInterface.h"
#include "WorkerInfo.h"
TWorkersInfo* TWorkersInfo::workersInfo = nullptr;
void TWorkersInfo::bubbleSort() {
    TWorker x;
	for (int i = 0; i < staff_qty; i++) {
		for (int j = staff_qty - 1; j > i; j--) {
			if (GetWorker(j - 1).GetCode() > GetWorker(j).GetCode()) {
				x = GetWorker(j);
				GetWorker(j) = GetWorker(j - 1);
				GetWorker(j - 1) = x;
			}
		}
	}
}
char* TWorkersInfo::linSearch(int requiredKey) {//�������� ����� �� ����
	int i=0;
	char _name[30];
	do {i++;
	} while (i <= staff_qty && GetWorker(i).GetCode() != requiredKey);
	if (i == (staff_qty + 1)) {
		cout << "��� �� ������" << endl;
	}
	strcpy_s(_name, GetWorker(i).GetName());
	return _name;
}
void TWorkersInfo::GetMaxSalary () {
	float max_salary = GetWorker(0).GetSalary();
	char name[30];
	strcpy_s(name, GetWorker(0).GetName());
	for (int i=1; i< staff_qty; i++){
		if(GetWorker(i).GetSalary()>max_salary) {
		max_salary=GetWorker(i).GetSalary();
		strcpy_s(name, GetWorker(i).GetName());
		}
	}
	cout<<"������������ ����� = "<<max_salary<<endl;
	cout<<"��� ���������� = "<<name<<endl;
}
TWorkersInfo::TWorkersInfo(){
    staff = nullptr;
    staff_qty = 0;
}
TWorkersInfo* TWorkersInfo::CreateInstanceDun(){
    if (workersInfo == nullptr) {
        workersInfo = new TWorkersInfo();
    }
    return workersInfo;
}
void TWorkersInfo::AddWorker(const TWorker& worker) {
    if(staff != nullptr){
        auto* temp_staff = new TWorker[++staff_qty];
        for(int i = 0; i < staff_qty - 1; i++){
            temp_staff[i] = staff[i];
        }
        temp_staff[staff_qty - 1] = worker;
        delete staff;
        staff = temp_staff;
    }
    else {
        staff = new TWorker[++staff_qty];
    }
    staff[staff_qty - 1] = worker;
}
void TWorkersInfo::UpdateWorker(TWorkersInfo* wi) {
    int _code;   //����� ������, ������� ����� ��������
    cout << "������� ����� ������, ������� ���������� ��������" << endl;
    cin >> _code;

    cout << "������� ����� ���: " ;
    char newname[30];
    cin >> newname;
    wi->GetWorker(_code - 1).SetName(newname);

    cout << "������� ����� ���: " ;
    int num;
    cin >> num;
    wi->GetWorker(_code - 1).SetCode(num);

    cout << "������� ����� �����: " ;
    float newsalary;
    cin >> newsalary;
    wi->GetWorker(_code - 1).SetSalary(newsalary);

    cout << "�� �������� ������ � " << _code << endl;
}
void TWorkersInfo::DeleteWorker(TWorkersInfo* wi, int _code) {
    if (_code < 0 && _code > staff_qty) {
        cout << "�� ���������� ������ � ����� �������" << endl;}
    TWorker* tmp_staff = nullptr;
    int index = 0; int j = 0;
    for (; index < staff_qty; index++){
        if (wi->staff[index].GetCode() == _code); break;
    }
    tmp_staff = new TWorker[--staff_qty];
    for (int i = 0; i < staff_qty; i++){
        if (i != index){
            tmp_staff[i] = staff[j++];
        }
        }
    delete staff;
    staff = tmp_staff;
}
/*    int delWorkNum;
    cout << "������� ����� ������, ������� ���������� �������" <<endl;
    cout << "���� ���������� ������� ��� ������, ������� 0"<<endl;
    cin >> delWorkNum;
    if (delWorkNum > 0 && delWorkNum <= staff_qty) {
        for (int i = (delWorkNum - 1); i < staff_qty; i++) //���� ��� �������� �������� ������, �������� ���� � ��������� ������
            wi->GetWorker(i) = wi->GetWorker(i+1);  //�������� ������� ������ ���������
        cout << "������ �������" << endl;
        wi-> staff_qty -= 1;
    }
    if (delWorkNum == 0) {
        for (int i = 0; i < staff_qty; i++) //���� �� ��� ������� �� ������ �� staff_qty
            wi->GetWorker(i) = wi->GetTMP();  //�������� ������ ��������� � ������� ������ ����������
        cout << "��� ������ �������" << endl;
        wi-> staff_qty = 0;
    }
    if (delWorkNum < 0 && delWorkNum > staff_qty) {
        cout << "�� ���������� ������ � ����� �������" << endl;
    }
}*/
void TWorkersInfo::ShowWorkerList(TWorkersInfo* wi) {
    wi->bubbleSort(); //���������� �� ����
    for  (int i=0; i< wi->staff_qty; i++) { //����� ���������� ��� ���� ����������
        cout << wi->GetWorker(i);
    }
}
void TWorkersInfo::FindWorkerInfo(TWorkersInfo* wi, int _code) {  //�������� �����
    cin >> _code;
    cout << linSearch(_code) << endl;
}