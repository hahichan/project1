#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Subject {        //���� ����
    string SubName = { 0 };     //���� �̸�
    int Hakjum = 0;         //���� ����
    string Grade = { 0 };       //���� ���
    double GPA = 0;          //���� ����
};

struct Student {        //�л� ����
    string StdName = { 0 };     //�л� �̸�
    int Hakbun = 0;         //�й�
    Subject Sub[3];     //����(����ü)
    double AveGPA = 0;       //������ ��� ����
};

//�޴� ��� �Լ�
inline void PrintMenu() {

    cout << "===== �޴� =====  \n1. �л� ���� �Է�   \n2. ��ü �л� ���� ����   \n3. �л� �̸� �˻�  \n4. ��ü �л� ��� ����  \n5.�л� ���� ����  \n6.���α׷� ����\n" << endl;
    cout << "���ϴ� ����� �Է��ϼ��� : ";
}

//���ڿ� �Է� �Լ�
inline void InputValue(string& str) {
    
    getline(cin, str);
}

// ���� �Է� �Լ�
inline void InputValue(int& i) {
    
    cin >> i;
    cin.ignore();
}

//���� ���� ���ϴ� �Լ�
void CalcGPA(Subject& Sub) {

    if (Sub.Grade.compare("A+") == 0) {
        Sub.GPA = 4.5 * (double)Sub.Hakjum;
    }
    else if (Sub.Grade.compare("A") == 0 || Sub.Grade.compare("A0") == 0) {
        Sub.GPA = 4.0 * (double)Sub.Hakjum;
    }
    else if (Sub.Grade.compare("B+") == 0) {
        Sub.GPA = 3.5 * (double)Sub.Hakjum;
    }
    else if (Sub.Grade.compare("B") == 0 || Sub.Grade.compare("B0") == 0) {
        Sub.GPA = 3.0 * (double)Sub.Hakjum;
    }
    else if (Sub.Grade.compare("C+") == 0) {
        Sub.GPA = 2.5 * (double)Sub.Hakjum;
    }
    else if (Sub.Grade.compare("C") == 0 || Sub.Grade.compare("C0") == 0) {
        Sub.GPA = 2.0 * (double)Sub.Hakjum;
    }
    else if (Sub.Grade.compare("D+") == 0) {
        Sub.GPA = 1.5 * (double)Sub.Hakjum;
    }
    else if (Sub.Grade.compare("D") == 0 || Sub.Grade.compare("D0") == 0) {
        Sub.GPA = 1.0 * (double)Sub.Hakjum;
    }
    else if (Sub.Grade.compare("F") == 0) {
        Sub.GPA = 0;
    }
}

//������ ��� ���� ���ϱ� �Լ�
float CalcAveGPA(Subject* Sub, int SubNum) {
    float total = 0;
    float ave = 0;
    for (int i = 0; i < SubNum; i++) {

        total += (float)Sub[i].GPA;
    }

    ave = (float)total / 3;

    return ave;
}

//�л� ���� �Է� �Լ�
void entry(Student *Stu) {
    for (int i = 0; i < 2; i++) {
        cout << "* " << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���." << endl;
        cout << "�̸� : ";
        InputValue(Stu[i].StdName);
        cout << "�й� : ";
        InputValue(Stu[i].Hakbun);
        
        cout << "\n\n\n" << "* ������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���." << endl;
        for (int j = 0; j < 3; j++) {
            cout << "������� : ";
            InputValue(Stu[i].Sub[j].SubName);
            cout << "������ ���� : ";
            InputValue( Stu[i].Sub[j].Hakjum);
            cout << "������(A+ ~ F) : ";
            InputValue( Stu[i].Sub[j].Grade);
            cout << endl;
            CalcGPA(Stu[i].Sub[j]);
        }
        Stu[i].AveGPA = CalcAveGPA(Stu[i].Sub, 3);
    }
}

//��ü �л� ������ ���
void PrintAllData(const Student* pst, int StudentNum) {
    cout << "                   ��ü �л� ���� ����\n";
    cout << "==============================================================\n";

    for (int i = 0; i < StudentNum; i++) {

        cout << "�̸� : " << pst[i].StdName << "  �й� : " << pst[i].Hakbun << endl;
        cout << "==============================================================\n";
        cout << "�����            ��������    ������    ��������\n";
        cout << "==============================================================\n";

        for (int j = 0; j < 3; j++) {
            cout << setw(20) << pst[i].Sub[j].SubName << setw(10) << pst[i].Sub[j].Hakjum << setw(10) << pst[i].Sub[j].Grade << setw(10) << pst[i].Sub[j].GPA << endl;
        }
        cout << "==============================================================\n";
        cout << "                       ��� ����     " << pst[i].AveGPA << endl;
        cout << "\n";
    }
}

//�� �л� ������ ���
void PrintOneData(const Student& rst) {
    
    if (rst.StdName.empty()) {
        cout << "�ش� �л��� �����ϴ�.\n";
        return;
    }
    
    cout << "�̸� : " << rst.StdName << "  �й� : " << rst.Hakbun << endl;
    cout << "==============================================================\n";
    cout << "�����            ��������    ������    ��������\n";
    cout << "==============================================================\n";

    for (int j = 0; j < 3; j++) {
        cout << setw(20) << rst.Sub[j].SubName << setw(10) << rst.Sub[j].Hakjum << setw(10) << rst.Sub[j].Grade << setw(10) << rst.Sub[j].GPA << endl;
    }
    cout << "==============================================================\n";
    cout << "                       ��� ����     " << rst.AveGPA << endl;
    cout << "\n";
    
    
}

//�л� �˻� �Լ�
Student* StdSearch(Student* pst, int StudentNum) {
    string name;
    cout << "�˻� �� �л��� �̸� : ";
    InputValue(name);
    for (int i = 0; i < StudentNum; i++) {
        if (pst[i].StdName == name) {
            return &pst[i];
        }
    }
    cout <<"�ش� �л��� �����ϴ�.";
    return nullptr;
}

//�л� ��� ����Լ�
void PrintAllStdList(const Student* pSt, int StudentNum = 2) {
    cout << "================================\n";
    cout << "�й�            �̸�\n";
    for (int i = 0; i < StudentNum; i++) {
        cout << setw(15) << pSt[i].Hakbun << setw(10) << pSt[i].StdName << endl;
    }
    cout << "================================\n";

}

//�л� ���� ���� �Լ�
void ModifyStdInfo(Student* pSt, int StdNum) {
    if (pSt ==nullptr) {
        return;
    }
    cout << "* (" << pSt->StdName <<", "<<pSt->Hakbun<<")�� ������ �����Ͻÿ�.\n";
    cout << "�̸� : ";
    InputValue(pSt->StdName );
    cout << "�й� : ";
    InputValue(pSt->Hakbun);

}



int main() {
    Student Stu[2];
    int err = 0;
    string name ="";
    int control=1;
    // �·� ����
    std::cout << std::left;

    //�Ҽ��� ����
    cout << fixed;
    cout.precision(2);

    while (control) {
        int choice = 0;
        control = 0;
        PrintMenu();
        cin >> choice;
        cout << endl;
        cin.ignore();

        //�л� ���� �Է� 
        if (choice == 1) {
            err = 1;
            entry(Stu);
            control = 1;
        }

        //��ü �л��� �Ż�, ���� ���� ���
        else if (choice == 2) {
            //�л� ������ ���� ��� �޴� �������� �̵�
            if (err == 0) {
                cout << "�л������� �����ϴ�.\n\n";
            }
            else {
                PrintAllData(Stu, 2);
            }
            control = 1;

        }
        //�� �л��� ���� �˻�
        else if (choice == 3) {            
            Student* foundStudent = StdSearch(Stu, 2);
            if (foundStudent != nullptr) {
                PrintOneData(*foundStudent);
            }
            control = 1;

        }
        //�л� ��� ���
        else if (choice == 4) {
            PrintAllStdList(Stu);
            control = 1;

        }
        //�л� ���� ����
        else if (choice == 5) {
            Student* foundStudent = StdSearch(Stu, 2);
            if (foundStudent != nullptr) {
                ModifyStdInfo(foundStudent, 2);
            }
            control = 1;
        }
        //���α׷� ����
        else if (choice == 6) {
            cout << "���α׷��� �����մϴ�.";
            break;
        }
    }
    return 0;
}