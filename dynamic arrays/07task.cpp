#include <iostream>
int* shiftArray(int* array, int n, int k)
{
	int* sec_array = new int[n];
	for (size_t i = 0; i < n; ++i)
	{
		if (i < k) sec_array[n - k + i] = array[i];
		else sec_array[i - k] = array[i];
	}
	return sec_array;
}
int main()
{
	int n, k;
	std::cout << "Enter the size and of an array and k " << "\n";
	std::cin >> n >> k;
	int* arr = new int[n];
	std::cout << "Enter array " << "\n";
	for (size_t i = 0; i < n; ++i) std::cin >> arr[i];
	int* shifted = shiftArray(arr, n, k);
	for (size_t i = 0; i < n; ++i) std::cout << shifted[i] << " ";
}
