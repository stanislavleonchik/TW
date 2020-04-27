#include "stdafx.h"
#include "TUserInterface.h"
void TUserInterface::BuildUserInterfaceMenu() {
	TWorkersInfo* wi = new TWorkersInfo;
	TWorkersInfo::CreateInstanceDun(wi);
	int num = 0;
	for (; num != 6;) {
		cout << "����" <<endl;
		cout << "1 - �������� ����������"<< endl;                           // AddWorker
		cout << "2 - ����� ���������� � ����������"<< endl;                 //FindWorkerInfo
		cout << "3 - �������� ���������� � ����������"<< endl;              //UpdateWorker
		cout << "4 - �������� ������ �����������"<< endl;                   //ShowWorkerList
		cout << "5 - ������� ���������� (��� ���� �����������)"<< endl;     //DeleteWorker  
		cout << "6 - �����"<< endl; 
		cout << endl;

		cout << "������� ����� ����� (1-6) " << endl;
		cin >> num;

		switch (num) {
		case 1:
			AddWorker(wi); break;
		case 2: 
			FindWorkerInfo(wi);break;
		case 3:
			UpdateWorker(wi);break;
		case 4:
			ShowWorkerList(wi);break;
		case 5:
			DeleteWorker(wi);break;
		case 6:
			break;
		default:
			cout << "������ ������������ �����"<< endl;
		}
	}
}

void TUserInterface::AddWorker(TWorkersInfo* wi) {
	if (wi->numberOfWorkers < max_count_workers) {
		cout << "����� ������: " << wi->numberOfWorkers + 1 << endl;
		EnterWorkerInfo(wi->GetWorker(wi->numberOfWorkers));
		wi->numberOfWorkers += 1;
	}
	else {
		cout << "������ ����������" << endl;
	}	
}


void TUserInterface::UpdateWorker(TWorkersInfo* wi) {
	int UpdateWorkNum;   //����� ������, ������� ����� ��������
	cout << "������� ����� ������, ������� ���������� ��������" << endl;
	cin >> UpdateWorkNum;

	cout << "������� ����� ���: " ;
	char newname[30];
	cin >> newname;
	wi->GetWorker(UpdateWorkNum - 1).SetName(newname);

	cout << "������� ����� ���: " ;
	int num;
	cin >> num;
	wi->GetWorker(UpdateWorkNum - 1).SetCode(num);

	cout << "������� ����� �����: " ;
	float newsalary;
	cin >> newsalary;
	wi->GetWorker(UpdateWorkNum - 1).SetSalary(newsalary);

	cout << "�� �������� ������ � "<< UpdateWorkNum << endl;
}


void TUserInterface::DeleteWorker(TWorkersInfo* wi) {
	int delWorkNum; //����� ������, ������� ����� �������
	cout << "������� ����� ������, ������� ���������� �������" <<endl;
	cout << "���� ���������� ������� ��� ������, ������� 0"<<endl;
	cin >> delWorkNum;
	if (delWorkNum > 0 && delWorkNum <= max_count_workers) {
		for (int i = (delWorkNum - 1); i < max_count_workers; i++) //���� ��� �������� �������� ������, �������� ���� � ��������� ������
			wi->GetWorker(i) = wi->GetWorker(i+1);  //�������� ������� ������ ���������
		cout << "������ �������" << endl;
		wi->numberOfWorkers -= 1;
	}
	if (delWorkNum == 0) {
		for (int i = 0; i < max_count_workers; i++) //���� �� ��� ������� �� ������ �� max_count_workers
			wi->GetWorker(i) = wi->GetTMP();  //�������� ������ ��������� � ������� ������ ����������
		cout << "��� ������ �������" << endl;
		wi->numberOfWorkers = 0;
	}
	if (delWorkNum < 0 && delWorkNum > max_count_workers) {
		cout << "�� ���������� ������ � ����� �������" << endl;
	}
}

void TUserInterface::ShowWorkerList(TWorkersInfo* wi) {
	
	wi->bubbleSort(); //���������� �� ����
	
	for  (int i=0; i< wi->numberOfWorkers; i++) { //����� ���������� ��� ���� ����������
		cout << i + 1 <<". ";
		PrintWorkerInfo(wi->GetWorker(i));
	}
}

void TUserInterface::FindWorkerInfo(TWorkersInfo* wi) {  //�������� �����
	int requiredKey;
	cout << "����� ��� ���������� �����? " << endl;
	cin >> requiredKey;
	cout << wi->linSearch(requiredKey) << endl;
}
void TUserInterface::PrintWorkerInfo(TWorker& worker) { //����� ���������� �� ����� ���������
	cout<<"��� ����������: "<<worker.GetName() << endl;
	cout<<"��� ����������: "<<worker.GetCode() << endl;
	cout<<"����� ����������: "<<worker.GetSalary() << endl;
}
TWorker& TUserInterface::EnterWorkerInfo(TWorker& worker) {
    char SampleName [30];
    int num;
    float aFloat;
    cout << "������� ��� ����������: ";
    cin >> SampleName;
    worker.SetName(SampleName);
    cout << "������� ��� ����������: ";
    cin >> num;
    worker.SetCode(num);
    cout << "������� ����� ����������: ";
    cin >> aFloat;
    worker.SetSalary(aFloat);
    return worker;
}

