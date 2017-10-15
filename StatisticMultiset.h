#ifndef STATISTICMULTISET_H_INCLUDED
#define STATISTICMULTISET_H_INCLUDED
#endif // STATISTICMULTISET_H_INCLUDED
#pragma once
#include <set>
#include <limits>
#include <vector>
#include <list>
#include <numeric>
#include <fstream>

using namespace std;
template<class T>

class StatisticMultiset {
public:
    // Добавляет число в набор.
    void AddNum( const T &num ) {
        statmset.insert(num);
        if (num > maxvalue) maxvalue = num;
        if (num < minvalue) minvalue = num;
        avgvalue = accumulate(statmset.begin(), statmset.end(), 0)/statmset.size();
    };
    // Данные из multiset-а
    void AddNum( const multiset<T>& numbers ) {
        for (typename multiset<T>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            StatisticMultiset::AddNum(*it);
        }
    }

    void AddNum (const vector<T>& numbers) {
    for (typename vector<T>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
            StatisticMultiset::AddNum(*it);
        }
    }

    void AddNum ( const list<T>& numbers ) {
        for (typename list<T>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
            StatisticMultiset::AddNum(*it);
        }
    }

    void AddNums( const StatisticMultiset& a_stat_set ) {
        for (typename multiset<T>::iterator it = a_stat_set.statmset.begin(); it != a_stat_set.statmset.end(); ++it) {
            StatisticMultiset::AddNum(*it);
        }
    }

    void AddNumsFromFile( const char* filename ) {
        ifstream datafile;
        datafile.open(filename);
        while (!datafile.eof()) {
            T num;
            datafile >> num;
            StatisticMultiset::AddNum(num);
        }
    }

    int GetMax() const {
        return maxvalue;
    }

    int GetMin() const {
        return minvalue;
    }

    float GetAvg() const {
        return avgvalue;
    }

    int GetCountUnder(float threshold) const {
        typename multiset<T>::iterator itlow = statmset.lower_bound(threshold);
        int countel = 0;
        for (typename multiset<T>::iterator it = statmset.begin(); it != itlow; ++it) countel++;
        //if (statmset.find(threshold) != statmset.end()) countel -= 1;
        return countel;
    }

    int GetCountAbove(float threshold) const {
        typename multiset<T>::iterator itup = statmset.upper_bound(threshold);
        int countel = 0;
        for (typename multiset<T>::iterator it = itup; it != statmset.end(); ++it) countel++;
        //if (statmset.find(threshold) != statmset.end()) countel -= 1;
        return countel;
    }

    void ShowMultiset() const {
        for (typename multiset<T>::iterator it = statmset.begin(); it != statmset.end(); ++it) {
            cout << *it << " ";
        }
}

private:
    multiset<T> statmset;
    T maxvalue = numeric_limits<T>::min();
    T minvalue = numeric_limits<T>::max();
    float avgvalue;
};
