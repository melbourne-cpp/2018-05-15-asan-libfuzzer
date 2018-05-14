int fetch(int array[], int index)
{
    int * newInt = new int;
    *newInt = array[index];
    return *newInt;
}

int main()
{
    int array[] = { 1,2,3,4 };
    return fetch(array, 4);
}
