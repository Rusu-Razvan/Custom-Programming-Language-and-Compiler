#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class ParamList {
    public:
    map<string, string> parameters; //name, type
    map<string, string> values; //name, value
    map<string,map<string,string>> classFuncParams;
    map<string,map<string,string>> classFuncValues;

    void addParam(const string& name, const string& type) {
        parameters[name] = type;
        //classFuncParams[name].emplace_back(name,type);
    }

    void addParamValue(const string& name, const string& value) {
        values[name] = value;
        //classFuncParams[name].emplace_back(name,type);
    }

    void addFuncParams(const string& name, const string& type, const string& func_name, std::string value){
        cout<< name<<" "<<type<<" "<<func_name<<  endl;
        classFuncParams[func_name][name]=type;
        classFuncValues[func_name][name]=value;
        for(auto j : classFuncParams[func_name]){
            cout<<j.first<<' '<<j.second << endl;
        }
    }

    ParamList() {}
};

class IdInfo {
    public:
    string idType;
    string type;
    string name;
    string value;
    ParamList params; //for functions
    IdInfo() {}
    IdInfo(const char* type, const char* name, const char* idType) : type(type),name(name),idType(idType),value("") {}
    IdInfo(const char* type, const char* name,const char* idType,const char* value) : type(type),name(name),idType(idType), value(value) {}
    IdInfo(const char* type, const char* name,const char* idType,int value) : type(type),name(name),idType(idType),value(std::to_string(value)) {}

    void printParams(){
        ofstream fout("SymTables.txt",std::ios::app);
        for(pair<string, string> i : params.parameters){
            fout<<"\tname: " << i.first<<" "<<"type: " << i.second<<" Parameter of function: "<<this->name<<endl; 
        }

    }
    void printMembers(){
        ofstream fout("SymTables.txt",std::ios::app);
        //De ce nu se afiseaza membrii functieiii??
        
        for(pair<string, string> i : params.parameters){
            fout<<"\tname: " << i.first<<" "<<"type: " << i.second<<" Member of class: "<<this->name<<endl; 
            for(auto j : params.classFuncParams[i.first]){
                fout<<"\t\tname: " << j.first<<" "<<" type: " << j.second<< " Parameter of function: "<<i.first<<endl; 
            }
        }
        /*for(pair<string, string> i : params.values){
            fout<<"\tname: " << i.first<<" "<<"value: " << i.second<<" Member of class: "<<this->name<<endl; 
        }*/
    }
};



class SymTable {
    
    public:
    map<string, IdInfo> ids;
    SymTable* parent;

    string name;
    SymTable(const char* name) :  name(name){}
    SymTable(const char* name, SymTable* parent = nullptr) : name(name), parent(parent) {}
    bool existsId(const char* s);
    bool existsIdRecursive(const char* s);
    bool existsIdFunction(std::string s, std::string func_name);
    bool existsIdInClass(std::string s, std::string class_name);
    bool existsIdInClassFunc(std::string s, std::string class_name, std::string func_name);
    int getValue(const char* name);
    std::string getValueInClass(std::string name, std::string class_name);
    std::string getRoot();
    SymTable* getRootPointer();
    std::string getValueAsString(const char* name);
    std::string getValueFunction(std::string name, std::string function_name);
    std::string getType(const char* name);
    std::string getTypeFunction(std::string name, std::string function_name);
    std::string getTypeInClass(std::string name,std::string class_name);
    std::string getTypeInClassFunc(std::string name, std::string class_name, std::string func_name);
    void addVar(const char* type, const char* name);
    void addVar(const char* type, const char* name,int value);
    void addVar(const char* type, const char* name,char* value);
    void addVar(const char* type, const char* name,std::string value);
    void addFunc(const char* type, const char* name );
    void addFuncParam(const char* type, const char* name,std::string func_name);
    void addClass(const char* type, const char* name );
    void changeValue(const char* name, char* value);
    void changeValue(const char* name, std::string value);
    void changeValue(const char* name, int value);
    void changeValueFunction(std::string name, std::string value, std::string function_name);
    void changeValueInClass(std::string name, std::string value, std::string class_name);
    void addClassParam(const char* type, const char* name, std::string class_name );
    void addClassParam(const char* type, const char* name, std::string class_name, std::string value );
    void addFuncToClass(const char* type, const char* name, std::string class_name);
    void addParamsToClassFunc(const char* type, const char* name, std::string class_name, std::string func_name, std::string value);
    void printVars();
    void printVals();
    SymTable* whereIsItDeclared(const char* name);
    SymTable* getParent();
    ~SymTable();
};