#include <iostream>
#include <string>
#include <fstream>
#include "videoTree.h"
#include "personTree.h"


using namespace std;
using namespace videoT;
using namespace personT;

void createVideoList(ifstream& infile, videoTree& videoList);
void displayMenu();
void customerName(string& name);
void movieTitle(string& title);
void customerCity(string& city);
void numberOfCopies(int& copies);

int main(){

	videoTree all;
	personTree customers;
	personType person;
	int choice;
	int copies;
	char ch;
	string title;
	string name;
	string city;

	ifstream infile;
	infile.open("videoDat.txt");

	if(!infile){

		cout << "The input file does not exist" << endl;
		return 1;
	}

	createVideoList(infile, all);
	infile.close();

	displayMenu();
	cout << "Enter your choice: ";
	cin >> choice;
	cin.get(ch);
	cout << endl;

	while(choice != 0){

		switch(choice){

			case 1:
				movieTitle(title);
				if(all.videoSearch(title))
					cout << "Title found." << endl;
				else
					cout << "The store does not carry this title." << endl;
				break;

			case 2:
				movieTitle(title);
				cout << endl;
				if(all.videoSearch(title)){

					if(all.isVideoAvailable(title)){

						customerName(name);

						if(customers.personSearch(name))
							customers.personSetMovie(name, title);
						else{

							customerCity(city);
							person.setPersonInfo(name, city, title, "-", "-");
							customers.insert(person);
						}

						all.videoCheckOut(title);
						cout << "Enjoy your movie: " << title << endl;
					}else
						cout << "The video is currently out of stock." << endl;
				
				}else
					cout << "The video is not in the store." << endl;

				break;

			case 3:

				customerName(name);
				if(customers.personSearch(name)){
					movieTitle(title);
					cout << endl;
					if(all.videoSearch(title)){

						customers.personRemoveMovie(name, title);
						all.videoCheckIn(title);
						cout << "Thanks for returning " << title << endl;
					}else
						cout << "This video is not from our store." << endl;
				}else
					cout << "You're not in our records.";
				break;

			case 4:
				movieTitle(title);
				cout << endl;
				if(all.videoSearch(title)){

					if(all.isVideoAvailable(title))
						cout << "The video is currently in stock." << endl;
					else
						cout << "The video is out of stock." << endl;
				}else
					cout << "The video in not in the store." << endl;
				break;

			case 5: 
				all.videoPrintTitle();
				break;

			case 6:
				all.inOrderTraversal();
				break;

			case 7: 
				customers.personPrintNames();
				break;

			case 8:
				customers.inOrderTraversal();
				break;

			case 9:
				movieTitle(title);
				numberOfCopies(copies);
				all.videoUpdateInStock(title, copies);
				break;

			default:
				cout << "Invalid selection." << endl;
		}

		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.get(ch);
		cout << endl;
	}

	return 0;
}

void createVideoList(ifstream& infile, videoTree& videoList){

	string title;
	string star1;
	string star2;
	string producer;
	string director;
	string productionCo;
	char ch;
	int inStock;

	videoType newVideo;

	getline(infile,title, '\n');
	while(infile){

		getline(infile, star1, '\n');
		getline(infile, star2, '\n');
		getline(infile, producer, '\n');
		getline(infile, director, '\n');
		getline(infile, productionCo, '\n');
		infile >> inStock;
		infile.get(ch);
		newVideo.setVideoInfo(title, star1, star2, producer, director, productionCo, inStock);
		videoList.insert(newVideo);

		getline(infile,title, '\n');
	}
}

void displayMenu(){

	cout << "\n\nSelect one of the following: " << endl;
	cout << "1: To check whether a particular video is in the store" << endl;
	cout << "2: To check out a video" << endl;
	cout << "3: To check in a video" << endl;
	cout << "4: To see whether a particular video is in stock" << endl;
	cout << "5: To print the titles of all the videos" << endl;
	cout << "6: To print list of all the videos" << endl;
	cout << "7: To print all customer names" << endl;
	cout << "8: To print all customer info" << endl;
	cout << "9: Update video stock" << endl;
	cout << "0: End program" << endl;
}

void customerName(string& name){

	cout << "What is your name: ";
	getline(cin, name);
}

void movieTitle(string& title){

	cout << "Enter the title: ";
	getline(cin, title);
}

void customerCity(string& city){

	cout << "Enter your city: ";
	getline(cin, city);
}

void numberOfCopies(int& copies){

	bool valid = false;

	do{

		cout << "How many copies did you receive: ";
		cin >> copies;

		if(cin.fail()){

			cin.clear();
			cin.ignore();
			break;

		}else if(copies <= 0){

		}else{

			valid = true;
		}

	}while(!valid);
}
