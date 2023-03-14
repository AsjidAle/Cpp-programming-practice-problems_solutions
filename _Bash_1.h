// Utility file for hospital Management system








#include <iostream>
#include <cstring>
using namespace std;
class base
{
protected:
    string name;
    string father_name;
    string address;
    unsigned int age;
};
class recommandations
{
public:
    string recommandation;
    recommandations *next;
    recommandations()
    {
        next = nullptr;
    }
};
class diseases
{
public:
    string disease;
    diseases *next;
    diseases()
    {
        next = nullptr;
    }
};
class medicenes
{
public:
    string medicene;
    medicenes *next;
    medicenes()
    {
        next = NULL;
    }
};
class patient : private base
{
    bool admit;
    medicenes *medicen;
    diseases *diseas;
    recommandations *recommand;

public:
    friend class receptionist;
    friend class doctor;
};
class meeting
{
    patient p;
    meeting *next;

public:
    friend class receptionist;
    friend class doctor;
};
meeting *meet = nullptr;
// meeting or appointment seted
class doctor : private base
{
    string education;
    unsigned int salary;

public:
    void enter_details ()
    {
        cout << "Enter Name ";
        getline(cin, this->name);
        cout << "Enter Father's Name ";
        getline(cin, this->father_name);
        cout << "Enter Address ";
        getline(cin, address);
        cout << "Enter Age ";
        try
        {
            cin >> age;
            if (age < 0)
            {
                throw false;
            }
        }
        catch (bool o)
        {
            cout << "Age Error ";
        }
        cin.ignore();
        cout << "Enter the education ";
        getline(cin, this->education);
        cout << "Enter Salary ";
        try
        {
            cin >> this->salary;
            if (this->salary < 0)
            {
                throw false;
            }
        }
        catch (bool o)
        {
            cout << "Salary wrong input ";
        }
    }
    void next_patient()
    {
        if(meet==nullptr){
            cout<<"No patient waiting ";
            return;
        }
        meeting *m2 = meet;
        meet = meet->next;
        cout << "Patient Name : " << m2->p.name << '\n';
        cout << "Father's Name : " << m2->p.father_name << '\n';
        cout << "Age : " << m2->p.age;
        cout << "Address : " << m2->p.address;
        bool ent = 0;
        do
        {
            cout << "Enter patient disease yes(1) not (0)";
            try
            {
                cin >> ent;
                if (ent != true && ent != false)
                {
                    throw false;
                }
            }
            catch (bool o)
            {
                cout << "Disease wrong choice ";
            }
            if (ent)
            {
                diseases *dis = new diseases;
                cout << "Enter Disease name ";
                getline(cin, dis->disease);
                if (m2->p.diseas == nullptr)
                {
                    m2->p.diseas = dis;
                }
                else
                {
                    diseases *ptr = m2->p.diseas;
                    while (ptr->next != nullptr)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = dis;
                }
            }
        } while (ent);
        do
        {
            cout << "Need to enter recommandation? yes(1) no(0) ";
            try
            {
                cin >> ent;
                if (ent != true && ent != false)
                {
                    throw false;
                }
            }
            catch (bool o)
            {
                cout << "Recommendation choice error ";
            }
            if (ent)
            {
                recommandations* r1 = new recommandations;
                cout << "Enter recommandation ";
                getline(cin, r1->recommandation);
                if (m2->p.recommand == nullptr)
                {
                    m2->p.recommand = r1;
                }
                else
                {
                    recommandations* r2 = m2->p.recommand;
                    while (r2->next != nullptr)
                    {
                        r2 = r2->next;
                    }
                    r2->next = r1;
                }
            }
        } while (ent);
        do
        {
            cout << "Need to enter the medecine Yes(1)/No(0)? ";
            try
            {
                cin >> ent;
                if (ent != true && ent != false)
                {
                    throw false;
                }
            }
            catch (bool o)
            {
                cout << "Medicene error ";
            }
            if (ent)
            {
                medicenes *mm = new medicenes;
                cout << "Enter the medicene details ";
                getline(cin, mm->medicene);
                if(m2->p.medicen==nullptr){
                    m2->p.medicen=mm;
                }
                else{
                    medicenes* mmm=m2->p.medicen;
                    while(mmm->next!=nullptr){
                        mmm=mmm->next;
                    }
                    mmm->next=mm;
                }
            }
        }while(ent);
        cout<<"Admit Patient Yes(1) NO(0)?";
        try{
            cin>>m2->p.admit;
            if(m2->p.admit!=true&&m2->p.admit!=false){throw false;}
        }
        catch(bool o){
            cout<<"Admit error";
        }
        meeting *m5=meet;
        meet=meet->next;
        delete m5;
    }
    bool update_own_details()
    {
        enter_details();
    }
    void display_own_details()
    {
        cout << "Name : " << this->name;
        cout << '\n'
             << "Father's Name : " << this->father_name;
        cout << '\n'
             << "Address : " << this->address;
        cout << '\n'
             << "Education : " << this->education;
        cout << '\n'
             << "Age : " << this->age;
        cout << '\n'
             << "Salary : " << this->salary;
    }
};
class receptionist : private base
{
    string education;
    unsigned int salary;

public:
    //
    void enter_own_details()
    {
        cout << "Enter Receptionist Name ";
        getline(cin, this->name);
        cout << "Enter Father's Name ";
        getline(cin, this->father_name);
        cout << "Enter your age ";
        try
        {
            cin >> this->age;
            if (this->age < 0)
            {
                throw false;
            }
        }
        catch (bool f)
        {
            cout << "Age error ";
        }
        cout << "Enter Address ";
        getline(cin, this->address);
        cout << "Enter Education ";
        getline(cin, this->education);
        cout << "Enter salary ";
        cin >> salary;
    }
    bool enter_patient() const
    {
        meeting *m1 = new meeting;
        cout << "Enter Patient Name ";
        getline(cin, m1->p.name);
        cout << "Enter Patient Gardian Name ";
        getline(cin, m1->p.father_name);
        cout << "Enter Patient Address ";
        getline(cin, m1->p.address);
        cout << "Enter Patient age ";
        try
        {
            cin >> m1->p.age;
            if (m1->p.age < 0)
                throw false;
        }
        catch (bool f)
        {
            cout << "Age wrong";
        }
        if (meet == nullptr)
        {
            meet = m1;
            return true;
        }
        meeting *ptrr = meet;
        while (ptrr->next != nullptr)
        {
            ptrr = ptrr->next;
        }
        ptrr->next = m1;
        return 1;
    }
    //bool view_patient_details();
    void view_own_details()
    {
        cout << "Receptionist Name : " << this->name;
        cout << "\nFather's Name : " << this->father_name;
        cout << "\nAddress : " << this->address;
        cout << "\nAge : " << age;
        cout << "\nEducation : " << this->education;
        cout << "\nSalary : " << this->salary;
    }
};
