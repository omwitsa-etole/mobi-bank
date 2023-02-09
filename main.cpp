#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
#include<cmath>
#include<cstring>
#include<fstream>
#include<sstream>
#include<ctime>
#include <unistd.h>
#include<string.h>

using namespace std;

int usr = 1, agnt = 1, ag_block=0, usr_block = 0;
int attempts = 3;

//int main();
void agent();
void user();
void check_exist(int , int, int);
void check_acc(int, int);
void validate_data(int, int, double);
double check_rate(double);

string ps;
string hidepass()
{
    char pass[10];
    int i=0;
    while((pass[i]=getch())!='\r')
    {
        i++;
        cout<<"*";
    }
    return pass;
}

class Account_bal
{
private:
    double balance;
public:
    void write_cost(double dep)
    {
        balance+=dep;
    }
    void ret_transcosts()
    {
        cout<<"\tKshs "<<balance;
    }
    double ret_bal()
    {
        return balance;
    }
};


class Agent
{
private:
    char username[100];
    int password;
    int ag_no;
    bool agent_blocked;
    double agent_float;
    double transaction_costs;
public:
    void agent_data(int ag)
    {
        cout<<"\nEnter Username: ";
        cin.ignore();
        cin.getline(username, 100);
        ag_no = ag;
        agent_blocked = 0;
        agent_float = 1.0;
        cout<<"\nEnter Password: ";
        ps = hidepass();
        stringstream p(ps);
        p >> password;

    }
    void agent_login(int n){
        cout<<"\nAgent Agent no: ";
        cin>>ag_no;
        cout<<"\nEnter Password: ";
        ps = hidepass();
        stringstream p(ps);
        p >> password;
        check_exist(ag_no, password, n);
    }
    void display_bal()
    {
        cout << "\nAgent Username: "<<username;
        cout <<"\nAgent no: "<<ag_no;
        cout << "\nAgent Float: "<<agent_float<<endl;
    }
    void getpass()
    {
        cin >> password;
    }
    int req_pass()
    {
        ps = hidepass();
        stringstream p(ps);
        p >> password;
        return password;
    }
    string ret_username() const
    {
        string n;
        n = username;
        return n;
    }
    int ret_password() const
    {
        return password;
    }
    int ret_agent()
    {
        return ag_no;
    }
    bool ret_agent_status()
    {
        return agent_blocked;
    }
    void add_float(double dep)
    {
        agent_float+=dep;
    }

    double ret_float()
    {
        return agent_float;
    }
};

class Accounts
{
private:
        char name[100];
        int phone;
        int acc_pass;
        double deposit;
        char ac_type;
        bool user_blocked;
        float atts;

public:
    void create_data(int ph)
    {
        phone = ph;
        user_blocked = 0;
        atts = 0;
        cout<<"\nEnter Name: ";
        cin.ignore();
        cin.getline(name, 100);
        ac_type = 'S';
        deposit = 0.0 ;
        cout<<"\nEnter Password: ";
        ps = hidepass();
        stringstream p(ps);
        p >> acc_pass;


    }
    void acc_login(int n){
        if(n == 3 || n == 5 ||n == 6){
            cout<<"\nEnter Password: ";
            ps = hidepass();
            stringstream p(ps);
            p >> acc_pass;
            check_exist(1, acc_pass, n);
        }else if(n == 4){
            cout<<"\nEnter current Password: ";
            ps = hidepass();
            stringstream p(ps);
            p >> acc_pass;
            check_exist(1, acc_pass, n);
        }else{
            cout<<"\nEnter Phone: ";
            cin>>phone;
            cout<<"\nEnter Password: ";
            ps = hidepass();
            stringstream p(ps);
            p >> acc_pass;
            check_exist(phone, acc_pass, n);
        }

    }
    void display_user()
    {
        cout << "\nName : "<< name;
        cout <<"\nPhone : "<< phone;
        cout << "\nAccount type : "<< ac_type;
        cout <<"\nBalance : "<< deposit;
    }
    string ret_name();
    int ret_phone();
    int ret_acc_pass();
    double ret_deposit()
    {
        return deposit;
    }
    void ac_getphone(int n)
    {
        cin>>phone;
        check_acc(phone, n);
    }
    void get_newpass()
    {
        ps = hidepass();
        stringstream p(ps);
        p >> acc_pass;
    }
    int req_pass()
    {
        ps = hidepass();
        stringstream p(ps);
        p >> acc_pass;
        return acc_pass;
    }
    void acc_transpass(int ph, double dep)
    {
        ps = hidepass();
        stringstream p(ps);
        p >> acc_pass;
        validate_data(ph, acc_pass, dep);
    }
    void ac_deposit(double dep)
    {
        deposit+=dep;
    }
    int ret_user_status()
    {
        return user_blocked;
    }
    void addattempt(int n)
    {
        atts+=n;
    }
    void resetatts()
    {
        atts = 0;
    }
    void add_block()
    {
        user_blocked = 1;
    }
    void remove_block()
    {
        user_blocked = 0;
    }
    int ret_atts()
    {
        return atts;
    }
    void set_acctype(char t)
    {
        ac_type = t;
    }
    string ret_acctype()
    {
        string n;
        n = ac_type;
        return n;
    }
};

string Accounts::ret_name()
{
    string n;
    n = name;
    return n;
}
int Accounts::ret_phone()
{
    return phone;
}
int Accounts::ret_acc_pass()
{
    return acc_pass;
}
void login(int );
void home();
void validate_login(int );
void admin_main();
void agent_main();
void user_main();
int check_phone(int, int);
void create_user();
void create_agent();
void display_user(int, int);
void acc_dep(int);
void account();
void transact(int, string, double);
void deduct_transact(double);
void statements(char, int, int, string, string, int, int, int);
void agent_bal();
void agent_deposit(int, double );
void all_balance();
int gen_code();

int minutes = 1;
int seconds = 0;

void timer()
{
    while (true) {

        sleep(1);

        seconds++;

        if (seconds == 60) {

            minutes--;
            seconds = 0;
        }
        if(minutes == 0)
        {

            minutes = 1;
            break;
        }
    }
}

void check_exist(int nm, int p, int n)
{
    Agent ag;
    int found = 0, found2 = 0, found3 = 1;
    Accounts ac;
    fstream fp, ft;
    switch(n)
    {
    case 1:
        fp.open("agents.dat", ios::in|ios::out|ios::binary);
        while(fp.read((char*)&ag,sizeof(ag)) && !fp.eof())
        {
            if(ag.ret_agent() == nm){
                found = 1;
                if(ag.ret_password() == p)
                {
                    found2 = 1;
                    agnt = ag.ret_agent();
                    cout <<"\n\tLOGIN SUCCESSFULL\n";
                    cin.ignore();
                    cin.get();
                    agent_main();

                }
            }
        }
        fp.close();
        if(found == 0){
            cout << "\n\tInvalid username\n";
                cin.ignore();
                cin.get();
                agent();
        }else if(found2 == 0){
            cout << "\n\tInvalid password\n";

                cin.ignore();
                cin.get();
                agent();
        }
        break;
    case 2:
        fp.open("accounts.dat", ios::in|ios::out|ios::binary);
        while(fp.read((char*)&ac,sizeof(ac)) && !fp.eof())
        {
            if(ac.ret_phone() == nm){
                if(ac.ret_user_status() == 1)
                {
                    cout << "\nAccount is blocked";
                    getch();
                    user();
                }
                found = 1;
                if(ac.ret_acc_pass() == p)
                {
                    found2 = 1;
                    usr = ac.ret_phone();
                    ac.resetatts();
                    ac.remove_block();
                    long long int pos=-1*sizeof(ac);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&ac,sizeof(Accounts));
                    cout <<"\n\tLOGIN SUCCESSFULL\n";
                    getch();
                    user_main();
                }
                if(ac.ret_atts() == 3)
                {
                     ac.add_block();
                     long long int pos=-1*sizeof(ac);
                     ft.seekp(pos,ios::cur);
                     ft.write((char*)&ac,sizeof(ac));
                     cout<<"\nAccount is blocked";
                     getch();
                     user();
                }
                ac.addattempt(1);
                long long int pos=-1*sizeof(ac);
                fp.seekp(pos,ios::cur);
                fp.write((char*)&ac,sizeof(ac));
                usr_block = ac.ret_atts();
            }
        }
        fp.close();
        if(found == 0){
            cout << "\n\tInvalid username\n";
                cin.ignore();
                cin.get();
                user();
        }
        if(found2 == 0){
            cout << "\nInvalid password\n";
            cout<<attempts-usr_block<<" attempts remaining\n";
            getch();
            user();
        }

        break;
    case 3:
        fp.open("accounts.dat", ios::in|ios::out|ios::binary);
        while(fp.read((char*)&ac,sizeof(ac)))
        {
            if(ac.ret_phone() == usr){
                if(ac.ret_user_status() == 1)
                {
                    cout << "\nAccount is blocked";
                    getch();
                    user();
                }
                if(ac.ret_acc_pass() == p)
                {
                    ac.resetatts();
                    ac.remove_block();
                    long long int pos=-1*sizeof(ac);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&ac,sizeof(Accounts));
                    found2 = 1;
                    ac.display_user();
                    getch();
                    user_main();

                }
                if(ac.ret_atts() == 3)
                {
                     ac.add_block();
                     long long int pos=-1*sizeof(ac);
                     ft.seekp(pos,ios::cur);
                     ft.write((char*)&ac,sizeof(ac));
                     cout<<"\nAccount is blocked";
                     getch();
                     user();
                }
                ac.addattempt(1);
                long long int pos=-1*sizeof(ac);
                fp.seekp(pos,ios::cur);
                fp.write((char*)&ac,sizeof(ac));
                usr_block = ac.ret_atts();
            }
        }
        fp.close();
        if(found2 == 0){
            cout << "\nInvalid password\n";
            cout<<attempts-usr_block<<" attempts remaining\n";
            getch();
            user_main();
        }
        break;
    case 4:
        fp.open("accounts.dat", ios::in|ios::out|ios::binary);
        while(fp.read((char*)&ac,sizeof(Accounts)))
        {
            if(ac.ret_phone() == usr){
                if(ac.ret_user_status() == 1)
                {
                    cout << "\nAccount is blocked";
                    getch();
                    user();
                }
                if(ac.ret_atts() == 3)
                {
                     ac.add_block();
                     long long int pos=-1*sizeof(ac);
                     ft.seekp(pos,ios::cur);
                     ft.write((char*)&ac,sizeof(ac));
                     cout<<"\nAccount is blocked";
                     getch();
                     user();
                }
                if(ac.ret_acc_pass() == p)
                {
                    found2 = 1;
                    ac.resetatts();
                    ac.remove_block();
                    cout <<"\n\nEnter new Password: ";
                    ac.get_newpass();
                    long long int pos=-1*sizeof(ac);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&ac,sizeof(ac));
                    found3 = 1;
                    break;
                }

                ac.addattempt(1);
                long long int pos=-1*sizeof(ac);
                fp.seekp(pos,ios::cur);
                fp.write((char*)&ac,sizeof(ac));
            }
        }
        fp.close();
        if(found2 == 0){
            cout << "\nInvalid password\n";
            cout<<attempts-usr_block<<" attempts remaining\n";
            getch();
            user_main();
        }
        if(found3 == 1)
        {
            cout<<"\nPassword Changed Successfull\n";
                    getch();
                    user_main();
        }else{
            cout<<"\nError during transaction\n";
                    getch();
                    user_main();
        }
        break;
    case 5:
        fp.open("accounts.dat", ios::in|ios::out|ios::binary);
        while(fp.read((char*)&ac,sizeof(Accounts)))
        {
            if(ac.ret_phone() == usr){
                if(ac.ret_acc_pass() == p)
                {
                    ac.set_acctype('C');
                    long long int pos=-1*sizeof(ac);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&ac,sizeof(ac));
                    found = 1;
                }
            }
        }
        fp.close();
        if(found == 0){
            cout << "\nInvalid password\n";
            getch();
            user_main();
        }else{
            cout << "\nAccount type successfuly changed to credit\n";
            getch();
            user_main();
        }
        break;
    case 6:
        fp.open("accounts.dat", ios::in|ios::out|ios::binary);
        while(fp.read((char*)&ac,sizeof(Accounts)))
        {
            if(ac.ret_phone() == usr){
                if(ac.ret_acc_pass() == p)
                {
                    if(ac.ret_deposit() < 0)
                    {
                        cout << "\n\nYou still have an overdraft of kshs "<< -(ac.ret_deposit()) <<". \nPlease clear the amount in order to opt out of credit.\n";
                        getch();
                        user_main();
                    }
                    ac.set_acctype('S');
                    long long int pos=-1*sizeof(ac);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&ac,sizeof(ac));
                    found = 1;
                }
            }
        }
        fp.close();
        if(found == 0){
            cout << "\nInvalid password\n";
            getch();
            user_main();
        }else{
            cout << "\nAccount type successfully changed to savings\n";
            getch();
            user_main();
        }
        break;
    default: break;
    }

}


void home()
{
    system("cls");
    usr = 1;
    agnt = 1;
    char op;
    do{
         system("cls");
        cout<<"\n1.AGENT\n";
        cout<<"\n2.USER\n";
        cout<<"\n3.EXIT\n";
        op = getch();
        switch(op)
        {
        case '1':
            agent();
            break;
        case '2':
            user();
            break;
        case '3':
            exit(0);
            break;
        default:
            cout<<"\nInvalid Choice\n";
            break;
        }
    }while(op != '3');
}

void login(int n){
    switch(n)
    {
    case 1:
        validate_login(1);
        break;
    case 2:
        validate_login(2);
        break;
    default:
        home();
    }

}

void validate_login(int n)
{
    system("cls");
    int nm;
    int p, i;
    int ps;
    int found;
    fstream fp;
    Agent ag;
    Accounts ac;
    switch(n)
    {
    case 1:
        ag.agent_login(1);
        break;
    case 2:
        ac.acc_login(2);
        break;
    default:
        home();
    }
}

void delete_agent()
{
    fstream ft, fp;
    Agent ag;
    int agentno, agentpass, found = 0, found2 = 0, found3 = 0;
    system("cls");
    cout << "\nEnter Agent no: ";
    cin >> agentno;
    cout << "\nEnter Agent Password: ";
    ps = hidepass();
    stringstream p(ps);
    p >>agentpass;
    ft.open("agents.dat", ios::in|ios::out);
    fp.open("temp.dat", ios::in|ios::out|ios::binary|ios::app);
    if(!ft || !fp){"\nCould not open database";exit(0);}
    while(ft.read((char*)&ag,sizeof(ag)) && !ft.eof())
    {
        if(ag.ret_agent() == agentno)
        {
            found = 1;
            if(ag.ret_password() == agentpass){
                found3 = 1;
            }
        }
    }
    ft.close();
    fp.close();
    if(found == 0)
    {
        cout << "\nAgent not found\n";
        getch();
        admin_main();
    }
    if(found3 == 0)
    {
        cout << "\nInvalid Agent password\n";
        getch();
        admin_main();
    }
    if(found3 == 1)
    {
        ft.open("agents.dat", ios::in|ios::out);
        fp.open("temp.dat", ios::in|ios::out|ios::binary|ios::app);
        while(ft.read((char*)&ag,sizeof(ag)) && !ft.eof())
        {
            if(ag.ret_agent() != agentno)
            {
                fp.write((char*)&ag,sizeof(ag));
            }
        }
        found2 = 1;
        ft.close();
        fp.close();
    }
    if(found2 == 1)
    {
        remove("agents.dat");
        rename("temp.dat", "agents.dat");
        cout << "\nAgent deleted\n";
        getch();
        admin_main();
    }
    if(found2 == 0){
        cout << "\nError while deleting record";
        getch();
        admin_main();
    }
}

void delete_user()
{
    fstream ft, fp;
    Accounts ag;
    int agentno, agentpass, found = 0, found2 = 0, found3 = 0;
    system("cls");
    cout << "\nEnter Account phone no: ";
    cin >> agentno;
    cout << "\nEnter Account Password: ";
    ps = hidepass();
    stringstream p(ps);
    p >>agentpass;
    ft.open("accounts.dat", ios::in|ios::out);
    fp.open("temp.dat", ios::in|ios::out|ios::binary|ios::app);
    if(!ft || !fp){"\nCould not open database";exit(0);}
    while(ft.read((char*)&ag,sizeof(ag)) && !ft.eof())
    {
        if(ag.ret_phone() == agentno)
        {
            found = 1;
            if(ag.ret_acc_pass() == agentpass){
                if(ag.ret_deposit() < 0)
                {
                    cout << "\nAccount holder "<<ag.ret_phone()<<" still has an overdraft of "<<ag.ret_deposit()<<". \nOverdraft must be cleared to delete account\n";
                    getch();
                    admin_main();
                    break;
                }
                found3 = 1;
            }
        }
    }
    ft.close();
    fp.close();
    if(found == 0)
    {
        cout << "\nAccount not found\n";
        getch();
        admin_main();
    }
    if(found3 == 0)
    {
        cout << "\nInvalid Account password\n";
        getch();
        admin_main();
    }
    if(found3 == 1)
    {
        ft.open("accounts.dat", ios::in|ios::out);
        fp.open("temp.dat", ios::in|ios::out|ios::binary|ios::app);
        while(ft.read((char*)&ag,sizeof(ag)) && !ft.eof())
        {
            if(ag.ret_phone() != agentno)
            {
                fp.write((char*)&ag,sizeof(ag));
            }
        }
        found2 = 1;
        ft.close();
        fp.close();
    }
    if(found2 == 1)
    {
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");
        cout << "\nUser Account deleted\n";
        getch();
        admin_main();
    }
    if(found2 == 0){
        cout << "\nError while deleting record";
        getch();
        admin_main();
    }
}

void admin_main()
{
    char op;
    int agentno;
    double dep;
    do
    {
        system("cls");
        cout <<"\n1.CREATE AGENT\n";
        cout <<"\n2.CREATE USER\n";
        cout <<"\n3.AGENT FLOAT\n";
        cout <<"\n4.CLOSE AGENT\n";
        cout <<"\n5.CLOSE USER\n";
        cout <<"\n6.ALL ACCOUNTS BALANCE\n";
        cout <<"\nq.EXIT\n";
        op = getch();
        switch(op)
        {
        case '1':
            create_agent();
            break;
        case '2':
            create_user();
            break;
        case '3':
            system("cls");
            cout << "\nEnter Agent no: ";
            cin >> agentno;
            cout << "\nEnter amount: ";
            cin >> dep;
            agent_deposit(agentno, dep);
            break;
        case '4':
            delete_agent();
            break;
        case '5':
            delete_user();
            break;
        case '6':
            system("cls");
            cout<<"\n\tACCOUNTS BALANCE\n\n";
            all_balance();
            break;
        case 'q':
            exit(0);
            break;
        case 'Q':
            exit(0);
            break;
        default:
            cout <<"\nInvalid option\n";
            getch();
            break;
        }

    }while(op != 'q');
}

void admin(int no)
{
    int admin_pass;
    /*fstream fp;
    fp.open("admin.dat", ios::in|ios::binary);*/
    do
    {
        cout << "\nEnter Password: ";
        ps = hidepass();
        stringstream p(ps);
        p >> admin_pass;
    }while((trunc(log10(admin_pass)) + 1) != 4);

    admin_main();
}

int main(int argc, char* argv[])
{
    if(argc == 3)
    {
        char *a = argv[1];
        char *b = argv[2];
        int no = atoi(b);
        admin(no);
    }
    home();
    return 0;
}

void create_agent()
{
    system("cls");
    Agent ag;
    fstream fp, ft;
    int op, ph, found = 0;
    cout << "\n\nEnter Agent no: ";
    cin>>ph;
    op = check_phone(ph, 1);
    if(op == 0)
    {
        cout << "\nInvalid Agent Number";
        getch();
        admin_main();
    }
    ft.open("agents.dat", ios::in|ios::out|ios::binary|ios::app);
    if(!ft){"\nCould not open database";exit(0);}
    while(ft.read((char*)&ag,sizeof(ag)) && !ft.eof())
    {
        if(ag.ret_agent() == ph)
        {
            found = 1;
        }
    }
    ft.close();
    if(found == 1)
    {
        cout << "\nAgent already exists";
            getch();
            admin_main();
    }
    fp.open("agents.dat",ios::out|ios::in|ios::app|ios::binary);
    ag.agent_data(ph);
    fp.write((char*)&ag,sizeof(ag));
    fp.close();
    cout<<"\nCreated Successfully";
    getch();
    admin_main();

}

void agent()
{
    char op;
    do{
            system("cls");
        cout<<"\n1.LOGIN\n";
        cout<<"\n2.BACK\n";
        cout<<"\n3.EXIT";
        op = getch();
        switch(op)
        {
        case '1':
            login(1);
            break;
        case '2':
            home();
            break;
        case '3':
            exit(0);
            break;
        default:
            cout<<"\ninvalid choice\n";
            break;
        }
    }while(op != '3');

}
void user()
{
    if(usr != 1)
    {
        user_main();
    }
    Accounts ac;
    char op;
    do
    {
        system("cls");
        cout<<"\n1.LOGIN\n";
        cout<<"\n2.FORGOT PASSWORD\n";
        cout<<"\n3.BACK\n";
        cout<<"\n4.EXIT\n";
        op=getch();
        switch(op)
        {
        case '1':
             login(2);
            break;
        case '2':
            system("cls");
            cout <<"\nEnter Phone number: ";
            ac.ac_getphone(3);
            break;
        case '3':
            home();
            break;
        case '4':
            exit(0);
            break;
        default:
            cout<<"\nInvalid Choice\n";
            break;
        }

    }while(op != '4');

}

void agent_main()
{
    Accounts ac;
    double dep;
    system("cls");
    char op;
    do
    {
        system("cls");
        cout<<"\n1.CREATE NEW ACCOUNT\n";
        cout<<"\n2.DEPOSIT TO ACCOUNT\n";
        cout<<"\n3.WITHDRAW FROM ACCOUNT\n";
        cout<<"\n4.CHECK FLOAT BALANCE\n";
        cout<<"\n5.HOME\n";
        cout<<"\nq. EXIT\n";
        op = getch();
        switch(op)
        {
        case '1':
            create_user();
            break;
        case '2':
            system("cls");
            cout << "\nEnter Phone number: ";
            ac.ac_getphone(1);
            break;
        case '3':
            system("cls");
            cout << "\nEnter Phone number: ";
            ac.ac_getphone(2);
            break;
        case '4':
            agent_bal();
            break;
        case '5':
            home();
            break;
        case 'q':
            exit(0);
            break;
        default:
            cout<<"\nInvalid Choice\n";
            break;
        }
    }while(op != 'q');
}

void agent_bal()
{
    fstream fp;
    Agent ag;
    int found = 0;
    fp.open("agents.dat", ios::in|ios::out|ios::binary);
    while(fp.read((char*)&ag,sizeof(ag)))
    {
        if(ag.ret_agent() == agnt){
            found = 1;
            ag.display_bal();
            getch();
            agent_main();
        }
    }
    fp.close();
    if(found == 0){
        cout << "\nError occurred\n";
        getch();
        agent_main();
    }
}

void agent_deposit(int no, double dep)
{
    fstream fp;
    Agent ag;
    int found = 0;
    double bal;
    int code;
    fp.open("agents.dat", ios::in|ios::out|ios::binary);
    while(fp.read((char*)&ag,sizeof(ag)))
    {
        if(ag.ret_agent() == no){
            ag.add_float(dep);
            long long int pos=-1*sizeof(ag);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&ag,sizeof(ag));
            bal = ag.ret_float();
            code = gen_code();
            statements('1', no, 1, "Admin", "Float purchase", dep, bal, code);
            found = 1;
        }
    }
    fp.close();
    if(found == 0){
        cout << "\nError occurred, Agent not found\n";
        getch();
        admin_main();
    }else{
        cout << "\nDeposited Successfully\n";
        getch();
        admin_main();
    }
}

void all_balance()
{
    fstream fs;
    Account_bal bg;
    double dep;
    fs.open("transactions.dat", ios::in|ios::out|ios::binary);
    while(fs.read((char*)&bg,sizeof(bg)) && !fs.eof())
    {
        bg.ret_transcosts();
    }
    fs.close();
    getch();
    admin_main();
}

void user_main()
{
    Accounts ac;
    system("cls");
    char op;
    do
    {
        system("cls");
        cout<<"\n1.MY ACCOUNT\n";
        cout<<"\n2.SEND MONEY\n";
        cout<<"\n3.CHECK STATEMENT\n";
        cout<<"\n4.HOME\n";
        cout<<"\nq. EXIT\n";
        op = getch();
        switch(op)
        {
        case '1':
            account();
            break;
        case '2':
            system("cls");
            cout<<"\nEnter Phone number: ";
            ac.ac_getphone(4);
            break;
        case '3':
            statements('2', usr, usr, "user", "n", 1.0, 1.0, 1);
            break;
        case '4':
            home();
            break;
        case 'q':
            exit(0);
            break;
        default:
            cout<<"\nInvalid Choice\n";
            break;
        }
    }while(op != 'q');
}

void account()
{
    Accounts ac;
    system("cls");
    char op;
    do
    {
        system("cls");
        cout<<"\n1.ACCOUNT DETAILS\n";
        cout<<"\n2.CHANGE PASSWORD\n";
        cout<<"\n3.OPT INTO CREDIT\n";
        cout<<"\n4.OPT OUT OF CREDIT\n";
        cout<<"\n5.HOME\n";
        cout<<"\nq. EXIT\n";
        op = getch();
        switch(op)
        {
            case '1':
                ac.acc_login(3);
                break;
            case '2':
                ac.acc_login(4);
                break;
            case '3':
                ac.acc_login(5);
                break;
            case '4':
                ac.acc_login(6);
                break;
            case '5':
                user_main();
                break;
            default:
                cout << "\n invalid option";
                getch();
                break;
        }
    }while(op != 'q');
}

void create_user()
{
    system("cls");
    Accounts ac;
    fstream fp, ft;
    int op, ph, found = 0;
    cout << "\n\nEnter Phone: ";
    cin>>ph;
    op = check_phone(ph, 2);
    if(op == 0)
    {
        cout << "\nInvalid Phone Number";
        getch();
        agent_main();
    }
    ft.open("accounts.dat", ios::in|ios::out|ios::binary|ios::app);
    if(!ft){"\nCould not open database";exit(0);}
    while(ft.read((char*)&ac,sizeof(ac)) && !ft.eof())
    {
        if(ac.ret_phone() == ph)
        {
            found = 1;
        }
    }
    ft.close();
    if(found == 1)
    {
        cout << "\nAccount with phone already exists";
            getch();
            agent_main();
    }
    fp.open("accounts.dat", ios::in|ios::app|ios::binary);
    if(!fp){"\nCould not open database";exit(0);}
    ac.create_data(ph);
    fp.write((char*)&ac, sizeof(ac));
    fp.close();
    cout << "\nCreated Successfully";
    getch();
    agent_main();
}

int check_phone(int ph, int n)
{
    switch(n)
    {
    case 1:
        if((trunc(log10(ph)) + 1) == 4){
            return ph;
        }else{
            return 0;
        }
        break;
    case 2:
        if((trunc(log10(ph)) + 1) == 9){
            return ph;
        }else{
            return 0;
        }
        break;
    default:
        return 0;
        break;
    }

}

void validate_data(int ph, int ps, double dep)
{
    fstream fp, ft;
    int found = 0, found2 = 0, cost;
    char op; string typ;
    double bal;
    Accounts ac;
    string nm;
    fp.open("accounts.dat",ios::in|ios::in);
    while(fp.read((char*)&ac,sizeof(ac)) && !fp.eof()){
        if(ac.ret_phone() == ph)
        {
            found = 1;
            nm = ac.ret_name();
        }
    }
    fp.close();
    ft.open("accounts.dat", ios::in|ios::out);
    while(ft.read((char*)&ac,sizeof(ac)) && !ft.eof())
    {
        if(ac.ret_phone() == usr)
        {
            if(ac.ret_acc_pass() == ps)
            {
                bal = ac.ret_deposit();
                typ = ac.ret_acctype();
                found2 = 1;
            }
        }
    }
    ft.close();
    if(ph == usr)
    {
        cout << "\n\nOperation can not be completed since both parties are the same\n";
        getch();
        user_main();
    }
    if(found == 1)
    {
        if(found2 == 1){
            cost = check_rate(dep);
            if(bal <= (dep+cost))
            {
                if(typ == "C" || typ == "c")
                {
                    if(bal < 0)
                    {
                        bal = 0;
                    }
                    cout << "\nYou have insufficient Funds in your account,\n do yo accept an overdraft charge of "<<(dep+cost) - bal<<" that will be made to your account\n\n1.Confirm\n2.Decline\n";
                    op = getch();
                    if(op == '1')
                    {
                        transact(ph, nm, dep);
                    }else{
                        cout <<"\nTransaction Canceled Successfully\n";
                        getch();
                        user_main();
                    }
                }else{
                    cout <<"\n\nTransaction cannot be completed, insufficient balance in account\n";
                    getch();
                    user_main();
                }

            }else{
                transact(ph, nm, dep);
            }

        }else{
            cout << "\nInvalid password\n";
            getch();
            user_main();
        }
    }else{
        cout << "\nAccount not found";
        getch();
        user_main();
    }

}


void check_acc(int ph, int n)
{
    if((trunc(log10(ph)) + 1) == 0)
    {
        cout << "\nAn error occurred please try again \n";
        getch();
        home();
    }
    fstream fp, ft, fs;
    Accounts ac;
    Agent ag;
    Account_bal bg;
    double dep;
    stringstream p(ps);
    string ag_name;
    double cost;
    int found = 0, found2 = 0, found3 = 0, found4 = 0, found5 = 0, pass, op, code;
        switch(n)
        {
        case 1:
            cout<<"\nEnter amount to deposit: ";
            cin >> dep;
            cout <<"\n Enter Your password: ";
            pass = ag.req_pass();
            fp.open("accounts.dat", ios::in|ios::out|ios::binary);
            ft.open("agents.dat", ios::in|ios::out);
            //fs.open("accounts.dat", ios::in|ios::out|ios::binary);
            while(fp.read((char*)&ac,sizeof(ac)) && !fp.eof())
            {
                if(ac.ret_phone() == ph){
                    found = 1;
                    while(ft.read((char*)&ag,sizeof(ag)))
                    {
                        if(ag.ret_agent() == agnt){
                            if(ag.ret_password() == pass){
                                ag_name = ag.ret_username();
                                found4 = 1;
                                found3 = 1;
                                found5 = 1;
                            }
                            if(found5 == 1)
                            {
                                if(ag.ret_float() < dep)
                                {
                                    cout << "\nInsufficient float Balance to deposit\n";
                                    getch();
                                    agent_main();
                                }
                            }

                        }
                    }
                    if(found3 == 1)
                    {
                        if(found5 == 1)
                        {
                            ac.ac_deposit(dep);
                            long long int pos=-1*sizeof(ac);
                            fp.seekp(pos,ios::cur);
                            fp.write((char*)&ac,sizeof(ac));
                            found2 = 1;
                            if(found2 == 1)
                            {
                                code = gen_code();
                                statements('1', ph, agnt, ag_name, "Agent Deposit", dep, ac.ret_deposit(), code);
                            }
                        }
                    }

                }

            }
            fp.close();
            ft.close();
            if(found4 == 1)
            {
                if(found5 == 1)
                {
                    ft.open("agents.dat", ios::in|ios::out|ios::binary);
                    while(ft.read((char*)&ag,sizeof(ag)))
                    {
                        if(ag.ret_agent() == agnt){
                            ag.add_float(-dep);
                            long long int pos=-1*sizeof(ag);
                            ft.seekp(pos,ios::cur);
                            ft.write((char*)&ag,sizeof(ag));
                        }
                    }
                    ft.close();
                }
            }
            if(found == 0)
            {
                cout<<"\nAccount not found\n";
                getch();
                agent_main();
            }
            if(found5 == 0){
                cout << "\nInvalid password\n";
                getch();
                agent_main();
            }
            if(found2 == 0)
            {
                cout<<"\nError occurred while initiating Deposit\n";
                getch();
                agent_main();
            }else{
                cout<<"\nDeposit Successfull\n";
                getch();
                agent_main();
            }
            break;
        case 2:
            cout<<"\nEnter amount to Withdraw: ";
            cin >> dep;
            cost = check_rate(dep);
            fp.open("accounts.dat", ios::in|ios::out|ios::binary);
            fs.open("transactions.dat", ios::in|ios::out|ios::binary);
            ft.open("agents.dat", ios::in|ios::out|ios::binary);
            while(fp.read((char*)&ac,sizeof(ac)) && !fp.eof())
            {
                if(ac.ret_phone() == ph){
                    found = 1;
                    cout<<"\nEnter account password: ";
                    pass = ac.req_pass();
                    if(ac.ret_acc_pass() == pass){
                        found2 = 1;
                        if(ac.ret_deposit() <= (dep+cost)){
                            cout << "\nInsufficient Balance to withdraw\n";
                            getch();
                            agent_main();
                        }
                    }
                    ac.ac_deposit(-(dep+cost));
                    long long int pos=-1*sizeof(ac);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&ac,sizeof(ac));
                    found5 = 1;
                    if(found5 == 1)
                    {
                        while(ft.read((char*)&ag,sizeof(ag)))
                        {
                            if(ag.ret_agent() == agnt){
                                ag_name = ag.ret_username();
                                found3 = 1;
                            }
                        }
                    }

                    if(found3 == 1)
                    {
                        code = gen_code();
                        statements('1', ph, agnt, ag_name, "Agent Withdrawal", dep, ac.ret_deposit(), code);
                        while(fs.read((char*)&bg,sizeof(bg)))
                        {
                            bg.write_cost(cost);
                            long long int pos=-1*sizeof(bg);
                            fs.seekp(pos,ios::cur);
                            fs.write((char*)&bg,sizeof(bg));
                            found4 = 1;
                        }
                    }
                }
            }
            fs.close();
            fp.close();

            if(found == 0)
            {
                cout<<"\nAccount not found\n";
                getch();
                agent_main();
            }
            if(found2 == 0){
                cout << "\nInvalid password\n";
                getch();
                agent_main();
            }
            if(found3 == 1)
            {
                cout<<"\nWithdrawal Successful\n";
                getch();
                agent_main();
            }else{
                cout<<"\nAn error occurred during transaction\n";
                getch();
                agent_main();
            }
            if(found4 == 0)
            {
                fs.open("transactions.dat", ios::in|ios::out|ios::binary);
                while(fs.read((char*)&bg,sizeof(bg)))
                {
                    bg.write_cost(cost);
                    long long int pos=-1*sizeof(bg);
                    fs.seekp(pos,ios::cur);
                    fs.write((char*)&bg,sizeof(bg));
                    found4 = 1;
                }
                fs.close();
            }
            break;
        case 3:
            fp.open("accounts.dat", ios::in|ios::out|ios::binary);
            while(fp.read((char*)&ac,sizeof(ac)))
            {
                if(ac.ret_phone() == ph){
                    found = 1;
                    cout << "\nEnter new Password: ";
                    ac.get_newpass();
                    long long int pos=-1*sizeof(ac);
                    fp.seekp(pos,ios::cur);
                    fp.write((char*)&ac,sizeof(ac));
                    cout<<"\nPassword change successful\n";
                    getch();
                    user();
                }
            }
            fp.close();
            if(found == 0)
            {
                cout<<"\nInvalid account or password\n";
                getch();
                user();
            }
            break;
        case 4:
            cout<<"\nEnter amount to Send: ";
            cin >> dep;
            cout<<"\nEnter password: ";
            ac.acc_transpass(ph, dep);
            break;
        case 5:

            //getch();
            break;
        default:
            break;
        }
        ft.close();

}

void transact(int ph, string nm, double amt)
{
    system("cls");
    fstream ft, fp, fs;
    Accounts ac;
    Account_bal bg;
    char op;int found =0, found2 = 0, found4 = 0, found5 = 0, code;
    double cost, bal;
    cost = check_rate(amt);
    string nme;
    cout <<"0"<< ph <<" "<<nm <<" will receive "<<amt<<"kshs. Transaction cost "<< cost <<"kshs. \nSelect option to continue\n";
    cout << "\n1.Confirm\n2.Cancel\n";
    cin>>op;
    switch(op)
    {
        case '1':
            code = gen_code();
            fs.open("transactions.dat", ios::in|ios::out|ios::binary);
            ft.open("accounts.dat", ios::in|ios::out|ios::binary);
            while(ft.read((char*)&ac, sizeof(ac)) && !ft.eof()){
                if(ac.ret_phone() == usr)
                {
                    if(ac.ret_acctype() == "S" || ac.ret_acctype() == "s")
                    {
                        if(ac.ret_deposit() <= amt+cost){
                            cout << "\nInsufficient Balance in account\n";
                            getch();
                            user_main();
                        }
                    }
                    long long unsigned int pos=-1*sizeof(ac);
                    ft.seekp(pos,ios::cur);
                    ac.ac_deposit(-(amt+cost));
                    ft.write((char*)&ac,sizeof(ac));
                    nme = ac.ret_name();
                    bal = ac.ret_deposit();
                    statements('1', usr, ph, "Sent", nm, amt, bal, code);
                    found2 = 1;
                }

            }
            fs.close();
            ft.close();
            if(found2 == 1)
            {
                ft.open("accounts.dat", ios::in|ios::out|ios::binary);
                while(ft.read((char*)&ac, sizeof(ac)) && !ft.eof()){
                if(ac.ret_phone() == ph){
                    ac.ac_deposit(amt);
                    long long unsigned int pos=-1*sizeof(ac);
                    ft.seekp(pos,ios::cur);
                    ft.write((char*)&ac,sizeof(ac));
                    bal = ac.ret_deposit();
                    found = 1;
                    if(found == 1)
                    {
                        statements('1', ph, usr, "Received", nme, amt, bal, code);
                        while(fs.read((char*)&bg,sizeof(bg)))
                        {
                            bg.write_cost(cost);
                            long long int pos=-1*sizeof(bg);
                            fs.seekp(pos,ios::cur);
                            fs.write((char*)&bg,sizeof(bg));
                            found4 = 1;
                        }
                    }
                }
                }
                ft.close();
            }
            if(found4 == 0)
            {
                fs.open("transactions.dat", ios::in|ios::out|ios::binary);
                while(fs.read((char*)&bg,sizeof(bg)))
                {
                    bg.write_cost(cost);
                    long long int pos=-1*sizeof(bg);
                    fs.seekp(pos,ios::cur);
                    fs.write((char*)&bg,sizeof(bg));
                    found4 = 1;
                }
                fs.close();
            }
            if(found == 1){
                cout<<"\nTransaction successful\n";
                getch();
                user_main();
            }else{
                cout<<"\nError during transaction\n";
                    getch();
                    user_main();
            }
            break;
        case '2':
            cout <<"\nTransaction Canceled Successfully\n";
            getch();
            user_main();
            break;
        default:
            cout << "\ninvalid option\n";
            getch();
            user_main();
            break;
    }

    if(found2 == 0){
        cout<<"\nTransaction error\n";
            getch();
            user_main();
    }
}

double check_rate(double amt)
{
    if(amt <= 100)
    {
        return 0;
    }else if(amt <= 300)
    {
        return 12;
    }else if(amt <= 499)
    {
        return 25;
    }else if(amt <= 999)
    {
        return 35;
    }else if(amt <= 1499)
    {
        return 55;
    }else if(amt <= 2499)
    {
        return 75;
    }else{
        return 100;
    }

}

void statements(char n, int ph, int ph2, string reff, string nn, int amt, int bal, int code)
{
    FILE *fp, *fpt;
    Accounts ac;
    int len = nn.length();
    char nm[len+1];
    strcpy(nm, nn.c_str());
    string p = to_string(ph)+"statements.txt";
    char filename[p.length()+1];
    strcpy(filename, p.c_str());
    char ch, op;int found =0, found2 = 0;
    string cd="TRANSACTION"+to_string(code);
    char line[500];
    time_t now = time(0);
    char* tt = ctime(&now);
    char search_q[100];
    string trans;
    if(reff == "Received")
    {
        trans = cd+" confirmed "+reff+" "+to_string(amt)+" kshs from "+nm+" "+to_string(ph2)+" New balance is "+to_string(bal);
    }else if(reff == "Sent")
    {
        trans = cd+" confirmed "+reff+" "+to_string(amt)+" kshs to "+nm+" "+to_string(ph2)+" New balance is "+to_string(bal);
    }else if(reff == "Admin"){
        trans = cd+" confirmed "+nn+" at "+reff+" "+to_string(ph2)+" "+to_string(amt)+" New float balance is "+to_string(bal);
    }else{
        trans = cd+" confirmed "+nn+" at "+reff+" "+to_string(ph2)+" "+to_string(amt)+" New balance is "+to_string(bal);
    }

    char refn[trans.length()+1];
    strcpy(refn, trans.c_str());
    char *ret;
    switch(n)
    {
    case '1':

        fp = fopen(filename, "a+");
        if(!fp){
            printf("\nCould not open file\n");
        }else
        {
            fprintf(fp, "%s\t%s\n", tt, refn);

        }
        fclose(fp);

        break;
    case '2':
        system("cls");
        cout << "\nAccount Statement for "<< usr<<endl;
        cout<<"--------------------------------------------------\n";
        fp = fopen(filename, "r");
        if(!fp){
            printf("\nCould not open file\n");
        }else
        {
            while((ch = fgetc(fp)) !=EOF)
            {
                printf("%c", ch);
            }
            if(!ch)
            {
                cout << "\nYou don't have any transaction records\n";
            }
        }
         fclose(fp);
         cout << "\nPress s to search for a transaction\n";
         op = getch();
         switch(op)
         {
         case 's':
             system("cls");
             cout << "Enter Transaction code or phone number to search: ";
             cin.ignore();
             cin.getline(search_q, 100);
            fp = fopen(filename, "r");
            if(!fp){
                printf("\nCould not open file\n");
            }
            while(fgets(line, 200, fp))
            {
                ret = strstr(line,search_q);
                if(ret != NULL)
                {
                    found++;
                    cout << line;
                }
            }
            fclose(fp);
            if(found == 0)
            {
                cout << "\nNo results \n";
            }
            getch();
            statements('2', usr, usr, "user", "n", 1.0, 1.0, 1);
            break;
         case 'S':
             system("cls");
             cout << "\nEnter Transaction code or phone number to search: ";
             cin.ignore();
             cin.getline(search_q, 100);
            fp = fopen(filename, "r");
            if(!fp){
                printf("\nCould not open file\n");
            }
            while(fgets(line, 200, fp))
            {
                ret = strstr(line,search_q);
                if(ret != NULL)
                {
                    found++;
                    cout << line;
                }
            }
            fclose(fp);
            if(found == 0)
            {
                cout << "\nNo results \n";
            }
            getch();
            statements('2', usr, usr, "user", "n", 1.0, 1.0, 1);
            break;
         default:
            user_main();
            break;
         }
        break;
    default:
        break;
    }
    return;
}

int gen_code()
{
    FILE *fp;int ch;
    fp = fopen("code.txt", "r");
    if(!fp){cout<<"error";getch();}
    fscanf(fp, "%d", &ch);
    fclose(fp);
    ch++;
    fp = fopen("code.txt", "w+");
    if(!fp){cout<<"error";getch();}
    fprintf(fp, "%d", ch);
    fclose(fp);
    return ch;
}
