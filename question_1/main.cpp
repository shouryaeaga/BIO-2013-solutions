#include <iostream>
#include <math.h>
#include <vector>

void QuestionB();

class Clock {
public:
    int hour = 0;
    int minute = 0;
    int offset;

    explicit Clock(int offset) : offset(offset) {}
    void printTime() {
        std::string hourString = hour < 10 ? "0" + std::to_string(hour) : std::to_string(hour);
        std::string minuteString = minute < 10 ? "0" + std::to_string(minute) : std::to_string(minute);

        std::cout << hourString << ":" << minuteString << std::endl;
    }
    void addRealHour() {
        int minutesToAdd = 60 + offset;
        int newMinuteValue = minutesToAdd + minute;
        minute = newMinuteValue % 60;
        hour = static_cast<int>(std::floor(newMinuteValue / 60) + hour) % 24;
    }
    bool operator==(const Clock &other) const {
        return hour == other.hour && minute == other.minute;
    }
};

int getInput() {
    std::string input;
    std::getline(std::cin, input);
    return std::stoi(input);
}

int main() {
    std::cout << "Enter how fast the first clock is (minutes): ";
    int offset1 = getInput();
    std::cout << "Enter how fast the second clock is (minutes): ";
    int offset2 = getInput();

    Clock firstClock(offset1);
    Clock secondClock(offset2);
    firstClock.addRealHour();
    secondClock.addRealHour();

    while (firstClock != secondClock) {
        firstClock.addRealHour();
        secondClock.addRealHour();
    }
    firstClock.printTime();

    QuestionB();
    return 0;
}

void QuestionB() {
    std::vector<int> answers;
    for (int i = 0; i < 20; i++) {
        Clock firstClock(0);
        firstClock.addRealHour();
        Clock secondClock(i);
        secondClock.addRealHour();
        while (firstClock != secondClock) {
            firstClock.addRealHour();
            secondClock.addRealHour();
        }
        firstClock.printTime();

        if (firstClock.hour != 0)
            answers.push_back(i);
    }
    std::cout << "Answers to question b: \n";
    for (int i = 0; i < answers.size(); i++) {
        std::cout << answers[i] << " minutes fast\n";
    }
}
