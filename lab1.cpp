// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <fstream>
#include <iostream>

using namespace std;




struct Student
{
    
    char name[27];
    char date_of_birth[12] ;
    
    float grades[8];
    int course;
    int group;

};

int main()
{setlocale(0, "ru");
    const int n = 41;
    cout << "name surname second name == имя фамилия отчество + номер в списке\n" << endl << endl;
    float average = 0;
    float averages[8];
    int k[8];
    char empty[1];
    Student st[8];
    ifstream fin;
    int b,v; float d;
    fin.open("TextFile3.txt");
   
    for (b = 0; b < 8; b++) {
        average = 0;
        fin.read(empty, 1);//решает непонятную проблему с чтением данных
       
        fin.getline(st[b].name, 27,'\n');
        fin.getline(st[b].date_of_birth, 12, '\n');
        for (int k1 = 0; k1 < 8; k1++) {
            fin >> st[b].grades[k1];
            average += st[b].grades[k1];
        }
        
        fin >> st[b].course;
        fin >> st[b].group;
        averages[b] = average / 8;//средняя оценка
        
        k[b] = b;cout <<st[b].name<<" : "<< averages[b] << endl ;//вывод масива средних оценок студентов
    }
    //упорядочение массива средних оценок
    for (v = 0; v < 2; v++) {//2 итерации достаточно для упорядочения
        
        for (b = 0; b < 7; b++) {
            
            if (averages[b] < averages[b + 1]) {
                d = averages[b]; averages[b] = averages[b + 1]; averages[b + 1] = d; d = k[b];k[b] = k[b + 1]; k[b + 1] = d;
            }
            
        }

    }
    //вывод имен студентов по среднему баллу
   
        for (int v = 0; v < 8; v++) {
            cout <<'\n'<<'\n' << st[k[v]].name << ": средний бал = " << averages[v] << endl;

        }
    
  
  
    fin.close();
    
    
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
