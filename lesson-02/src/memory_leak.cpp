#include <cstddef>
#include <cstdlib>

int main()
{
    size_t* arr = (size_t *)malloc(sizeof(size_t) * 100);
    //arr == NULL;
    ////……..
    arr = (size_t *)malloc(sizeof(size_t) * 200);
    free(arr);
}
