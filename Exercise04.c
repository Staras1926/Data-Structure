/// icsd17093 koufalis-kanelis xristos
/// icsd17159 platsatouras konstantinos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
///dilwsi sunartisewn
void InsertionSort (int *A, int N,int* sugkriseis);
void quicksort(int a[], int lo, int hi,int* sugkriseis);
void merge(int arr[], int l, int m, int r,int* sugkriseis);
void mergesort(int arr[], int l, int r,int* sugkriseis);
void swap(int *xp, int *yp);
void SelectionSort(int arr[], int n,int* sugkriseis);

int main()
{
    int i, N, k, option;
    int *A;
    double mesosXronos=0;
    int sugkriseis=0;
    clock_t start, end;
    double elapsed;


    printf("\n 1.Insertion Sort\n 2.Merge Sort\n 3.Quick Sort\n 4.Selection Sort\n 5.Heap Sort\n 6.Exit.\n");

    printf("Choose algorithm : ");
    scanf("%d", &option);


    printf("\n\n Size of Array : ");
    scanf("%d", &N);
    printf("\n\n");

    ///desmeusi mnimis gia ton pinaka
    A= (int *) malloc(N*sizeof(int ));

    for ( i=0; i<50; i++)
    {
        for(k=0; k<N; k++)
        {
            A[k]=(rand()%30001);
        }

        ///INSERTION SORT
        if(option==1)
        {

            start = clock();

            InsertionSort(A, N, &sugkriseis);

            ///ypologismos xronou
            end = clock();
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            mesosXronos = mesosXronos + elapsed;



        }

        ///MERGESORT SORT
        else if(option==2)
        {

            start = clock();
            mergesort(A,0,N, &sugkriseis);
            end = clock();
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            mesosXronos = mesosXronos + elapsed;

        }

        ///QUICKSORT
        else if(option==3)
        {

            start = clock();
            quicksort(A, 0, N-1, &sugkriseis);
            end = clock();
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            mesosXronos = mesosXronos + elapsed;

        }
        else if(option==4)
            {
            start = clock();
            SelectionSort(A,N-1, &sugkriseis);
            end = clock();
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            mesosXronos = mesosXronos + elapsed;
            }
        else if(option==5)
        {

        }



        ///EXIT
        else if (option==6)
        {
            printf("goodbye");
        }
        else
        {
            printf("wrong option");
        }

    }

///emfanisi arithmou sugrisewn kai tou mesou xronou
    printf("Mesos # Sugkrisewn  : %f \n",(double) sugkriseis/100);
    printf("Mesos Xronos taksinomhshs : %f\n",mesosXronos/100);

}


void InsertionSort (int A[], int N,int *sugkriseis)
{

    int c, d, t;

    for(c=1 ; c<=N; c++)
    {

        d = c;

        while (A[d] > A[d-1])
        {
            t = A[d];
            A[d] = A[d-1];
            A[d-1] = t;
            d--;
            ++*sugkriseis;
        }
    }


}


void mergesort(int arr[], int l, int r, int *sugkriseis)
{
    if (l < r)
    {
        ++*sugkriseis;
        ///brisko to meso
        int m = (l+r)/2;

        ///taksinomw anadromika ta 2 misa
        mergesort(arr, l, m, sugkriseis);
        mergesort(arr, m+1, r, sugkriseis);

        merge(arr, l, m, r, sugkriseis);

    }

}

void merge(int arr[], int l, int m, int r,int *sugkriseis)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    ///dhmiurgw prosorinous pinakes
    int L[n1], R[n2];

    /// metaferw stoixeia se L[] kai R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    ///sygxvneyv tous prosorinous pinakes ston arxiko taksinomwntas
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = R[j];
            j++;
        }
        else
        {
            arr[k] = L[i];
            i++;
        }
        k++;
        ++*sugkriseis;
    }

    ///antigrafw ta stoixeia tou L an uparxnoun
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    ///antigrafw ta stoixeia tou R an uparxnoun

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}




void quicksort(int a[], int first, int last, int *sugkriseis)
{
    int h, l, aksonas, t, c;

    if (first < last)
    {
        l = first;
        h = last;
        aksonas = a[last];

        do
        {
            while ((l < h) && (a[l] >= aksonas))
                l = l+1;
            ++*sugkriseis;

            while ((h > l) && (a[h] <= aksonas))
                h = h-1;
            ++*sugkriseis;

            if (l < h)
            {
                t = a[l];
                a[l] = a[h];
                a[h] = t;
            }
        }
        while (l < h);

        a[last] = a[l];
        a[l] = aksonas;

        quicksort( a, first, l-1, sugkriseis );
        quicksort( a, l+1, last, sugkriseis );

    }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SelectionSort(int arr[], int n,int *sugkriseis)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 ++*sugkriseis;
        swap(&arr[min_idx], &arr[i]);
         ++*sugkriseis;
    }
}
