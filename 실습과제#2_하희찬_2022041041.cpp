#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>

using namespace std;

struct Subject {        //과목 정보
    string SubName = { 0 };     //과목 이름
    int Hakjum = 0;         //과목 학점
    string Grade = { 0 };       //과목 등급
    double GPA = 0;          //과목 평점
};

struct Student {        //학생 정보
    string StdName = { 0 };     //학생 이름
    int Hakbun = 0;         //학번
    Subject Sub[3];     //과목(구조체)
    double Total = 0;        //과목 평점 총합
    double AveGPA = 0;       //교과목 평균 평점
};


int main() {
    Student Stu[2];
    int n = 0, err = 0;

    // 좌로 정렬
    std::cout << std::left;

    //소수점 설정
    cout << fixed;
    cout.precision(2);

    while (n != 3) {

        //메뉴 출력 
        cout << "===== 메뉴 =====\n1. 학생 성적 입력\n" << "2. 전체 학생 성적 보기\n" << "3. 프로그램 종료\n" << endl;
        cout << "원하는 기능을 입력하세요 : ";
        cin >> n;
        cout << endl;
        cin.ignore();

        //입력 오류시 다시 시작
        if (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
        }


        //학생 성적 입력 
        if (n == 1) {
            err = 1;
            for (int i = 0; i < 2; i++) {
                cout << "* " << i + 1 << " 번째 학생 이름과 학번을 입력하세요." << endl;
                cout << "이름 : ";
                getline(cin, Stu[i].StdName);
                cout << "학번 : ";
                cin >> Stu[i].Hakbun;
                cin.ignore();
                cout << "\n\n\n" << "* 수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요." << endl;
                for (int j = 0; j < 3; j++) {
                    cout << "교과목명 : ";
                    getline(cin, Stu[i].Sub[j].SubName);
                    cout << "과목학 점수 : ";
                    cin >> Stu[i].Sub[j].Hakjum;
                    cin.ignore();
                    cout << "과목등급(A+ ~ F) : ";
                    getline(cin, Stu[i].Sub[j].Grade);
                    cout << endl;



                    //과목 평점 구하기
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

        //전체 학생의 신상, 성적 정보 출력
        else if (n == 2) {
            //학생 정보가 없을 경우 메뉴 선택으로 이동
            if (err == 0) {
                cout << "학생정보가 없습니다.\n\n";
            }

            else {
                cout << "                   전체 학생 성적 보기\n";
                cout << "==============================================================\n";

                for (int i = 0; i < 2; i++) {

                    cout << "이름 : " << Stu[i].StdName << "  학번 : " << Stu[i].Hakbun << endl;
                    cout << "==============================================================\n";
                    cout << "과목명            과목학점    과목등급    과목평점\n";
                    cout << "==============================================================\n";

                    for (int j = 0; j < 3; j++) {
                        //과목 평점 총합 구하기
                        Stu[i].Total += (double)Stu[i].Sub[j].GPA;
                        //교과목 평균 평점
                        Stu[i].AveGPA = (double)Stu[i].Total / 3;


                        cout << setw(20) << Stu[i].Sub[j].SubName << setw(10) << Stu[i].Sub[j].Hakjum << setw(10) << Stu[i].Sub[j].Grade << setw(10) << Stu[i].Sub[j].GPA << endl;
                    }
                    cout << "==============================================================\n";
                    cout << "                       평균 평점     " << Stu[i].AveGPA << endl;
                    cout << "\n";
                }
            }


        }


        //프로그램 종료
        else if (n == 3) {
            cout << "프로그램을 종료합니다.";
            break;
        }
    }
    return 0;
}