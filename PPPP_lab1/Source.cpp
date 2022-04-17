//������ ����� ���-34
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// �������� �������  matrix_row*matrix_column 
int** create_matrix(int matrix_row, int matrix_column)
{
	int** mas = new int* [matrix_row];
	for (int i = 0; i < matrix_row; i++) {
		mas[i] = new int[matrix_column];
		for (int j = 0; j < matrix_column; j++)
			mas[i][j] = 0;
	}
	return mas;
}
int** create_matrix(int n)//����� �������� ������� n*n
{
	int** mas = new int* [n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[n];
		for (int j = 0; j < n; j++)
			mas[i][j] = 0;
	}
	return mas;
}

int** init_matrix(int** mas, int matrix_row, int matrix_column, int choice)// ������������� �������
{
	if (choice == 1)
	{
		for (int i = 0; i < matrix_row; i++)
			for (int j = 0; j < matrix_column; j++)
				cin >> mas[i][j];
	}
	else
	{
		for (int i = 0; i < matrix_row; i++)
			for (int j = 0; j < matrix_column; j++)
				mas[i][j] = rand() % 10;
	}
	return mas;
}

// ����� ������� �� �����
void print_matrix(int matrix_row, int matrix_column, int** mas)
{
	for (int i = 0; i < matrix_row; i++)
	{
		for (int j = 0; j < matrix_column; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}

//���������� ������ � ���������� �������
void convertion_matrix(int** modified_matrix, int** matrix, int required_matrix_size, int matrix_row, int matrix_column)
{
	for (int i = 0; i < required_matrix_size; i++)
	{
		modified_matrix[i] = new int[required_matrix_size];
		for (int j = 0; j < required_matrix_size; j++)  //������� , �� ����� ���� ��������������� � i , j
			modified_matrix[i][j] = 0;
	}

	for (int i = 0; i < matrix_row; i++)
	{
		for (int j = 0; j < matrix_column; j++)
			modified_matrix[i][j] = matrix[i][j];
	}
}

//���������� �������� ������� ���������� 
void filling_submatrix(int** submatrix, int** modified_matrix, int matrix_size, int choice)
{

	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
			switch (choice)
			{
			case 1:
				submatrix[i][j] = modified_matrix[i][j];
				break;
			case 2:
				submatrix[i][j] = modified_matrix[i][j + matrix_size];
				break;
			case 3:
				submatrix[i][j] = modified_matrix[i + matrix_size][j];
				break;
			case 4:
				submatrix[i][j] = modified_matrix[i + matrix_size][j + matrix_size];
				break;
			default:
				break;
			}
	}
}

//����� ������������ ������� �������
int border_matrix(int** preResult_matrix, int required_matrix_size, int finish_elem, bool choice)
{

	for (int i = 0; i < required_matrix_size; i++)
	{
		int non_zero_elements_count = 0;
		for (int j = 0; j < required_matrix_size; j++)
		{
			int cell;
			if (choice)
				cell = preResult_matrix[i][j];
			else
				cell = preResult_matrix[j][i];

			if (cell != 0)
			{
				non_zero_elements_count++;
				finish_elem = 100;
			}
		}
		if (non_zero_elements_count == 0 && i < finish_elem)
		{
			finish_elem = i;
		}
		if (finish_elem == 100)
			finish_elem = required_matrix_size;
	}

	return finish_elem;
}

//����� ����������� �������. ��� x y �����������
void copyMatrix(int** result_matrix, int** preResult_matrix, int finish_row, int finish_columns)
{
	for (int i = 0; i < finish_row; i++)
	{
		for (int j = 0; j < finish_columns; j++)
			result_matrix[i][j] = preResult_matrix[i][j];
	}
}

// ������������ ������ ���������� �������
void delete_matrix(int** matrix, int m)
{
	for (int i = 0; i < m; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void main()
{
	srand(time(NULL));
	int matrix1_row, matrix1_column, matrix2_row, matrix2_column, choice, required_matrix_size = 2;
	system("chcp 1251");
	cout << "��� ������������ ���������" << endl <<
		"�������� ������������ ������ ������� ���������\n\n";

	//���� �������� ������� �������������
	do
	{
		cout << "������� ������� ������ �������\n";
		cin >> matrix1_row >> matrix1_column;
	} while (matrix1_row <= 0 || matrix1_column <= 0);
	do
	{
		cout << "������� ������� ������ �������\n";
		cin >> matrix2_row >> matrix2_column;
	} while (matrix2_row <= 0 || matrix2_column <= 0);

	int** matrix1 = create_matrix(matrix1_row, matrix1_column);
	int** matrix2 = create_matrix(matrix2_row, matrix2_column);

	//����� ������� ���������� � ���������� ������
	do
	{
		cout << "�������� ������ ���������� ������\n" <<
			"1 - ������� \n2 - ��������� �������\n";
		cin >> choice;
	} while (choice < 1 || choice > 2);

	matrix1 = init_matrix(matrix1, matrix1_row, matrix1_column, choice);
	matrix2 = init_matrix(matrix2, matrix2_row, matrix2_column, choice);
	cout << "\n������� 1\n\n";
	print_matrix(matrix1_row, matrix1_column, matrix1);
	cout << "\n������� 2\n\n";
	print_matrix(matrix2_row, matrix2_column, matrix2);

	//���������� ������ � ���������� �������
	while (required_matrix_size < matrix1_row || required_matrix_size < matrix1_column ||
		   required_matrix_size < matrix2_row || required_matrix_size < matrix2_column)

		   required_matrix_size *= 2;
	int** modified_matrix1 = new int* [required_matrix_size];
	int** modified_matrix2 = new int* [required_matrix_size];

	convertion_matrix(modified_matrix1, matrix1, required_matrix_size, matrix1_row, matrix1_column);
	convertion_matrix(modified_matrix2, matrix2, required_matrix_size, matrix2_row, matrix2_column);

	cout << "����������� �������\n";
	cout << "\n������� 1\n\n";
	print_matrix(required_matrix_size, required_matrix_size, modified_matrix1);
	cout << "\n������� 2\n\n";
	print_matrix(required_matrix_size, required_matrix_size, modified_matrix2);

	const int half_required_matrix_size = required_matrix_size / 2;
	const int submatrix_count = 8;
	const int auxiliary_matrices_count = 4;

	//��������� ������ �� ���������� � �� ����������
	int*** submatrices = new int** [submatrix_count];
	for (int i = 0; i < submatrix_count; i++)
	{
		submatrices[i] = create_matrix(half_required_matrix_size);
		if (i < submatrix_count/2)
			filling_submatrix(submatrices[i], modified_matrix1, half_required_matrix_size, i + 1);
		else
			filling_submatrix(submatrices[i], modified_matrix2, half_required_matrix_size, (i % (submatrix_count / 2)) + 1);
	}

	//�������� ������������� ������
	int*** intermediate_matrices = new int** [submatrix_count - 1];
	for (int i = 0; i < submatrix_count - 1; i++)
		intermediate_matrices[i] = create_matrix(half_required_matrix_size);

	//���������� �������� ������������� ������
	for (int i = 0; i < half_required_matrix_size; i++)
	{
		for (int j = 0; j < half_required_matrix_size; j++)
		{
			for (int z = 0; z < half_required_matrix_size; z++)
			{
				intermediate_matrices[0][i][j] += (submatrices[0][i][z] +  submatrices[3][i][z]) * (submatrices[4][z][j] + submatrices[7][z][j]);
				intermediate_matrices[1][i][j] += (submatrices[2][i][z] +  submatrices[3][i][z]) *  submatrices[4][z][j];
				intermediate_matrices[2][i][j] +=  submatrices[0][i][z] * (submatrices[5][z][j]  -  submatrices[7][z][j]);
				intermediate_matrices[3][i][j] +=  submatrices[3][i][z] * (submatrices[6][z][j]  -  submatrices[4][z][j]);
				intermediate_matrices[4][i][j] += (submatrices[0][i][z] +  submatrices[1][i][z]) *  submatrices[7][z][j];
				intermediate_matrices[5][i][j] += (submatrices[2][i][z] -  submatrices[0][i][z]) * (submatrices[4][z][j] + submatrices[5][z][j]);
				intermediate_matrices[6][i][j] += (submatrices[1][i][z] -  submatrices[3][i][z]) * (submatrices[6][z][j] + submatrices[7][z][j]);
			}
		}
	}

	//�������� ��������������� ������
	int*** auxiliary_matrices = new int** [auxiliary_matrices_count];
	for (int i = 0; i < auxiliary_matrices_count; i++)
		auxiliary_matrices[i] = create_matrix(half_required_matrix_size);
		
	//������� �������� ��������������� ������ �� �������������
	for (int i = 0; i < half_required_matrix_size; i++)
	{
		for (int j = 0; j < half_required_matrix_size; j++)
		{
			auxiliary_matrices[0][i][j] = intermediate_matrices[0][i][j] + intermediate_matrices[3][i][j] - intermediate_matrices[4][i][j] + intermediate_matrices[6][i][j];
			auxiliary_matrices[1][i][j] = intermediate_matrices[2][i][j] + intermediate_matrices[4][i][j];
			auxiliary_matrices[2][i][j] = intermediate_matrices[1][i][j] + intermediate_matrices[3][i][j];
			auxiliary_matrices[3][i][j] = intermediate_matrices[0][i][j] - intermediate_matrices[1][i][j] + intermediate_matrices[2][i][j] + intermediate_matrices[5][i][j];
		}
	}

	//�������� �������������� �������
	int** preResult_matrix = create_matrix(required_matrix_size);

	//��������� ���������� �� ��������������� ������ � ��������������
	for (int i = 0; i < half_required_matrix_size; i++)
	{
		for (int j = 0; j < half_required_matrix_size; j++)
		{
			preResult_matrix[i][j] = auxiliary_matrices[0][i][j];
			preResult_matrix[i][j + half_required_matrix_size] = auxiliary_matrices[1][i][j];
			preResult_matrix[i + half_required_matrix_size][j] = auxiliary_matrices[2][i][j];
			preResult_matrix[i + half_required_matrix_size][j + half_required_matrix_size] = auxiliary_matrices[3][i][j];
		}
	}

	//������������ ������ �������������� �������
	int numbers_of_non_zero_elements = 0, finish_row = 100, finish_columns = 100;//!!

	finish_row = border_matrix(preResult_matrix, required_matrix_size, finish_row, true);//��������� �������
	finish_columns = border_matrix(preResult_matrix, required_matrix_size, finish_columns, false);//��������� �������

	//�������� � ���������� �������������� �������
	int** result_matrix = create_matrix(finish_row, finish_columns);
	copyMatrix(result_matrix, preResult_matrix, finish_row, finish_columns);//��������� �������������� �������� � 6 �������.

	//����� �������������� �������
	cout << "\n�������������� �������\n\n";
	print_matrix(finish_row, finish_columns, result_matrix);
	system("pause");

	//������� ������������ ������
	delete_matrix(matrix1, matrix1_row);
	delete_matrix(matrix2, matrix2_row);
	delete_matrix(modified_matrix1, required_matrix_size);
	delete_matrix(modified_matrix2, required_matrix_size);
	delete_matrix(preResult_matrix, required_matrix_size);
	delete_matrix(result_matrix, finish_row);
	for (int i = 0; i < submatrix_count; i++)
		delete_matrix(submatrices[i], half_required_matrix_size);
	for (int i = 0; i < 4; i++)
		delete_matrix(auxiliary_matrices[i], half_required_matrix_size);
	for (int i = 0; i < submatrix_count - 1; i++)
		delete_matrix(intermediate_matrices[i], half_required_matrix_size);
	
}