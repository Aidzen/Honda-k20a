#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// Helper function template to read numbers safely with input validation
template <typename T>
bool readNumber(const string& prompt, T minVal, T maxVal, T& outVal) {
    while (true) {
        cout << prompt;
        if (cin >> outVal) {
            if (outVal >= minVal && outVal <= maxVal) {
                return true;
            }
            cout << "Invalid input. Please enter a value between " << minVal << " and " << maxVal << ".\n";
        } else {
            if (cin.eof()) return false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid entry. Please enter a valid number.\n";
        }
    }
}

// Displays overview of VTEC and i-VTEC technology
void showTechnology() {
    cout << "\n--- HONDA VTEC & i-VTEC TECHNOLOGY ---\n"
            "VTEC (Variable Valve Timing and Lift Electronic Control) alters\n"
            "valve lift and duration to optimize efficiency and performance.\n"
            "i-VTEC combines VTEC with VTC (Variable Timing Control) for continuous\n"
            "intake camshaft phasing, improving torque response across all RPMs. [S1]\n";
}

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