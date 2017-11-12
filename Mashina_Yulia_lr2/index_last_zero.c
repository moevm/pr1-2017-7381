int index_last_zero(int arr[], int i)
{
    int last;
    for (last = i; last >= 1; last--)
    {
        if (arr[last] == 0)
            break;
    }
    return last - 1;
}
