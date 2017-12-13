#ifndef PERSONTYPE_H
#define PERSONTYPE_H
#include <iostream>

using namespace std;

namespace person{

	class personType{

		friend ostream& operator<<(ostream&, const personType&);

		public:

			personType(string pName = "", string pCity = "", string movie_1 = "-", string movie_2 = "-", string movie_3 = "-");

			~personType();

			void setPersonInfo(string pName, string pCity, string movie_1, string movie_2, string movie_3);

			void printInfo() const;

			void setMovie(string title);

			void removeMovie(string title);

			bool maxMovies();

			string getName();

			bool operator==(const personType&) const;

			bool operator!=(const personType&) const;

			bool operator<(const personType&) const;

			bool operator<=(const personType&) const;

			bool operator>(const personType&) const;

			bool operator>=(const personType&) const;

		private:

			string name;
			string city;
			string movie1;
			string movie2;
			string movie3;	
		};
}

#endif //PERSONTYPE_H
#include "personType.cpp"