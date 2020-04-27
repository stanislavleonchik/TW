#include "TWorker.h"
class TWorkersInfo {
    TWorker* staff;
    int staff_qty;
	static TWorkersInfo* workersInfo;
public:
    TWorkersInfo();
    TWorker& GetWorker(int _code){return staff[_code];};
    static TWorkersInfo* CreateInstanceDun();
    void GetMaxSalary ();
    char* linSearch(int requiredKey);
    void bubbleSort();
    void FindWorkerInfo(TWorkersInfo* wi, int _num);         //����� ��������� �� ����
    void ShowWorkerList(TWorkersInfo* wi);         //�������� ���� ����� ����������
    void DeleteWorker(TWorkersInfo* wi, int _code);           //������� ���� ������ ��� ���
    void UpdateWorker(TWorkersInfo* wi);           //�������� ���������� � ���������
    void AddWorker(const TWorker& worker);              //���� ���������� ��� ���� ����������
};

