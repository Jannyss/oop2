#include <iostream>
#include <set>
#include "StatisticMultiset.h"
#include <limits>
#include <numeric>
#include <fstream>

using namespace std;

StatisticMultiset::StatisticMultiset() {}
StatisticMultiset::~StatisticMultiset() {}

void StatisticMultiset::AddNum (int num) {
    //statmset.insert(num);
    //if (statmset.count(num) <> 0) cout << "didn't change";
    statmset.insert(num);

    if (num > maxvalue) maxvalue = num;
    if (num < minvalue) minvalue = num;
    avgvalue = accumulate(statmset.begin(), statmset.end(), 0)/statmset.size();
}

void StatisticMultiset::AddNum (const multiset<int>& numbers) {
    for (multiset<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            StatisticMultiset::AddNum(*it);
        }
}

void StatisticMultiset::AddNum (const vector<int>& numbers) {
    for (vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
            StatisticMultiset::AddNum(*it);
        }
}

void StatisticMultiset::AddNum ( const list<int>& numbers ) {
    for (list<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        StatisticMultiset::AddNum(*it);
    }
}

void StatisticMultiset::AddNums( const StatisticMultiset& a_stat_set ) {
    for (multiset<int>::iterator it = a_stat_set.statmset.begin(); it != a_stat_set.statmset.end(); ++it) {
            StatisticMultiset::AddNum(*it);
        }
}

void StatisticMultiset::AddNumsFromFile( const char* filename ) {
    ifstream datafile;
    datafile.open(filename);
    while (!datafile.eof()) {
        int num;
        datafile >> num;
        StatisticMultiset::AddNum(num);
    }
}

int StatisticMultiset::GetMax() const {
    return maxvalue;
}

int StatisticMultiset::GetMin() const {
    return minvalue;
}

float StatisticMultiset::GetAvg() const {
    return avgvalue;
}

int StatisticMultiset::GetCountUnder(float threshold) const {
    multiset<int>::iterator itup = statmset.upper_bound(threshold);
    int countel = 0;
    for (multiset<int>::iterator it = statmset.begin(); it != itup; ++it) countel++;
    if (statmset.find(threshold) != statmset.end()) countel -= 1;
    return countel;
}

int StatisticMultiset::GetCountAbove(float threshold) const {   //error
    multiset<int>::iterator itlow = statmset.lower_bound(threshold);
    int countel = 0;
    for (multiset<int>::iterator it = itlow; it != statmset.end(); ++it) countel++;
    if (statmset.find(threshold) != statmset.end()) countel -= 1;
    return countel;
}


void StatisticMultiset::ShowMultiset() const {
        for (multiset<int>::iterator it = statmset.begin(); it != statmset.end(); ++it) {
            cout << *it << " ";
        }
}

