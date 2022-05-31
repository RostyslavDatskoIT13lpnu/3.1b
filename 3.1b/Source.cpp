#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "����'�����i �����", "I����������", "���������� �� ������i��", "�i���� �� i����������", "������� ��������" };

struct Student {
    string lname;
    int kurs;
    Spec spec;
    int physics;
    int math;
    union {
        int progr;
        int numb;
        int ped;
    };
};

void create(Student* s, int amSt);
void print(Student* s, int amSt);
bool check(Student s);
int amount(Student* s, int amSt);
void print_mod(Student* s, int amSt);

int main() {
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    cout << "�i���i��� �������i�: ";
    cin >> n;
    Student* stud = new Student[n];
    create(stud, n);
    print(stud, n);
    cout << "³������ ��������:" << (double)amount(stud, n) / n * 100 << "%" << endl;

    print_mod(stud, n);

    return 0;

}

void create(Student* s, int amSt) {
    int sp;
    for (int i = 0; i < amSt; i++) {
        cout << "��i�����: ";
        cin >> s[i].lname;
        cout << "����: ";
        cin >> s[i].kurs;
        cout << "����i����i��� (0 - ����'�����i �����, 1 - I����������, 2 - ���������� �� ������i��, 3 - �i���� �� i����������, 4 - ������� ��������) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "��i��� � �i����: ";
        cin >> s[i].physics;
        cout << "��i��� � ����������: ";
        cin >> s[i].math;
        if (s[i].spec == 0) {
            cout << "��i��� � �������������: ";
            cin >> s[i].progr;
        }
        else if (s[i].spec == 1) {
            cout << "��i��� � ��������� �����i�: ";
            cin >> s[i].numb;
        }
        else {
            cout << "��i��� � �������i��: ";
            cin >> s[i].ped;
        }
    }
}

void print(Student* s, int amSt)
{
    cout << "=========================================================================================================================="
        << endl;
    cout << "| � |    ��i�����   | ���� |      ����i����i���     | �i���� | ���������� | ������������� | �������i ������ | �������i�� |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < amSt; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[i].lname
            << "| " << setw(5) << right << s[i].kurs
            << "| " << setw(23) << left << strSpec[s[i].spec]
            << "| " << setw(7) << s[i].physics
            << "| " << setw(11) << right << s[i].math;
        if (s[i].spec == 0) {
            cout << "| " << setw(14) << right << s[i].progr
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << " " << "| ";
        }
        else if (s[i].spec == 1) {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << s[i].numb
                << "| " << setw(11) << right << " " << "| ";
        }
        else {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << s[i].ped << "| ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
}


int amount(Student* s, int amSt)
{
    int k = 0;
    for (int i = 0; i < amSt; i++) {
        if (check(s[i])) {
            k++;
        }
    }
    return k;
}

void print_mod(Student* s, int amSt)
{
    cout << "=========================================================================================================================="
        << endl;
    cout << "| � |    ��i�����   | ���� |      ����i����i���     | �i���� | ���������� | ������������� | �������i ������ | �������i�� |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < amSt; i++) {
        if (s[i].physics > 3) {
            cout << "| " << setw(2) << right << i + 1 << "";
            cout << "| " << setw(14) << left << s[i].lname
                << "| " << setw(5) << right << s[i].kurs
                << "| " << setw(23) << left << strSpec[s[i].spec]
                << "| " << setw(7) << s[i].physics
                << "| " << setw(11) << right << s[i].math;
            if (s[i].spec == 0) {
                cout << "| " << setw(14) << right << s[i].progr
                    << "| " << setw(16) << right << " "
                    << "| " << setw(11) << right << " " << "| ";
            }
            else if (s[i].spec == 1) {
                cout << "| " << setw(14) << right << " "
                    << "| " << setw(16) << right << s[i].numb
                    << "| " << setw(11) << right << " " << "| ";
            }
            else {
                cout << "| " << setw(14) << right << " "
                    << "| " << setw(16) << right << " "
                    << "| " << setw(11) << right << s[i].ped << "| ";
            }
            cout << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
}

bool check(Student s) {
    if (s.math > 3 && s.physics > 3 && (s.numb > 3 || s.ped > 3 || s.progr > 3)) {
        return true;
    }
    else {
        return false;
    }
}
