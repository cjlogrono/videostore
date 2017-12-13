#ifndef VIDEOTYPE_H
#define VIDEOTYPE_H
#include <iostream>

using namespace std;

namespace video{

	class videoType{

		friend ostream& operator<<(ostream&, const videoType&);

		public:

			videoType(string title = "", string star1 = "", string star2 = "", string producer = "", string director = "", string productionCo = "", int setInStock = 0);

			~videoType();

			void setVideoInfo(string title, string star1, string star2, string producer, string director, string productionCo, int setInStock);

			int getNoOfCopiesInStock() const;

			void checkOut();

			void checkIn();

			void printTitle() const;

			void printInfo() const;

			bool checkTitle(string title);

			void updateInStock(int num);

			void setCopiesInStock(int num);

			string getTitle();

			bool operator==(const videoType&) const;

			bool operator!=(const videoType&) const;

			bool operator<(const videoType&) const;

			bool operator<=(const videoType&) const;

			bool operator>(const videoType&) const;

			bool operator>=(const videoType&) const;


		private:

			string videoTitle;
			string movieStar1;
			string movieStar2;
			string movieProducer;
			string movieDirector;
			string movieProductionCo;
			int copiesInStock;
	};
} //queue

#endif //VIDEOTYPE_H
#include "videoType.cpp"