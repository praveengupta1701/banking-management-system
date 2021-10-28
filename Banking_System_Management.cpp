/*Banking System Management
Design a project to represent a bank account and its relevant operations, where following details
can be maintained:
1. Depositor name,
2. account number(you may define any starting number),
3. type of account,
4. balance amount in the account.
5. Any other attribute required you may add it by your own.
Also, the following set of operations/actions should be provided:
1. Add new customers to the bank who become an account holder.
2. Display a list of all the account holders of the bank along with their account numbers and
balance.
3. Delete the information related to the account holder from the customer data file
4. Update the balance after customer has performed a deposit or withdraw transaction
5. display the account number of the last entry
6. check whether an account exists or not
7. retrieve the name of the account holder
8. retrieve the address of the account holder
9. retrieve the balance of the account holder
10. returns the record number from the customer file when an employee of the bank enters
the account number related to an account holder(Transaction details along with the
account information)
11. displays all the information related to an account holder from the customer file on the
basis of specified account number.
12. Calculate the interest to date on the deposit if a particular customer has not withdrawn
for more than a month
 
*/
#include<iostream>
#include<cstring>
#include "bank_detail.h"
using namespace std;

#define NO_OF_CUSTOMER 10000
ll lastaccount=21;

int main()
{
       
        BankDetails b_acc[NO_OF_CUSTOMER];
        ll acc_no=100,m_id=1;
        string name="a", acc_type,add="0";
        ld balance=100.0;
        initialize_bank_account(b_acc,lastaccount,acc_no,m_id,name,acc_type,add,balance);
        
        //display_all(b_acc,20);

        while(1)
        {
          int cus_id,choice;
          cout<<"\n\n**********************************************************************************\n";
          cout<<"\nFeatures of Bank are as follows\n\n";
          cout<<"\n\n**********************************************************************************\n";
          cout<<"\n1.  Add new customers to the bank who become an account  holder.";
          cout<<"\n2.  Display a list of all the account holders of the bank along\n    with their account numbers and balance.";
          cout<<"\n3.  Delete the information related  to the account holder  from \n    the customer data file.";
          cout<<"\n4.  Update the balance after  customer has  performed a deposit \n    or withdraw transaction.";
          cout<<"\n5.  Display the account number of the last entry.";
          cout<<"\n6.  Check whether an account exists or not.";
          cout<<"\n7.  Retrieve the name of the account holder.";
          cout<<"\n8.  Retrieve the address of the account holder.";
          cout<<"\n9.  Retrieve the balance of the account holder.";
          cout<<"\n10. Returns the record  number from the  customer  file when an \n    employee of the  bank  enters  the account  number  related \n    to an account holder ( Transaction  details  along with the \n    account information).";
          cout<<"\n11. Displays  all the information  related to an account holder \n    from the customer file  on  the  basis of specified account \n    number.";
          cout<<"\n12. Calculate  the  interest  to  date  on  the  deposit  if  a \n    particular  customer has  not  withdrawn  for  more  than a \n    month.";
          cout<<"\n13. EXIT";
          cout<<"\n\n**********************************************************************************\n";
          cout<<"\nEnter the choice for the operation which has to be performed on the Bank Account \n\n";
          cin>>choice;
          switch (choice)
          {
          
              /*Add new customers to the bank who become an account  holder.*/
              case 1:
                b_acc[lastaccount]=b_acc[lastaccount].addNewCustomer(b_acc[lastaccount],lastaccount);
                lastaccount+=1;

                break;

              /*Display a list of all the account holders of the bank along with their account numbers and balance.*/
              case 2:
              display_all(b_acc,lastaccount);
                break;

              /*Delete the information related  to the account holder  from the customer data file.*/
              case 3:
                
                cout<<"\nPlease Enter the customer Id for the account to be deleted :- ";
                cin>>cus_id;
                b_acc[cus_id]=b_acc[cus_id].deleteAccount(b_acc[cus_id]);

                break;
              
              /*Update the balance after  customer has  performed a deposit or withdraw transaction.*/
              case 4:
                int choice;
                cout<<"\n\nEnter  the choice\n\n1. for deposit transaction  \n2. for withdraw transaction \n\n";
                cin>>choice;
                switch (choice)
                {
                  /*for deposit transaction*/ 
                  case 1:
                    cout<<"\nPlease Enter the customer Id :- ";
                    cin>>cus_id;
                    b_acc[cus_id]=b_acc[cus_id].deposit(b_acc[cus_id]);
                    // b_acc[cus_id].display();
                    choice=0;
                    break;
                  /*for withdraw transaction*/
                  case 2:
                    cout<<"\nPlease Enter the customer Id :- ";
                    cin>>cus_id;
                    b_acc[cus_id]=b_acc[cus_id].withdraw(b_acc[cus_id]);
                    // b_acc[cus_id].display();
                    choice=0;
                    break;
                  
                  default:
                    cout<<"\nYour choice is incorrect.\n\n";
                    break;
                  }
                
                break;
                          
              /*Display the account number of the last entry.*/
              case 5:
                b_acc[lastaccount-1].display();
              
                break;
                      
              /*Check whether an account exists or not.*/
              case 6:
                cout<<"\nPlease Enter the customer Id :- ";
                cin>>cus_id;
                if(accountExist(b_acc,cus_id,lastaccount))
                {
                  cout<<"\nAccount exist\n";
                }
                else
                {
                  cout<<"\nAccount does not exist\n";
                }

                break;

              /*Retrieve the name of the account holder.*/
              case 7:
                cout<<"\nPlease Enter the customer Id :- ";
                cin>>cus_id;
                cout<<"Name of the account holder :- "<<b_acc[cus_id].get_depositorName();

                break;

                      
              /*Retrieve the address of the account holder.*/
              case 8:
                cout<<"\nPlease Enter the customer Id :- ";
                cin>>cus_id;
                cout<<"Address of the account holder :- "<<b_acc[cus_id].get_address();
                break;
                      
              /*Retrieve the balance of the account holder.*/
              case 9:
                cout<<"\nPlease Enter the customer Id :- ";
                cin>>cus_id;
                cout<<"Balance of the account holder :- "<<b_acc[cus_id].get_balanceAmount();
              
                break;
                      
              /*Returns the record  number from the  customer  file when an employee of the  bank  enters  the account  number  related to an account holder ( Transaction  details  along with the account information).*/
              case 10:
                cout<<"\nPlease Enter the account  number :- ";
                cin>>acc_no;
                cout<<"record  number from the  customer  file when an employee of the  bank  enters  the account  number  related to an account holder ( Transaction  details  along with the account information) :- "<<retrieveRecordNo(b_acc,acc_no,lastaccount)<<endl;
              
                break;
                      
              /*Displays  all the information  related to an account holder from the customer file  on  the  basis of specified account number.*/
              case 11:
                cout<<"\nPlease Enter the account  number :- ";
                cin>>acc_no;
                cout<<"\nDisplays  all the information  related to an account holder from the customer file  on  the  basis of specified account number.  \n";
                display_info_on_account(b_acc,acc_no,lastaccount);

              
                break;
                      
              /*Calculate  the  interest  to  date  on  the  deposit  if  a particular  customer has  not  withdrawn  for  more  than a month.*/
              case 12:
                m_id=b_acc[lastaccount-1].get_monthId();
                cout<<"\nPlease Enter the customer Id :- ";
                cin>>cus_id;
                b_acc[cus_id].interestPerMonth(m_id,b_acc[cus_id]);
                
                break;
              
                      
              /*EXIT*/
              case 13:
                exit(0);
              default:
                cout<<"\nYour choice is incorrect. Please choose the correct option\n\n";
                break;
        }
      }

        return 0;
}
