#include <string>
#include <algorithm>
using namespace std;

class DVD {
private:
	string  name;
	string	 director;
	string	 category;
	float	 price;

public:
	DVD() {
		name = "";
		director = "";
		category = "";
		price = 0.0;
	};
	DVD(string name, string director, string category, float price) {
		this->name = name;
		this->director = director;
		this->category = category;
		this->price = price;
	};


	void setName(string name) {
		transform(name.begin(), name.begin() + 1, name.begin(), ::toupper);
		this->name = name;
	}
	void setDirector(string director) {
		transform(director.begin(), director.begin() + 1, director.begin(), ::toupper);
		this->director = director;
	}
	void setCategory(string category) {
		transform(category.begin(), category.end(), category.begin(), ::toupper);
		this->category = category;
	}
	void setPrice() {
		if (category == "ACTION") {
			price = 45.00f;
		}
		else if (category == "COMEDY") {
			price = 40.00f;
		}
		else if (category == "DRAMA") {
			price = 30.00f;
		}
		else {
			price = 25.00f;
		}
	}
	string getName() {
		return name;
	}
	string getDirector() {
		return director;
	}
	string getCategory() {
		return category;
	}
	float getPrice() {
		return price;
	}
};