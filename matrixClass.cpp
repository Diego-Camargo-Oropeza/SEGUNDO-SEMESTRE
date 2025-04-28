#include <iostream>
#include <stdexcept> 
using namespace std;

class matrix
{
private:
    int rows;
    int cols;
    int **store;

public:
    // Constructor
    matrix(int r, int c)
    {
        rows = r;
        cols = c;

        // Dynamically allocate memory for the 2D array
        store = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            store[i] = new int[cols];
        }
    }

    // Copy constructor
    matrix(const matrix &m)
    {
        rows = m.rows;
        cols = m.cols;

        // Allocate and copy elements
        store = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            store[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                store[i][j] = m.store[i][j];
            }
        }
    }

    // Method to read matrix elements from the user
    void read()
    {
        cout << "\nPlease enter " << rows << "x" << cols << " matrix elements:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> store[i][j];
            }
            // (Optional) flush or handle input in a new line
            cout << endl;
        }
    }

    // Method to print the matrix
    void print()
    {
        cout << "\nMatrix contents (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << store[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Method to compute and display the mean of each row
    void row_mean()
    {
        cout << "\nRow means:\n";
        for (int i = 0; i < rows; i++)
        {
            double sum = 0.0;
            for (int j = 0; j < cols; j++)
            {
                sum += store[i][j];
            }
            double mean = sum / cols;
            cout << "Mean of row " << i << " = " << mean << endl;
        }
    }

    // -------- Transpose --------
    matrix transpose()
    {
        // Swapped dimensions
        matrix transposed(cols, rows);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                transposed.store[j][i] = store[i][j];
            }
        }
        return transposed;
    }

    // -------- Matrix Addition --------
    matrix operator+(matrix &a)
    {
        // Fix dimension check: must match rows and cols
        if (rows != a.rows || cols != a.cols)
        {
            throw std::invalid_argument("For matrix addition, both matrices must be the same size.");
        }
        matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.store[i][j] = store[i][j] + a.store[i][j];
            }
        }
        return result;
    }

    // -------- Matrix Subtraction --------
    matrix operator-(matrix &a)
    {
        // Fix dimension check: must match rows and cols
        if (rows != a.rows || cols != a.cols)
        {
            throw std::invalid_argument("For matrix subtraction, both matrices must be the same size.");
        }
        matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.store[i][j] = store[i][j] - a.store[i][j];
            }
        }
        return result;
    }

    // -------- MATRIX MULTIPLICATION (NEW) --------
    matrix operator*(matrix &a)
    {
        // Dimension check: (this->cols == a.rows)
        if (cols != a.rows)
        {
            throw std::invalid_argument("Matrix multiplication requires that cols of the left matrix == rows of the right matrix.");
        }

        // The resulting matrix will have dimensions (this->rows x a.cols)
        matrix result(rows, a.cols);

        // Initialize and multiply
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < a.cols; j++)
            {
                // compute dot product for element [i][j]
                int sum = 0;
                for (int k = 0; k < cols; k++) // or (k < a.rows)
                {
                    sum += store[i][k] * a.store[k][j];
                }
                result.store[i][j] = sum;
            }
        }
        return result;
    }

    // Destructor
    ~matrix()
    {
        cout << "\nDestroying matrix object...\n";
        for (int i = 0; i < rows; i++)
        {
            delete[] store[i];
        }
        delete[] store;
    }
};

int main()
{
    int a, b;

    cout << "Enter number of rows for matrix m: ";
    cin >> a;

    cout << "Enter number of columns for matrix m: ";
    cin >> b;

    matrix m(a, b);
    m.read();
    m.print();
    m.row_mean();

    cout << "\nEnter number of rows for matrix z: ";
    cin >> a;

    cout << "Enter number of columns for matrix z: ";
    cin >> b;

    matrix z(a, b);
    z.read();
    z.print();

    // Pause the screen (Windows-specific, typically)
    system("pause");

    // Addition
    cout << "\n/------------------/";
    try
    {
        cout << "\nSum of the two matrices:\n";
        matrix sum = m + z;
        sum.print();
    }
    catch (const std::exception &e)
    {
        cerr << "Error: " << e.what() << '\n';
    }

    // Subtraction
    cout << "\n/------------------/";
    try
    {
        cout << "\nSubtraction of the two matrices:\n";
        matrix sub = m - z;
        sub.print();
    }
    catch (const std::exception &e)
    {
        cerr << "Error: " << e.what() << '\n';
    }

    // Multiplication
    cout << "\n/------------------/";
    try
    {
        cout << "\nMultiplication of the two matrices:\n";
        matrix product = m * z;
        product.print();
    }
    catch (const std::exception &e)
    {
        cerr << "Error: " << e.what() << '\n';
    }

    // Transpose of m
    cout << "\n/------------------/";
    cout << "\nTranspose of matrix m:\n";
    matrix mt = m.transpose();
    mt.print();

    system("pause");
    return 0;
}
