    #include "SymTable.h"
    #include <cstring>
    using namespace std;

    void SymTable::addVar(const char* type, const char*name) {
        IdInfo var(type, name, "var");
        ids[name] = var; 
    }

    void SymTable::addVar(const char* type, const char*name, int value) {
        IdInfo var(type, name,  "var",value);
        ids[name] = var; 
    }

    void SymTable::addVar(const char* type, const char*name,  char* value) {
        if(value[0] == '"' && value[strlen(value)-1] == '"' ||
        value[0] == '\'' && value[strlen(value)-1] == '\'') {
            value = value + 1;
            value[strlen(value)-1] = 0;
        }
        IdInfo var(type, name,  "var",value);
        ids[name] = var; 
    }

    void SymTable::addVar(const char* type, const char*name,  std::string value) {
            if(value[0] == '"' && value[value.length()-1] == '"' ||
            value[0] == '\'' && value[value.length()-1] == '\'') {
            value.erase(0,1);
            value[value.length()-1] = 0;
        }
        ids[name].value = value;
        IdInfo var(type, name,  "var",value.c_str());
        ids[name] = var; 
    }

    void SymTable::addFunc(const char* type, const char*name) {
        if(strcmp(type,"int")== 0){
            IdInfo func(type, name, "func", "1");
            ids[name] = func; 
        }
        else if(strcmp(type,"float")== 0){
            IdInfo func(type, name, "func", "1.0");
            ids[name] = func; 
        }
        else if(strcmp(type,"bool")== 0){
            IdInfo func(type, name, "func", "true");
            ids[name] = func; 
        }
        else{
            IdInfo func(type, name, "func");
            ids[name] = func; 
        }
        
    }

    void SymTable::addFuncParam(const char* type, const char* name, std::string function_name){
        this->ids[function_name].params.addParam(name,type);
        this->ids[function_name].params.addParamValue(name,"1");
    }

    void SymTable::addFuncToClass(const char* type, const char* name, std::string class_name){
        this->ids[class_name].params.addParam(name,type);
    }

    void SymTable::addParamsToClassFunc(const char* type, const char* name, std::string class_name, std::string func_name, std::string value){
        if(!existsIdRecursive(class_name.c_str())){
            cout<<"Doesnt exist\n";
        }
        this->ids[class_name].params.addFuncParams(name,type,func_name,value);
    }

    bool SymTable::existsIdInClassFunc(std::string s, std::string class_name, std::string func_name){
        SymTable* temp = this;
        while(temp->name!="classes"){
            temp = temp->getParent();
        }
        if(temp->ids[class_name].params.classFuncParams[func_name].find(s)!=temp->ids[class_name].params.classFuncParams[func_name].end()){
            return true;
        }
        return false;
    }

    std::string SymTable::getTypeInClassFunc(std::string name, std::string class_name, std::string func_name){
        SymTable* temp = this;
        while(temp->name!="classes"){
            temp = temp->getParent();
        }
        return temp->ids[class_name].params.classFuncParams[func_name][name];  
    }
    
    void SymTable::addClassParam(const char* type, const char* name, std::string class_name){
        this->ids[class_name].params.addParam(name,type);
        this->ids[class_name].params.addParamValue(name,"invalid");
    }

    void SymTable::addClassParam(const char* type, const char* name, std::string class_name,std::string value){
        this->ids[class_name].params.addParam(name,type);
        this->ids[class_name].params.addParamValue(name,value);
    }

    void SymTable::addClass(const char* type, const char*name) {
        IdInfo clas(type, name, "class");
        ids[name] = clas; 
    }

    bool SymTable::existsId(const char* s) {
        return ids.find(s) != ids.end();
    }

    int SymTable::getValue(const char* name) {
        //return std::stoi(ids[name].value);
        SymTable* temp = this->whereIsItDeclared(name);
        if(existsIdRecursive(name) && !temp->ids[name].value.empty()){
            try{
                return std::stoi(temp->ids[name].value);
            }
            catch(const std::invalid_argument& e){
                printf("Invalid use! %s\n",e.what());
                return -9999;
            }
        }
        else if(!existsIdRecursive(name)){
            printf("Variable %s used in equation but not defined.\n", name);
            return -9999;
        } else if(temp->ids[name].value.empty()){
            printf("Variable %s used in equation but not initiated.%s\n", name, temp->name.c_str());
            return -9999;
        }
        return -9999;
    }

    std::string SymTable::getValueAsString(const char* name) {
        //return std::stoi(ids[name].value);
        SymTable* temp = this->whereIsItDeclared(name);
        if(existsIdRecursive(name) && !temp->ids[name].value.empty()){
            try{
                return temp->ids[name].value;
            }
            catch(const std::invalid_argument& e){
                printf("Invalid use! %s\n",e.what());
                return "invalid";
            }
        }
        else if(!existsIdRecursive(name)){
            printf("Variable %s used in equation but not defined.\n", name);
            return "invalid";
        } else if(temp->ids[name].value.empty()){
            printf("Variable %s used in equation but not initiated.%s\n", name, temp->name.c_str());
            return "invalid";
        }
        return "invalid";
    }

    std::string SymTable::getType(const char* name) {
        //return std::stoi(ids[name].value);
        SymTable* temp = this->whereIsItDeclared(name);
        if(existsIdRecursive(name) /*&& !temp->ids[name].value.empty()*/){
            return temp->ids[name].type;
        }
        else if(!existsIdRecursive(name)){
            printf("Variable %s used in equation but not defined.\n", name);
            return "invalid";
        } /*else if(temp->ids[name].value.empty()){
            printf("Variable %s used in equation but not initiated.%s\n", name, temp->name.c_str());
            return "invalid";
        }*/
        return "invalid";
    }


    bool SymTable::existsIdRecursive(const char* s) {
        if(ids.find(s) != ids.end()) {
            return true;
        }
        if (parent != nullptr) {
            return parent->existsIdRecursive(s);
        }
        return false;  
    }

    bool SymTable::existsIdFunction(std::string s, std::string function_name){
        if(existsIdRecursive(s.c_str())) {
            return true;
        }    
        SymTable* temp = this->getParent();
        while(temp->name != "functions"){
            temp = temp->getParent();
        }
        if(temp->ids[function_name].params.parameters.find(s) != temp->ids[function_name].params.parameters.end()){
            return true;
        }
        return false;
    }

    std::string SymTable::getTypeFunction(std::string name, std::string function_name){
        if(existsIdRecursive(name.c_str())){
            SymTable* temp = whereIsItDeclared(name.c_str());
            return temp->ids[name].type;
        }
        else{
            SymTable* temp = this->getParent();        
            while(temp->name != "functions"){
                temp = temp->getParent();
            }
            return temp->ids[function_name].params.parameters[name];
        }
        return "invalid";
    }

    void SymTable::changeValueFunction(std::string name, std::string value, std::string function_name){
        if(existsId(name.c_str())){
            this->ids[name].value = value;
        }
        else{
            SymTable* temp = this->getParent();
            //cout<<name<<' '<<value<<' '<<temp->ids[function_name].params.values[name];
            while(temp->name != "functions"){
                temp = temp->getParent();
            }
            temp->ids[function_name].params.values[name] = value;
        }
    }

    std::string SymTable::getValueFunction(std::string name, std::string function_name){
        if(existsId(name.c_str())){
            return this->ids[name].value;
        }
        else{
            SymTable* temp = this->getParent();
            /*for(auto i : temp->ids[function_name].params.values){
                if(i.first == name){
                    return i.second;
                }
            }
            return "invalid";*/
            while(temp->name != "functions"){
                temp = temp->getParent();
            }
            return temp->ids[function_name].params.values[name];
        }
        return "invalid";
    }


    std::string SymTable::getTypeInClass(std::string name,std::string class_name){
        SymTable* temp = this;
        while(temp->name!="classes"){
            temp = temp->getParent();
        }
        return temp->ids[class_name].params.parameters[name];
    }

    bool SymTable::existsIdInClass(std::string s, std::string class_name){
        SymTable* temp = this;
        while(temp->name!="classes"){
            temp = temp->getParent();
        }
        if(temp->ids[class_name].params.parameters.find(s)!=temp->ids[class_name].params.parameters.end()){
            return true;
        }
        return false;
    }


    void SymTable::changeValueInClass(std::string name, std::string value, std::string class_name){
        SymTable* temp = this;
        while(temp->name!="classes"){
            temp = temp->getParent();
        }
        temp->ids[class_name].params.values[name] = value;
    }

    std::string SymTable::getValueInClass(std::string name, std::string class_name){
        SymTable* temp = this;
        while(temp->name!="classes"){
            temp = temp->getParent();
        }
        return temp->ids[class_name].params.values[name];
    }



    SymTable* SymTable::whereIsItDeclared(const char* name){
        SymTable* temp = new SymTable("temp",nullptr);

        if(this->existsId(name)){
            return this;
        }
        else{
            temp = this->getParent();
            while(!temp->existsId(name)){
                temp = temp->getParent();
            }
            if(temp->existsId(name)){
                return temp;
            }
            else return nullptr;
        }

    }

    void SymTable::printVars() {
        ofstream fout("SymTables.txt", std::ios::app);
        if(this->name == "global"){
            fout<<"Variables:\n";
        }
        else if(this->name == "functions"){
            fout<<"Functions:\n";
        }
        else if(this->name == "classes"){
            fout<<"Classes:\n";
        }
        for (pair<string, IdInfo> v : ids) {
            fout << "name: " << v.first << " type:" << v.second.type << " value: " <<(v.second.value.empty() ? "uninitialized" : v.second.value)  <<  " idType: "<< v.second.idType<<endl; 
            if(v.second.idType == "func") {
                v.second.printParams();
            }
            if(v.second.idType == "class"){
                v.second.printMembers();
            }
        }
    }

    void SymTable::printVals(){
        ofstream fout("SymTables.txt", std::ios::app);
        if(this->name == "global"){
            fout<<"Variables:\n";
        }
        else if(this->name == "functions"){
            fout<<"Functions:\n";
        }
        else if(this->name == "classes"){
            fout<<"Classes:\n";
        }
        for (pair<string, IdInfo> v : ids) {
            fout << "name: " << v.first << " type:" << v.second.type << " value: " <<(v.second.value.empty() ? "uninitialized" : v.second.value)  <<  " idType: "<< v.second.idType<<endl; 
            if(v.second.idType == "func") {
                v.second.printParams();
            }
            if(v.second.idType == "class"){
                v.second.printMembers();
            }
        }   
    }

    std::string SymTable::getRoot(){
        SymTable* temp = this;
        while(temp->getParent()!=nullptr){
            temp = temp->getParent();
        }
        //cout<<temp->name;
        return temp->name;
    }


    SymTable* SymTable::getRootPointer(){
        SymTable* temp = this;
        while(temp->getParent()!=nullptr){
            temp = temp->getParent();
        }
        //cout<<temp->name;
        return temp;
    }


    void SymTable::changeValue(const char* name,  char* value){
        SymTable* temp = this->whereIsItDeclared(name);
        if(temp!=nullptr){
            if(value[0] == '"' && value[strlen(value)-1] == '"' ||
            value[0] == '\'' && value[strlen(value)-1] == '\'') {
                value = value + 1;
                value[strlen(value)-1] = 0;
            }
            temp->ids[name].value = value;
        }
    }

    void SymTable::changeValue(const char* name,  std::string value){
        SymTable* temp = this->whereIsItDeclared(name);
        if(temp!=nullptr){
            if(value[0] == '"' && value[value.length()-1] == '"' ||
            value[0] == '\'' && value[value.length()-1] == '\'') {
                value.erase(0,1);
                value[value.length()-1] = 0;
            }
            temp->ids[name].value = value;
        }
    }

    void SymTable::changeValue(const char* name, int value){
        SymTable* temp = this->whereIsItDeclared(name);
        if(temp != nullptr){
            printf("Found %s in scope %s\n",name, temp->name.c_str());
            temp->ids[name].value = std::to_string(value);
        }
    }

    SymTable* SymTable::getParent() {
        return parent;
    }

    SymTable::~SymTable() {
        ids.clear();
    }