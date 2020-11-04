
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std::string_literals;
using namespace std;
class Zapis {
public:
    string lastname = "";
    string firstname = "";
    string pobatiushke;
    string date = "";
    int time = -1;
    string polis;
};
class Raspisanie {
    public:
        int i = 0;
        Zapis* zapis = new Zapis[10];
        int formrasp() {
            fstream MF;
            MF.open("data.csv");
            string* datemas = new string[366];
            string firstname, lastname, svalka;
            while (MF.good()) {
                    getline(MF, datemas[i], ',');
                    getline(MF, svalka, '\n');
                    i++;
            }
            MF.close();
            MF.open("data.csv");
            int a, s = 0, time;
            int* zanyato = new int[10];
            string date, ln, fn, pb, dat, vremya, imya, otch, fam, polis, zap = ",", per = "\n";
                cout << "Укажите дату приема (xx.xx.xxxx):\n";
                cin >> date;
                for (int i = 0; i < 366; i++) {
                    if (date == datemas[i]) {
                        cout << "Занятое время для записи: \n";
                        while (MF.good()){
                            getline(MF, dat, ',');
                            if (dat == date) {
                                getline(MF, vremya, ',');
                                getline(MF, fam, ',');
                                getline(MF, imya, ',');
                                getline(MF, otch, ',');
                                getline(MF, polis, '\n');
                                cout << vremya << ":00" << " " << fam << " " << imya << " " << otch << " " << polis << "\n";
                            }
                            getline(MF, svalka, '\n');
                        }
                    }
                    else {
                    }
                }
                MF.close();
                cout << "Выберите время приема, отличное от занятого, в пределах от 9 до 17:";
                cin >> time;
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
            int n = 10;
            string dat, vremya, fam, imya, otch, polis, svalka;
            string date;
            cout << "\n";
            cout << "Выберите дату:\n";
            cin >> date;
            cout << "Записи на выбранный день:\n";
            fstream MF;
            MF.open("data.csv");
            while (MF.good()) {
                getline(MF, dat, ',');
                if (dat == date) {
                    getline(MF, vremya, ',');
                    getline(MF, fam, ',');
                    getline(MF, imya, ',');
                    getline(MF, otch, ',');
                    getline(MF, polis, '\n');
                    cout << vremya << ":00" << " " << fam << " " << imya << " " << otch << " " << polis << "\n";
                }
                else {
                    getline(MF, svalka, '\n');
                }
            }
            return 0;
        }
        int coutrasp() {
            string dat, vremya, fam, imya, otch, polis;
            fstream MF;
            MF.open("data.csv");
            while (MF.good()) {
                getline(MF, dat, ',');
                getline(MF, vremya, ',');
                getline(MF, fam, ',');
                getline(MF, imya, ',');
                getline(MF, otch, ',');
                getline(MF, polis, '\n');
                cout << dat << " " << vremya << ":00" << " " << fam << " " << imya << " " << otch << " " << polis << "\n";
                }
            return 0;
            }
        int udal() {
            string dat, vremya, fam, imya, otch, polis, zap = ",", per = "\n";
            int i = 1, j = 0, nomer;
            fstream MF;
            MF.open("data.csv");
            fstream COPY;
            COPY.open("copy.csv");
            while (MF.good()) {
                getline(MF, dat, ',');
                getline(MF, vremya, ',');
                getline(MF, fam, ',');
                getline(MF, imya, ',');
                getline(MF, otch, ',');
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
                getline(MF, dat, ',');
                getline(MF, vremya, ',');
                getline(MF, fam, ',');
                getline(MF, imya, ',');
                getline(MF, otch, ',');
                getline(MF, polis, '\n');
                if (nomer == i) {
                    cout << "\nСтрока номер " << i << ". " << dat << " " << vremya << ":00" << " " << fam << " " << imya << " " << otch << " " << polis << " Удалена\n";
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
            rename("data.csv", "copy1.csv");
            rename("copy.csv", "data.csv");
            rename("copy1.csv", "copy.csv");
            return 0;
        }
};

int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Raspisanie raspisanie;
    bool n = true;
    int deistv;
    while (n)
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
            n = false;
        }
        else {
            cout << "Нет такого действия\n";
        }
    }
}
