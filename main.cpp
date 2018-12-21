#include <iostream>
#include "Vector.h"
#include "Figure.h"
#include <cstdlib>
#include <memory>
#include "TAlloccationBlock.h"

using std::cin;
using std::cout;
using std::endl;

void menu();

int main() {
    int key;
    int index;
    int a = 0;
    int b = 0;
    int c = 0;

    std::shared_ptr<Figure> tri;
    LolVector<Figure> *vector = new LolVector <Figure> (10);
    Trapeze *t = nullptr;
    Pentagon *r = nullptr;
    Rhombus *f = nullptr;
    do {
        menu();
        cin >> key;
        switch(key){
            case 1:
                cout << "Введите стороны трапеции" << endl;
                cin >> a >> b >> c;
                t = new Trapeze (a, b, c);
                tri = std::shared_ptr<Figure>(t);
                vector -> Push(tri);
                break;
            case 2:
                cout << "Введите стороны ромба" << endl;
                cin >> a;
                f = new Rhombus(a);
                tri = std::shared_ptr<Figure>(f);
                vector -> Push(tri);
                break;
            case 3:
                cout << "Введите стороны пятиугольника" << endl;
                cin >> a >> b;
                r = new Pentagon(a, b);
                tri = std::shared_ptr<Figure>(r);
                vector -> Push(tri);
                break;
            case 4:
                cout << "Введите индекс фигуры" << endl;
                cin >> index;
                if (index >= vector -> GetSize()) {
                    cout << "Фигура не найдена" << endl;
                } else {
                        vector -> Get(index);
                    }
                break;
            case 5:
                if(vector -> GetSize() > 0){
                    vector -> Delete();
                } else {
                    cout << "Фигура не найдена" << endl;
                }
                break;
            case 6:
                vector -> ~LolVector();
                key = 0;
                break;
            case 7:
                cout << *vector;
                break;
            case 8:
                for (auto i : *vector) {
                    (*i).Print();
                }
                break;
            case 0:
                break;
            default:
                cout << "Неизвестная команда" << endl;
                break;
            }
        } while(key);    
    }   

void menu(){
    cout << "Введите номер" << endl;
    cout << "1) Дать значения трапеции" << endl;
    cout << "2) Дать значения ромбу" << endl;
    cout << "3) Дать значения пятиугольнику" << endl;
    cout << "4) Индекс фигуры" << endl;
    cout << "5) Удалить последнюю фигуру" << endl;
    cout << "6) Удалить все фигуры" << endl;
    cout << "7) Напечатать вектор" << endl;
    cout << "8) 'for' с итератором" << endl;
    cout << "0) Выход" << endl;
}