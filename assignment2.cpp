#include<iostream>
using namespace std;

class Bank{
	private:
		string accountHolder;
		int accountNumber;
		string accountType;
		double balance;
		
	public:
		void getAccountDetails(){
			cout<<"Holder        :" <<accountHolder <<endl;
		    cout<<"Account Number:" <<accountNumber <<endl;
		    cout<<"Type          :" <<accountType <<endl;
		    cout<<"Balance       :" <<balance <<endl <<endl;
		}
		
		void setAccountType(string newType){
			this->accountType=newType;
			cout<<"Updated Account Type to" <<accountType <<endl <<endl;
		}
		
		int deposit(double amount){
			this->balance=balance+amount;
			cout<<"Depositing :" <<amount <<endl;
			cout<<"New balance" <<balance <<endl <<endl;	
		}
		
		int withdraw(double amount){
			this->balance = balance - amount;
			cout<<"withdrawing :" <<amount <<endl;
			cout<<"New balance :" <<balance <<endl <<endl; 
		}
		
		Bank(){
			accountHolder="none";
			accountNumber=0;
			accountType="none";
			balance=0;
		}
		
		Bank(string AH, int AN, string AT,double B){
			accountHolder = AH;
			accountNumber = AN;
			accountType = AT;
			balance = B;
	    }
		
};

int main(){
	
	Bank holder1("Harshvardhan Gurav",87889887,"savings",3000);
	holder1.getAccountDetails();
	holder1.deposit(3000);
	holder1.withdraw(1500);
	holder1.setAccountType("current");
	cout<<"final";
	
} 
