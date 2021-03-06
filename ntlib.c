#include "ntlib.h"

long factorial (int n) //Developed by Ojasvin Nagpal
{ //Returns product of all numbers from 1 to n
    int fact=1;
    for (int i=n; i>0; i--)
    {
        fact*=i;
    }
    return fact;
}

int sumUpto(int n) //Developed by Ojasvin Nagpal
{ //returns sum of all numbers from 1 to n
    int sum= (n*(n+1))/2; //using formula
    return sum;
}

int exponent(int a, int b) //Developed by Ojasvin Nagpal
{ //Returns a^b, or, a multiplied by itself b times.=
    int e=1;
    for(int i=0; i<b; i++)
    {
        e*=a;
    }
    return e;
}

int* sortArray(int *arr, int n) //Developed by Ojasvin Nagpal
{ //sorts array in accending order
    int temp;
    for (int i=0; i<n ; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
          if (arr[i] > arr[j])
          {
              temp=arr[i];
              arr[i] = arr[j];
              arr[j] = temp;
          }
      }
  }
  return arr;
}

int gcd(int a, int b) //Developed by Ojasvin Nagpal
{ //function to calculate Greatest Common Divisor of a and b
	a = abs(a);
	b = abs(b);
	int c, hcf;
	if(a > 0 && b > 0)
    	{
    		if(a < b)
    			c = a;    
    		else
    			c = b;
    		for(int i = 1; i <= c; i++)
    		{
     			if(a % i == 0 && b % i == 0)
     				{
     					hcf = i;
     				}
    		}
    		return hcf;
    	}
   	else
    		return a + b;
}

int lcm(int a, int b) //Developed by Ojasvin Nagpal
{ //function to calculate the Lowest Common Multiple of two integers
	return abs(a*b)/gcd(a, b); //Uses property: LCM(a, b) = a*b/GCD(a, b)
}

int arrayGCD(int nums[], int n) //Developed by Aastha Girotra
{ //Returns Greatest Common Divisor of all n numbers in array nums
    int g = nums[0]; 
    for (int i = 1; i < n; i++) 
        g = gcd(nums[i], g); //utilizes property: gcd(a,b,c)=gcd(gcd(a,b),c)
    return g; 
} 

int arrayLCM(int nums[], int n) //Developed by Aastha Girotra
{ //Returns Lowest Common Multiple of all n numbers in array nums
    int l = nums[0]; 
    for (int i = 1; i < n; i++) 
        l = lcm(nums[i], l);  //utilizes property: lcm(a,b,c)=lcm(gcd(a,b),c)
    return l;
}

bool isPrime(int n) //Developed by Ojasvin Nagpal
{ //Checks whether n is prime
    bool flag=true;
    for (int i=2; i<=sqrt((double)n) && flag; i++) //Uses property: if n is not prime, it has atleast one prime factor p such that p<sqrt(n)
    {
        if (n%i==0) 
        {
            flag=false;
        }
    }
    if (n==1)
        flag = false;
    return flag;
}

bool areCoPrime(int a, int b) //Developed by Ojasvin Nagpal
{ //Checks if a and b are relatively prime
    int g=gcd(a,b); //uses property: two numbers are coprime iff their gcd is 1
    if (g==1) 
        return true;
    else
        return false;
}

int nextPrime(int n) //Developed by Ojasvin Nagpal
{ //returns closest prime number greater than n
    for (int i=n+1; ; i++)
    {
        if (isPrime(i))
            return i;
    }
}

int prevPrime(int n) //Developed by Ojasvin Nagpal
{ //returns closest prime number less than n
    if(n<=2) //since 2 is the lowest prime number, returns 2 for any numbers <= 2
    	return 2;
    else
    {
        for (int i=n-1; i>1 ; i--)
        {
            if (isPrime(i))
            return i;
        }
    }
}

int nearestPrime(int n) //Developed by Ojasvin Nagpal
{ //rounds n off to nearest prime number
    if (n<=1)
        return 2; //since 2 is the lowest prime number, returns 2 for all values <=2
    else
    {
        int prev=prevPrime(n); //get previous prime
        int next=nextPrime(n); //get next prime
        int prevdiff=n-prev; //get distance from prev prime to n
        int nextdiff=next-n; //get distance from next prime to n
        if(prevdiff<=nextdiff) //return prime with least distance from n
            return prev;
        else
            return next;
    }
}

int* listPrimes (int n) //Developed by Aastha Girotra
{ //returns pointer to an array that lists first n prime numbers
    int index=0;
    int *p;
    do
    {
        p=(int*)malloc(n*sizeof(int)); //allocates memory to p for an array of n integers
    }while(p==NULL); //ensures that malloc is successful
    for(int i=2; index<n; i++)
    {
        if(isPrime(i)) //if i is prime, it is added to array. This process continues till array contains n numbers
        {
            p[index++]=i;
        }
    }
    sortArray(p, n);
    return p;
}

int countPrimesTill (int n) //Developed by Aastha Girotra
{ //counts and returns number of primes till n
    int count=0;
    for (int i=1; i<abs(n); i++) //array runs from 1 to n-1
    {
        if(isPrime(i)) //if i is prime, increment count
            count++;
    }
    return count;
}

int* listPrimesTill (int n) //Developed by Aastha Girotra
{ //returns pointer to an array rhat holds all prime numbers till n
    int index=0;
    int c=countPrimesTill(n); //gets number of primes till n
    int *p;
    do
    {
        p=(int*)malloc(c*sizeof(int)); //allocates memory to p for an array of c integers
    }while(p==NULL); //ensures malloc is successful
    for(int i=2; i<n; i++) //iterates from 2 to n-1
    {
        if(isPrime(i))
        {
            p[index++]=i; //if i is prime, it is added to array
        }
    }
    sortArray(p, c); //sorts array holding primes in ascending order 
    return p;
}

int getMod(int a, int b) //Developed by Aastha Girotra
{ //function to calculate 'a modulo b' or 'a mod b', i.e., the remainder when a is divided by b
	bool neg=false; //variable created incase negation is required later
	if(b==0)
	{
	    printf("ERROR: DIVISION BY ZERO\n"); 
	    return -1;
	}
	if(a<0 && b<0)
	{ //(-a) mod (-b) = (-1)(a mod b)
		a=abs(a); 
		b=abs(b);
		neg=true; //allows for neagtion of mod later
	}
	
	if((b == 1) || (a==b))
	{
		return 0; //a mod b=0 if b=1, or a=b

	}
	else if (a>0 && b<0)
	{
	    while(a > 0)
			a += b; //when be is negative, continue reducing value of a by b till a becomes negative
	    return a; 
	}
	//if b is positive and not equal to a.
	else
	{ //if a is positive but less than b then 'a mod b' is equal to a.
		if(a > 0 && a < b)
		{
			if(neg) //negate mod if necessary
			    a=0-a;
			return a;
		}
		else if(a < 0)
		{ //as long as a is negative, keep adding b to it. After that, a mod b = a.
			while(a < 0)
				a += b;
		}
		else 		//if a is greater than equal to b.
		{ //keep tracting b from a until a < b. After that, a mod b = a. 
			while(a >= b)			
				a -= b;
		}
	}
	if(neg) //negate mod if necessary
	    return (0-a);
	else
	    return a;
}

bool isCongruent(int a, int b, int m) 
{ //checks whether a mod m is congruent to b mod m, i.e,, a and b give the same remainder when divided by m
	if(getMod(a, m) == getMod(b, m)) 
		return true; 
	else
		return false;
}

int addMod (int a, int b, int m) //Developed by Aastha Girotra
{ // returns a+b (mod m) 
    int sum=a+b;
    return getMod(sum,m);
}

int subMod (int a, int b, int m) //Developed by Aastha Girotra
{ //returns a-b (mod m)
    int diff=a-b;
    return getMod(diff,m);
}

int multiplyMod (int a, int b, int m) //Developed by Aastha Girotra
{ //returns a*b (mod m)
    int prod=a*b;
    return getMod(prod,m);
}

int inverseMod(int a, int m) //Developed by Aastha Girotra
{ //returns x such that a*x (mod m) = 1
    a = getMod(a,m); 
    for (int x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x; 
} 

int expMod(int a, int b, int m) //Developed by Aastha Girotra
{ //returns a^b (mod m)
   int num=exponent(a,b);
   return getMod(num, m);
}

int squareMod(int a, int m) //Developed by Aastha Girotra
{ //returns a^2 (mod m)
   int num=a*a;
   return getMod(a,m);
}

QRT QRtheorem(int a, int b) //Developed by Aastha Girotra
{ //returns a structure QRT x such that a = b*(x.quotient) + (x.remain), where 0 <= x.remain < b
	QRT x;
	x.remain = getMod(a, b);
	x.quotient = (a - x.remain)/b;
	return x;
}

int countFactors (int n) //Developed by Aastha Girotra
{ //returns the number of factors n has, including 1 and n
    int count=0;
    for(int i=1; i<=n; i++) //iterates from 1 to n
    {
        if (n%i==0) //increment count if i divides n
            count++;
    }
    return count;
}

int countPrimeFactors (int n) //Developed by Aastha Girotra
{ //returns the number of prime factors n has
    int count=0;
    for(int i=1; i<=n; i++) //iterates from 1 to n
    {
        if (n%i==0 && isPrime(i)) //increment count if i divides n and i is prime
            count++;
    }
    return count;
}

int* listFactors (int n) //Developed by Aastha Girotra
{ //returns pointer to array that holds all factors of n
    int count=countFactors(n); //gets number of factors
    int index=0;
    int *p;
    do
    {
        p=(int*)malloc(n*sizeof(int)); //allocates memory to p to hold integers equal to number of factors
    }while(p==NULL);  //ensures malloc is successful
    for(int i=1; i<=sqrt(n); i++) //iterates from 1 to sqrt(n) due to property discussed above
    {
        if(n%i==0) //if i divides n
        {
            p[index++]=i;  //add i to array
            p[index++]=(n/i); //add n/i to array since if i divides n, so does n/i
        }
    }
    sortArray(p, count); //sort factors in ascending order
    return p;
}

int* listPrimeFactors (int n) //Developed by Aastha Girotra
{
    int count=countPrimeFactors(n); //gets number of prime factors
    int index=0;
    int *p;
    do
    {
        p=(int*)malloc(n*sizeof(int));  //allocates memory to p to hold integers equal to number of prime factors
    }while(p==NULL); //ensures malloc is successful
    for(int i=1; i<=n; i++) //iterates from 1 to n
    {
        if(n%i==0 && isPrime(i)) //if i divides n and i is prime, adds i to array
        {
            p[index]=i;
            index++;
        }
    }
    return p;
}

int divTimes(int n, int a) //Developed by Aastha Girotra
{ //returns number of times a divides n perfectly
    int count=0;
    while(n%a==0) //if a divides n, n=n/a till a no longer divides n
    {
        n/=a;
        count++;
    }
    return count;
}

int* primeFactorize(int n) //Developed by Aastha Girotra
{ //returns pointer to array holding prime factorization of n
    int count = countPrimeFactors(n);  //get number of prime factors
    int* factors = listPrimeFactors(n); //get array of prime factors
    int* dtimes; //create array to hold how many times each prime factor diides n
    do
    {
        dtimes=(int*)malloc(count*sizeof(int)); //allocates memory to dtimes to hold integers equal to number of unique prime factors
    }while (dtimes==NULL); //ensures malloc is successful
    int index=0;
    for(int i=0; i<count; i++)
    {
        dtimes[i]=divTimes(n, factors[i]); //each element in dttimes holds the number of times the corresponfding elemsnt in factors divides n 
    }
    int size=0; 
    for(int i=0; i<count; i++)
    {
        for(int j=0; j<dtimes[i]; j++)
        {
            size++;
        }
    } //calculates sixe of rrray needed to hold prime factorization
    int* factorization;
    do
    {
        factorization=(int*)malloc(size*sizeof(int)); //allocates appropriate memory to pointer
    }while(factorization==NULL); //ensures malloc is successful
    for(int i=0; i<count; i++)
    { //adds each prime factor to factorization the number of times the factor divides n
        for(int j=0; j<dtimes[i]; j++)
        {
            factorization[index++]=factors[i];
        }
    }
    return factorization;
}

int discreteLogarithm(int a, int b, int m) //Developed by Aastha Girotra
{ //Returns x such that a^x = b (mod m)
    for (int i=0; i<m; i++)
    {
        if(isCongruent(exponent(a,i), b, m)) //checks if a^i = b (mod m)
            return i;
    }
}

//Return degree of a polynomial
// Takes as arguments two arrays (one of coefficient and one of exponent) and the size of the array
int degree(int coefficient[], int exponent[], int n) //Developed by Kavya Narain
{
	int deg = exponent[0];
	for(int i = 1; i < n; i++)
	{
		if(exponent[i] > exponent[i-1])
			return deg = exponent[i];
	}
	return deg;
}

//Sorting two arrays in coordination
//It sorts the array with exponents in ascending order and the coeffcient array according to the exponent array
// Takes as arguments two arrays (one of coefficient and one of exponent) and the size of the array
void sort(int sortarr[], int corrarr[], int n) //Developed by Kavya Narain
{
	int swap = 1; 
	int temp[1];

	while(swap != 0)
	{
		swap = 0;

		for (int i = 0; i < n - 1; i++)
		{
			if(sortarr[i] > sortarr[i+1])
			{
				//Sorting the main array
				temp[0] = sortarr[i];
				sortarr[i] = sortarr[i+1];
				sortarr[i+1] = temp[0];
				//Sorting the array along with it
				temp[0] = corrarr[i];
				corrarr[i] = corrarr[i+1];
				corrarr[i+1] = temp[0];
				swap += 1;
			}
		} 
	}
}

//Combining the same exponents: This adds the coefficients which have the same exponent. It also reflects these changes in the exponent array.
// Takes as arguments two arrays (one of coefficient and one of exponent) and the size of the array
void combine(int coefficient[], int exponent[], int n) //Developed by Kavya Narain
{
	int comb = 1;
	int temp[1];

	while(comb!=0)
	{
		comb = 0;
		for(int i = 0; i < n-1; i++)
		{
			if(exponent[i] == exponent[i + 1])					//If there are like terms
			{
				temp[0] = coefficient[i] + coefficient[i+1];
				coefficient[i] = temp[0];
				for(int j = i+1; j < n-1; j++)
				{
					coefficient[j] = coefficient[j+1]; 			//Adding like terms
					exponent[j] = exponent[j+1];				//Reflecting changes in the exponents
					n--;
				}
				//Accounting for changes to be made to the last coefficient and corresponding exponent
				coefficient[n] = 0;
				exponent[n] = exponent[n-1] + 1;
				comb += 1;
			}
		}
	}
}

//Returns the coefficient array in a uniform format 
//Does away with the need for a exponent array
// Takes as arguments two arrays (one of coefficient and one of exponent) and the size of the array
int *uniform(int coefficient[], int exponent[], int n) //Developed by Kavya Narain
{
	int count = 0;

	//Counts the number of additional memory will be needed in the new coefficient array
	for (int i = 1; i < n; i++)
	{
		//No additional memory if the two terms in the exponent array are consecutive
		if(exponent[i] - exponent[i-1] == 1) 
		{
			count = count;
		}
		//Additional memory required if the two terms in the exponent array are not consecutive
		else
		{
			count = count + exponent[i] - exponent[i-1] -1;
		}
	}
	//Additional memory required if the exponent array does not reflect possibility for the constant term
	if(exponent[0] != 0)
	{
		count++;
	}

	int z = 0;
	int ncoefficient[n+count];
	int cnt = 0;
	int difference;

	//Adding space for the constant term in the new coefficient array
	if(exponent[0] != 0)
	{
		ncoefficient[0] = 0;
		cnt++;
	}
	//Adding the other additional space required in the new coefficient array
	for(int i = 1; i < n; i++)
	{
		if(z == 0) 										//Only runs if in the previous loop additional space was not added
		{	
			difference = exponent[i] - exponent[i-1];	//Calculated the amount of additional space that neds to be added
		}

		//If no additional space needs to be added, the term in the new coefficeint array is the same as the term in the coefficient array
		if(difference == 1)
		{
			ncoefficient[cnt] = coefficient[i-1];
			cnt++;
			z = 0;
		}
		else										//If additional space needs to be added
		{
			//The term in the coefficient array and the new array is the same.
			ncoefficient[cnt] = coefficient[i-1];
			cnt++;
			//The loop runs till all the additional space has been created in the new coefficient array
			while(difference != 1)
			{
				//All additional space has the coefficient of 0
				ncoefficient[cnt] = 0;
				cnt++;
				difference--;
			}
			z = 1;
		}
	}
	//Taking care of the last element in the coefficent array
	ncoefficient[n-1] = coefficient[n-1];

	//Returning a pointer to the new coefficeint array
	int *ptr;
	ptr = ncoefficient;
	return ptr;
}

//Returna Standard form
// Takes as arguments two arrays (one of coefficient and one of exponent) and the size of the array
void standard(int coefficient[], int exponent[], int n) //Developed by Kavya Narain
{
	//Uses the sort and combine function to convert the coefficent and exponent array into standard form
	
	//Sorts the arrays in ascending order of exponents
	sort(exponent, coefficient, n);
	//Adds like terms
	combine(coefficient, exponent, n);
}

//Returns sum of two polynomials
// Takes as argument two arrays (each of coefficents of a polynomial) and two integers (each for the size of the array)
int *sum(int coefficient1[], int n1, int coefficient2[], int n2) //Developed by Kavya Narain
{ //Assumption: array inputs of coefficients are in standard form
	//Finds which arrays has more elements
	int max;
	if(n1 > n2)
	{	
		max = n1;
	}
	else
	{
		max = n2;
	}

	//Creates a new array to store the sum of the two arrays, size of this array is the size of the larger array
	int sumcoefficient[max];

	//If the size of both arrays is the same, then all elements are simply added.
	if(n1 == n2)
	{
		for(int i = 0; i < n1; i++)
		{
			sumcoefficient[i] = coefficient1[i] +  coefficient2[i];
		}
	}
	//If the size of array 1 is greater
	else if(n1 > n2)
	{
		//Elements of both arrays are simply added till traversal through the second array is complete
		for(int i = 0; i < n2; i++)
		{
			sumcoefficient[i] = coefficient1[i] +  coefficient2[i];
		}
		//The remaining elements are equal to the elements in the first array
		for(int i = n2; i < n1; i++)
		{
			sumcoefficient[i] = coefficient1[i];
		}
	}
	//If the size of array 2 is greater	
	else
	{
		//Elements of both arrays are simply added till traversal through the first array is complete
		for(int i = 0; i < n1; i++)
		{
			sumcoefficient[i] = coefficient1[i] +  coefficient2[i];
		}
		//The remaining elements are equal to the elements in the second array
		for(int i = n2; i < n2; i++)
		{
			sumcoefficient[i] = coefficient2[i];
		}
	}

	//Creating a pointer to the sum array
	int *ptr = (int *)malloc((max)*sizeof(int));
	ptr = sumcoefficient;
	//Returns pointer to the array storing the sum
	return ptr;
}

//Returns difference of two polynomials
// Takes as argument two arrays (each of coefficents of a polynomial) and two integers (each for the size of the array)
int* dif(int coefficient1[], int n1, int coefficient2[], int n2) //Developed by Kavya Narain
{ //Assumption: array inputs of coefficients are in standard form
	//Finds which arrays has more elements
	int max;
	if(n1 > n2)
	{
		max = n1;
	}
	else
	{
		max = n2;
	}
	//Creates a new array to store the difference of the two arrays, size of this array is the size of the larger array
	int difcoefficient[max];

	//If the size of both arrays is the same, then all elements in the second array are simply subtracted from the elements in the first array.
	if(n1 == n2)
	{
		for(int i = 0; i < n1; i++)
		{
			difcoefficient[i] = coefficient1[i] - coefficient2[i];
		}
	}
	//If the size of array 1 is greater
	else if(n1 > n2)
	{
		//Normal subtraction occurs till traversal through the second array is complete
		for(int i = 0; i < n2; i++)
		{
			difcoefficient[i] = coefficient1[i] - coefficient2[i];
		}
		//The difference now is simply equal to the elements in the first array
		for(int i = n2; i < n1; i++)
		{
			difcoefficient[i] = coefficient1[i];
		}
	}	
	//If the size of array 2 is greater
	else
	{
		//Normal subtraction occurs till traversal through the first array is complete
		for(int i = 0; i < n1; i++)
		{
			difcoefficient[i] = coefficient1[i] - coefficient2[i];
		}
		//The difference now is simply equal to the elements in the second array subtracted from 0
		for(int i = n2; i < n2; i++)
		{
			difcoefficient[i] = 0 - coefficient2[i];
		}
	}

	//Creating a pointer to the array storing the difference
	int *ptr = (int *)malloc((max)*sizeof(int));
	ptr = difcoefficient;

	//Returning a pointer to the array storing the difference of two arrays
	return ptr;
}

//Returns Product of two polynomials
// Takes as argument two arrays (each of coefficents of a polynomial) and two integers (each for the size of the array)
int *product(int coefficient1[], int n1, int coefficient2[], int n2) //Developed by Kavya
{ //Assumption: array inputs of coefficients are in standard form
	//Dynamically creates a new array to store the product of the polynomials 
	//Size of this array is the sum of the number of element in both the polynomials
	int *prodcoef = (int*)malloc((n1 + n2 - 1)*sizeof(int));

	//The new array is initialised to 0
	for(int i = 0; i < n2+n1-1; i++)
	{
		prodcoef[i] = 0;
	}

	//Runs for all the elements in the first polynomial
	for (int i = 0; i < n1; i++)
	{
		//Runs for all the elements in the second polynomial
		for (int j = 0; j < n2; j++)
		{
			//Multiplies the coefficients of every element in the first polynomial with every element in the second polynomial
			prodcoef[i+j] += coefficient1[i]*coefficient2[j];
		}
	}

	//Returns a pointer to the array that is storing the product of the polynomials.
	return prodcoef;
}

// Takes as arguments two arrays (one of coefficient and one of exponent) and the size of the array
fac* factor(int coefficient1[],int exponent1[], int n1) //Developed by Kavya Narain
{ //Assumption: array inputs of coefficients are in standard form
	//Finds the GCD of the array
	int h = arrayGCD(coefficient1, n1);
	int f = 0;
	//Data of type fac (struct) is created
	fac* new = (fac*)malloc(sizeof(fac));
	
	//If the GCD is greater than 1, the polynomial is factorised
	if (h > 1)
	{
		//Runs for the length of the polynomial
		//Finds the exponent (and stores in f) which is common to all elements in the polynomial
		for(int i = 0; i < n1; i++)
		{
			if(coefficient1[i] != 0)
			{
				f = exponent1[i];
				break;
			}
			else
			{
				//The exponent remains 0, if there is a constant term in the polynomial
				f = 0;
			}
		}

		//Runs for the length of the polynomial
		for (int i = 0; i < n1; i++)
		{
			//Modifies the coefficeint array and the exponent array to reflect the changes made due to factorisation
			coefficient1[i] = coefficient1[i]/h;
			exponent1[i] = exponent1[i] - f;
		}

		//Stores all the factors in the struct variable
		for(int i = 0; i < n1; i++)
		{
			new->arr1[i] = coefficient1[i];
			new->arr2[i] = exponent1[i];
		}
		new->common = h;
		new->expcom = f;
	}
	//If the GCF is 1
	else
	{
		//Checks if an exponent can be used to factorise
		for(int i = 0; i < n1; i++)
		{
			//Ensures that the exponent factor (f) is the exponent of the first non-zero coefficient in the polynomial
			if(coefficient1[i] == 0)
			{
				f=0;
				continue;
			}
			else
			{
				f = exponent1[i];
				break;
			}
		}

		//Runs for the length of the polynomial
		for (int i = 0; i < n1; i++)
		{
			//Modifies the coefficeint array and the exponent array to reflect the changes made due to factorisation
			coefficient1[i] = coefficient1[i]/h;
			exponent1[i] = exponent1[i] - f;
		}

		//Stores all the factors in the struct variable
		for(int i = 0; i < n1; i++)
		{
			new->arr1[i] = coefficient1[i];
			new->arr2[i] = exponent1[i];
		}
		new->common = h;
		new->expcom = f;
	}
	// Returns the struct variable so all the factors and their corresponding exponents are returned
	return new;
}
