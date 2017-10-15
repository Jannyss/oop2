#ifndef STATISTICMULTISET_H_INCLUDED
#define STATISTICMULTISET_H_INCLUDED
#pragma once
#include <set>
#include <limits>
#include <vector>
#include <list>
#endif // STATISTICMULTISET_H_INCLUDED
using namespace std;

class StatisticMultiset {
public:
    StatisticMultiset();
    ~StatisticMultiset();
    // Добавляет число в набор.
    void AddNum( int num );
    // Данные из multiset-а
    void AddNum( const multiset<int>& numbers );
    // Данные из вектора
    void AddNum( const vector<int>& numbers );
    // Данные из списка
    void AddNum( const list<int>& numbers );
    // Данные из другого набора
    void AddNums( const StatisticMultiset& a_stat_set );
    // Данные из файла
    void AddNumsFromFile( const char* filename );
    // Максимальное число в наборе.
    int GetMax() const;
    // Минимальное число в наборе.
    int GetMin() const;
    // Среднее арифметическое всего набора.
    float GetAvg() const;
    // Кол-во чисел в наборе меньше заданного порога.
    int GetCountUnder( float threshold ) const;
    // Кол-во чисел в наборе больше заданного порога.
    int GetCountAbove( float threshold ) const;
    // Содержимое набора
    void ShowMultiset() const;

private:
    multiset<int> statmset;
    int maxvalue = numeric_limits<int>::min();
    int minvalue = numeric_limits<int>::max();
    float avgvalue;
};


