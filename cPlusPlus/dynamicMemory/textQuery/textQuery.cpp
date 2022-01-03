//**************************
// Author:  yh
// Time:    2021/12/26
//**************************
#include <algorithm>
#include <sstream>
#include <cctype>
#include "textQuery.h"

textQuery::textQuery(ifstream &ifs) : input(new vector<string>) {
    lineNo lineNoTmp{ 0 };

    for(string line; getline(ifs, line); ++lineNoTmp) {
        input->push_back(line);
        std::istringstream line_stream(line);
        for(string text, word; line_stream >> text; word.clear()) {
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            //std::cout << "text: " << text  << " word: " << word << std::endl;
            auto &nos =result[word];
            if(!nos) {
                nos.reset(new set<lineNo>);
            }
            nos->insert(lineNoTmp);
        }
    }
}

queryResult textQuery::query(const string & str) const {
    static shared_ptr<std::set<lineNo>> nodata(new std::set<lineNo>);
    auto found = result.find(str);

    if (found == result.end()) {
        return queryResult(str, nodata, input);
    } else {
        return queryResult(str, found->second, input);
    }
}

std::ostream& print(std::ostream &out, const queryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i+1 << ") " << qr.inputFile->at(i) << std::endl;
    return out;
}

void runQueries(std::ifstream &infile)
{
    textQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main()
{
    std::ifstream file("../cPlusPlus/data/storyDataFile.txt");
    runQueries(file);

    return 0;
}

