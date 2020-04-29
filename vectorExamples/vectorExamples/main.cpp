#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

vector<string> convertStrgToStrVect(string *inString)
{
	int end = 0, start = 0, i = 0, len = 0, j = 0;
	string *s = inString, newString = "";
	vector<int> startLenVect, endLenVect, strLenVect;
	vector<int> :: iterator itr1, itr2;
	vector<string> stringVect;
	vector<string> :: iterator itr3;

	for(i = 0; i < s->length(); i++)
	{
		if(s[i] != " ")
		{
			end++;
			len = end - start;
		}
		else
		{
			endLenVect.push_back(end);
			startLenVect.push_back(start);
			strLenVect.push_back(len);
			end = i;
			start = i;
		}
	}

	for(itr1 = startLenVect.begin(), itr2 = endLenVect.begin; itr1 != startLenVect.end(); itr1++, itr2++)
	{
		for(i = *itr1, j = 0; i < *itr2; i++, j++)
		{
			newString[j] = s[i];
		}
		newString[++j] = '\0';
		stringVect.push_back(newString);
	}

	for(itr3 = stringVect.begin(); itrs != stringVect.end(); itr3++)
	{
		cout << "stringVect: " << *itr3 << endl;
	}
	return stringVect;
}

vector<string> creatStrVect(int numOfStringElem)
{
	vector<string> vectOfStrngs;
	string inString = ""; // String to accept user input strings  
	int i = numOfStringElem;
	
	// Build the vector of strings, accepting input from user
	for(i = 0; i < numOfStringElem; i++)
	{
		cout << "Enter a string: ";
		cin >> inString;
		vectOfStrngs.push_back(inString);
	}
	return vectOfStrngs;
}

vector<int> getCountOfStr(vector<string> inVectOfStrs)
{
	vector<string> textStrings = inVectOfStrs;
	vector<string> uniqStrings;
	vector<int> countOfStrgs;
	vector<int> :: iterator itr1;
	vector<string> :: iterator itr2, itr3;
	string comparStr = "";
	int *ptrToitrCountStr = NULL;
	unsigned int i = 0, j = 0;

	 // Initialize all vector of count elements to 0
	for(i = 0; i < inVectOfStrs.size(); i++)
	{
		countOfStrgs.push_back(0);
	}

	// Use this pointer to iterate through the vector
	ptrToitrCountStr = countOfStrgs.data();
	for(itr2 = textStrings.begin(), j = 0; itr2 != textStrings.end(); itr2++, j++)
	{
		comparStr = *itr2;
		for(itr3 = textStrings.begin(), i = 0; itr3 != textStrings.end(); itr3++)
		{
			if(comparStr == *itr3)
			{
				ptrToitrCountStr[j] = ++i;
				//cout << "pointToStCount[j]" << j << " " << pointToStCount[j] << endl;
			}
			else
			{
				uniqStrings.push_back(comparStr);
			}
		}
	}
	/*for(itr2 = uniqStrings.begin(); itr2 != uniqStrings.end(); itr2++)
	{
		cout << *itr2 << " ";
	}*/
	return countOfStrgs;
}

void main()
{
	vector <string> textStrings;
	vector<int> stringCount;
	string wordsExcluded[] = {"hello", "world"};
	//vector<string> wrdsToExclud;
	vector <int> :: iterator itr;
	vector<string> :: iterator itr2, itr3;
	int numOfElemStr = 0;
	bool excludWrdFlag = false, uniqOccr = true;
	vector<int> excludStrCount;
	vector<string> excludedWrds;
	vector<string> outVect, outVect2;

	//Create a vector of strings from an array of strings
	vector<string> wrdsToExclud (begin(wordsExcluded), end(wordsExcluded));

	/*cout << "Created a vector from an array of strings\n";
	for(itr2 = wrdsToExclud.begin(); itr2 != wrdsToExclud.end(); itr2++)
	{
		cout << "wrdsToExclud " << *itr2;
	}*/

	// Specify number of strings in vector needed
	cout << "Enter number of strings you want to add: ";
	cin >> numOfElemStr;

	// Build the vector of strings, accepting input from user
	textStrings = creatStrVect(numOfElemStr);

	stringCount = getCountOfStr(textStrings);

	// Vector of count of each of the words
	/*for(itr = stringCount.begin(); itr != stringCount.end(); itr++)
	{
		cout << *itr << " ";
	}*/

	// Build a vector with frequency of only the not excluded words
	for(itr2 = textStrings.begin(), itr = stringCount.begin(); itr2 != textStrings.end(); itr2++, itr++)
	{
		for(itr3 = wrdsToExclud.begin(); itr3 != wrdsToExclud.end(); itr3++)
		{
			//excludWrdFlag = false;
			if(*itr2 == *itr3)
			{
				excludWrdFlag = true;
				break;
			}
			else
			{
				excludWrdFlag = false;
			}
		}
		if(!excludWrdFlag)
		{
			excludedWrds.push_back(*itr2);
			excludStrCount.push_back(*itr);
		}
	}

	// Print the string and it's frequency of the not excluded words
	for(itr = excludStrCount.begin(), itr2 = excludedWrds.begin(); itr != excludStrCount.end(); itr++, itr2++)
	{
		cout << "Word: " << *itr2 << " Frequency: " << *itr << endl;

		// If the frequency of word occurrence is greater than 1
        if(*itr > 1)
		{
			outVect.push_back(*itr2);
		}
	}

	// Print the final output vector of strings to be returned
	cout << "The vector of strings not excluded, that repeat more than once is:\n";
	for(itr2 = outVect.begin(); itr2 != outVect.end(); itr2++)
	{
		cout << "Word: " << *itr2 << endl;
	}

	// Taking a copy, since outVect is going to be altered below
	outVect2 = outVect;

	// Print unique occurrences of words that repeated
    itr2 = unique (outVect.begin(), outVect.end());

    outVect.resize(distance(outVect.begin(),itr2) ); // 10 20 30 20 10

	// Print the final output vector of unique strings to be returned
	cout << "The vector of unique strings not excluded, that repeat more than once is:\n";
	for(itr2 = outVect.begin(); itr2 != outVect.end(); itr2++)
	{
		cout << "Word: " << *itr2 << endl;
	}

	// Another method?
	sort(A.begin(),A.end());
	A.erase(unique(A.begin(),A.end()),A.end());
	for(int&x:A)
	{
		cout<<x<<" ";
	}

	// Print the strings in the vector textStrings
	/*for(itr1 = textStrings.begin(); itr1 != textStrings.end(); itr1++)
	{
		cout << *itr1 << " " << endl;
	}*/

	/*pointToStCount = stringCount.data(); // Assign a pointer to the vector's 'data', to access/ edit the vector's elements

	// Compare each of the string vector's elements with all others each time - O(n^2) :(!!
	for(itr1 = textStrings.begin(), j = 0; itr1 != textStrings.end(); itr1++, j++)
	{
		compareString = *itr1;
        for(itr2 = textStrings.begin(), i = 0; itr2 != textStrings.end(); itr2++)
	    {
		    //stringCount[j] = i; // YOU CAN'T DO THIS! POINT A PTR TO .data() & then assign value to it like shown below
	    	if(*itr2 == compareString)
		    {
				pointToStCount[j] = ++i;
				//cout << "pointToStCount[j]" << j << " " << pointToStCount[j] << endl;
		    }
	    }
	}

	// Output the elements of vector stringCount
	for(itr3 = stringCount.begin(); itr3 != stringCount.end(); itr3++)
	{
		cout << *itr3 << " " << endl;
	}*/
	
	while(1);
}