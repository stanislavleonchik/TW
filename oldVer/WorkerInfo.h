#include "TWorker.h"

#define max_count_workers 5
//const int max_count_workers=20; ��� �� ������, ������ ����� #define, �� � �������� �������� ������ ����� �����


class TWorkersInfo {
	TWorker staff [max_count_workers];
	static TWorkersInfo* workersInfo;
public:
    TWorkersInfo();
    TWorker tmp;  //������ ����������� ������ ��� �������� ��������
    int numberOfWorkers = 0; //������� ����������
//	void GetMaxSalary ();
	void bubbleSort();
	char* linSearch(int requiredKey);
	TWorker& GetWorker(int _num){return staff[_num];};
    TWorker& GetTMP(){return tmp;};
    static TWorkersInfo* CreateInstanceDun(TWorkersInfo* workersInfo);
};

