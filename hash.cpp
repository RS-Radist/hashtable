/*Задание: Создайте хеш-таблицу инвентаря магазина конфет.
           Таблица будет представлять собой массив структур.
           Программа должна позволять проводить проверку цен.

Input: Значения данных таблицы будут считаны из текстового файла. Входным файлом является C162P7candy.txt (см. Ниже). Программа будет инициализировать таблицу, используя хеш-функцию для размещения каждой структуры в соответствующем расположении массива. Используемая структура данных:

struct Candy
{
    string IDcode; // 4-char alphanumeric code
    string itemName; // name/description of the candy
    double quantity; // quantity on hand, in pounds
    double price; // price per pound
};

Вы можете определить размер массива. Создайте соответствующий хеш-расчет, чтобы назначить каждый элемент в массив. Решите, как будут обрабатываться одинаковые элементы таблицы(collision); для этого назначения используйте метод, отличный от линейного.

Processing: укажите меню для пользователя. Варианты должны включать:
availability check: товар на складе (количество> 0), и если да, какова его цена?
purchase: уменьшить количество на определенную сумму
delivery: увеличение количества
inventory: распечатать полную инвентаризацию в отчете о печатной копии
 
 C433
 candy corn
 10.0
 1.15
 C672
 caramels
 20.0
 1.25
 K761
 chocolate kisses
 22.0
 2.95
 F045
 fudge
 7.0
 4.99
 G123
 gumballs
 5.5
 1.75
 J004
 jelly beans
 30.0
 1.19
 L878
 licorice
 15.5
 2.30
 P767
 peanut brittle
 5.3
 3.45
 R117
 raisin clusters
 30.0
 1.79
 R068
 rock candy
 3.0
 1.5
 S030
 seafoam
 7.0
 1.19
 T555
 truffles
 12.0
 8.99
*/
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <math.h>


using namespace std;

struct Candy
{
    string IDcode; // 4-char alphanumeric code
    string itemName; // name/description of the candy
    double quantity; // quantity on hand, in pounds
    double price; // price per pound
};
/*
int Din_Number(int number)
{
    int j=26;
    int sum = 0;
    for (int i=65;i<=90;++i)
    {
        if(number==i)
        {
            sum=(90-i)-j;
            if (sum<0)
            {
                sum=-sum;
            }
        }
    }
    return sum;
}
void output(multimap<int, Candy>& temp)
{
    FILE *f;
    string a;
    string* dyn;
    int c=0;
    int size=4;
    f = fopen("C162P7candy.txt","r");
    ifstream fin ("C162P7candy.txt");
    for (int i=0;i<4;++i)
    {
        getline(fin,a);
        dyn=new string[size];
        dyn[c]=a;
        int numberA=static_cast<int>(a[0]);
        if(numberA>=65&&numberA<=90)
        {
            Din_Number(numberA);
        }
        
        if (!(dyn[0].empty())||!(dyn[1].empty()))
        {
            Candy* temp_struct;
            temp_struct=new Candy;
            temp_struct->IDcode=dyn[0];
            temp_struct->itemName=dyn[1];
            temp_struct->quantity=atof(dyn[2].c_str());
            temp_struct->price=atof(dyn[3].c_str());
            pair<int,Candy>element( numberA, *temp_struct );
            temp.insert(element);
            cout<<temp_struct->IDcode;
            cout<<temp_struct->itemName<<endl;
//            cout<<temp_struct->quantity<<endl;
//            cout<<temp_struct->price<<endl;
            c=0;
            delete[] dyn;
        }
        ++c;
    }
    fclose(f);
}
 */

void AddRightDigit(int &D, int K)
{
    D = D*100 + K;
}
int numberID(int& number)
{
    int sum=number%12;
    return sum;
}
void output(multimap<int, Candy>& temp)
{
    FILE *f;
    string str;
    int number = 0;
    Candy object;
    //object=new Candy;
    int circle=0;
    f = fopen("C162P7candy.txt","r");
    ifstream fin ("C162P7candy.txt");
    for (int j=0;j<50;++j)
    {
        getline(fin,str);
        if(str[0]>=65&&str[0]<=90)
        {
            for(int p=0;p<str.size();++p)
            {
                int temp_cast;
                temp_cast=static_cast<int>(str[p]);
                AddRightDigit(number, temp_cast);
                object.IDcode=str;
                circle=1;
            }
        }
        
        if(str[0]>=97&&str[0]<=122)
        {
            object.itemName=str;
            ++circle;
        }
        if(atof(str.c_str()))
        {
            object.quantity=atof(str.c_str());
            ++circle;
        }
//        if(object)///
//        {
//            cout<<" qweqe";
//            object.price=atof(str.c_str());
//            ++circle;
//        }
        if(circle==3)
        {
            numberID(number);
            temp.insert(make_pair(numberID(number),object));
        }
       // object->quantity=atof(str.c_str());
        
        
    }
    fclose(f);
}

int main()
{
//    int x;
//    x=67525151%12;
//    cout<<endl;
//    cout<<endl;
//    cout<<x;
    multimap<int, Candy> table;
    output(table);
    multimap<int, Candy>::iterator it;
    for(it=table.begin();it!=table.end();it++)
    {
        cout<<it->first<<" "<<it->second.IDcode<<" "<<it->second.itemName<<" "<<it->second.quantity<<" "<<it->second.price<<endl;
    }
    
//    Processing: укажите меню для пользователя. Варианты должны включать:
//    availability check: товар на складе (количество> 0), и если да, какова его цена?
//    purchase: уменьшить количество на определенную сумму
//    delivery: увеличение количества
//    inventory: распечатать полную инвентаризацию в отчете о печатной копии
    
}
