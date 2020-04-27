#pragma once //��� ���� ��������� ������ "��������������� ���� TWorker"
class TWorker
{
    char name [30];
    int code;
    float salary;
    public:
        TWorker (char* _name, int _code, float _salary);
        TWorker ();  //������������� �� ���������
    char* GetName();
    int GetCode();
    float GetSalary();
    void SetName(char* value);
    void SetCode(int value);
    void SetSalary(float _salary);
    friend ostream& operator << (ostream& os, TWorker& c);
    friend istream& operator >> (istream& os, TWorker& c);
};