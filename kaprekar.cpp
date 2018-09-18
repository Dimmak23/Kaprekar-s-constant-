#include <iostream>

// Main information stored private in the class
class Kaprekar
{
	private:
	// Variable for inputed number
	unsigned long long initial_in=0;
	// Quatity of digits from inputed number
	int K=0;
	// Container for storing digits of the calc. number
	int newNumber[19]={0};
	// Variable for current number
	unsigned long long actual_in=0;
	// Variable for left operand of the substruction
	unsigned long long outL=0;
	// Variable for right operand of the substruction
	unsigned long long outR=0;
	// Container for storing new numbers
	unsigned long long SEQ[19]={0};
	// Quantity of the repetetive numbers 
	int Num=0; 
	// Starting point of the repetetive numbers
	int count=0;
	// Quatity of the iterations
	int iter=0;

	public:
	// User get notification with promt to enter
	// a number for research
	void setInput()
		{
			//std::cout<<"\nEnter your N-digit number ";
			//std::cout<<"(less than 18446744073709551615): ";
			std::cout<<"\nEnter numbers for research: ";
			std::cin>>initial_in;
			actual_in=initial_in;
		}
	// Function check if entered number is valid
	// for calculations
	bool checkValid()
		{
			// Temporary container with initial number 
			unsigned long long x=initial_in;
			// Array (checker) with quantity repeates times
			// and variable (maxs) with max repeates 
			int cheker[19]={0}, maxs=0;
			// Check digit quantity and set array of digits
			do
				{
					newNumber[K++]=x%10;
					x/=10;
				}
			while(x);
			// Set repeates in the checker[]
			for(int i=0;i<K;i++)
				for(int j=0;j<K;j++)
					if(newNumber[i]==newNumber[j]) cheker[i]++;
			// Set max repeates
			for(int i=0;i<K;i++) if(maxs<cheker[i]) maxs=cheker[i];
			// Error note for 4-digit numbers
			if( (maxs>2) && (K==4) ) 
				{
					std::cout<<"Entered number is invalid.\n";
					std::cout<<"Avoid more than 2-times ";
					std::cout<<"repeated numbers for 4-digit input.\n";
					return false;
				}
			// Error note for 3-digit number
			if( (maxs>1) && (K==3) )
				{
					std::cout<<"Entered number is invalid.\n";
					std::cout<<"Avoid repeatetive numbers ";
					std::cout<<"for 3-digit input.\n";
					return false;
				}
			// Error note everyone else
			if( (K>2) && (maxs>=(K-1)) )
				{
					std::cout<<"Entered number is invalid.\n";
					std::cout<<"Too many repetetive numbers.\n";
					return false;
				}								
		}
	// Check if new number is not stored in the SEQ container
	bool checkNew()
		{
			// Zero input will be avoid
			if(!actual_in) return false;
			// If number already in the SEQ return index
			// for later printing
			for(int i=0; i<Num; i++)
				if(actual_in==SEQ[i])
					{
						count=i;
						return false;
					}
			// Lines executes only if new number is
			// not stored yet
			SEQ[Num++]=actual_in;
			// Return up with "true"
			return true;
		}
	// Claculate new left, right operand of substraction
	// for getting new nuber
	unsigned long long postedNew(unsigned long long y,
		unsigned long long &resD, unsigned long long &resA)
		{
			// Temporary containers
			int temp=0, z=0;
			// Set operands to zero
			resA=resD=0;
			// If enetered number is 1-digit
			// reload it to 2-digit
			if(K==1)
				{
					K=2;
					newNumber[0]=0;
					newNumber[1]=y;
					goto NEXT;
				}
			// Reset digits in the container
			do
				{
					newNumber[z++]=y%10;
					y/=10;
				}
			while(y);
			// Sort container
			NEXT:
			for(int i=(K-1);i>0;i--)
				for(int j=1;j<=i;j++)
					if(newNumber[j-1]>newNumber[j])
						{
							temp=newNumber[j-1];
							newNumber[j-1]=newNumber[j];
							newNumber[j]=temp;
						}
			// Get ascending and descending numbers		
			for(int i=0;i<K;i++) 
				{
					resA=resA*10+newNumber[i];
					resD=resD*10+newNumber[K-i-1];
				}
		}
	// Calculate repeates SEQ
	int getIter()
		{
			// If researched number is not stored yet
			if( checkNew() )
				{
					// Get operands
					postedNew(actual_in,outL,outR);
					iter++;
					// Print iterations
					std::cout<<iter<<". "<<outL<<" - ";
					std::cout<<outR<<" = "<<outL-outR<<"\n";
					// Set new number for research
					actual_in=outL-outR;
					// Recurse function
					getIter();
				}
		}
	// Return quantity of iterations
	int retIter()
		{
			return iter;
		}
	// Print result
	void getResult()
		{
			int j=0;
			std::cout<<"\nRepetetive sequence for ";
			std::cout<<K<<"-digit input is: "<<"\n\n";
			for(int i=count;SEQ[i]!=0;i++)
				std::cout<<j++<<". "<<SEQ[i]<<"\n";
		}

};

// Starting point
int main()
{
	// Creation of caller
	Kaprekar call;
	// Get number from user
	call.setInput();
	// Start research if input valid
	if(call.checkValid())
		{
			std::cout<<"\nGetting iterations:\n\n";
			// Initilize of calculations
			call.getIter();
			// Output of quantity of iterations
			std::cout<<"\nResearch took "<<call.retIter()<<" iterations.\n";
			// Print when calculations is finished
			call.getResult();
		}

	return 0;
}
