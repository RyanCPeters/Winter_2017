#include "stored_data/movie/movie.h"
#include <string>
#include <utility> #include "dvd.h"


//std::ostream& operator<<(std::ostream& out, const Movie& TOPRINT) {
//	out << "Movie Format: " << TOPRINT.mediaType->MEDIA_TYPE << ", ";
//	out << "Genre: " << TOPRINT.movieType << ", ";
//	out << "Title: " << TOPRINT.title << ", ";
//	out << "Director: " << TOPRINT.director << ", ";
//	out << "Release Year: " << TOPRINT.date_released;
//	return out;
//}

Movie::Movie(std::string genre, int init_stock, std::string title,
						 std::string director, std::string releaseY, std::string actor) {

}


std::string Movie::getType() const {
	return movieType;
}

int Movie::getStock() const {
	return stock;
}

Media Movie::getMedia() const {
	return Media(mediaType.MEDIA_TYPE);
}

void Movie::setMedia(Media media) {
	delete mediaType;
	mediaType = media;
}

bool Movie::setStock(int s) {
	if (s >= 0) {
		stock = s;
		return true;
	}
	else {
		return false;
	}
}


std::vector<std::string> splitString(std::string line, std::string delimiter) {

	std::vector<std::string> out;

	size_t pos = 0;
	std::string token;
	while ((pos = line.find(delimiter)) != std::string::npos) {
		token = line.substr(0, pos);
		//std::cout << token << std::endl;

		out.push_back(token);

		line.erase(0, pos + delimiter.length());
	}

	return out;
}

//THE STRING SHOULD NOT INCLUDE THE MEDIA TYPE!
bool Movie::parse(std::string line, bool hasStock) {
	std::string delim = ",";

	std::vector<std::string> lineSplit = splitString(line, delim);

	int index = 0;

	if ((hasStock && lineSplit.size() != 5) || (!hasStock && lineSplit.size() != 4)) {
		return false;
	}

	movieType = std::stoi(lineSplit[index++]);

	if (hasStock) {
		stock = std::stoi(lineSplit[index++]);
	}
	else {
		stock = 1;
	}

	director = lineSplit[index++];

	title = lineSplit[index++];

	date_released = std::stoi(lineSplit[index++]);

	return true;
}

bool Movie::operator==(const Movie& OTHER) const {
	return movieType == OTHER.movieType
		&& *mediaType == *OTHER.mediaType
		&& director == OTHER.director
		&& title == OTHER.title
		&& date_released == OTHER.date_released;
}

bool Movie::operator!=(const Movie& OTHER) const {
	return !(*this == OTHER);
}



