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
        changed = 1;
        changedunder = 1;
        changedabove = 1;

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

    T GetMax() const {
        if (!CheckEmptyMultiset()) {
            if (changed == 0) return maxvalue;
            else {
                for (auto i : statmset) {
                    if (i > maxvalue) maxvalue = i;
                }
                return maxvalue;
            }
        }
        else {
            cout << "Error. Multiset is empty.";
            return -1;
        ;}
    }

    T GetMin() const {
        if (!CheckEmptyMultiset()) {
            if (changed == 0) return minvalue;
            else {
                for (auto i : statmset) {
                    if (i < maxvalue) minvalue = i;
                }
                changed = 0;
                return minvalue;
            }
        }
        else {
            cout << "Error. Multiset is empty.";
            return -1;
        }

    }

    float GetAvg() const {
        if (!CheckEmptyMultiset()) {
            if (changed == 0) return avgvalue;
            else {
                avgvalue = (float)accumulate(statmset.begin(), statmset.end(), 0)/statmset.size();
                changed = 0;
                return avgvalue;
            }
        }
        else {
            cout << "Error. Multiset is empty.";
            return -1;
        }
    }

    int GetCountUnder(float threshold) const {
        if (!CheckEmptyMultiset()) {
            if ((countunder.second == threshold) && (changedunder == 0)) return countunder.first;
            else {
                typename multiset<T>::iterator itlow = statmset.lower_bound(threshold);
                int countel = 0;
                for (typename multiset<T>::iterator it = statmset.begin(); it != itlow; ++it) countel++;
                changedunder = 0;
                countunder = make_pair(countel, threshold);
                return countel;
            }
        }
        else {
            cout << "Error. Multiset is empty.";
            return -1;
        }
    }

    int GetCountAbove(float threshold) const {
        if (!CheckEmptyMultiset()) {
            if ((countabove.second == threshold) && (changedabove == 0)) return countabove.first;
            else {
                typename multiset<T>::iterator itup = statmset.upper_bound(threshold);
                int countel = 0;
                for (typename multiset<T>::iterator it = itup; it != statmset.end(); ++it) countel++;
                changedabove = 0;
                return countel;
            }
        }
        else {
            cout << "Error. Multiset is empty.";
            return -1;
        }
    }

    void ShowMultiset() const {
        for (typename multiset<T>::iterator it = statmset.begin(); it != statmset.end(); ++it) {
            cout << *it << " ";
        }
    }

    bool CheckEmptyMultiset() const {
        return statmset.empty();
    }

private:
    multiset<T> statmset;
    mutable pair<int, float> countunder;
    mutable pair<int, float> countabove;
    mutable T maxvalue = numeric_limits<T>::min();
    mutable T minvalue = numeric_limits<T>::max();
    mutable float avgvalue;
    mutable bool changed = 0, changedunder = 0, changedabove = 0;
};
