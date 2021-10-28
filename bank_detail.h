#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

#define ll long long
#define ld long double

string type1="current",type2="saving";

class BankDetails
{
        ll accNumber,customerId,recordNo,monthId;
        string depositorName, accType,address;
        float balanceAmount;  
   public:
        BankDetails();  //Non Parameterized Constructor
        BankDetails(ll,ll,string,string,string, float);  //Parameterized Constructor
        
        //for Input/Output access
        void set_customerId(ll);
        ll get_customerId();
        void set_recordNo(ll);
        ll get_recordNo();
        void set_accNumber(ll);
        ll get_accNumber();
        void set_monthId(ll);
        ll get_monthId();
        void set_depositorName(string);
        string get_depositorName();
        void set_accType(string);
        string get_accType();
        void set_address(string);
        string get_address();
        void set_balanceAmount(ld);
        ld get_balanceAmount();
        
       
        void title_diplay(ll);
        void display(ll);
        void display_info_on_account(BankDetails*,ll,ll);
        friend void display_all(BankDetails*,ll);
        friend void initialize_bank_account(BankDetails*,ll,ll,ll,string,string,string,ld);
        friend bool accountExist(BankDetails*,ll,ll);



        BankDetails addNewCustomer(BankDetails,ll);
        BankDetails deleteAccount(BankDetails);
        BankDetails deposit(BankDetails);
        BankDetails withdraw(BankDetails);
        void interestPerMonth(ll,BankDetails);


        friend ll retrieveRecordNo(BankDetails*,ll,ll);

        friend void write(BankDetails*,int);
        friend void read(BankDetails);



};

BankDetails::BankDetails()
{
        accNumber=0;
        depositorName="";
        accType="";
        address="";
        balanceAmount=0.0;
        monthId=0;
}

BankDetails::BankDetails(ll acc_no,ll m_id,string name,string acc_type,string add, float balance)  //Parameterized Constructor
{
        accNumber=acc_no;
        depositorName=name;
        accType=acc_type;
        address=add;
        balanceAmount=balance;
        monthId=m_id;
}


void write(BankDetails b_acc[],int last)
{

   ofstream file1("BankDetails.txt");
   string s;
   ld b;
    for(ll i=0;i<last;i++)
    {
        b_acc[i]=BankDetails(i+1,i+2,s,s,s,b);
    file1.write((char *)& b_acc[i],sizeof(b_acc[i]));
    }
    file1.close();
}

void read(BankDetails b_acc)
{
    ifstream fread("BankDetails.txt");
    
    while(fread)
    {

        fread.read((char *) & b_acc,sizeof(b_acc));// the information is being red from the file object wise

      //  b_acc.display();// after reading from file the member function of the object is being called.

        cout<<endl;
    }
    fread.close();
}

//definition of member function
void BankDetails::set_customerId(ll cus_id)
{
    customerId=cus_id;
}
ll BankDetails::get_customerId()
{
    return customerId;
}

void BankDetails::set_recordNo(ll rc_no)
{
    recordNo=rc_no;
}
ll BankDetails::get_recordNo()
{
    return recordNo;
}


void BankDetails::set_address(string add)
{
    address=add;
}
string BankDetails::get_address()
{
    return address;
}


void BankDetails::set_accNumber(ll acc_no)
{
    accNumber=acc_no;
}
ll BankDetails::get_accNumber()
{
    return accNumber;
}

void BankDetails::set_monthId(ll m_id)
{
    monthId=m_id;
}
ll BankDetails::get_monthId()
{
    return monthId;
}

void BankDetails::set_depositorName(string name)
{
    depositorName=name;
}
string BankDetails::get_depositorName()
{
    return depositorName;
}

void BankDetails::set_accType(string acc_type)
{
    accType=acc_type;
}
string BankDetails::get_accType()
{
    return accType;
}

void BankDetails::set_balanceAmount(ld balance)
{
    balanceAmount=balance;
}
ld BankDetails::get_balanceAmount()
{
    return balanceAmount;
}



void BankDetails::title_diplay(ll flag=0)
{
    if(flag==1)
    {
     
        cout<<"\n\n**********************************************************************************\n";
        cout<<"\nBank Account details of all the Customer in this table\n\n";
    }
    //formatting
    cout.setf(ios::left,ios::adjustfield);
    cout.setf(ios::fixed,ios::floatfield);

    cout.width(15);
    cout<<"Customer Id";
    cout.width(15);
    cout<<"Record No.";
    cout.width(15);
    cout<<"Account No.";
    cout.width(15);
    cout<<"Name";
    cout.width(15);
    cout<<"Account Type";
    cout.width(15);
    cout<<"Month Id";
    cout.width(15);
    cout<<"Address";
    cout.width(15);
    cout<<"Account Balance"<<endl<<endl;
}
void BankDetails::display(ll flag=0)  //displaying the details for one person
{ 
        if(flag==0)
        {  
            cout<<"\n\n**********************************************************************************\n\n";
            title_diplay();

        }
        cout.setf(ios::left,ios::adjustfield);
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(10);
        cout.width(15);
        cout<<customerId;
        cout.width(15);
        cout<<recordNo;
        cout.width(15);
        cout<<accNumber;
        cout.width(15);
        cout<<depositorName;
        cout.width(15);
        cout<<accType;
        cout.width(15);
        cout<<monthId;
        cout.width(15);
        cout<<address;
        cout.width(15);
        cout<<balanceAmount<<endl;
        if(flag==0)
        {    
        cout<<"\n**********************************************************************************\n\n";
        }

        
}
void display_info_on_account(BankDetails* b_acc,ll acc_no,ll last)
{
    for(int i=1;i<last;i++)
    {
        if(b_acc[i].get_accNumber()==acc_no)
        {
            read(b_acc[i]);
            return b_acc[i].display();
        }
    }
}

void display_all(BankDetails b_acc[],ll last)   
{   
    b_acc[0].title_diplay(1);
    for(int i=1;i<last;i++)
    {   
        read(b_acc[i]);
        b_acc[i].display(1);
    }
    cout<<"\n\n**********************************************************************************\n";

}

void initialize_bank_account(BankDetails b_acc[],ll last,ll acc_no,ll m_id,string name,string acc_type,string address,ld balance)
{
    int j=1001;
    for(int i=1;i<last;i++,j++)
    {
        b_acc[i].set_customerId(i);
        b_acc[i].set_recordNo(j);
        b_acc[i].set_accNumber(acc_no);
        acc_no+=100;

        b_acc[i].set_depositorName(name);
        name[0]=name[0]+1;

        if(i%2==0)
        {
            b_acc[i].set_accType(type1);
        }
        else
        {
            b_acc[i].set_accType(type2);
        }
        b_acc[i].set_address(address);
        address[0]=address[0]+1;
        b_acc[i].set_balanceAmount(balance);
        balance+=balance;
        m_id=i%12+1;
        b_acc->set_monthId(m_id);

    }
    write(b_acc,last);
    
}
ll retrieveRecordNo(BankDetails b_acc[],ll acc_No,ll last)
{
    //int cus_id;
    for(int i=1;i<last;i++)
    {
        if(b_acc[i].get_accNumber()==acc_No)
        {
            return b_acc[i].get_recordNo();
        }
    }
    return -1;
}
bool accountExist(BankDetails  b_acc[],ll cus_id,ll last)
{
    if(cus_id>=1&&cus_id<last)
    {
        return true;
    }
    return false;
}

BankDetails BankDetails::addNewCustomer(BankDetails  b_acc,ll last)
{   ll acc_no;
    string name;
    string acc_type;
    string address;
    ll month_id;
    ld balance;
    cout<<"\nPlease Enter the Account No.:- ";
    cin>>acc_no;
    cout<<"\nPlease Enter the Name :- ";
    cin>>name;
    cout<<"\nPlease Enter the  Account Type as type1(current) or type2(saving)  :- ";
    cin>>acc_type;
    cout<<"\nPlease Enter the  Month of Creation  :- ";
    cin>>month_id;
    cout<<"\nPlease Enter the  Address  :- ";
    cin>>address;
    cout<<"\nPlease Enter the Balance :- ";
    cin>>balance;

    b_acc.set_customerId(last);
    b_acc.set_accNumber(acc_no);
    b_acc.set_depositorName(name);
    b_acc.set_accType(type1);
    b_acc.set_address(address);
    b_acc.set_monthId(month_id);
    b_acc.set_balanceAmount(balance);

    b_acc.display();
    return b_acc;
}

BankDetails BankDetails::deleteAccount(BankDetails b_acc)
{
    b_acc.set_customerId(-1);
    b_acc.set_accNumber(-1);
    b_acc.set_depositorName("");
    b_acc.set_recordNo(-1);
    b_acc.set_accType("");
    b_acc.set_balanceAmount(-1.0);
    b_acc.set_address("");
    b_acc.set_monthId(-1);

    return b_acc;
}

BankDetails BankDetails::deposit(BankDetails  b_acc)   //depositing an amount
{
        ld depositAmount;
        cout<<"\n Enter Deposit Amount = ";
        cin>>depositAmount;
        b_acc.set_balanceAmount(b_acc.get_balanceAmount()+depositAmount);
        return b_acc;
}
BankDetails BankDetails::withdraw(BankDetails  b_acc)  //withdrawing an amount
{
        ld withdrawAmount;
        cout<<"\n Enter Withdraw Amount :- ";
        cin>>withdrawAmount;
        if(withdrawAmount>balanceAmount)
        {
          cout<<"\n Cannot Withdraw Amount\n";
        }
        else
        {
            b_acc.set_balanceAmount(b_acc.get_balanceAmount()-withdrawAmount);
        }
        return b_acc;
}

void BankDetails::interestPerMonth(ll m_id,BankDetails b_acc)
{
    int dif=m_id-b_acc.get_monthId();
    //if(dif<=1)
    {
        int rate=1;
        cout<<"\nRate of interest is 1% per month\n";
        float interest=b_acc.get_balanceAmount()*rate*dif/100.0;
    }
    // else
    // {
    //     cout<<"\nCustomer has withdrawn in less than one month";
    // }
}