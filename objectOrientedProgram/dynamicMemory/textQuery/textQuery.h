//**************************
// Author:  yh
// Time:    2021/12/26
//**************************

#ifndef CESSENCE_TEXTQUERY_H
#define CESSENCE_TEXTQUERY_H
#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <vector>
#include <memory>
using std::vector;
using std::ifstream;
using std::string;
using std::shared_ptr;
using std::set;
using std::map;

class queryResult;
class textQuery {
public:
    using lineNo = vector<string>::size_type;
    textQuery(ifstream &ifs);
    queryResult query(const string &) const;
private:
    shared_ptr<vector<string>> input;
    map<string, shared_ptr<set<lineNo>>> result;
};

class queryResult {
public:
    friend std::ostream& print(std::ostream &, const queryResult&);
    queryResult(const string& _word, shared_ptr<set<textQuery::lineNo>> _set, shared_ptr<vector<string>> _inputFile)
            : word(_word), nos(_set), inputFile(_inputFile) {}
private:
    string word;
    shared_ptr<set<textQuery::lineNo>> nos;
    shared_ptr<vector<string>> inputFile;
};
std::ostream& print(std::ostream &, const queryResult&);
#endif //CESSENCE_TEXTQUERY_H
