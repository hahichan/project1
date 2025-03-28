#include <iostream>
#include <iomanip>
#include <string>

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
    double AveGPA = 0;       //교과목 평균 평점
};

//메뉴 출력 함수
inline void PrintMenu() {

    cout << "===== 메뉴 =====  \n1. 학생 성적 입력   \n2. 전체 학생 성적 보기   \n3. 학생 이름 검색  \n4. 전체 학생 목록 보기  \n5.학생 정보 수정  \n6.프로그램 종료\n" << endl;
    cout << "원하는 기능을 입력하세요 : ";
}

//문자열 입력 함수
inline void InputValue(string& str) {
    
    getline(cin, str);
}

// 정수 입력 함수
inline void InputValue(int& i) {
    
    cin >> i;
    cin.ignore();
}

//과목 평점 구하는 함수
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

//교과목 평균 평점 구하기 함수
float CalcAveGPA(Subject* Sub, int SubNum) {
    float total = 0;
    float ave = 0;
    for (int i = 0; i < SubNum; i++) {

        total += (float)Sub[i].GPA;
    }

    ave = (float)total / 3;

    return ave;
}

//학생 정보 입력 함수
void entry(Student *Stu) {
    for (int i = 0; i < 2; i++) {
        cout << "* " << i + 1 << " 번째 학생 이름과 학번을 입력하세요." << endl;
        cout << "이름 : ";
        InputValue(Stu[i].StdName);
        cout << "학번 : ";
        InputValue(Stu[i].Hakbun);
        
        cout << "\n\n\n" << "* 수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요." << endl;
        for (int j = 0; j < 3; j++) {
            cout << "교과목명 : ";
            InputValue(Stu[i].Sub[j].SubName);
            cout << "과목학 점수 : ";
            InputValue( Stu[i].Sub[j].Hakjum);
            cout << "과목등급(A+ ~ F) : ";
            InputValue( Stu[i].Sub[j].Grade);
            cout << endl;
            CalcGPA(Stu[i].Sub[j]);
        }
        Stu[i].AveGPA = CalcAveGPA(Stu[i].Sub, 3);
    }
}

//전체 학생 데이터 출력
void PrintAllData(const Student* pst, int StudentNum) {
    cout << "                   전체 학생 성적 보기\n";
    cout << "==============================================================\n";

    for (int i = 0; i < StudentNum; i++) {

        cout << "이름 : " << pst[i].StdName << "  학번 : " << pst[i].Hakbun << endl;
        cout << "==============================================================\n";
        cout << "과목명            과목학점    과목등급    과목평점\n";
        cout << "==============================================================\n";

        for (int j = 0; j < 3; j++) {
            cout << setw(20) << pst[i].Sub[j].SubName << setw(10) << pst[i].Sub[j].Hakjum << setw(10) << pst[i].Sub[j].Grade << setw(10) << pst[i].Sub[j].GPA << endl;
        }
        cout << "==============================================================\n";
        cout << "                       평균 평점     " << pst[i].AveGPA << endl;
        cout << "\n";
    }
}

//한 학생 데이터 출력
void PrintOneData(const Student& rst) {
    
    if (rst.StdName.empty()) {
        cout << "해당 학생이 없습니다.\n";
        return;
    }
    
    cout << "이름 : " << rst.StdName << "  학번 : " << rst.Hakbun << endl;
    cout << "==============================================================\n";
    cout << "과목명            과목학점    과목등급    과목평점\n";
    cout << "==============================================================\n";

    for (int j = 0; j < 3; j++) {
        cout << setw(20) << rst.Sub[j].SubName << setw(10) << rst.Sub[j].Hakjum << setw(10) << rst.Sub[j].Grade << setw(10) << rst.Sub[j].GPA << endl;
    }
    cout << "==============================================================\n";
    cout << "                       평균 평점     " << rst.AveGPA << endl;
    cout << "\n";
    
    
}

//학생 검색 함수
Student* StdSearch(Student* pst, int StudentNum) {
    string name;
    cout << "검색 할 학생의 이름 : ";
    InputValue(name);
    for (int i = 0; i < StudentNum; i++) {
        if (pst[i].StdName == name) {
            return &pst[i];
        }
    }
    cout <<"해당 학생이 없습니다.";
    return nullptr;
}

//학생 목록 출력함수
void PrintAllStdList(const Student* pSt, int StudentNum = 2) {
    cout << "================================\n";
    cout << "학번            이름\n";
    for (int i = 0; i < StudentNum; i++) {
        cout << setw(15) << pSt[i].Hakbun << setw(10) << pSt[i].StdName << endl;
    }
    cout << "================================\n";

}

//학생 정보 수정 함수
void ModifyStdInfo(Student* pSt, int StdNum) {
    if (pSt ==nullptr) {
        return;
    }
    cout << "* (" << pSt->StdName <<", "<<pSt->Hakbun<<")의 정보를 수정하시오.\n";
    cout << "이름 : ";
    InputValue(pSt->StdName );
    cout << "학번 : ";
    InputValue(pSt->Hakbun);

}



int main() {
    Student Stu[2];
    int err = 0;
    string name ="";
    int control=1;
    // 좌로 정렬
    std::cout << std::left;

    //소수점 설정
    cout << fixed;
    cout.precision(2);

    while (control) {
        int choice = 0;
        control = 0;
        PrintMenu();
        cin >> choice;
        cout << endl;
        cin.ignore();

        //학생 성적 입력 
        if (choice == 1) {
            err = 1;
            entry(Stu);
            control = 1;
        }

        //전체 학생의 신상, 성적 정보 출력
        else if (choice == 2) {
            //학생 정보가 없을 경우 메뉴 선택으로 이동
            if (err == 0) {
                cout << "학생정보가 없습니다.\n\n";
            }
            else {
                PrintAllData(Stu, 2);
            }
            control = 1;

        }
        //한 학생의 정보 검색
        else if (choice == 3) {            
            Student* foundStudent = StdSearch(Stu, 2);
            if (foundStudent != nullptr) {
                PrintOneData(*foundStudent);
            }
            control = 1;

        }
        //학생 목록 출력
        else if (choice == 4) {
            PrintAllStdList(Stu);
            control = 1;

        }
        //학생 정보 수정
        else if (choice == 5) {
            Student* foundStudent = StdSearch(Stu, 2);
            if (foundStudent != nullptr) {
                ModifyStdInfo(foundStudent, 2);
            }
            control = 1;
        }
        //프로그램 종료
        else if (choice == 6) {
            cout << "프로그램을 종료합니다.";
            break;
        }
    }
    return 0;
}