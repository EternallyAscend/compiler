#include<unordered_map>
#include<string>
#include<vector>


struct PntInfo {
    char type[10];
    int dimension;
    std::vector<int> width;
};

std::unordered_map<std::string, PntInfo*> PntTable;

PntInfo* createPntInfo(const char* type, int dimension);

void setArrayWidth(const char* id, int _width);

 PntInfo* getPntInfo(const char* id);

 void getArrayWidth(const char* id, int _dimension);


