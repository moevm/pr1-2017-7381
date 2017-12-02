int index_first_zero(int arr[], int i)
{
    int first;
    for (first = 1; first <= i; first++)
    {
        if (arr[first] == 0)
            break;
    }
    return first - 1;
}
