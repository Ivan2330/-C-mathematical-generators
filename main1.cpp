#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

class RandomGenerator {
public:
    virtual std::vector<double> generate(int n) = 0;
    virtual void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) = 0;
};


// Лінійний конгруентний метод
class LinearCongruentialGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers(n);
        const long long a = 1664525;
        const long long c = 1013904223;
        const long long m = 4294967296; // 2^32
        long long X = 1;

        for (int i = 0; i < n; ++i) {
            X = (a * X + c) % m;
            numbers[i] = static_cast<double>(X) / m;
        }
        return numbers;
    }

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            int bin = std::min(static_cast<int>((num - min_value) / bin_size), bins - 1);
            histogram[bin]++;
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};

// Квадратичний конгруентний метод
class QuadraticCongruentialGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers(n);
        const long long a = 123;
        const long long c = 456;
        const long long d = 789;
        const long long m = 100000; 
        long long X = 1;

        for (int i = 0; i < n; ++i) {
            X = (d * X * X + a * X + c) % m;
            numbers[i] = static_cast<double>(X) / m;
        }
        return numbers;
    }

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            int bin = std::min(static_cast<int>((num - min_value) / bin_size), bins - 1);
            histogram[bin]++;
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};

// Числа Фібоначчі
class FibonacciGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers(n);
        const long long m = 100000;
        long long X1 = 1, X2 = 1;

        for (int i = 0; i < n; ++i) {
            long long X = (X1 + X2) % m;
            X1 = X2;
            X2 = X;
            numbers[i] = static_cast<double>(X) / m;
        }
        return numbers;
    }

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            int bin = std::min(static_cast<int>((num - min_value) / bin_size), bins - 1);
            histogram[bin]++;
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};

long long modInverse(long long a, long long p) {
    long long t = 0, new_t = 1;
    long long r = p, new_r = a;
    while (new_r != 0) {
        long long quotient = r / new_r;
        long long temp = t;
        t = new_t;
        new_t = temp - quotient * new_t;
        temp = r;
        r = new_r;
        new_r = temp - quotient * new_r;
    }
    if (r > 1) return -1; // Немає оберненого елементу
    if (t < 0) t += p;
    return t;
}

// Обернена конгруентна послідовність
class InverseCongruentialGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers(n);
        const long long a = 69069;
        const long long c = 1;
        const long long p = 10007;
        long long X = 1;

         for (int i = 0; i < n; ++i) {
            X = (a * modInverse(X, p) + c) % p;
            numbers[i] = static_cast<double>(X) / p;
        }
        return numbers;
    }

    

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            int bin = std::min(static_cast<int>((num - min_value) / bin_size), bins - 1);
            histogram[bin]++;
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};

// Метод об'єднання
class CombinationMethodGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers(n);
        const long long m1 = 2147483563;
        const long long m2 = 2147483399;
        long long X1 = 1, X2 = 1;

        // 2 ЛКГ методи
        for (int i = 0; i < n; ++i) {  
            X1 = (40014 * X1) % m1;
            X2 = (40692 * X2) % m2;

            
            long long Z = (X1 - X2 + m1) % m1;

            numbers[i] = static_cast<double>(Z) / m1;
        }
        return numbers;
    }

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            int bin = std::min(static_cast<int>((num - min_value) / bin_size), bins - 1);
            histogram[bin]++;
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};

class ThreeSigmaRuleGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers(n);
        std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<> dist(0.0, 1.0);  // Рівномірний розподіл на [0, 1]

        for (int i = 0; i < n; ++i) {
            double sum = 0;
            for (int j = 0; j < 12; ++j) {
                sum += dist(gen);  // Додавання 12 випадкових чисел для генерації нормального розподілу
            }
            numbers[i] = sum - 6;
        }
        return numbers;
    }

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            if (num >= min_value && num < max_value) {
                int bin = static_cast<int>((num - min_value) / bin_size);
                histogram[bin]++;
            }
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};


// Метод полярних координат (нормальний розподіл)
class PolarCoordinateMethodGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers;
        std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<> dist(0.0, 1.0);

        while (numbers.size() < n) {
            double u1 = dist(gen);
            double u2 = dist(gen);
            double v1 = 2.0 * u1 - 1.0;
            double v2 = 2.0 * u2 - 1.0;
            double s = v1 * v1 + v2 * v2;

            if (s >= 1 || s == 0) continue;

            double multiplier = sqrt(-2.0 * log(s) / s);
            numbers.push_back(v1 * multiplier);
            if (numbers.size() < n)
                numbers.push_back(v2 * multiplier);
        }

        return numbers;
    }

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            if (num >= min_value && num < max_value) {
                int bin = static_cast<int>((num - min_value) / bin_size);
                histogram[bin]++;
            }
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};

// Метод співвідношень (експоненційний розподіл)
class RatioMethodGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers(n);
        std::mt19937 gen(std::random_device{}());
        std::exponential_distribution<> dist(0.1); //лямбда розширення діапазону

        for (int i = 0; i < n; ++i) {
            numbers[i] = dist(gen);
        }
        return numbers;
    }

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            if (num >= min_value && num < max_value) {
                int bin = static_cast<int>((num - min_value) / bin_size);
                histogram[bin]++;
            }
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};

// Метод логарифму для показового розподілу
class LogarithmMethodGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers(n);
        std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<> dist(0.0, 1.0);

        for (int i = 0; i < n; ++i) {
            double U = dist(gen);
            numbers[i] = -log(U) * 10;  // Масштабуємо розподіл, щоб значення краще розподілялись у [0; 100]
            if (numbers[i] > 100.0) {
                numbers[i] = 100.0;  // Обмежуємо максимальне значення
            }
        }

        return numbers;
    }

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            if (num >= min_value && num < max_value) {
                int bin = std::min(static_cast<int>((num - min_value) / bin_size), bins - 1);
                histogram[bin]++;
            }
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};

// Метод Аренса для гамма-розподілу
class ArensMethodGenerator : public RandomGenerator {
public:
    std::vector<double> generate(int n) override {
        std::vector<double> numbers;
        std::mt19937 gen(std::random_device{}());
        double a = 2.0;

        while (numbers.size() < n) {
            double d = a - 1.0 / 3.0;
            double c = 1.0 / sqrt(9.0 * d);
            double U, V, X;

            do {
                U = std::uniform_real_distribution<>(0.0, 1.0)(gen);
                V = std::normal_distribution<>(0.0, 1.0)(gen);
                X = V;
                double temp = 1.0 + c * X;
                if (temp <= 0) continue;
                double W = d * pow(temp, 3);
                double lnU = log(U);
                if (lnU < (0.5 * X * X + d - W + d * log(W / d))) {
                    numbers.push_back(W * 10);  // Масштабування значень
                    break;
                }
            } while (true);

            if (numbers.back() > 100.0) {
                numbers.back() = 100.0;  // Обмеження максимальних значень
            }
        }

        return numbers;
    }

    void buildHistogram(const std::vector<double>& numbers, int bins, double min_value, double max_value) override {
        std::vector<int> histogram(bins, 0);
        double bin_size = (max_value - min_value) / bins;

        for (double num : numbers) {
            if (num >= min_value && num < max_value) {
                int bin = static_cast<int>((num - min_value) / bin_size);
                histogram[bin]++;
            }
        }

        std::cout << "Інтервал\tЧастота\n";
        for (int i = 0; i < bins; ++i) {
            double start = min_value + i * bin_size;
            double end = start + bin_size;
            double frequency = static_cast<double>(histogram[i]) / numbers.size();
            std::cout << "[" << start << "; " << end << "]\t" << frequency << "\n";
        }
    }
};

class Menu {
public:
    void display() {
        std::locale::global(std::locale(""));

        int choice;
        const int num_samples = 10000;

        while (true) {
            std::cout << "Оберіть генератор псевдовипадкових чисел:\n";
            std::cout << "1. Лінійний конгруентний метод\n";
            std::cout << "2. Квадратичний конгруентний метод\n";
            std::cout << "3. Числа Фібоначчі\n";
            std::cout << "4. Обернена конгруентна послідовність\n";
            std::cout << "5. Метод об’єднання\n";
            std::cout << "6. Правило 3 сигма (нормальний розподіл)\n";
            std::cout << "7. Метод полярних координат (нормальний розподіл)\n";
            std::cout << "8. Метод співвідношень\n";
            std::cout << "9. Метод логарифму для показового розподілу\n";
            std::cout << "10. Метод Аренса (гамма-розподіл)\n";
            std::cout << "0. Вихід\n";
            std::cin >> choice;

            RandomGenerator* generator = nullptr;
            switch (choice) {
                case 1:
                    generator = new LinearCongruentialGenerator();
                    break;
                case 2:
                    generator = new QuadraticCongruentialGenerator();
                    break;
                case 3:
                    generator = new FibonacciGenerator();
                    break;
                case 4:
                    generator = new InverseCongruentialGenerator();
                    break;
                case 5:
                    generator = new CombinationMethodGenerator();
                    break;
                case 6:
                    generator = new ThreeSigmaRuleGenerator();
                    break;
                case 7:
                    generator = new PolarCoordinateMethodGenerator();
                    break;
                case 8:
                    generator = new RatioMethodGenerator();
                    break;
                case 9:
                    generator = new LogarithmMethodGenerator();
                    break;
                case 10:
                    generator = new ArensMethodGenerator();
                    break;
                case 0:
                    return;
                default:
                    std::cout << "Невірний вибір, спробуйте ще раз.\n";
                    continue;
            }

            std::vector<double> numbers = generator->generate(num_samples);

            // Визначаємо межі для гістограми залежно від вибраного генератора
            double min_value, max_value;
            int bins = 10;

            if (choice == 6 || choice == 7) {
                // Для нормального розподілу
                min_value = -3.0;
                max_value = 3.0;
            } else if (choice == 9 || choice == 10 || choice == 8) {
                // Для експоненційного та гамма-розподілу - інтервал [0; 100]
                min_value = 0.0;
                max_value = 100.0;
            } else {
                // Для рівномірного розподілу
                min_value = 0.0;
                max_value = 1.0;
            }

            generator->buildHistogram(numbers, bins, min_value, max_value);
            delete generator;
        }
    }
};

int main() {
    Menu menu;
    menu.display();
    return 0;
}