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
    std::cout << "\n--- development timeline ---\n"
        << "1984: honda starts its new concept engine programme. [s1]\n"
        << "1986: vtec production development project approved. [s1]\n"
        << "1989: b16a vtec introduced in the integra. [s2]\n"
        << "2000: dohc i-vtec debuts in the honda stream. [s3]\n"
        << "2001: new cr-v adopts 2.0-litre dohc i-vtec. [s4]\n"
        << "2007: fd2 civic type r uses the naturally aspirated k20a. [s5]\n";

        .....
        
     using namespace std;

// Displays the historical milestones of VTEC development
void showTimeline() {
    cout << "\n--- DEVELOPMENT TIMELINE ---\n"
            "1984: Honda starts its New Concept Engine programme. [S1]\n"
            "1986: VTEC production development project approved. [S1]\n"
            "1989: B16A VTEC introduced in the Integra. [S2]\n"
            "2000: DOHC i-VTEC debuts in the Honda Stream. [S3]\n"
            "2001: New CR-V adopts 2.0-litre DOHC i-VTEC. [S4]\n"
            "2007: FD2 Civic Type R uses the naturally aspirated K20A. [S5]\n";
}

// Outputs the hardcoded specs for the FD2 K20A engine based on Part 1 research
void showK20ASpecs() {
    cout << "\n--- FD2 K20A SPECIFICATIONS ---\n"
            "Engine Type: 2.0-litre DOHC i-VTEC (Naturally Aspirated)\n"
            "Max Power: 165 kW (225 PS) @ 8000 RPM [S5]\n"
            "Max Torque: 215 Nm @ 6100 RPM [S5]\n"
            "Redline: 8400 RPM\n";
}

// Calculates mechanical shaft power based on user input for Torque and RPM
void calculatePower() {
    cout << "\n--- POWER CALCULATOR ---\n"
            "Enter torque and RPM measured at the same operating point.\n";

    double torque = 0.0;
    double rpm = 0.0;

    if (!readNumber("Torque in Nm (0-1000): ", 0.0, 1000.0, torque)) return;
    if (!readNumber("Engine speed in RPM (0-10000): ", 0.0, 10000.0, rpm)) return;

    double powerKw = (torque * rpm * 2.0 * 3.14159265359) / 60000.0;

    cout << fixed << setprecision(2) << "Calculated power: " << powerKw << " kW\n";
}

// Prints the reference links used for the research poster
void showSources() {
    cout << "\n--- REFERENCES ---\n"
            "[S1] The VTEC Engine / 1989 (Honda Global)\n"
            "[S2] B16A: Honda's Innovative Engine with VTEC\n"
            "[S3] Honda Launches DOHC i-VTEC (2000)\n"
            "[S4] CR-V Full Model Change (2001)\n"
            "[S5] Honda Adds New Type R (2007)\n";
}

int main() {
    int choice = -1;

    while (choice != 0) {
        cout << "\n=== HONDA VTEC EDUCATIONAL CONSOLE ===\n"
                "1. Learn about VTEC / i-VTEC\n"
                "2. View development timeline\n"
                "3. View FD2 K20A specifications\n"
                "4. Calculate engine power\n"
                "5. View research sources\n"
                "0. Exit\n";

        if (!readNumber("Choose an option (0-5): ", 0, 5, choice)) {
            break; 
        }

        switch (choice) {
            case 1: showTechnology(); break;
            case 2: showTimeline();   break;
            case 3: showK20ASpecs();  break;
            case 4: calculatePower(); break;
            case 5: showSources();    break;
            case 0: cout << "Session ended.\n"; break;
        }
    }
    return 0;
}