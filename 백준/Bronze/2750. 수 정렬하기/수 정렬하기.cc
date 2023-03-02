#include <iostream>

using namespace std;

int main() {
	int a, b, tmp;
	cin >> a;
	int* array = new int[a];
	

	for (int i = 0; i < a; i++)
	{
		cin >> b;
		array[i] = b;
	}

	for (int x = 0; x < a-1; x++)
	{
		for (int y = 0; y < a-1; y++) {
			if (array[y] > array[y + 1]) {
				tmp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = tmp;
			}
		}
	}

	for (int z = 0; z < a; z++)
	{
		cout << array[z] << endl;
	}

	delete array;
	return 0;


}