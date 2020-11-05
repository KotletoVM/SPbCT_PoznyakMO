#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std::string_literals;
using namespace std;
class Raspisanie {
    public:
        int i = 0, j = 0;
        int formrasp() {
            fstream MF;
            MF.open("data.csv");
            string* datemas = new string[366];
            string* timemas = new string[100];
            string firstname, lastname, svalka;
            while (MF.good()) {
                    getline(MF, datemas[i], ';');
                    getline(MF, svalka, '\n');
                    i++;
            }
            MF.close();
            MF.open("data.csv");
            int a, s = 0, schet = 0;
            bool n = true;
            string date, ln, fn, pb, dat, vremya, imya, otch, fam, polis, zap = ";", per = "\n", time;
                cout << "Укажите дату приема (xx.xx.xxxx):\n";
                cin >> date;
                cout << "Занятое время для записи: \n";
                        while (MF.good()){
                            getline(MF, dat, ';');
                            schet++;
                            if (dat == date) {
                                getline(MF, vremya, ';');
                                getline(MF, fam, ';');
                                getline(MF, imya, ';');
                                getline(MF, otch, ';');
                                getline(MF, polis, '\n');
                                cout << vremya << ":00" << " " << fam << " " << imya << " " << otch << " " << polis << "\n";
                                timemas[j] = vremya;
                                j++;

                            }
                            else {
                                getline(MF, svalka, '\n');
                            }
                        }
                MF.close();
                a:
                cout << "Выберите время приема, отличное от занятого, в пределах от 9 до 17:";
                cin >> time;
                    for (int i = 0; i <= j; i++) {
                        if (time == timemas[i]) {
                            cout << "Вы выбрали занятое время, попробуйте еще раз:\n";
                            goto a;
                        }
                    }
                cout << "Укажите фамилию пациента\n";
                cin >> ln;
                cout << "Укажите имя пациента\n";
                cin >> fn;
                cout << "Укажите отчество пациента\n";
                cin >> pb;
                cout << "Укажите номер полиса пациента\n";
                cin >> polis;
                MF.open("data.csv", std::ios::app);
                    MF << per << date << zap << time << zap << ln << zap << fn << zap << pb << zap << polis;
                
                MF.close();
                
            return 0;
        };
        int coutraspdate() {
            int n = 0;
            string dat, vremya, fam, imya, otch, polis, svalka;
            string date;
            cout << "\n";
            cout << "Выберите дату:\n";
            cin >> date;
            cout << "Записи на выбранный день:\n";
            fstream MF;
            MF.open("data.csv");
            while (MF.good()) {
                getline(MF, dat, ';');
                if (dat == date) {
                    getline(MF, vremya, ';');
                    getline(MF, fam, ';');
                    getline(MF, imya, ';');
                    getline(MF, otch, ';');
                    getline(MF, polis, '\n');
                    cout << vremya << ":00" << " " << fam << " " << imya << " " << otch << " " << polis << "\n";
                    n++;
                }
                else {
                    getline(MF, svalka, '\n');
                }
            }
            if (n == 0) {
                cout << "На выбранный день нет записей\n";
            }
            return 0;
        }
        int coutrasp() {
            string dat, vremya, fam, imya, otch, polis;
            fstream MF;
            MF.open("data.csv");
            while (MF.good()) {
                getline(MF, dat, ';');
                getline(MF, vremya, ';');
                getline(MF, fam, ';');
                getline(MF, imya, ';');
                getline(MF, otch, ';');
                getline(MF, polis, '\n');
                cout << dat << " " << vremya << ":00" << " " << fam << " " << imya << " " << otch << " " << polis << "\n";
                }
            MF.close();
            return 0;
            }
        int udal() {
            string dat, vremya, fam, imya, otch, polis, zap = ";", per = "\n";
            int i = 1, j = 0, nomer, chisl = 0;
            fstream MF;
            MF.open("data.csv");
            fstream COPY;
            COPY.open("copy.csv");
            while (MF.good()) {
                getline(MF, dat, ';');
                getline(MF, vremya, ';');
                getline(MF, fam, ';');
                getline(MF, imya, ';');
                getline(MF, otch, ';');
                getline(MF, polis, '\n');
                cout << i << ". " << dat << " " << vremya << ":00" << " " << fam << " " << imya << " " << otch << " " << polis << "\n";
                i++;
            }
            MF.close();
            MF.open("data.csv");
            cout << "Введите номер строки, которую надо удалить\n";
            cin >> nomer;
            i = 1;
            while (MF.good()) {
                getline(MF, dat, ';');
                getline(MF, vremya, ';');
                getline(MF, fam, ';');
                getline(MF, imya, ';');
                getline(MF, otch, ';');
                getline(MF, polis, '\n');
                if (nomer == i) {
                    cout << "\nСтрока номер " << i << ". " << dat << " " << vremya << ":00" << " " << fam << " " << imya << " " << otch << " " << polis << " Удалена\n";
                    chisl = 1;
                }
                else {
                    if (j == 0) {
                        COPY << dat << zap << vremya << zap << fam << zap << imya << zap << otch << zap << polis;
                        j++;
                    }
                    else {
                        COPY << per << dat << zap << vremya << zap << fam << zap << imya << zap << otch << zap << polis;

                    }
                }
                i++;
            }
            MF.close();
            COPY.close();
            if (chisl == 0) {
                cout << "Строки с таким номером нет\n";
            }
            else if (chisl == 1){
                rename("data.csv", "copy1.csv");
                cout << "\n";
                rename("copy.csv", "data.csv");
                cout << "\n";
                rename("copy1.csv", "copy.csv");
                remove("copy.csv");
                ofstream oFile("copy.csv");
            }
            return 0;
        }
};

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Raspisanie raspisanie;
    bool m = true;
    int deistv;
    while (m)
    {
        cout << "Выберите действие:\n";
        cout << "1. Добавить запись\n";
        cout << "2. Посмотреть расписание на определенный день\n";
        cout << "3. Посмотреть всё расписание\n";
        cout << "4. Удалить запись\n";
        cout << "5. Выйти\n";
        cin >> deistv;
        if (deistv == 1) {
            raspisanie.formrasp();
        }
        else if (deistv == 2) {
            raspisanie.coutraspdate();
        }
        else if (deistv == 3) {
            raspisanie.coutrasp();
        }
        else if (deistv == 4) {
            raspisanie.udal();
        }
        else if (deistv == 5) {
            m = false;
        }
        else {
            cout << "Нет такого действия\n";
        }
    }
}
