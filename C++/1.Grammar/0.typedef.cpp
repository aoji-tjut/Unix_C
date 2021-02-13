/*
 * #define INT int
 * typedef int INT;
 * INT i; --> int i;
 *
 * #define pINT int*
 * pINT p, q; --> int *p, q;
 * typedef int* pINT
 * pINT p, q; --> int *p, *q;
 *
 * typedef int ARR[10];
 * ARR a; --> int a[10];
 *
 * typedef int FUN(int);
 * FUN f; --> int f(int);
 *
 * typedef int* pFUN(int);
 * pFUN p; --> int* p(int);
 *
 * typedef int* (*pFUN)(int);
 * pFUN p; --> int* (*p)(int);
 */