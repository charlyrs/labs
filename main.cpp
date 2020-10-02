//VARIANT 7
#include <iostream>
#include <ctime>
double matr(double** matrix, int i, int j) {
    if (j > i) {
        return matrix[j][i];
    }
    else return matrix[i][j];
}
void matrix_output(double** matrix, int size) {

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matr(matrix, i, j) << "  ";
        }
        std::cout << "\n";
    }
}

int main() {
    srand(time(nullptr));

    std::cout << "Enter the length of square\n";
    int size;
    std::cin >> size;
    if (size < 0 || size > 10) std::cout << "Error";
    else {


        double** matrix = new double* [size];
        std::cout << "How do you want to enter matrix?\n1.From keyboard\n2.Random numbers\n";
        int enter;
        std::cin >> enter;

        switch (enter) {
        case 1: {
            int numbers = 0; //the amount of different numbers in matrix equals a!
            for (int i = 1; i <= size; ++i) {
                numbers += i;
            }
            std::cout << "Enter " << numbers << " numbers\n";
            for (int i = 0; i < size; ++i) {
                matrix[i] = new double[i + 1];
                for (int j = 0; j < i + 1; ++j) {
                    std::cin >> matrix[i][j];
                }
            }
            break;
        }
        case 2: {
            double  max;
            double min;
            std::cout << "Enter min number in matrix\n ";
            std::cin >> min;
            std::cout << "Enter max number in matrix\n ";
            std::cin >> max;


            for (int i = 0; i < size; ++i) {
                matrix[i] = new double[i + 1];
                for (int j = 0; j < i + 1; ++j) {
                    double X = ((double)rand() / (double)RAND_MAX);
                    matrix[i][j] = (max - min) * X + min;
                }
            }
            break;
        }
        default: return 0;
        }

        std::cout << "The original matrix is\n";
        matrix_output(matrix, size);


        double currentMaxElement = matrix[0][0];
        int maxIndex_i = 0;
        int maxIndex_j = 0;
        int diagonal = 0;
        double  minElement = matrix[0][0];
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (matr(matrix, i, j) < minElement) minElement = matr(matrix, i, j);
            }
        }
        double maxElement = minElement;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (matr(matrix, i, j) > maxElement) maxElement = matr(matrix, i, j);
            }
        }
        double temp = maxElement + 1;
        while (diagonal < size) {
            currentMaxElement = minElement - 1;
            for (int i = size - 1; i >= 0; i--) {
                for (int j = i; j >= 0; j--) {
                    if (matr(matrix, i, j) > currentMaxElement && matr(matrix, i, j) < temp) {
                        currentMaxElement = matr(matrix, i, j);
                        maxIndex_i = i;
                        maxIndex_j = j;
                    }
                }
            }
            std::swap(matrix[maxIndex_i][maxIndex_j], matrix[diagonal][diagonal]);
            temp = currentMaxElement;
            maxIndex_i = 0;
            maxIndex_j = 0;
            diagonal++;
        }

        std::cout << "\n";
        std::cout << "The matrix after task 1\n";

        matrix_output(matrix, size);

        int negativerow = -1;
        int currentelement = 0;
        for (int i = 0; i < size; ++i) {
            if (negativerow > 0) break;
            else {
                for (int j = 0; j < size; ++j) {

                    if (matr(matrix, i, j) < 0) {
                        negativerow = i + 1;  //counting rows starting from 1

                    }
                    else {
                        negativerow = -1;
                        break;
                    }


                }
            }

        }
        std::cout << "\n";
        if (negativerow > 0)std::cout << "The number of the first row with only negative elements is " << negativerow;
        else std::cout << "There is no row with only negative elements\n";

    }

    return 0;
}
