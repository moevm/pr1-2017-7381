int index_last_zero(int arr[], int i)
{
    int last;
    for (last = i-1; last >= 0; last--)
    {
        if (arr[last] == 0)
            break;
    }
    return last;
}
