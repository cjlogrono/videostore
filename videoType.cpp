#ifndef VIDEOTYPE_CPP
#define VIDEOTYPE_CPP

#include <iostream>
#include <string>
#include "videoType.h"

using namespace std;

namespace video{

	void videoType::setVideoInfo(string title, string star1, string star2, string producer, string director, string productionCo, int setInStock){

		videoTitle = title;
		movieStar1 = star1;
		movieStar2 = star2;
		movieProducer = producer;
		movieDirector = director;
		movieProductionCo = productionCo;
		copiesInStock = setInStock;
	}

	void videoType::checkOut(){

		if(getNoOfCopiesInStock() > 0)
			copiesInStock--;
		else
			cout << "Currently out of stock" << endl;
	}

	void videoType::checkIn(){

		copiesInStock++;
	}

	int videoType::getNoOfCopiesInStock() const{

		return copiesInStock;
	}

	void videoType::printTitle() const{

		cout << "Video Title: " << videoTitle << endl;
	}

	void videoType::printInfo() const{

		cout << "Video Title: " << videoTitle << endl;
		cout << "Stars: " << movieStar1 << " and " << movieStar2 << endl;
		cout << "Producer: " << movieProducer << endl;
		cout << "Director: " << movieDirector << endl;
		cout << "Production Company: " << movieProductionCo << endl;
		cout << "Copies in stock: " << copiesInStock << endl;
	}

	bool videoType::checkTitle(string title){

		return (videoTitle == title);
	}

	void videoType::updateInStock(int num){

		copiesInStock += num;
	}

	void videoType::setCopiesInStock(int num){

		copiesInStock = num;
	}

	string videoType::getTitle(){

		return videoTitle;
	}

	videoType::videoType(string title, string star1, string star2, string producer, string director, string productionCo, int setInStock){

		setVideoInfo(title, star1, star2, producer, director, productionCo, setInStock);
	}

	videoType::~videoType(){}

	bool videoType::operator==(const videoType& right) const{

		return (videoTitle == right.videoTitle);
	}

	bool videoType::operator!=(const videoType& right) const{

		return (videoTitle != right.videoTitle);
	}

	bool videoType::operator<(const videoType& right) const{

		return (videoTitle < right.videoTitle);
	}

	bool videoType::operator<=(const videoType& right) const{

		return (videoTitle <= right.videoTitle);
	}

	bool videoType::operator>(const videoType& right) const{

		return (videoTitle > right.videoTitle);
	}

	bool videoType::operator>=(const videoType& right) const{

		return (videoTitle >= right.videoTitle);
	}

	ostream& operator <<(ostream& out, const videoType& video){

		out << endl;
		out << "Video Title: " << video.videoTitle << endl;
		out << "Stars: " << video.movieStar1 << " and " << video.movieStar2 << endl;
		out << "Producer: " << video.movieProducer << endl;
		out << "Director: " << video.movieDirector << endl;
		out << "Production Company: " << video.movieProductionCo << endl;
		out << "Copies in stock: " << video.copiesInStock << endl;
		out << "__________________________________________" << endl;

		return out;
	}
}
#endif //VIDEOTYPE_CPP