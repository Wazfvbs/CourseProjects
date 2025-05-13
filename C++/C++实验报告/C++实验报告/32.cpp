#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Singer {
public:
    Singer(int id, const std::string& name) : id(id), name(name) {}

    void addScore(double score) {
        scores.push_back(score);
    }

    double getAverageScore() const {
        double sum = 0;
        for (size_t i = 0; i < scores.size(); ++i) {
            sum += scores[i];
        }
        return sum / scores.size();
    }

    void print() const {
        std::cout << "ID: " << id << ", Name: " << name 
                  << ", Average Score: " << getAverageScore() << std::endl;
    }

    int getId() const { return id; }
    const std::string& getName() const { return name; }

private:
    int id;
    std::string name;
    std::vector<double> scores;
};
bool compareSingers(const Singer& a, const Singer& b) {
    return a.getAverageScore() > b.getAverageScore();
}

int main() {
    int n;
    std::cout << "Enter the number of singers: ";
    std::cin >> n;

    std::vector<Singer> singers;
    for (int i = 0; i < n; ++i) {
        int id;
        std::string name;
        std::cout << "Enter singer ID: ";
        std::cin >> id;
        std::cout << "Enter singer name: ";
        std::cin >> name;
        Singer singer(id, name);

        std::cout << "Enter the number of scores: ";
        int scoresCount;
        std::cin >> scoresCount;
        for (int j = 0; j < scoresCount; ++j) {
            double score;
            std::cout << "Enter score " << j + 1 << ": ";
            std::cin >> score;
            singer.addScore(score);
        }
        singers.push_back(singer);
    }

    std::sort(singers.begin(), singers.end(), compareSingers);

    std::cout << "Singers sorted by average score:\n";
    for (size_t i = 0; i < singers.size(); ++i) {
        singers[i].print();
    }

    return 0;
}


