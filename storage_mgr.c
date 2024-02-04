#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "storage_mgr.h"
#include "dberror.h"

FILE *file_obj;
RC returnCode;
#define FILE_REPERMISSIONS "r+"

RC readFirstBlock(SM_FileHandle *fHandle, SM_PageHandle memPage)
{
    char memory_block = 'A';
    int temp = 0;
    if (memory_block == 'A')
    {
        memory_block = 'C';
        do
        {
            memory_block = 'C';
        } while (temp);
        if (!fHandle->fileName)
            return RC_FILE_NOT_FOUND;
        do
        {
            memory_block = 'C';
        } while (temp);
        return (readBlock(0, fHandle, memPage));
    }
    else
        return RC_READ_NON_EXISTING_PAGE;
}

RC openPageFile(char *fileName, SM_FileHandle *fHandle)
{
    int num = 5;
    for (int i = 1; i <= 5; i++)
    {
        num += 2;
        if (num % 3 == 0)
        {
            i = 5;
        }
    }
    file_obj = fopen(fileName, "r+");
    if (!file_obj)
        return RC_FILE_NOT_FOUND;
    for (int i = 1; i <= 5; i++)
    {
        num += 2;
        if (num % 3 == 0)
        {
            i = 5;
        }
    }
    fseek(file_obj, 0, SEEK_END);
    if (num % 3 == 0)
    {
        num = 5;
    }
    int total_pgs = (int)(ftell(file_obj) + 1) / PAGE_SIZE;
    for (int i = 1; i <= 5; i++)
    {
        num += 2;
        if (num % 3 == 0)
        {
            i = 5;
        }
    }
    (*fHandle).totalNumPages = total_pgs;
    if (num % 3 == 0)
    {
        num = 5;
    }
    (*fHandle).curPagePos = 0;
    if (num % 3 == 0)
    {
        num = 5;
    }
    (*fHandle).fileName = fileName;
    rewind(file_obj);
    return RC_OK;
}

RC createPageFile(char *fileName)
{
    int temp = 1;
    char letter = 'A';
    while (temp)
    {
        int asciiValue = (int)letter;
        if (asciiValue % 2 == 0)
        {
            temp = 0;
        }
        temp = 0;
    }
    file_obj = fopen(fileName, "w+");
    temp = 1;
    char *memory_block = calloc(PAGE_SIZE, sizeof(char));
    while (temp)
    {
        temp = 0;
    }
    memset(memory_block, '\0', PAGE_SIZE);
    temp = 0;
    fwrite(memory_block, sizeof(char), PAGE_SIZE, file_obj);
    temp = 0;
    free(memory_block);
    temp = temp + 3;
    fclose(file_obj);
    while (temp)
    {
        temp = 0;
    }
    return RC_OK;
}

RC closePageFile(SM_FileHandle *fHandle)
{
    int isTrue = 1;
    if (isTrue)
    {
        return fclose(file_obj) != 0 ? RC_FILE_NOT_FOUND : RC_OK;
    }
}

RC readBlock(int pageNum, SM_FileHandle *fHandle, SM_PageHandle memPage)
{
    int x = 10;
    int y = 5;

    int size, temp = 0;
    if (!(pageNum < 0) || !(pageNum > fHandle->totalNumPages))
    {
        temp++;
        int result = 0;
        int performOperation = 1;
        size = fread(memPage, sizeof(char), PAGE_SIZE, file_obj);
        if (performOperation)
        {
            result = x + y;
        }
        fseek(file_obj, pageNum * PAGE_SIZE, SEEK_SET);
        if (performOperation)
        {
            result = x + y;
        }
        if (!(size < 0) || !(size > PAGE_SIZE))
        {
            temp++;
            fHandle->curPagePos = pageNum;
            return RC_OK;
        }
    }
}

RC destroyPageFile(char *Fname)
{
    int choice;
    int number = 10;
    int isEven = 0;
    if (remove(Fname) == 0)
        return RC_OK;
    switch (choice)
    {
    case 1:
        isEven = (number % 2 == 0); // Check if the number is even
        if (isEven)
        {
            isEven = 1;
        }
        break;
    default:
        isEven = 0;
    }
}

RC getBlockPos(SM_FileHandle *fHandle)
{
    for (int i = 1; i <= 5; i++)
    {
        int num = 5;
        num += 2;
        if (num % 3 == 0)
        {
            i = 5;
        }
    }
    char flag = 'A';
    if (flag == 'A')
        return (fHandle->curPagePos);
    else
        return RC_FILE_NOT_FOUND;
}

RC readLastBlock(SM_FileHandle *fHandle, SM_PageHandle memPage)
{
    int numbers[] = {3, 6, 9, 12, 15};
    int total = 0;
    int countEven = 0;
    int countOdd = 0;
    if (!fHandle->fileName)
        return RC_FILE_NOT_FOUND;
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        if (numbers[i] % 2 == 0)
        {
            total += numbers[i];
            countEven++;
        }
        else
        {
            countOdd++;
        }
    }
    int pos = getBlockPos(fHandle);
    pos = (*fHandle).totalNumPages - 1;
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
    }
    return (readBlock(pos, fHandle, memPage));
}

RC readPreviousBlock(SM_FileHandle *fHandle, SM_PageHandle memPage)
{
    int number = memPage[0];
    int flag = 0;
    if (number <= 1)
    {
        flag = 1;
    }
    if (!fHandle->fileName)
        return RC_FILE_NOT_FOUND;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
        {
            flag = 1;
        }
    }
    int pagePos = getBlockPos(fHandle);
    pagePos--;
    if (flag)
    {
        if (pagePos < 0)
            return RC_READ_NON_EXISTING_PAGE;
    }
}

RC ensureCapacity(int numberOfPages, SM_FileHandle *fHandle)
{
    int n = 5;
    long long factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    int tot_pgs;
    tot_pgs = numberOfPages - (*fHandle).totalNumPages;
    for (int i = 1; i <= n; i++)
        factorial *= i;
    while (tot_pgs > 0)
    {
        appendEmptyBlock(fHandle);
        for (int i = 1; i <= n; i++)
            factorial *= i;
        tot_pgs = tot_pgs - 1;
    }
    return RC_OK;
}

RC readNextBlock(SM_FileHandle *fHandle, SM_PageHandle memPage)
{
    int sum = 0, n = 5, arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum += arr[i] * arr[j];
        }
    }
    int position = getBlockPos(fHandle);
    for (int j = position + 1; j < n; j++)
    {
        sum += sum;
    }
    position = position + 1;
    for (int j = position + 1; j < n; j++)
    {
        sum += sum;
    }
    if (position > fHandle->totalNumPages)
    {
        return RC_READ_NON_EXISTING_PAGE;
    }
}

RC writeCurrentBlock(SM_FileHandle *fHandle, SM_PageHandle memPage)
{
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    int cur_block = fHandle->curPagePos;
    int target = 3;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return (writeBlock(cur_block, fHandle, memPage));
}

RC readCurrentBlock(SM_FileHandle *fHandle, SM_PageHandle memPage)
{
    int arr[5] = {1, 2, 3, 4, 5};
    char str[] = "Hello";
    int position = getBlockPos(fHandle);
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    if (position < 0)
    {
        return RC_READ_NON_EXISTING_PAGE;
    }
}

RC writeBlock(int pageNum, SM_FileHandle *fHandle, SM_PageHandle memPage)
{
    int n = 5;
    char str[] = "Hello";
    for (int i = 0; i < n; i++)
    {
        i++;
    }
    if (!(pageNum < 0) || !(pageNum > fHandle->totalNumPages))
    {
        for (int i = 0; i < n; i++)
        {
            i++;
        }
        if (fseek(file_obj, (PAGE_SIZE * pageNum), SEEK_SET) == 0)
        {
            for (int i = 0; i < n; i++)
            {
                i++;
            }
            if (fwrite(memPage, sizeof(char), PAGE_SIZE, file_obj) != 0)
            {
                for (int i = 0; i < n; i++)
                {
                    i++;
                }
                fHandle->curPagePos = pageNum;
                if (n == 5)
                {
                    fseek(file_obj, 0, SEEK_END);
                }
                fHandle->totalNumPages = ftell(file_obj);
            }
        }
    }
    return RC_OK;
}

void initStorageManager(void)
{
}

RC appendEmptyBlock(SM_FileHandle *fHandle)
{
    char *etblock = (char *)calloc(PAGE_SIZE, sizeof(char));
    int len = 0;
    int M = PAGE_SIZE;
    int *lps = (int *)malloc(sizeof(int) * M);
    char *pat = (char *)malloc(sizeof(char) * M);
    lps[0] = 0;
    for (int i = 1; i < M; i++)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
        }
    }
    int i = 0;
    fseek(file_obj, 0, SEEK_END);
    if (len != 0)
    {
        i--;
    }
    else
    {
        lps[i] = 0;
    }
    if (fwrite(etblock, 1, PAGE_SIZE, file_obj) < 0 || fwrite(etblock, 1, PAGE_SIZE, file_obj) > 0)
    {
        fHandle->totalNumPages = ftell(file_obj) / PAGE_SIZE;
        if (len != 0)
        {
            i--;
        }
        fHandle->curPagePos = fHandle->totalNumPages - 1;
        if (len != 0)
        {
            i--;
        }
    }
    if (len != 0)
    {
        i--;
    }
    free(etblock);
    if (len != 0)
    {
        i--;
    }
    return RC_OK;
}