#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>

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
    double Total = 0;        //���� ���� ����
    double AveGPA = 0;       //������ ��� ����
};


int main() {
    Student Stu[2];
    int n = 0, err = 0;

    // �·� ����
    std::cout << std::left;

    //�Ҽ��� ����
    cout << fixed;
    cout.precision(2);

    while (n != 3) {

        //�޴� ��� 
        cout << "===== �޴� =====\n1. �л� ���� �Է�\n" << "2. ��ü �л� ���� ����\n" << "3. ���α׷� ����\n" << endl;
        cout << "���ϴ� ����� �Է��ϼ��� : ";
        cin >> n;
        cout << endl;
        cin.ignore();

        //�Է� ������ �ٽ� ����
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
        }


        //�л� ���� �Է� 
        if (n == 1) {
            err = 1;
            for (int i = 0; i < 2; i++) {
                cout << "* " << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���." << endl;
                cout << "�̸� : ";
                getline(cin, Stu[i].StdName);
                cout << "�й� : ";
                cin >> Stu[i].Hakbun;
                cin.ignore();
                cout << "\n\n\n" << "* ������ ���� 3���� �� �������, ��������, �������� �Է��ϼ���." << endl;
                for (int j = 0; j < 3; j++) {
                    cout << "������� : ";
                    getline(cin, Stu[i].Sub[j].SubName);
                    cout << "������ ���� : ";
                    cin >> Stu[i].Sub[j].Hakjum;
                    cin.ignore();
                    cout << "������(A+ ~ F) : ";
                    getline(cin, Stu[i].Sub[j].Grade);
                    cout << endl;



                    //���� ���� ���ϱ�
                    if (Stu[i].Sub[j].Grade.compare("A+") == 0) {
                        Stu[i].Sub[j].GPA = 4.5 * (double)Stu[i].Sub[j].Hakjum;
                    }
                    else if (Stu[i].Sub[j].Grade.compare("A") == 0 || Stu[i].Sub[j].Grade.compare("A0") == 0) {
                        Stu[i].Sub[j].GPA = 4.0 * (double)Stu[i].Sub[j].Hakjum;
                    }
                    else if (Stu[i].Sub[j].Grade.compare("B+") == 0) {
                        Stu[i].Sub[j].GPA = 3.5 * (double)Stu[i].Sub[j].Hakjum;
                    }
                    else if (Stu[i].Sub[j].Grade.compare("B") == 0 || Stu[i].Sub[j].Grade.compare("B0") == 0) {
                        Stu[i].Sub[j].GPA = 3.0 * (double)Stu[i].Sub[j].Hakjum;
                    }
                    else if (Stu[i].Sub[j].Grade.compare("C+") == 0) {
                        Stu[i].Sub[j].GPA = 2.5 * (double)Stu[i].Sub[j].Hakjum;
                    }
                    else if (Stu[i].Sub[j].Grade.compare("C") == 0 || Stu[i].Sub[j].Grade.compare("C0") == 0) {
                        Stu[i].Sub[j].GPA = 2.0 * (double)Stu[i].Sub[j].Hakjum;
                    }
                    else if (Stu[i].Sub[j].Grade.compare("D+") == 0) {
                        Stu[i].Sub[j].GPA = 1.5 * (double)Stu[i].Sub[j].Hakjum;
                    }
                    else if (Stu[i].Sub[j].Grade.compare("D") == 0 || Stu[i].Sub[j].Grade.compare("D0") == 0) {
                        Stu[i].Sub[j].GPA = 1.0 * (double)Stu[i].Sub[j].Hakjum;
                    }
                    else if (Stu[i].Sub[j].Grade.compare("F") == 0) {
                        Stu[i].Sub[j].GPA = 0;
                    }

                }

            }
        }

        //��ü �л��� �Ż�, ���� ���� ���
        else if (n == 2) {
            //�л� ������ ���� ��� �޴� �������� �̵�
            if (err == 0) {
                cout << "�л������� �����ϴ�.\n\n";
            }

            else {
                cout << "                   ��ü �л� ���� ����\n";
                cout << "==============================================================\n";

                for (int i = 0; i < 2; i++) {

                    cout << "�̸� : " << Stu[i].StdName << "  �й� : " << Stu[i].Hakbun << endl;
                    cout << "==============================================================\n";
                    cout << "�����            ��������    ������    ��������\n";
                    cout << "==============================================================\n";

                    for (int j = 0; j < 3; j++) {
                        //���� ���� ���� ���ϱ�
                        Stu[i].Total += (double)Stu[i].Sub[j].GPA;
                        //������ ��� ����
                        Stu[i].AveGPA = (double)Stu[i].Total / 3;


                        cout << setw(20) << Stu[i].Sub[j].SubName << setw(10) << Stu[i].Sub[j].Hakjum << setw(10) << Stu[i].Sub[j].Grade << setw(10) << Stu[i].Sub[j].GPA << endl;
                    }
                    cout << "==============================================================\n";
                    cout << "                       ��� ����     " << Stu[i].AveGPA << endl;
                    cout << "\n";
                }
            }


        }


        //���α׷� ����
        else if (n == 3) {
            cout << "���α׷��� �����մϴ�.";
            break;
        }
    }
    return 0;
}