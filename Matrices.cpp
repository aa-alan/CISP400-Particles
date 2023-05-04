#include "Matrices.h"

namespace Matrices
{
	Matrix::Matrix(int _rows, int _cols)
	{
		rows = _rows;
		cols = _cols;
		a.resize(_rows);
		for (int i = 0; i < _rows; i++)
		{
			a.at(i).resize(_cols);
		}
	}

	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			throw runtime_error("Error: dimensions must agree");
		}

		Matrix c(a.getRows(), a.getCols());

		for (int i = 0; i < a.getRows(); i++)
		{
			for (int j = 0; j < a.getCols(); j++)
			{
				c(i, j) = a(i, j) + b(i, j);
			}
		}

		return c;
	}

	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		if (a.getCols() != b.getRows())
		{
			throw runtime_error("Error: dimensions must agree");
		}

		Matrix c(a.getRows(), b.getCols());

		for (int i = 0; i < a.getRows(); i++)
		{
			for (int k = 0; k < b.getCols(); k++)
			{
				for (int j = 0; j < a.getCols(); j++)
				{
					c(i, k) += a(i, j) * b(j, k);
				}
			}
		}

		return c;
	}

	bool operator==(const Matrix& a, const Matrix& b)
	{
		bool flag = true;
		if (a.getRows() != b.getRows() || a.getCols() != b.getCols())
		{
			flag = false;
		}
		if (flag)
		{
			bool exit_flag = false; // exit for loops
			for (int i = 0; i < a.getRows() && !exit_flag; i++)
			{
				for (int j = 0; j < a.getCols() && !exit_flag; j++)
				{
					if (!(fabs(a(i, j) - b(i, j)) < 0.001))
					{
						flag = false;
						exit_flag = true;
					}
				}
			}
		}

		return flag;
	}

    bool operator!=(const Matrix& a, const Matrix& b)
    {
        bool flag = true;
		if (a.getRows() == b.getRows() && a.getCols() == b.getCols())
		{
			flag = false;
		}
		if (flag)
		{
			bool exit_flag = false; // exit for loops
			for (int i = 0; i < a.getRows() && !exit_flag; i++)
			{
				for (int j = 0; j < a.getCols() && !exit_flag; j++)
				{
					if (fabs(a(i, j) - b(i, j)) < 0.001)
					{
						flag = false;
						exit_flag = true;
					}
				}
			}
		}

		return flag;
    }

    ostream& operator<<(ostream& os, const Matrix& a)
    {
        for (int i = 0; i < a.getRows();i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                os << setw(10) << a(i, j) << ' ';
            }
            os << '\n';
        }
        return os;
    }
}
