#include <iostream>
#include <fstream>

using namespace std;

class Account {
public:
    void setUserName(string uName){userName = uName;}
    void setPassWord(string pWord){passWord = pWord;}
    string getUserName(){return userName;}
    string getPassWord(){return passWord;}
private:
    string userName;
    string passWord;
};

class Employee {
public:
    int baseSalary(){
        int baseSal = xp *50 + 3000;
        return baseSal;
    }
    void setName(string n){name = n;}
    void setAge(int a){age = a;}
    void setId(int i){id = i;}
    void setXp(int x){xp = x;}
    string getName(){return name;}
    int getAge(){return age;}
    int getId(){return id;}
    int getXp(){return xp;}
    virtual double getSalary(){};
    Account acc;
    void print(){
        cout << "Username: " << acc.getUserName() << endl;
        cout << "Password: " << acc.getPassWord() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Id: " << getId() << endl;
        cout << "Xp: " << getXp() << endl;
    }

    friend ostream &operator <<(ostream &out, Employee &emp);

private:
    string name;
    int age;
    int id; //! 4 digits and unique id
    int xp; //! Experience
};

class Advisor: public Employee {
public:
    int getScore(){
        score = succeedAdvices * 2 - complaints;
        return score;
    }
    double getSalary() {
        salary = baseSalary() + advices * 50 + getScore() * 100;
        return salary;
    }
    //! Getters
    int getAdvices() {return advices;}
    int getSucceedAdvices() {return succeedAdvices;}
    int getComplaints() {return complaints;}
    //! Setters
    void setAdvices(int inp) {advices = inp;}
    void setSucceedAdvices(int inp) {succeedAdvices = inp;}
    void setComplaints(int inp) {complaints = inp;}
    void printt(){
        print();
        cout << "Advices: " << getAdvices() << endl;
        cout << "Succeed advices: " << getSucceedAdvices() << endl;
        cout << "Complaints: " << getComplaints() << endl;
        cout << "Score: " << getScore() << endl;
        cout << "Salary: " << getSalary() << endl << endl;
    }

    friend ostream &operator <<(ostream &out, Advisor &adv);

private:
    int advices;
    int succeedAdvices;
    int complaints;
    int score;
    int salary;
};

class Manager: public Employee {
public:
    int getScore(){
        score = succeedAdvices * 2 - complaints;
        return score;
    }
    double getSalary() {
        salary = baseSalary() + advices * 50 + getScore() * 100; //! baseSalary + advisorSalary
        salary += avgHlp * 100;
        salary /= 10;
        return salary;
    }
    //! Getters
    int getAdvices() {return advices;}
    int getSucceedAdvices() {return succeedAdvices;}
    int getComplaints() {return complaints;}
    int getAvgHlp() {return avgHlp;}
    //! Setters
    void setAdvices(int inp) {advices = inp;}
    void setSucceedAdvices(int inp) {succeedAdvices = inp;}
    void setComplaints(int inp) {complaints = inp;}
    void setAvgHlp(int inp) {avgHlp = inp;}
    void printt(){
        print();
        cout << "Advices: " << getAdvices() << endl;
        cout << "Succeed advices: " << getSucceedAdvices() << endl;
        cout << "Complaints: " << getComplaints() << endl;
        cout << "Helps: " << getAvgHlp() << endl;
        cout << "Score: " << getScore() << endl;
        cout << "Salary: " << getSalary() << endl << endl;
    }

    friend ostream &operator <<(ostream &out, Manager &man);

private:
    int advices;
    int succeedAdvices;
    int complaints;
    int avgHlp;
    int score;
    int salary;
};

class RealEstateAgency {
public:
    RealEstateAgency(string ad){
        fileReader(ad);
        fstream myFile;
        myFile.open(ad, ios::in);
        string tempString;
        int tempInt;
        int adx=0, emx=0;
        emps = new Employee[empQ];
        advs = new Advisor[advsQ];
        for(int i=0; i<(empQ + advsQ + 1); i++){
            myFile >> tempString;
            if(tempString == "manager"){
                for(int j=1; j<=10; j++){
                    if(j==1) {
                        myFile >> tempString;
                        manager.acc.setUserName(tempString);
                    }
                    else if(j==2) {
                        myFile >> tempString;
                        manager.acc.setPassWord(tempString);
                    }
                    else if(j==3) {
                        myFile >> tempString;
                        manager.setName(tempString);
                    }
                    else if(j==4) {
                        myFile >> tempInt;
                        manager.setAge(tempInt);
                    }
                    else if(j==5) {
                        myFile >> tempInt;
                        manager.setId(tempInt);
                    }
                    else if(j==6) {
                        myFile >> tempInt;
                        manager.setXp(tempInt);
                    }
                    else if(j==7) {
                        myFile >> tempInt;
                        manager.setAdvices(tempInt);
                    }
                    else if(j==8) {
                        myFile >> tempInt;
                        manager.setSucceedAdvices(tempInt);
                    }
                    else if(j==9) {
                        myFile >> tempInt;
                        manager.setComplaints(tempInt);
                    }
                    else if(j==10) {
                        myFile >> tempInt;
                        manager.setAvgHlp(tempInt);
                    }
                }
            }else if(tempString == "employee") {
                for(int j=1; j<=6; j++){
                    if(j==1) {
                        myFile >> tempString;
                        emps[emx].acc.setUserName(tempString);
                    }
                    else if(j==2) {
                        myFile >> tempString;
                        emps[emx].acc.setPassWord(tempString);
                    }
                    else if(j==3) {
                        myFile >> tempString;
                        emps[emx].setName(tempString);
                    }
                    else if(j==4) {
                        myFile >> tempInt;
                        emps[emx].setAge(tempInt);
                    }
                    else if(j==5) {
                        myFile >> tempInt;
                        emps[emx].setId(tempInt);
                    }
                    else if(j==6) {
                        myFile >> tempInt;
                        emps[emx].setXp(tempInt);
                    }
                }
                emx++;
            }else if(tempString == "Advisor") {
                for(int j=1; j<=9; j++){
                    if(j==1) {
                        myFile >> tempString;
                        advs[adx].acc.setUserName(tempString);
                    }
                    else if(j==2) {
                        myFile >> tempString;
                        advs[adx].acc.setPassWord(tempString);
                    }
                    else if(j==3) {
                        myFile >> tempString;
                        advs[adx].setName(tempString);
                    }
                    else if(j==4) {
                        myFile >> tempInt;
                        advs[adx].setAge(tempInt);
                    }
                    else if(j==5) {
                        myFile >> tempInt;
                        advs[adx].setId(tempInt);
                    }
                    else if(j==6) {
                        myFile >> tempInt;
                        advs[adx].setXp(tempInt);
                    }
                    else if(j==7) {
                        myFile >> tempInt;
                        advs[adx].setAdvices(tempInt);
                    }
                    else if(j==8) {
                        myFile >> tempInt;
                        advs[adx].setSucceedAdvices(tempInt);
                    }
                    else if(j==9) {
                        myFile >> tempInt;
                        advs[adx].setComplaints(tempInt);
                    }
                }
                adx++;
            }
        }
    }
    ~RealEstateAgency(){
        delete[] emps;
        delete[] advs;
    }
    void fileReader(string ad){
        fstream myFile;
        myFile.open(ad, ios::in);
        string temp;
        int trashCount;
        while(true){
            myFile >> temp;
            if(temp == "employee"){
                empQ++;
                trashCount = 0;
                continue;
            }else if(temp == "Advisor"){
                advsQ++;
                trashCount = 0;
                continue;
            }
            trashCount++;
            if(trashCount == 15){
                break;
            }
        }
        myFile.close();
    }

    void membersLog(){
        cout << "Manager:" << endl << endl;
        cout << manager;
        cout << "--------" << endl;
        cout << "Advisors:" << endl << endl;
        for(int i=0; i<advsQ; i++){
            cout << advs[i];
        }
        cout << "--------" << endl;
        cout << "Employees:" << endl << endl;
        for(int i=0; i<empQ; i++){
            cout << emps[i];
            cout << endl;
        }
    }

    friend ostream &operator <<(ostream &out, RealEstateAgency &rea);

private:
    Employee *emps;
    Advisor *advs;
    Manager manager;
    int empQ = 0;
    int advsQ = 0;
};

ostream &operator <<(ostream &out, RealEstateAgency &rea){
    rea.membersLog();
    return out;
}

ostream &operator <<(ostream &out, Manager &man){
    man.printt();
    return out;
}

ostream &operator <<(ostream &out, Advisor &adv){
    adv.printt();
    return out;
}

ostream &operator <<(ostream &out, Employee &emp){
    emp.print();
    return out;
}

int main()
{

    RealEstateAgency realEA("real-estate-info.txt"); //! Takes the address of the text file as an argument.

    cout << realEA;

    return 0;
}
