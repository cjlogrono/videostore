#ifndef PERSONTYPE_CPP
#define PERSONTYPE_CPP

#include <iostream>
#include <string>
#include "personType.h"

using namespace std;

namespace person{

	void personType::setPersonInfo(string pName, string pCity, string movie_1, string movie_2, string movie_3){

		name = pName;
		city = pCity;
		movie1 = movie_1;
		movie2 = movie_2;
		movie3 = movie_3;
	}

	void personType::printInfo() const{

		cout << "Person Name: " << name << endl;
		cout << "City: " << city << endl;
		cout << "Movie: " << movie1 << endl;
		cout << "Movie: " << movie2 << endl;
		cout << "Movie: " << movie3 << endl;
	}

	void personType::setMovie(string title){

		if(!maxMovies())
			if(movie1 == "-")
				movie1 = title;
			else if(movie2 == "-")
				movie2 = title;
			else
				movie3 = title;
		else
			cout << "You have a max number of movies checked out";
		
	}

	void personType::removeMovie(string title){

		if(movie1 == title || movie2 == title || movie3 == title){
			if(movie1 == title)
				movie1 = "-";
			else if(movie2 == title)
				movie2 = "-";
			else
				movie3 = "-";
		}else{

			cout << "You haven't checked out this movie yet";
		}
	}

	bool personType::maxMovies(){

		if(movie1 != "-" && movie2 != "-" && movie3 != "-")
			return true;
		else 
			return false;
	}

	string personType::getName(){

		return name;
	}

	personType::personType(string pName, string pCity, string movie_1, string movie_2, string movie_3){

		setPersonInfo(pName, pCity, movie_1, movie_2, movie_3);
	}

	personType::~personType(){}

	ostream& operator <<(ostream& out, const personType& person){

		person.printInfo();

		return out;
	}

	bool personType::operator==(const personType& right) const{

		return (name == right.name);
	}

	bool personType::operator!=(const personType& right) const{

		return (name != right.name);
	}

	bool personType::operator<(const personType& right) const{

		return (name < right.name);
	}

	bool personType::operator<=(const personType& right) const{

		return (name <= right.name);
	}

	bool personType::operator>(const personType& right) const{

		return (name > right.name);
	}

	bool personType::operator>=(const personType& right) const{

		return (name >= right.name);
	}
}
#endif //PERSONTYPE_CPP