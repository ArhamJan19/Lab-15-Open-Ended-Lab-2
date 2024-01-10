#include<iostream>
#include<string>
using namespace std;

int AscMergeArray(int Arr1[], int size1, int Arr2[], int size2, int MergedArray[], int sizeMerged);
string Common(int Arr1[], int size1, int Arr2[], int size2);
bool Palindrome(string Str);

int main()
{
	string commonElements, Sentence;
	int mergedarray[12];
	int Arr1[5] = { 21,34,45,12,56 };
	int Arr2[7] = { 5,23,7,3,7,1,34 };
	const int sizeArr1 = 5, sizeArr2 = 7, sizeMerged = 12;
	cout << "Enter a Sentence: ";
	getline(cin, Sentence);
	cout << endl;
	cout << "Array 1 :  ";
	for (int i = 0; i < sizeArr1; i++)
	{
		cout << Arr1[i] << "  ";
	}
	cout << endl;
	cout << "Array 2 :  ";
	for (int i = 0; i < sizeArr2; i++)
	{
		cout << Arr2[i] << "  ";
	}

	AscMergeArray(Arr1,sizeArr1 ,Arr2, sizeArr2 ,mergedarray, sizeMerged);
	cout << "\n\n------------------------MERGED ARRAY-------------------------- \n\n";
	for (int i = 0; i < sizeMerged; i++)
	{
		cout << mergedarray[i] << "    ";
	}
	cout << endl << endl;
	commonElements = Common(Arr1, sizeArr1, Arr2, sizeArr2);
	cout << "------------------------COMMON ELEMENTS-------------------------- \n\n";
	cout << commonElements;
	cout << endl << endl;
	cout << "------------------------PALINDROME-------------------------- \n\n";
	if (Palindrome(Sentence)) {
		cout << "The sentence entered is a palindrome." << endl;
	}
	else {
		cout << "The sentence entered is not a palindrome." << endl;
	}
}

int AscMergeArray(int Arr1[], int size1, int Arr2[], int size2, int MergedArray[], int sizeMerged)
{
	
	for (int i = 0; i < size1; i++) {
		MergedArray[i] = Arr1[i];
	}
	for (int i = 0; i < size2; i++) {
		MergedArray[i + 5] = Arr2[i];
	}

	for (int j = 0; j < sizeMerged - 1; j++)
	{
		int temp;
		for (int k = 0; k < sizeMerged - j - 1; k++)
		{
			if (MergedArray[k] > MergedArray[k + 1])
			{
				temp = MergedArray[k];
				MergedArray[k] = MergedArray[k + 1];
				MergedArray[k + 1] = temp;
			}
		}
	}
	return MergedArray[sizeMerged];
}

string Common(int Arr1[], int size1, int Arr2[], int size2) 
{
	string comm = "";
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (Arr1[i] == Arr2[j])
			{
				comm += to_string(Arr1[i]) + " ";
			}
		}
	}
	return comm;
}

bool Palindrome(string Str)
{
	int leftStr = 0;
	int rightStr = Str.length() - 1;
	while (leftStr < rightStr)
	{
		while (leftStr < rightStr && isspace(Str[leftStr])) {
			leftStr++;
		}

		while (leftStr < rightStr && isspace(Str[rightStr])) {
			rightStr--;
		}

		if (tolower(Str[leftStr]) != tolower(Str[rightStr])) {
			return false;
		}
		leftStr++;
		rightStr--;
	}
	return true;
}