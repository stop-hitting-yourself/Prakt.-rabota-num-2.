#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int arrLenght = 100;

void elementsExchange(int* arr1, int* arr2) {
	for (int i = 0; i < arrLenght; ++i) {
		arr2[i] = arr1[i];
	}
}

int biggestCommonDivision(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	if (b % a == 0) {
		return a;
	}
	if (a > b) {
		return biggestCommonDivision(b, a % b);
	}
	else {
		return biggestCommonDivision(b % a, a);
	}
}

void bubbleSort(int* arr) {
	for (int i = 0; i < arrLenght - 1; ++i) {
		for (int j = 0; j < arrLenght - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void shakerSort(int* arr) {
	int left = 0, right = arrLenght - 1;
	while (left <= right) {
		for (int i = left; i < right; ++i) {
			if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
		}
		--right;
		for (int i = right; i > left; --i) {
			if (arr[i] < arr[i - 1]) swap(arr[i], arr[i - 1]);
		}
		++left;
	}
}

void insertionSort(int* arr) {
	for (int i = 1; i < arrLenght; ++i) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void gnomeSort(int* arr) {
	int i = 0;
	while (i < arrLenght) {
		if (i == 0 || arr[i - 1] <= arr[i]) {
			++i;
		}
		else {
			swap(arr[i], arr[i - 1]);
			--i;
		}
	}
}

void quicksort(int* arr, int end , int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l) / 2];
	while (f < l)
	{
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l)
		{
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l) quicksort(arr, l, begin);
	if (f < end) quicksort(arr, end, f);
}

int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == value) {
            return mid;
        }
        
        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }
        
        return binarySearch(arr, value, mid + 1, end);
    }
    
    return -1;
}

int main() {

	setlocale(0, "");

	int n;
	int arr[arrLenght];
	while (true) {
		srand(time(NULL));
		for (int i = 0; i < arrLenght; ++i) {
			arr[i] = rand() % 199 - 99;
		}
		break;
	}

	do
	{
		cout << "Введите номер задания 1-8, 9 - ИДЗ, 0 для выхода \n";

		cin >> n;

		int randomArr[arrLenght], sortingArr[arrLenght], sortedArr[arrLenght];

		elementsExchange(arr, randomArr);
		elementsExchange(randomArr, sortingArr);
		elementsExchange(randomArr, sortedArr);
		quicksort(sortedArr, arrLenght - 1, 0);

		//Создает целочисленный массив размерности N = 100. Элементы массивы должны принимать случайное значение в диапазоне от -99 до 99.

		if (n == 1) {
			cout << "Полученный целочисленный массив со случайными значениями с диапазоне от -99 до 99: \n";
			for (int i = 0; i < arrLenght; ++i) {
				cout << setw(4) << randomArr[i];
			}
			cout << '\n';
		}

		//Отсортировать заданный в пункте 1 массив различными сортировками (от меньшего к большему). Определить время, затраченное на сортировку, 
		// используя библиотеку chrono. Сравнить время работы различных сортировок. Необходимо реализовать 4 простых сортировки O(n²)  (описанных в курсе), 
		// 1 сортировку из эффективных (по принципу разделяй и властвуй)  O(n log n) *.

		if (n == 2) {

			cout << "Различные сортировки завершились за следующее время: \n";

			auto start1 = high_resolution_clock::now();
			bubbleSort(sortingArr);
			auto end1 = high_resolution_clock::now();
			auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
			cout << "Сортировка bubbleSort завершилась за " << duration1 << " наносекунд.\n";

			elementsExchange(randomArr, sortingArr);

			auto start2 = high_resolution_clock::now();
			shakerSort(sortingArr);
			auto end2 = high_resolution_clock::now();
			auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();
			cout << "Сортировка shakerSort завершилась за " << duration2 << " наносекунд.\n";

			elementsExchange(randomArr, sortingArr);

			auto start3 = high_resolution_clock::now();
			insertionSort(sortingArr);
			auto end3 = high_resolution_clock::now();
			auto duration3 = duration_cast<nanoseconds>(end3 - start3).count();
			cout << "Сортировка insertionSort завершилась за " << duration3 << " наносекунд.\n";

			elementsExchange(randomArr, sortingArr);

			auto start4 = high_resolution_clock::now();
			gnomeSort(sortingArr);
			auto end4 = high_resolution_clock::now();
			auto duration4 = duration_cast<nanoseconds>(end4 - start4).count();
			cout << "Сортировка gnomeSort завершилась за " << duration4 << " наносекунд.\n";

			elementsExchange(randomArr, sortingArr);

			auto start5 = high_resolution_clock::now();
			quicksort(sortingArr, arrLenght - 1, 0);
			auto end5 = high_resolution_clock::now();
			auto duration5 = duration_cast<nanoseconds>(end5 - start5).count();
			cout << "Сортировка quicksort завершилась за " << duration5 << " наносекунд.\n";


			cout << "Отсортированный масив имеет следующий вид:\n";
			for (int i = 0; i < arrLenght; ++i) {
				cout << setw(4) << sortingArr[i];
			}
			cout << '\n';
	
		}

		//Найти максимальный и минимальный элемент массива. Подсчитайте время поиска этих элементов в 
		// отсортированном массиве и неотсортированном, используя библиотеку chrono.
		
		if (n == 3) {
			
			int mn = randomArr[0], mx = randomArr[0];

			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] > mx) {
					mx = randomArr[i];
				}
			}
			for (int i = 1; i < arrLenght; ++i){
				if (randomArr[i] < mn) {
					mn = randomArr[i];
				}
			}
			cout << "Максимальный элемент равен:" << mx << endl;
			cout << "Минимальный элемент равен:" << mn << endl;

			auto start1 = high_resolution_clock::now();
			int mn0 = randomArr[0], mx0 = randomArr[0];

			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] > mx0) {
					mx0 = randomArr[i];
				}
			}
			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] < mn0) {
					mn0 = randomArr[i];
				}
			}
			auto end1 = high_resolution_clock::now();
			auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
			cout << "Время поиска макс. и мин. элементов в неотсортированном массиве составило " << duration1 << " наносекунд.\n";

			auto start2 = high_resolution_clock::now();
			int mn1 = sortedArr[0], mx1 = sortedArr[arrLenght];
			auto end2 = high_resolution_clock::now();
			auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();
			cout << "Время поиска макс. и мин. элементов в отсортированном массиве составило " << duration2 << " наносекунд.\n";
			cout << '\n';

		}

		//Выводит среднее значение (если необходимо, число нужно округлить) максимального и минимального значения в отсортированном и неотсортированном. 
		// Выводит индексы всех элементов, которые равны этому значению, и их количество. Подсчитайте время поиска.

		if (n == 4) {

			auto start1 = high_resolution_clock::now();
			int mn = randomArr[0], mx = randomArr[0],k=0;

			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] > mx) {
					mx = randomArr[i];
				}
			}
			for (int i = 1; i < arrLenght; ++i) {
				if (randomArr[i] < mn) {
					mn = randomArr[i];
				}
			}
			int middleValue = (mn+mx)/2;
			cout << "Индексы элементов, равных среднему значению максимального и минимального элементов неотсортированного массива:" << ' ';
			for (int i = 0; i < arrLenght; ++i) {
				if (randomArr[i] == middleValue) {
					cout << i << ' ';
					k += 1;
				}
			}
			cout << '\n' << "Количество таких элементов:" << k << '\n';
			auto end1 = high_resolution_clock::now();
			auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
			cout << "Время поиска таких элементов в неотсортированном массиве составило " << duration1 << " наносекунд.\n";

			cout << '\n';

			auto start2 = high_resolution_clock::now();
			int mn1 = sortedArr[0], mx1 = sortedArr[0], k1 = 0;

			for (int i = 1; i < arrLenght; ++i) {
				if (sortedArr[i] > mx1) {
					mx1 = sortedArr[i];
				}
			}
			for (int i = 1; i < arrLenght; ++i) {
				if (sortedArr[i] < mn1) {
					mn1 = sortedArr[i];
				}
			}
			int middleValue1 = (mn1 + mx1) / 2;
			cout << "Индексы элементов, равных среднему значению максимального и минимального элементов отсортированного массива:" << ' ';
			for (int i = 0; i < arrLenght; ++i) {
				if (sortedArr[i] == middleValue1) {
					cout << i << ' ';
					k1 += 1;
				}
			}
			cout << '\n' << "Количество таких элементов:" << k1 << '\n';
			auto end2 = high_resolution_clock::now();
			auto duration2 = duration_cast<nanoseconds>(end2 - start2).count();
			cout << "Время поиска таких элементов в отсортированном массиве составило " << duration2 << " наносекунд.\n";

		}

		//Выводит количество элементов в отсортированном массиве, которые меньше числа a, которое инициализируется пользователем.

		if (n == 5) {
			
			cout << "Введите значение а: \n";
			
			int a;

			cin >> a;

			int k = 0;

			for (int i = 0; i < arrLenght; ++i) {
				if (sortedArr[i] < a) {
					k += 1;
				}
			}
			cout << "Элементов, меньших а в отсортированном массиве:" << ' ' << k << '\n';
		}

		//Выводит количество элементов в отсортированном массиве, которые больше числа b, которое инициализируется пользователем.

		if (n == 6) {

			cout << "Введите значение b: \n";

			int b;

			cin >> b;

			int k = 0;

			for (int i = 0; i < arrLenght; ++i) {
				if (sortedArr[i] > b ) {
					k += 1;
				}
			}
			cout << "Элементов, больших b в отсортированном массиве:" << ' ' << k << '\n';
		}

		//Выводит информацию о том, есть ли введенное пользователем число в отсортированном массиве.Реализуйте 
		// алгоритм бинарного поиска.Сравните скорость его работы с обычным перебором. (*)

		if (n == 7) {

			int n, k = 0;

			cout << "Введите искомое значение n: \n";

			cin >> n;

			auto start = high_resolution_clock::now();
			for (int i = 0; i < arrLenght; ++i) {
				if (sortedArr[i] == n) {
					cout << "Искомое значение n = " << n << " есть в отсортированном массиве, он находится на позиции " << i << '\n';
					k += 1;
					break;
				}
			}
			if (k == 0) {
				cout << "Искомый элемент не найден в отсортированном масиве\n";
			}
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<nanoseconds>(end - start).count();
			cout << "Поиск заданного значения методом обычного перебора занял " << duration << " наносекунд.\n";

			auto start1 = high_resolution_clock::now();
			int result = binarySearch(sortedArr, n, 0, arrLenght - 1);
			if (result == -1) {
				cout << "Искомый элемент не найден в отсортированном масиве\n";
			}
			else {
				cout << "Искомое значение n = " << n << " есть в отсортированном массиве, он находится на позиции " << result << '\n';
			}
			auto end1 = high_resolution_clock::now();
			auto duration1 = duration_cast<nanoseconds>(end1 - start1).count();
			cout << "Поиск заданного значения методом бинарного поиска занял " << duration1 << " наносекунд.\n";
		}

		//Меняет местами элементы массива, индексы которых вводит пользователь. Выведите скорость обмена, используя библиотеку chrono.

		if (n == 8) {

			int l, p;

			cout << "Введите индексы элементов, места которых вы хотите поменять: \n";

			cin >> l >> p;

			if ((l <= 99) and (l>=0) and (p <= 99) and (p >= 0)) {
				swap(sortedArr[l], sortedArr[p]);
				cout << "Массив с измененными по заданным индексам элементами:\n";
				for (int i = 0; i < arrLenght; ++i) {
					cout << setw(4) << sortedArr[i];
				}
			}
			else {
				cout << "Введены неподходящие значения";
			}

			cout << '\n';
			

		}

		//Определите, есть ли в массиве хотя бы одна пара соседних элементов, которые являются взяимно простыми числами. Выведите индексы всех таких пар.

		if (n == 9) {

			cout << "Индексы элементов массива, стоящих по соседству и являющихся взаимно простыми числами в отсортированном массиве:\n";

			for (int i = 0; i < (arrLenght-1); ++i) {
				if ((sortedArr[i]!=0 and sortedArr[i+1] != 0) and (biggestCommonDivision(abs(sortedArr[i]), abs(sortedArr[i + 1])) == 1)) {
					cout  << i << ' ' << i + 1<< '\n';
				}
			}

			cout << "\nИндексы элементов массива, стоящих по соседству и являющихся взаимно простыми числами в неотсортированном массиве:\n";

			for (int i = 0; i < (arrLenght - 1); ++i) {
				if ((randomArr[i] != 0 and randomArr[i + 1] != 0) and (biggestCommonDivision(abs(randomArr[i]), abs(randomArr[i + 1])) == 1)) {
					cout << i << ' ' << i + 1 << '\n';
				}
			}

		}
		
	} while (n != 0);
}
