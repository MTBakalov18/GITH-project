#include <iostream>

#include <string>



using namespace std;



struct WORDS

{

	string mainword;

	string description;

	//bool favorite = false;

};



WORDS word[100];



int getAvailableSpot()

{

	for (int i = 0; i < 100; i++)

	{

		if (word[i].mainword == "")

		{

			return i;

		}

	}

	return -1;

}



void printAllWords() {

	for (int i = 0; i < 100; i++) {

		if (word[i].mainword != "") {

			cout << i + 1 << ". " << word[i].mainword << " - " << word[i].description << endl;

		}

	}

}



void startupMessage()

{

	cout << "Welcome to WordNotes" << endl;

	cout << "Our program is meant to help students and people with learning foreign languages by saving words, that they insert." << endl;

	cout << "You can also add descriptions to the words.";

}

void menuMessage()

{

	cout << "Choose one of the options listed below by typing the number on the next line." << endl;

	cout << "1. Add a word to your WordBook" << endl;

	cout << "2. Find a word in your WordBook" << endl;

	cout << "3. Remove a word in your WordBook" << endl;

	cout << "4. Exit the program." << endl;

}

void showAllFindings(char letter) {

	int l = 0;

	for (int i = 0; i < 100; i++) {

		if (word[i].mainword[0] == letter) {

			l += 1;

			cout << l << ". " << word[i].mainword << endl;

		}

	}

	cout << endl;

}



void findAndDelete(string input) {

	for (int i = 0; i < 100; i++) {

		if (word[i].mainword == input) {

			word[i].mainword = "";

			word[i].description = "";

			for (int j = i; j < 99; j++) {

				word[j].mainword = word[j + 1].mainword;

				word[j].description = word[j + 1].description;

			}

			cout << "Word " << input << " has been deleted from WordBook!" << endl;

			return;

		}

	}

	cout << "No word has been found by the name: " << input << ".";

}

//-----------=------------------

// Main Functions



void createWord()

{

	if (getAvailableSpot() != -1) {

		string fake;

		getline(cin, fake);

		cout << "Please enter a new word!" << endl;

		string tword;

		getline(cin, tword);

		cout << "Please enter a description of the word!" << endl;

		string tdesc;

		getline(cin, tdesc);

		int spotindex = getAvailableSpot();
		
		word[spotindex] = { tword,tdesc };

		cout << endl << "Word has been added to the WordBook!" << endl << endl;

	}

}

void editWord() {

	cout << "Choose one of the options bellow." << endl << "1. Search a word by first letter." << endl << "2. Show all the words that have been added." << endl;

	char a; cin >> a;

	if (a == '1') {

		cout << endl << "Enter the Word's Letter." << endl; char b; cin >> b;

		showAllFindings(b);

	}
	else if (a == '2') {

		printAllWords();

	}
	else {

		cout << "Please enter a valid numbered option." << endl;

	}

}



void deleteWord() {

	cout << "Choose the Word that you would like to delete." << endl;

	printAllWords();

	cout << endl;

	string a;

	cin >> a;

	findAndDelete(a);

}



//--------------------



int main()

{

	startupMessage();

	char num;

	while (true)

	{

		menuMessage();

		cin >> num;

		if (num == '1') {

			createWord();

		}
		else if (num == '2') {

			editWord();

		}
		else if (num == '3') {

			deleteWord();

		}
		else if (num == '4') {

			cout << "Thank you for using our programme!";

			return 0;

		}
		else {

			cout << "Please enter a valid numbered option." << endl;

		}

	}
}