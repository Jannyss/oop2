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
    // ��������� ����� � �����.
    void AddNum( int num );
    // ������ �� multiset-�
    void AddNum( const multiset<int>& numbers );
    // ������ �� �������
    void AddNum( const vector<int>& numbers );
    // ������ �� ������
    void AddNum( const list<int>& numbers );
    // ������ �� ������� ������
    void AddNums( const StatisticMultiset& a_stat_set );
    // ������ �� �����
    void AddNumsFromFile( const char* filename );
    // ������������ ����� � ������.
    int GetMax() const;
    // ����������� ����� � ������.
    int GetMin() const;
    // ������� �������������� ����� ������.
    float GetAvg() const;
    // ���-�� ����� � ������ ������ ��������� ������.
    int GetCountUnder( float threshold ) const;
    // ���-�� ����� � ������ ������ ��������� ������.
    int GetCountAbove( float threshold ) const;
    // ���������� ������
    void ShowMultiset() const;

private:
    multiset<int> statmset;
    int maxvalue = numeric_limits<int>::min();
    int minvalue = numeric_limits<int>::max();
    float avgvalue;
};


