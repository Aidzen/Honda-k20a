// Honda VTEC Learning and Power Calculator
// Research references and limitations: RESEARCH.md and README.md.

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// Read a complete line: reject trailing text, fractions for integer choices,
// non-finite numbers, and values outside the permitted range. EOF exits cleanly.
template <typename T>
bool readNumber(const std::string& prompt, T minimum, T maximum, T& value) {
    std::string line;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, line)) return false;
        std::istringstream input(line);
        T candidate{};
        if (input >> candidate) {
            input >> std::ws;
            if (input.eof() && std::isfinite(static_cast<double>(candidate)) &&
                candidate >= minimum && candidate <= maximum) {
                value = candidate;
                return true;
            }
        }
        std::cout << "Invalid input. Enter a number from " << minimum
                  << " to " << maximum << " only.\n";
    }
}

void showTechnology() {
    std::cout << "\n--- UNDERSTANDING VTEC / i-VTEC ---\n"
        << "VTEC means Variable Valve Timing and Lift Electronic Control.\n"
        << "The early DOHC system switches cam profiles to balance everyday\n"
        << "low/mid-speed operation with high-speed breathing. [S2]\n"
        << "The 2000 DOHC i-VTEC design combines VTEC with VTC, which\n"
        << "continuously adjusts intake cam timing to suit engine load. [S3]\n"
        << "Implementations differ between engines. This program does not\n"
        << "simulate the ECU or predict a VTEC engagement RPM.\n";
}

void showTimeline() {
    std::cout << "\n--- DEVELOPMENT TIMELINE ---\n"
        << "1984: Honda starts its New Concept Engine programme. [S1]\n"
        << "1986: VTEC production development project approved. [S1]\n"
        << "1989: B16A VTEC introduced in the Integra. [S2]\n"
        << "2000: DOHC i-VTEC debuts in the Honda Stream. [S3]\n"
        << "2001: New CR-V adopts 2.0-litre DOHC i-VTEC. [S4]\n"
        << "2007: FD2 Civic Type R uses the naturally aspirated K20A. [S5]\n";
