#include "stdafx.h"
#include "TWorker.h"
#include "WorkerInfo.h"

struct TUserInterface {
static void BuildUserInterfaceMenu();
static TWorker& EnterWorkerInfo(TWorker& worker);     //���� ���������� �� ����� ���������, ����������� � AddWorker
static void FindWorkerInfo(TWorkersInfo* wi);         //����� ��������� �� ����
static void ShowWorkerList(TWorkersInfo* wi);         //�������� ���� ����� ����������
static void DeleteWorker(TWorkersInfo* wi);           //������� ���� ������ ��� ���
static void UpdateWorker(TWorkersInfo* wi);           //�������� ���������� � ���������
static void AddWorker(TWorkersInfo* wi);              //���� ���������� ��� ���� ����������
static void PrintWorkerInfo(TWorker &worker);         //����� ���������� �� ����� ���������, ����������� � ShowWorkerList
};
	




