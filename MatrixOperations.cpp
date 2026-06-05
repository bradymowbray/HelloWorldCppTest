#include <iostream>
#include <fstream>
#include <string>
#include "Eigen/Dense"


///////////////////////////////////////////////////////////////////////////////
// Practiced matrix operations
using Eigen::MatrixXd;

int main()
{
    // Comma Initialization
    Eigen::Matrix3f nums;   // Makes an empty 3x3 matrix containing type float
    nums << 1, 2, 3, 4, 5, 6, 7, 8, 9;   // Passes numbers into the matrix
    std::cout << nums << '\n';   // Prints the matrix

    // Create a 2x2 or 4x4 matrix and print the size
    Eigen::Matrix4f price;
    std::cout << price.size() << std::endl;

    // Create a 10x10 matrix populated with sixes
    Eigen::MatrixXd games;   // Makes a matrix of unknown size containing type double
    games = MatrixXd::Constant(10, 10, 6);
    std::cout << games << '\n';

    // Create a 4x4 with a set value of zero
    Eigen::Matrix <float, 4, 4> mynums;   // Makes an empty 4x4 matrix containg type float
    mynums.setZero();   // Sets every element to zero
    std::cout << mynums << std::endl;

    // Working with functions
    // using the transposeInPlace() function
    Eigen::MatrixXf results(4, 4);
    results << 8, 12, 17, 33, 39, 101, 20, 91, 36, 42, 55, 88, 10, 37, 27, 17;
    std::cout << "This is the original matrix results:\n" << results << std::endl;

    // Now, let's use the function transposeInPlace()
    results.transposeInPlace();
    std::cout << "The new results after using transposeInPlace:\n" << results << std::endl;

    // Some basic arithmetic operations with Eigen library
    // We can use the sum(), prod(), mean(), minCoeff(), maxCoeff(), and trace() functions
    Eigen::Matrix4d scores;
    scores << 12, 18, 21, 34, 98, 122, 98, 27, 38, 20, 31, 45, 38, 11, 49, 51;
    std::cout << "All values in the scores 4x4 matrix:\n" << scores << '\n';

    // Let's use the fuctions
    std::cout << "Result for sum() function:\n" << scores.sum() << '\n';
    std::cout << "Result for prod() function:\n" << scores.prod() << std::endl;
    std::cout << "Result for mean() function:\n" << scores.mean() << '\n';
    std::cout << "Result for minCoeff() function:\n" << scores.minCoeff() << std::endl;
    std::cout << "Result for maxCoeff() function:\n" << scores.maxCoeff() << std::endl;
    std::cout << "Result for trace() function:\n" << scores.trace() << '\n';

    // Printing individual elements from a matrix
    Eigen::Matrix3f goals;
    goals << 23, 54, 92, 49, 27, 39, 53, 96, 63;
    std::cout << goals(4) << std::endl;
    std::cout << goals << std::endl;


    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
// Practiced reading from a file
// int main()
// {
//     std::ifstream file("CMakeLists.txt");   // attempts to create input file stream named file using CMakeLists.txt

//     if(file)   // checks the file opened OK
//     {
//         std::string str;   // create a string named str

//         while(getline(file, str))   // loops through every line in the file
//         {
//             std::cout << str << '\n';   // prints str
//         }

//         file.close();   // closes the file
//         return 0;
//     }
//     else
//     {
//         throw std::runtime_error("Failed to read from file");   // throws an error if the file opened incorrectly
//     }
// }