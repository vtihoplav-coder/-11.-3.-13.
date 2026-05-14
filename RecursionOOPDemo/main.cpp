#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <cmath>

class RecursionTasks {
public:
    static long long power(int x, int y) {
        if (y < 0) {
            throw std::invalid_argument("Only non-negative integer exponent is supported in this demo.");
        }
        if (y == 0) return 1;
        return static_cast<long long>(x) * power(x, y - 1);
    }

    static void printOneToN(int n) {
        if (n <= 0) return;
        printOneToN(n - 1);
        std::cout << n << " ";
    }

    static void printOnesZeros(int n) {
        if (n <= 0) return;
        std::cout << 1;
        printOnesZeros(n - 1);
        std::cout << 0;
    }

    static int sumDigits(long long n) {
        n = std::llabs(n);
        if (n < 10) return static_cast<int>(n);
        return static_cast<int>(n % 10) + sumDigits(n / 10);
    }

    static int minDigit(long long n) {
        n = std::llabs(n);
        if (n < 10) return static_cast<int>(n);
        int tailMin = minDigit(n / 10);
        int last = static_cast<int>(n % 10);
        return last < tailMin ? last : tailMin;
    }

    static void printArray(const std::vector<int>& a, int index = 0) {
        if (index >= static_cast<int>(a.size())) return;
        std::cout << a[index] << " ";
        printArray(a, index + 1);
    }

    static int sumArray(const std::vector<int>& a, int index = 0) {
        if (index >= static_cast<int>(a.size())) return 0;
        return a[index] + sumArray(a, index + 1);
    }

    static int maxArray(const std::vector<int>& a, int index = 0) {
        if (a.empty()) throw std::invalid_argument("Array must not be empty.");
        if (index == static_cast<int>(a.size()) - 1) return a[index];
        int nextMax = maxArray(a, index + 1);
        return a[index] > nextMax ? a[index] : nextMax;
    }

    static double averageArray(const std::vector<int>& a) {
        if (a.empty()) throw std::invalid_argument("Array must not be empty.");
        return static_cast<double>(sumArray(a)) / static_cast<double>(a.size());
    }

    static int sumPositive(const std::vector<int>& a, int index = 0) {
        if (index >= static_cast<int>(a.size())) return 0;
        int current = a[index] > 0 ? a[index] : 0;
        return current + sumPositive(a, index + 1);
    }

    static int productNegative(const std::vector<int>& a, int index = 0, bool* found = nullptr) {
        bool localFound = false;
        if (found == nullptr) found = &localFound;
        if (index >= static_cast<int>(a.size())) return 1;
        int current = 1;
        if (a[index] < 0) {
            current = a[index];
            *found = true;
        }
        return current * productNegative(a, index + 1, found);
    }

    static int productOdd(const std::vector<int>& a, int index = 0, bool* found = nullptr) {
        bool localFound = false;
        if (found == nullptr) found = &localFound;
        if (index >= static_cast<int>(a.size())) return 1;
        int current = 1;
        if (a[index] % 2 != 0) {
            current = a[index];
            *found = true;
        }
        return current * productOdd(a, index + 1, found);
    }
};

class RecursionDemoApp {
private:
    static void printTitle(const std::string& title) {
        std::cout << "\n" << title << "\n";
        std::cout << std::string(title.size(), '-') << "\n";
    }

public:
    void run() const {
        const std::vector<int> a = { 4, -2, 10, 0, -3 };
        const std::vector<int> b = { 1, 2, 5, 3, 4 };
        const std::vector<int> c = { 4, -7, 10, 1, -3 };

        std::cout << "OOP practice: recursion and class-based methodology\n";
        std::cout << "All tasks are demonstrated with test data.\n";

        printTitle("1. Recursive exponentiation");
        std::cout << "2^5 = " << RecursionTasks::power(2, 5) << "\n";

        printTitle("2. Print numbers from 1 to N");
        std::cout << "N = 7: ";
        RecursionTasks::printOneToN(7);
        std::cout << "\n";

        printTitle("3. Print N ones and then N zeros");
        std::cout << "N = 5: ";
        RecursionTasks::printOnesZeros(5);
        std::cout << "\n";

        printTitle("4. Sum of digits of a natural number");
        std::cout << "sumDigits(45872) = " << RecursionTasks::sumDigits(45872) << "\n";

        printTitle("5. Minimum digit of a natural number");
        std::cout << "minDigit(738261) = " << RecursionTasks::minDigit(738261) << "\n";

        printTitle("6. Recursive array printing");
        std::cout << "Array a: ";
        RecursionTasks::printArray(a);
        std::cout << "\n";

        printTitle("7. Recursive array sum");
        std::cout << "sumArray(a) = " << RecursionTasks::sumArray(a) << "\n";

        printTitle("8. Recursive maximum element in an array");
        std::cout << "Array b: ";
        RecursionTasks::printArray(b);
        std::cout << "\nmaxArray(b) = " << RecursionTasks::maxArray(b) << "\n";

        printTitle("9. Recursive arithmetic mean");
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "averageArray(b) = " << RecursionTasks::averageArray(b) << "\n";

        printTitle("10. Sum of positive elements");
        std::cout << "sumPositive(a) = " << RecursionTasks::sumPositive(a) << "\n";

        printTitle("11. Product of negative elements");
        bool hasNegative = false;
        int negativeProduct = RecursionTasks::productNegative(a, 0, &hasNegative);
        std::cout << "productNegative(a) = " << (hasNegative ? negativeProduct : 0) << "\n";

        printTitle("12. Product of odd elements");
        bool hasOdd = false;
        int oddProduct = RecursionTasks::productOdd(c, 0, &hasOdd);
        std::cout << "Array c: ";
        RecursionTasks::printArray(c);
        std::cout << "\nproductOdd(c) = " << (hasOdd ? oddProduct : 0) << "\n";

        std::cout << "\nProgram completed successfully.\n";
    }
};

int main() {
    try {
        RecursionDemoApp app;
        app.run();
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
