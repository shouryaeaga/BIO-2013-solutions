#include <iostream>
#include <math.h>

class Clock {
public:
    int hour = 0;
    int minute = 0;
    int offset;

    Clock(int offset) : offset(offset) {
        std::cout << "Clock created with offset " << offset << "\n";
    }
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

    while (firstClock.hour != secondClock.hour || firstClock.minute != secondClock.minute) {
        firstClock.addRealHour();
        secondClock.addRealHour();
    }
    firstClock.printTime();
    return 0;
}
