#include <stdio.h>
void Print(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void Swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}
// // 选择排序
// #include <stdio.h>

// int main()
// {
//     int arr[] = {2, 1, 88, 90, 33, 34};
//     int len = sizeof(arr) / sizeof(arr[0]) - 1;
//     int count = 0; // 记录循环的次数

//     for (int i = 0; i <= len; i++)
//     {
//         printf("%2d ", arr[i]);
//     }
//     printf("\n");

//     for (int i = 0; i < len; i++)
//     {
//         int flag = 1;
//         for (int j = i; j < len; j++)
//         {
//             if (arr[i] > arr[j + 1])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j + 1];
//                 arr[j + 1] = temp;
//                 flag = 0;
//                 count++;
//             }
//             if (1 == flag)
//             {
//                 break;
//             }
//         }
//     }
//     for (int i = 0; i <= len; i++)
//     {
//         printf("%2d ", arr[i]);
//     }
//     printf("\ncount = %d\n", count);

//     return 0;
// }

// 数组元素逆置（行列置换）
// #include <stdio.h>

// int main()
// {
//   int arr1[2][3] = {23, 34, 89, 90, 12, 45};
//   int arr2[2][3] = {0};
//   int len = sizeof(arr1) / sizeof(arr1[0][0]);
//   printf("len = %d\n", len);

//   printf("arr1:\n");
//   for (int i = 0; i < 2; i++)
//   {
//     for (int j = 0; j < 3; j++)
//     {
//       printf("%2d ", arr1[i][j]);
//       arr2[j][i] = arr1[i][j];
//     }
//     printf("\n");
//   }
//   printf("arr2:\n");
//   for (int i = 0; i < 3; i++)
//   {
//     for (int j = 0; j < 2; j++)
//     {
//       printf("%d ", arr2[i][j]);
//     }
//     printf("\n");
//   }
//   return 0;
// }

// 利用选择排序得出一个数组的最大值
// #include <stdio.h>

// int main()
// {
//   // 初始化数组
//   int arr[][4] = {2300, 11200, 24000, 89, 90, 24, 56, 234, 902, 11, 25, 904};
//   int len = sizeof(arr) / sizeof(arr[0][0]); // 数组元素的个数
//   int max = arr[0][0];                       // 假设数组的最大值为数组首元素
//   int count = 0;                             // 记录循环的总次数
//   int row = 0, col = 0;                      // 记录最大值的行号与列号

//   for (int i = 0; i < 3; i++)
//   {
//     for (int j = i; j < 4; j++)
//     {
//       if (max < arr[i][j])
//       {
//         int temp = max;
//         max = arr[i][j];
//         arr[i][j] = temp;
//         count++;
//         row = i;
//         col = j;
//       }
//     }
//   }
//   printf("max = %d, row = %d, col = %d, count = %d\n", max, row, col, count);

//   return 0;
// }

// 选择排序的优化版：每一次排序都选出当时数组的最大值与最小值
// #include <stdio.h>

// int main()
// {
//   int arr[] = {12, 34, 89, 90, 2, 1, 23, 90, 231, 34, 89, 10};
//   int len = sizeof(arr) / sizeof(arr[0]); // 数组元素的个数
//   // 初始化数组的最右端和最左端
//   int left = 0;
//   int right = len - 1;

//   // 记录循环的总次数
//   int count = 0;
//   // 打印排序前的数组的各元素
//   for (int i = 0; i <= len - 1; i++)
//   {
//     printf("%2d ", arr[i]);
//   }
//   printf("\n");
//   while (left < right)
//   {
//     // 首先假设数组元素的最大值和最小值的索引分别为数组的最左端和最右端
//     int min = left;
//     int max = right;
//     // 标记每趟比较中的数组元素的最大值和最小值的索引
//     for (int i = left; i <= right; i++)
//     {
//       max = (arr[max] > arr[i] ? max : i);
//       min = (arr[min] < arr[i] ? min : i);
//       count++;
//     }
//     // 将数组元素的最大值放在数组最右端
//     int temp = arr[max];
//     arr[max] = arr[right];
//     arr[right] = temp;

//     // 因为是先放置最大值在数组的最右端，所以必须考虑最小值在数组最右端的情况
//     if (min == right)
//     {
//       // 此时max所代表数组下标不再是数组最大值的下标
//       min = max;
//     }

//     // 将数组元素的最小值放在最左端
//     temp = arr[min];
//     arr[min] = arr[left];
//     arr[left] = temp;

//     left++;
//     right--;
//   }

//   // 打印排序前的数组的各元素
//   for (int i = 0; i <= len - 1; i++)
//   {
//     printf("%2d ", arr[i]);
//   }
//   printf("\ncount = %d\n", count);
//   return 0;
// }

// 选择排序
// #include <stdio.h>

// int main()
// {
//   int count = 0; // 记录循环的总次数
//   int arr[] = {12, 34, 89, 90, 2, 1, 23, 90, 231, 34, 89, 10};
//   int len = sizeof(arr) / sizeof(arr[0]);

//   for (int i = 0; i <= len - 1; i++)
//   {
//     printf("%2d ", arr[i]);
//   }
//   printf("\n");
//   for (int i = 0; i < len - 1; i++)
//   {
//     for (int j = i; j < len - 1; j++)
//     {
//       if (arr[i] > arr[j + 1])
//       {
//         int temp = arr[j + 1];
//         arr[j + 1] = arr[i];
//         arr[i] = temp;
//         count++;
//       }
//     }
//   }
//   for (int i = 0; i <= len - 1; i++)
//   {
//     printf("%2d ", arr[i]);
//   }
//   printf("\ncount = %d\n", count);

//   return 0;
// }

// 冒泡排序（升序）
//  #include <stdio.h>

// int main()
// {
//   int arr[] = { 234, 23, 9, 12, 2, 22, 19};
//   int len = sizeof(arr) / sizeof(arr[0]) - 1;//数组元素的最大下标

//   for (int i = 0; i < len; i++)
//   {
//     printf("%3d ", arr[i]);
//   }
//   printf("\n");
//   for (int i = 0; i < len - 1; i++)
//   {
//       for (int j = 0; j < len - i - 1; j++)
//       {
//         if (arr[j] > arr[j + 1])
//         {
//           int temp = arr[j];
//           arr[j] = arr[j + 1];
//           arr[j + 1] = temp;
//         }
//       }
//   }
//   for (int i = 0; i < len; i++)
//   {
//     printf("%3d ", arr[i]);
//   }

//   return 0;
// }

// 冒泡排序优化1(升序)
// #include <stdio.h>
// #include <stdbool.h>

// int main()
// {
//   int arr[] = {1, 2, 3, 5, 4, 6, 8, 7};
//   int len = sizeof(arr) / sizeof(arr[0]);
//   int count = 0; // 记录循环的总次数
//   bool Issort = false;

//   for (int i = 0; i <= len - 1; i++)
//   {
//     printf("%2d ", arr[i]);
//   }
//   printf("\n");
//   for (int i = 0; i < len - 1; i++)
//   {
//     for (int j = 0; j < len - i - 1; j++)
//     {
//       if (arr[j] > arr[j + 1])
//       {
//         int temp = arr[j];
//         arr[j] = arr[j + 1];
//         arr[j + 1] = temp;
//         count++;
//         Issort = true;
//       }
//     }
//     if (!Issort)
//     {
//       break;
//     }
//   }
//   for (int i = 0; i <= len - 1; i++)
//   {
//     printf("%2d ", arr[i]);
//   }
//   printf("\ncount = %d\n", count);

//   return 0;
// }

// 冒泡排序优化2(升序)
// #include <stdio.h>

// static void PreSort(int *arr, int len, int left);
// static void BackSort(int *arr, int len, int right);

// int main()
// {
//   int arr[] = {25, 19, 34, 9, 11, 8, 5};
//   int len = sizeof(arr) / sizeof(arr[0]);
//   // 初始化数组最右端和最左端的索引
//   int left = 0;
//   int right = len - 1;

//   // 打印数组的各元素
//   for (int i = 0; i < len; i++)
//   {
//     printf("%2d ", arr[i]);
//   }
//   printf("\n");
//   while (left < right)
//   {
//     // 获取当前数组的最小值
//     PreSort(arr, len, left);
//     // 获取完成后，数组的最小下标进一位
//     left++;
//     // 判断数组的最小下标是否大于等于最大下标
//     if (left >= right)
//     {
//       break;
//     }
//     // 获取当前数组的最大值
//     BackSort(arr, len, right);
//     right--;
//   }
//   // 打印数组的各元素
//   for (int i = 0; i < len; i++)
//   {
//     printf("%2d ", arr[i]);
//   }
//   printf("\n");
//   return 0;
// }

// // 从前向后排序：将数组最大值放在数组的末端
// static void PreSort(int *arr, int len, int left)
// {
//   for (int i = left + 1; i < len; i++)
//   {
//     if (*(arr + left) > *(arr + i))
//     {
//       int temp = *(arr + left);
//       *(arr + left) = *(arr + i);
//       *(arr + i) = temp;
//     }
//   }
// }

// // 从后向前排序：将数组的最小值放在数组的首部
// static void BackSort(int *arr, int len, int right)
// {
//   for (int i = right; i >= 0; i--)
//   {
//     if (*(arr + right) < *(arr + i))
//     {
//       int temp = *(arr + i);
//       *(arr + i) = *(arr + right);
//       *(arr + right) = temp;
//     }
//   }
// }

// 冒泡排序练习
// #include <stdio.h>
// #include <stdbool.h>

// int main()
// {
//   // 记录循环的总次数
//   int count = 0;
//   int arr[] = {89, 23, 90, 56, 76, 84, 12, 34};
//   // 数组元素的总数
//   int len = sizeof(arr) / sizeof(arr[0]);

//   // 打印数组个元素
//   printf("冒泡排序前：");
//   for (int i = 0; i < len; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   printf("\n");
//   for (int i = 0; i < len - 2; i++)
//   {
//     bool flag = false;
//     for (int j = 0; j < len - i - 1; j++)
//     {
//       if (arr[j] > arr[j + 1])
//       {
//         int temp = arr[j];
//         arr[j] = arr[j + 1];
//         arr[j + 1] = temp;
//         count++;
//         // 元素发生交换时，标记为真值
//         flag = true;
//       }
//     }
//     if (!flag)
//     {
//       break;
//     }
//   }
//   printf("冒泡排序后：");
//   for (int i = 0; i < len; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   printf("\n");

//   return 0;
// }

// 双向冒泡排序

// #include <stdio.h>

// int main()
// {
//   int arr[] = {34, 12, 9, 45, 7, 8, 3};
//   int len = sizeof(arr) / sizeof(arr[0]);
//   int left = 0;
//   int right = len - 1;

//   // 打印排序前的数组元素
//   printf("排序前：");
//   for (int i = 0; i <= len - 1; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   printf("\n");
//   while (left < right)
//   {
//     // 从前向后排序（正向循环）：将数组的最大值移动到数组的末端
//     for (int i = left + 1; i <= len - 1; i++)
//     {
//       if (*(arr + i) < *(arr + left))
//       {
//         int temp = *(arr + left);
//         *(arr + left) = *(arr + i);
//         *(arr + i) = temp;
//       }
//     }
//     left++;
//     if (left >= right)
//     {
//       break;
//     }
//     // 从后向前排序（反向循环）：将数组的最小值移动到数组的首部
//     for (int i = right; i >= 0; i--)
//     {
//       if (*(arr + i - 1) > *(arr + right))
//       {
//         int temp = *(arr + right);
//         *(arr + right) = *(arr + i - 1);
//         *(arr + i - 1) = temp;
//       }
//     }
//     right--;
//   }
//   // 打印排序后的数组元素
//   printf("排序后：");
//   for (int i = 0; i <= len - 1; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   printf("\n");

//   return 0;
// }

// 插入排序练习
// #include <stdio.h>

// int main()
// {
//   int arr[] = {4, 6, 8, 5, 9};
//   int len = sizeof(arr) / sizeof(arr[0]);

//   for (int i = 0; i < len; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   printf("\n");

//   int tmp;
//   int i;
//   int j;
//   for (i = 1; i < len; i++)
//   {
//     tmp = arr[i];
//     for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
//     {
//       // 当待插入元素比当前有序序列的数组元素小时，有序序列的数组元素往后移动
//       arr[j + 1] = arr[j];
//     }
//     //  当for循环结束后，插入元素
//     arr[j + 1] = tmp;
//   }
//   for (int i = 0; i < len; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   printf("\n");

//   return 0;
// }

// // 直接插入排序
// #include <stdio.h>

// int main()
// {
//     int arr[] = {23, 6, 89, 1, 0, 3, 7};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     int j = 0;

//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%2d ", arr[i]);
//     }
//     printf("\n");
//     for (int i = 1; i < len; i++)
//     {
//         int temp = arr[i];
//         for (j = i - 1; j >= 0 && arr[j] > temp; j--)
//         {
//             arr[j + 1] = arr[j];
//         }
//         arr[j + 1] = temp;
//     }
//     printf("排序后：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%2d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }

// 直接插入排序
// #include <stdio.h>

// int main()
// {
//   int arr[] = {23, 89, 10, 23, 25};
//   int len = sizeof(arr) / sizeof(arr[0]);
//   int j = 0;

//   printf("排序前：");
//   for (int i = 0; i < len; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   printf("\n");
//   // 假设数组的首元素是有序的
//   for (int i = 1; i < len; i++)
//   {
//     // 当前方已排好序的元素比当前元素大时，执行插入元素的操作
//     if (arr[i] < arr[i - 1])
//     {
//       // 创建临时变量存储当前的待插入的数组元素
//       int temp = arr[i];
//        // 从后往前查找要插入的位置
//       for (j = i - 1; j >= 0 && arr[j] > temp; j--)
//       {
//         // 有序序列的元素往后移动
//         arr[j + 1] = arr[j];
//       }
//       // 将待插入的元素放到应插入的位置
//       arr[j + 1] = temp;
//     }
//   }
//   printf("排序后：");
//   for (int i = 0; i < len; i++)
//   {
//     printf("%d ", arr[i]);
//   }
//   printf("\n");

//   return 0;
// }

// 直接插入排序的另一种写法
// #include <stdio.h>

// int main()
// {
//     int arr[] = {23, 34, 12, 11, 10, 89};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     for (int i = 0; i < len - 1; i++)
//     {
//         // 记录有序序列的最后一个元素
//         int end = i;
//         // 待插入的元素
//         int temp = arr[end + 1];
//         // 单趟排序
//         while (end >= 0)
//         {
//             // 当待插入的元素比有序序列的元素小时，有序序列的数组元素向后移动
//             if (temp < arr[end])
//             {
//                 arr[end + 1] = arr[end];
//                 end--;  // end递减，从后往前遍历有序序列的数组元素
//             }
//             // 待插入的元素比有序序列的元素大，则跳出循环
//             else
//             {
//                 break;
//             }
//         }
//         // 程序执行到此有两层意思：1、待插入元素比有序序列的元素都要小（while循环到此就结束了）
//         // 2、待插入元素找到应插入位置（break跳出循环到此）
//         arr[end + 1] = temp;
//     }
//     printf("\n排序后：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     return 0;
// }

// 折半插入查找
// #include <stdio.h>

// int main()
// {
//     int arr[] = {6, 2, 1, 4, 7, 9};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     int j = 0;
//     for (int i = 0; i < len; i++)
//     {
//         printf("%2d ", arr[i]);
//     }
//     // 假设数组首元素是一个有序序列，则下标应从1开始
//     for (int i = 1; i < len; i++)
//     {
//         // 创建临时变量储存当前的待插入元素值
//         int temp = arr[i];
//         // 设置折半查找的范围
//         int left = 0;
//         int right = i - 1;
//         int mid = 0;
//         // 在有序序列中查找待插入的位置
//         while (left <= right)
//         {
//             mid = left + (right - left) / 2;
//             // 查找左子表
//             if (temp < arr[mid])
//             {
//                 right = mid - 1;
//             }
//             // 查找右子表
//             else if (temp > arr[mid])
//             {
//                 left = mid + 1;
//             }
//         }
//         for (j = i - 1; j >= right + 1; j--)
//         {
//             // 在有序序列中，从right + 2开始到i - 1结束，该范围内的数组元素往后移动，空出插入位置
//             arr[j + 1] = arr[j];
//         }
//         arr[right + 1] = temp; // 将待插入的元素插入到该位置
//     }
//     printf("\n排序后：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%2d ", arr[i]);
//     }

//     return 0;
// }

// 直接插入排序
// #include <stdio.h>

// int main()
// {
//     int arr[] = {23, 12, 89, 67, 45};
//     int j = 0;
//     int len = sizeof(arr) / sizeof(arr[0]);
//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     for (int i = 1; i < len; i++)
//     {
//         // 暂时记录待插入数组元素
//         int temp = arr[i];
//         for (j = i - 1; j >= 0 && temp < arr[j]; j--)
//         {
//             // 数组元素往后移动
//             arr[j + 1] = arr[j];
//         }
//         arr[j + 1] = temp;
//     }
//     printf("\n排序后：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");

//     return 0;
// }

// 希尔排序
// #include <stdio.h>

// int main()
// {
//     int arr[] = {24, 12, 10, 25, 13, 11, 55};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     for (int inc = len / 2; inc > 0; inc /= 2)
//     {
//         for (int i = inc; i < len; i++)
//         {
//             int temp = arr[i];
//             int j = 0;
//             for (j = i; j >= inc && temp < arr[j - inc]; j -= inc)
//             {
//                 arr[j] = arr[j - inc];
//             }
//             arr[j] = temp;
//         }
//     }
//     printf("\n排序后：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// 折半查找插入排序
// #include <stdio.h>

// int main()
// {
//     int arr[] = {23, 34, 89, 12, 31, 90, 11};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     for (int i = 1; i < len; i++)
//     {
//         int left = 0;
//         int right = i - 1;
//         int temp = arr[i];
//         while (left <= right)
//         {
//             int mid = left + (right - left) / 2;
//             if (arr[mid] < arr[i])
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid - 1;
//             }
//         }
//         // 从有序列的最后一位开始遍历数组，比较待插入元素与有序数组的数组元素的大小
//         for (int j = i - 1; j >= right + 1; j--)
//         {
//             arr[j + 1] = arr[j];
//         }
//         arr[right + 1] = temp;
//     }
//     printf("\n排序后：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// // 选择排序练习一
// #include <stdio.h>

// int main()
// {
//     int arr[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     for (int i = 0; i < len - 1; i++)
//     {
//         for (int j = i; j < len; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     printf("\n排序后：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }

// }

// // 冒泡排序练习一（升序）
// #include <stdio.h>

// int main()
// {
//     int arr[] = {1, 2, 3, 7, 8, 9};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     for (int i = 0; i < len - 2; i++)
//     {
//         for (int j = 0; j < len - i - 1; j++)
//         {
//             if (arr[j] < arr[j + 1])
//             {
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
//     printf("\n排序后：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// // 直接插入排序练习一
// #include <stdio.h>

// int main()
// {
//     int arr[] = {23, 12, 90, 11, 21, 13};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n排序后：");
//     for (int i = 1; i < len; i++)
//     {
//         // 暂存待插入的元素
//         int temp = arr[i];
//         int j = 0;
//         for (j = i - 1; j >= 0 && temp < arr[j]; j--)
//         {
//             // 当前的有序数组的元素比待插入元素小，则有序数组的元素往后移动一位
//             arr[j + 1] = arr[j];
//         }
//         arr[j + 1] = temp;
//     }
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// 选择排序的优化版
// #include <stdio.h>

// int main()
// {
//     int arr[] = {22, 11, 90, 34, 56, 12, 91, 24};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     int left = 0;
//     int right = len - 1;
//     int min = left;
//     int max = right;

//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n排序后：");
//     while (left < right)
//     {
//         for (int i = left; i <= right; i++)
//         {
//             min = (arr[min] > arr[i] ? i : min);
//             max = (arr[max] < arr[i] ? i : max);
//         }
//         将数组的最小值放在数组的左边
//         int temp = arr[min];
//         arr[min] = arr[left];
//         arr[left] = temp;
//         因为先置换最小值，所以要考虑最大值在最左边的情况
//         if (max == left)
//         {
//             max = min;
//         }
//         temp = arr[right];
//         arr[right] = arr[max];
//         arr[max] = temp;
//         left++;
//         right--;
//     }
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// // 直接插入排序的另一种写法
// #include <stdio.h>

// int main()
// {
//     int arr[] = {23, 11, 90, 34, 21, 56, 10};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     // 排序的次数是数组元素的总数减1
//     for (int i = 0; i < len - 1; i++)
//     {
//         // 记录有序序列的最后一个数组元素
//         int end = i;
//         // 暂存待插入数组元素
//         int temp = arr[i + 1];
//         while (end >= 0)
//         {
//             if (temp < arr[end])
//             {
//                 arr[end + 1] = arr[end];
//                 end--;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         arr[end + 1] = temp;
//     }
//     printf("\n排序后：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// // 快速排序(CSDN)
// #include <stdio.h>

// void Print(int *arr, int n);
// void QuickSort(int *arr, int begin, int end);
// int count = 0; // 创建一个统计循环总数的全局变量
// int main()
// {
//     int arr[] = {23, 1, 2, 3, 89, 0, 5, 11, 90, 13, 67};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     int begin = 0;
//     int end = sizeof(arr) / sizeof(arr[0]) - 1;

//     printf("排序前：");
//     Print(arr, len);
//     QuickSort(arr, begin, end);
//     // Quick_Sort(arr, begin, end);
//     printf("\n排序后：");
//     Print(arr, len);
//     printf("\ncount = %d\n", count);

//     return 0;
// }

// void Print(int *arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%2d ", *(arr + i));
//     }
// }

// void QuickSort(int *arr, int begin, int end)
// {
//     if (begin > end)
//     {
//         return;
//     }
//     int temp = arr[begin]; // 假设数组首元素为基准数
//     int i = begin;
//     int j = end;
//     while (i != j)
//     {
//         while (j > i && arr[j] >= temp)
//         {
//             j--;
//         }
//         while (j > i && arr[i] <= temp)
//         {
//             i++;
//         }
//         if (j > i)
//         {
//             int t = arr[i];
//             arr[i] = arr[j];
//             arr[j] = t;
//         }
//     }
//     arr[begin] = arr[i];
//     arr[i] = temp;
//     QuickSort(arr, begin, i - 1);
//     QuickSort(arr, i + 1, end);
// }

// void Quick_Sort(int *arr, int begin, int end)
// {
//     if (begin > end)
//         return;
//     int tmp = arr[begin];
//     int i = begin;
//     int j = end;
//     while (i != j)
//     {
//         while (arr[j] >= tmp && j > i)
//             j--;
//         while (arr[i] <= tmp && j > i)
//             i++;
//         if (j > i)
//         {
//             int t = arr[i];
//             arr[i] = arr[j];
//             arr[j] = t;
//         }
//     }
//     arr[begin] = arr[i];
//     arr[i] = tmp;
//     Quick_Sort(arr, begin, i - 1);
//     Quick_Sort(arr, i + 1, end);
// }

// // 快速排序练习一
// void QuickSort(int *arr, int begin, int end)
// {
//     if (begin > end)
//     {
//         return;
//     }
//     int tmp = arr[begin]; // 假设数组首元素为基准数
//     int i = begin;
//     int j = end;
//     while (i != j)
//     {
//         while (j > i && tmp <= arr[j])
//         {
//             j--;
//             count++;
//         }
//         while (j > i && tmp >= arr[i])
//         {
//             i++;
//             count++;
//         }
//         if (j > i)
//         {
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
//     arr[begin] = arr[i];
//     arr[i] = tmp;
//     QuickSort(arr, begin, i - 1);
//     QuickSort(arr, i + 1, end);
// }

// // 计数排序
// #include <stdio.h>
// int arr[] = {2, 1, 3, 1, 1, 1, 2, 4, 4, 3, 0};
// const int len = sizeof(arr) / sizeof(arr[0]);
// int main()
// {
//     int count[len + 1];

//     // 打印排序前的数组元素
//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//         // 初始化统计数组的各元素为零
//         count[i] = 0;
//     }
//     printf("\n排序后：");
//     // 统计各数组元素在数组出现的次数
//     for (int i = 0; i < len; i++)
//     {
//         count[arr[i]]++;
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         for (int j = 0; j < count[i]; j++)
//         {
//             printf("%d ", i);
//         }
//     }

//     return 0;
// }

// 计数排序练习一
// #include <stdio.h>

// int main()
// {
//     int arr[] = {2, 2, 1, 1, 8, 9, 0, 3, 3, 4, 4, 9, 0};
//     int count[10] = {0};

//     printf("排序前：");
//     for (int i = 0; i < 13; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n排序后：");
//     for (int i = 0; i < 13; i++)
//     {
//         count[arr[i]]++;
//     }
//     for (int i = 0; i <= 9; i++)
//     {
//         for (int j = 0; j < count[i]; j++)
//         {
//             printf("%d ", i);
//         }
//     }

//     return 0;
// }

// // 直接插入排序练习
// #include <stdio.h>

// int main()
// {
//     int arr[] = {23, 12, 89, 90, 11, 45, 65};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printf("排序前：");
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n排序后：");
//     for (int i = 1; i < len; i++)
//     {
//         int temp = arr[i];
//         int j = 0;
//         for (j = i - 1; j >= 0 && temp < arr[j]; j--)
//         {
//             arr[j + 1] = arr[j];
//         }
//         arr[j + 1] = temp;
//     }
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

// // 快速排序练习一
// #include <stdio.h>

// void QuickSort(int *arr, int begin, int end);

// int main()
// {
//     int arr[] = {34, 56, 76, 88, 90, 11, 22, 31, 34, 56};
//     int begin = 0;
//     int end = sizeof(arr) / sizeof(arr[0]) - 1;

//     printf("排序前：");
//     for (int i = 0; i <= end; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     QuickSort(arr, begin, end);
//     printf("\n排序后：");
//     for (int i = 0; i <= end; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }

// void QuickSort(int *arr, int begin, int end)
// {
//     if (begin > end)
//     {
//         return;
//     }
//     int i = begin;
//     int j = end;
//     int tmp = arr[begin];

//     while (i != j)
//     {
//         while (j > i && tmp <= arr[j])
//         {
//             j--;
//         }
//         while (j > i && tmp >= arr[i])
//         {
//             i++;
//         }
//         if (j > i)
//         {
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
//     arr[begin] = arr[i];
//     arr[i] = tmp;
//     // 左子列
//     QuickSort(arr, begin, i - 1);
//     // 右子列
//     QuickSort(arr, i + 1, end);
// }

// // 寒假选择练习
// #include <stdio.h>

// // Day13 selection1
// int fun(int x)
// {
//     int n = 0;

//     while (x + 1)
//     {
//         n++;
//         x = x | (x + 1);
//     }

//     return n;
// }

// int main()
// {
//     // test1
//     // int w = 1, x = 2, y = 3, z = 4;
//     // int temp = w < x ? w : y < z ? y : z;
//     // printf("temp = %d\n", temp);

//     // // test2
//     // int a = 1, b = 2, m = 0, n = 0, k;
//     // k = (n = b < a) && (m = a);
//     // printf("k = %d, m = %d\n", k, m);

//     // test3
//     // char c = 'A';
//     // if ('0' <= c <= '9')
//     // {
//     //     printf("YES");
//     // }
//     // else{
//     //     printf("NO");
//     // }
//     // printf("\n'0' = %d, 0 = %c\n", '0', 0);

//     // Day12 selection 3
//     // int n = 1001;
//     // int ans = 0;
//     // for (int i = 0; i <= n; i++)
//     // {
//     //     ans^=i % 3;
//     // }
//     // printf("ans = %d\n", ans);

//     // Day13 selection1
//     printf("result = %d\n", fun(2014));

//     return 0;
// }

// // 堆排序练习
// #include <stdio.h>

// // 维护堆的性质
// void Heapify(int *arr, int n, int i);
// // 堆排序入口
// void HeapSort(int *arr, int n);
// // 交换数值
// void Swap(int *num1, int *num2);
// // 打印数组元素
// void Print(int *arr, int len);

// int main()
// {
//     int arr[] = {23, 12, 34, 89, 10, 22, 56, 90};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     printf("排序前：");
//     Print(arr, len);
//     HeapSort(arr, len);
//     printf("\n排序后：");
//     Print(arr, len);

//     return 0;
// }

// void Print(int *arr, int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }

// void Swap(int *num1, int *num2)
// {
//     int temp = *num1;
//     *num1 = *num2;
//     *num2 = temp;
// }

// void Heapify(int *arr, int n, int i)
// {
//     int largest = i;
//     int lson = i * 2 + 1;
//     int rson = i * 2 + 2;

//     if (lson < n && arr[largest] < arr[lson])
//     {
//         largest = lson;
//     }
//     if (rson < n && arr[largest] < arr[rson])
//     {
//         largest = rson;
//     }
//     if (largest != i)
//     {
//         Swap(&arr[largest], &arr[i]);
//         Heapify(arr, n, largest);
//     }
// }

// void HeapSort(int *arr, int n)
// {
//     for (int i = (n - 1) / 2; i >= 0; i--)
//     {
//         Heapify(arr, n, i);
//     }
//     for (int i = n - 1; i > 0; i--)
//     {
//         Swap(&arr[i], &arr[0]);
//         Heapify(arr, i, 0);
//     }
// }

// // 堆排序练习
// #include <stdio.h>

// void Print(int* arr, int n);
// void Swap(int* num1, int* num2);
// void Heapify(int* arr, int n, int i);
// void HeapSort(int* arr, int n);

// int main()
// {
//     int arr[] = {23, 12, 34, 90, 89, 77, 57, 66};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     Print(arr, len);
//     HeapSort(arr, len);
//     Print(arr, len);

//     return 0;
// }

// void Print(int* arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void Swap(int* num1, int* num2)
// {
//     int temp = *num1;
//     *num1 = *num2;
//     *num2 = temp;
// }

// void Heapify(int* arr, int n, int i)
// {
//     int largest = i;
//     int lson = i * 2 + 1;
//     int rson = i * 2 + 2;

//     if (lson < n && arr[largest] < arr[lson])
//     {
//         largest = lson;
//     }
//     if (rson < n && arr[largest] < arr[rson])
//     {
//         largest = rson;
//     }
//     if (i != largest)
//     {
//         Swap(&arr[largest], &arr[i]);
//         Heapify(arr, n, largest);
//     }
// }

// void HeapSort(int* arr, int n)
// {
//     int i = 0;
//     for (i = (n - 1) / 2; i >= 0; i--)
//     {
//         Heapify(arr, n, i);
//     }
//     for (i = n - 1; i > 0; i--)
//     {
//         Swap(&arr[i], &arr[0]);
//         Heapify(arr, i, 0);
//     }
// }

// // 插入排序练习
// #include <stdio.h>

// void Print(int* arr, int n);

// int main()
// {
//     int arr[] = {23, 11, 90, 34, 45, 89, 78};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     Print(arr, len);
//     for (int i = 1; i < len; i++)
//     {
//         int j = 0;
//         int tmp = arr[i];
//         for (j = i - 1; j >= 0 && tmp < arr[j]; j--)
//         {
//             arr[j + 1] = arr[j];
//         }
//         arr[j + 1] = tmp;
//     }
//     Print(arr, len);
// }

// void Print(int* arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// Winter Holiday's homework
// #include <stdio.h>

// int main()
// {
//     // Day11 selection4
//     int k = 1 ^ (1 << 31 >> 31);

//     printf("k = %d\n", k);

//     //
//     int a, *x = &a;
//     return 0;
// }

// // 快速排序练习
// void QuickSort(int *arr, int begin, int end);

// int main()
// {
//     int arr[] = {23, 11, 90, 89, 12, 78, 33, 22};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     int begin = 0;
//     int end = len;
//     Print(arr, len);
//     QuickSort(arr, begin, end);
//     Print(arr, len);

//     return 0;
// }

// void QuickSort(int *arr, int begin, int end)
// {
//     if (begin >= end)
//     {
//         return;
//     }
//     int left = begin;
//     int right = end;
//     int key = arr[begin];

//     while (left != right)
//     {
//         while (left < right && arr[right] >= key)
//         {
//             right--;
//         }
//         while (left < right && arr[left] <= key)
//         {
//             left++;
//         }
//         if (left < right)
//         {
//             int tmp = arr[left];
//             arr[left] = arr[right];
//             arr[right] = tmp;
//         }
//     }
//     arr[begin] = arr[left];
//     arr[left] = key;
//     QuickSort(arr, begin, left - 1);
//     QuickSort(arr, left + 1, end);
// }

// // 堆排序
// #include <stdio.h>

// void Print(int *arr, int len);
// void Heapify(int *arr, int n, int i);
// void HeapSort(int *arr, int n);
// void Swap(int *num1, int *num2);

// int main()
// {
//     int arr[] = {12, 23, 11, 90, 99, 87, 88, 77};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     Print(arr, len);
//     HeapSort(arr, len);
//     Print(arr, len);

//     return 0;
// }

// void Print(int *arr, int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void Swap(int *num1, int *num2)
// {
//     *num1 = *num1 - *num2;
//     *num2 = *num1 + *num2;
//     *num1 = *num2 - *num1;
// }

// void Heapify(int *arr, int n, int i)
// {

//     int lson = i * 2 + 1;
//     int rson = i * 2 + 2;
//     int largest = i;

//     if (arr[largest] <= arr[lson] && lson < n)
//     {
//         largest = lson;
//     }
//     if (arr[largest] <= arr[rson] && rson < n)
//     {
//         largest = rson;
//     }
//     if (i != largest)
//     {
//     Swap(&arr[largest], &arr[i]);
//     Heapify(arr, n, largest);
//     }
// }

// void HeapSort(int* arr, int n)
// {
//     for (int i = (n - 1) / 2; i >= 0; i--)
//     {
//         Heapify(arr, n, i);
//     }
//     for (int i = n - 1; i > 0; i--)
//     {
//         Swap(&arr[i], &arr[0]);
//         Heapify(arr, i - 1, 0);
//     }
// }

// // 十进制转二进制
// #include <stdio.h>
// #include <limits.h>

// char* itobs(int, char*);
// void show_bstr(const char*);

// int main()
// {
//     char bin_str[CHAR_BIT * sizeof(int) + 1];
//     int number = 0;

//     puts("Enter integers and see them in binary");
//     puts(".Non-numric input terminates program.");

//     while (scanf("%d", &number) == 1)
//     {
//         itobs(number, bin_str);
//         printf("%d is ", number);
//         show_bstr(bin_str);
//         putchar('\n');
//     }

//     return 0;
// }

// char* itobs(int n, char* ps)
// {
//     int i = 0;

//     const static int size = CHAR_BIT * sizeof(int);
//     for (int i = size - 1; i >= 0; i--, n >>= 1)
//     {
//         ps[i] = (01 & n) + '0';

//     }
//     ps[size] = '\0';
//     return ps;
// }
// void show_bstr(const char* str)
// {
//     int i =  0;

//     while (str[i])
//     {
//         putchar(str[i]);
//         if (++i % 4 == 0 && str[i])
//         {
//             putchar(' ');
//         }
//     }
// }

// C11对齐特性
// #include <stdio.h>
// #include <limits.h>
// #include <stdalign.h>
// #include <stdlib.h>
// #include <stdbool.h>

// int main()
// {
//     // printf("CHAR_BIBT = %d\n", CHAR_BIT);
//     // printf("sizeof(int) = %d\n", sizeof(int));
//     // printf("sizeof(int) * CHAR_BIT = %d\n", sizeof(int) * CHAR_BIT);

//     // C11对齐特性
//     double dx;
//     double dy;
//     double da;
//     double db;
//     float fa;
//     float fb;
//     float fc;
//     char  ca;
//     char alignas(double) cx;
//     char alignas(double) cb;
//     char alignas(double) cz;

//     // 观察double的对齐值情况
//     // printf("&dx: %p\n", &dx);
//     // printf("&dy: %p\n", &dy);
//     // printf("&da: %p\n", &da);
//     // printf("&db: %p\n", &db);

//     // 观察float的对齐值情况
//     // printf("&fa: %p\n", &fa);
//     // printf("&fb: %p\n", &fb);
//     // printf("&fc: %p\n", &fc);

//     // 观察char的对齐值情况
//     // printf("&ca: %p\n", &ca);
//     // printf("&cx: %p\n", &cx);
//     // printf("&cb: %p\n", &cb);

//     printf("&cz: %p\n", &cz);
//     printf("&ca: %p\n", &ca);
//     printf("&cx: %p\n", &cx);
//     printf("&cb: %p\n", &cb);

//     return 0;
// }

// // 快速排序练习
// #include <stdio.h>

// void Print(int* arr, int len);
// void Swap(int* num1, int* num2);
// void QuickSort(int* arr, int begin, int end);

// int main()
// {
//     int arr[] = {23, 11, 90, 89, 78, 67};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     int begin = 0;
//     int end = len - 1;

//     Print(arr, len);
//     QuickSort(arr, begin, end);
//     Print(arr, len);

// }

// void Print(int* arr, int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void Swap(int* num1, int* num2)
// {
//     *num1 = *num1 - *num2;
//     *num2 = *num1 + *num2;
//     *num1 = *num2 - *num1;
// }

// void QuickSort(int* arr, int begin, int end)
// {
//     if (begin >= end)
//     {
//         return;
//     }
//     int left = begin;
//     int right = end;
//     int key = arr[begin];

//     while (left != right)
//     {
//         while (left < right && key <= arr[right])
//         {
//             right--;
//         }
//         while (left < right && key >= arr[left])
//         {
//             left++;
//         }
//         if (left < right)
//         {
//             int temp = arr[left];
//             arr[left] = arr[right];
//             arr[right] = temp;
//         }
//     }
//     arr[begin] = arr[left];
//     arr[left] = key;
//     QuickSort(arr, begin, left - 1);
//     QuickSort(arr, left + 1, end);
// }

// // 堆排序练习
// #include <stdio.h>

// void Print(int *arr, int len);
// void Swap(int *num1, int *num2);
// void Heapify(int *arr, int n, int i);
// void HeapSort(int *arr, int n);

// int main()
// {
//     int arr[] = {23, 11, 90, 89, 78, 12, 13, 34};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     Print(arr, len);
//     HeapSort(arr, len);
//     Print(arr, len);

//     return 0;
// }

// void Print(int *arr, int len)
// {
//     for (int i = 0; i < len; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// void Swap(int *num1, int *num2)
// {
//     int temp = *num1;
//     *num1 = *num2;
//     *num2 = temp;
// }

// void Heapify(int *arr, int n, int i)
// {
//     int lson = i * 2 + 1;
//     int rson = i * 2 + 2;
//     int largest = i;

//     if (lson < n && arr[largest] < arr[lson])
//     {
//         largest = lson;
//     }
//     if (rson < n && arr[largest] < arr[rson])
//     {
//         largest = rson;
//     }
//     if (largest != i)
//     {
//         Swap(&arr[largest], &arr[i]);
//         Heapify(arr, n, largest);
//     }
// }

// void HeapSort(int *arr, int n)
// {
//     for (int i = (n - 1) / 2; i >= 0; i--)
//     {
//         Heapify(arr, n, i);
//     }
//     for (int i = n - 1; i > 0; i--)
//     {
//         Swap(&arr[i], &arr[0]);
//         Heapify(arr, i, 0);
//     }
// }

// 桶排序
// #include <stdio.h>
// int main()
// {
//     int book[1001], i, j, t, n;

//     // 初始化桶数组
//     for (i = 0; i <= 1000; i++)
//     {
//         book[i] = 0;
//     }
//     // 输入一个数n，表示接下来有n个数
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++)
//     {
//         // 把每一个数读到变量中去
//         scanf("%d", &t);
//         // 计数
//         book[t]++;
//     }
//     // 从大到小输出
//     for (i = 1000; i >= 0; i--)
//     {
//         for (j = 1; j <= book[i]; j++)
//         {
//             printf("%d ", i);
//         }
//     }
//     getchar();
//     // getchar()用来暂停程序，以便查看程序输出的内容
//     // 也可以用system("pause");来代替
//     return 0;
// }

// 希尔排序练习

// int main()
// {
//     int arr[] = {23, 11, 89, 56, 34, 22, 90};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     Print(arr, len);
//     for (int inc = len / 2; inc > 0; inc /= 2)
//     {
//         for (int i = inc; i < len; i++)
//         {
//             int j = 0;
//             int tmp = arr[i];
//             for (j = i; j >= inc && tmp < arr[j - inc]; j -= inc)
//             {
//                 arr[j] = arr[j - inc];
//             }
//             arr[j] = tmp;
//         }
//     }
//     Print(arr, len);

//     return 0;
// }

// // 字符串11.1.1的练习
// #include <string.h>

// int main()
// {
//     char str[] = "abc";

//     printf("\n*(\"abc\") = %c", *("abc"));
//     printf("\n( &str  + 2 ) = %p\n        str = %p\n", &str + 2, str);

//     printf("sizeof(str) = %d\n", sizeof(str));
//     printf("strlen(str) = %d\n", strlen(str));

//     printf("    *(\"abc\") = %p\n&(*(\"abc\")) = %p, *(\"abc\" + 1) = %c, *(\"abc\" + 2) = %c",
//            "abc", &(*("abc")), *("abc" + 1), *("abc" + 2));

//     return 0;
// }

// int main()
// {
//     char *pt1 = "abc";
//     char arr[] = "abc";

//     *(pt1 + 1) = 'd';
//     printf("%s\n%s\n", pt1, arr);

//     return 0;
// }

// // 希尔排序练习
// void ShellSort(int* arr, int len);

// int main()
// {
//     int arr[] = {23, 10, 89, 90, 99, 40, 50};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     Print(arr, len);
//     ShellSort(arr, len);
//     Print(arr, len);

//     return 0;
// }

// void ShellSort(int* arr, int len)
// {
//     for (int inc = len / 2; inc > 0; inc /= 2)
//     {
//         for (int i = inc; i < len; i++)
//         {
//             int j = 0;
//             int tmp = arr[i];
//             for (j = i; j >= inc && tmp < arr[j - inc]; j -= inc)
//             {
//                 arr[j] = arr[j - inc];
//             }
//             arr[j] = tmp;
//         }
//     }
// }

// // 数据有效位数的检验
// int main()
// {
//     printf("sizeof(int) = %d\n", sizeof(int));
//     printf("sizeof(short) = %d\n", sizeof(short));
//     printf("sizeof(long) = %d\n", sizeof(long));
//     printf("sizeof(long long) = %d\n", sizeof(long long));

//     // 有效位数7位
//     float f0 = 2.12345;
//     float f1 = 2.123456;
//     float f2 = 2.1234567;
//     printf("f1 = %f\n", f0);
//     printf("f1 = %f\n", f1);
//     printf("f1 = %f\n", f2);

//     double d0 = 2.1234567;
//     double d1 = 2.123456;
//     double d2 = 2.12345;

//     printf("\nd0 = %lf\n", d0);
//     printf("d0 = %lf\n", d1);
//     printf("d0 = %lf\n", d2);

//     return 0;
// }

// // 选择排序练习
// int main()
// {
//     int arr[] = {23, 11, 89, 67, 45, 22, 34};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     Print(arr, len);
//     for (int i = 0; i < len; i++)
//     {
//         int j = 0;
//         for (j = i + 1; j < len; j++)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int tmp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = tmp;
//             }
//         }
//     }
//     Print(arr, len);

//     return 0;
// }

// // 直接插入排序练习
// int main()
// {
//     int arr[] = {23, 11, 89, 56, 70, 67, 33};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     Print(arr,len);
//     for (int i = 1; i < len; i++)
//     {
//         int j = 0;
//         int tmp = arr[i];
//         for (j = i - 1; j >= 0 && tmp < arr[j]; j--)
//         {
//             arr[j + 1] = arr[j];
//         }
//         arr[j + 1] = tmp;
//     }
//     Print(arr, len);

//     return 0;
// }

// // 计数排序练习
// int main()
// {
//     int arr[] = {1, 2, 3, 1, 1, 0, 0, 8, 3, 3, 3, 4, 5};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     int count[13] = {0};
//     printf("len = %d\n", len);
//     Print(arr, len);
//     for (int i = 0; i < len; i++)
//     {
//         count[arr[i]]++;
//     }
//     for (int i = 0; i < len; i++)
//     {
//         for (int j = 0; j < count[i]; j++)
//         {
//             printf("%d ", i);
//         }
//     }

//     return 0;
// }

// // 希尔排序
// #include <string.h>

// int main()
// {
//     int arr[] = {23, 11, 89, 78, 90, 34, 21, 10};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     Print(arr, len);
//     for (int inc = len / 3 + 1; inc > 0; inc /= 3)
//     {
//         for (int i = inc; i < len; i++)
//         {
//             int tmp = arr[i];
//             int j = 0;
//             for (j = i; j >= inc && tmp < arr[j - inc]; j -= inc)
//             {
//                 arr[j] = arr[j - inc];
//             }
//             arr[j] = tmp;
//         }
//     }
//     Print(arr, len);

//     return 0;
// }

// // 字符串函数练习
// #define STR "abcdef"
// #define N 6
// #define M N + 75
// int main()
// {
//     // 输入输出
//     char str[N];
//     puts("Enter a string:");
// gets(str);
// puts(str);

// 验证gets函数的返回值
// char *ch = gets(str);
// // 字符串的首字符的地址
// printf("字符串中的首字符的地址：\n");
// printf("    gets(str) = %p\n", ch);
// printf("          str = %p\n\n", str);

// // 字符串中个字符的地址
// printf("字符串中各字符的地址：\n");
// printf("&(*(str))     = %p\n", &(*(str)));
// printf("&(*(str + 1)) = %p\n", &(*(str + 1)));
// printf("&(*(str + 2)) = %p\n\n", &(*(str + 2)));

// printf("          str = %p\n", str);
// printf("      str + 1 = %p\n", str + 1);
// printf("      str + 2 = %p\n\n", str + 2);

// printf("           ch = %p\n", ch);
// printf("       ch + 1 = %p\n", ch + 1);
// printf("       ch + 2 = %p\n", ch + 2);

// // 验证fgets函数的返回值
// char *ch = fgets(str, 4, stdin);
// fputs(str, stdout);

// // 字符串的首字符地址
// printf("字符串中的首字符地址：\n");
// printf(" ch = %p\n", ch);
// printf("str = %p\n", str);

// // 字符串中各字符的地址
// printf("字符串中各字符的地址：\n");
// printf("&(*(str))     = %p\n", &(*(str)));
// printf("&(*(str + 1)) = %p\n", &(*(str + 1)));
// printf("&(*(str + 2)) = %p\n\n", &(*(str + 2)));

// printf("          str = %p\n", str);
// printf("      str + 1 = %p\n", str + 1);
// printf("      str + 2 = %p\n\n", str + 2);

// printf("           ch = %p\n", ch);
// printf("       ch + 1 = %p\n", ch + 1);
// printf("       ch + 2 = %p\n", ch + 2);

// 验证fgets_s函数的返回值
//     char *ch = gets_s(str, 4);
//     fputs(str, stdout);

//     // 字符串的首字符地址
//     printf("\n字符串中的首字符地址：\n");
//     printf(" ch = %p\n", ch);
//     printf("str = %p\n", str);

//     // 字符串中各字符的地址
//     printf("字符串中各字符的地址：\n");
//     printf("&(*(str))     = %p\n", &(*(str)));
//     printf("&(*(str + 1)) = %p\n", &(*(str + 1)));
//     printf("&(*(str + 2)) = %p\n\n", &(*(str + 2)));

//     printf("          str = %p\n", str);
//     printf("      str + 1 = %p\n", str + 1);
//     printf("      str + 2 = %p\n\n", str + 2);

//     printf("           ch = %p\n", ch);
//     printf("       ch + 1 = %p\n", ch + 1);
//     printf("       ch + 2 = %p\n", ch + 2);

//     return 0;
// }

// // winter_homework_day1
// int main()
// {
//     int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int len = sizeof(mon) / sizeof(mon[0]);
//     int year = 0;
//     int month = 0;
//     int day = 0;

//     while (3 == scanf("%d %d %d", &year, &month, &day))
//     {
//         int sum = 0;

//         for (int i = 0; i < month; i++)
//         {
//             sum += mon[i];
//         }
//         if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
//         {
//             if (month >= 3)
//             {
//                 sum++;
//             }
//         }
//         printf("%d\n", sum + day);
//     }

//     return 0;
// }

// // 验证尼科彻斯定理
// int main()
// {
//     int n = 0;

//     while (1 == scanf("%d", &n))
//     {
//         int tmp = (n * n) - (n - 1);
//         for (int i = 0; i < n; i++)
//         {
//             printf("%d", tmp);
//             tmp += 2;
//             if (i < (n - 1) && n != 1)
//             {
//                 printf("+");
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }

// 求首项为2，公差为3的等差数列的前n项和

// int main()
// {
//     int n = 0;

//     while (1 == scanf("%d", &n))
//     {
//         printf("%d\n", n * (n * 3 + 1) / 2);
//     }

//     return 0;
// }

// 记负均正

// int main()
// {
//     // 记录所有整数的个数
//     int count = 0;

//     // 实现多组输入
//     while (1 == scanf("%d", &count))
//     {
//         // 清空缓冲区的内容
//         while (getchar() != '\n')
//         {
//             continue;
//         }
//         // 存储每次输入的整数
//         int num = 0;
//         // 记录所有整数的求和
//         int sum = 0;
//         // 记录负整数的个数
//         int nega = 0;
//         // 记录零出现的次数
//         int zero = 0;
//         for (int i = 1; i <= count; i++)
//         {
//             scanf("%d", &num);
//             // 记录负整数的总个数
//             if (num < 0)
//             {
//                 nega++;
//             }
//             // 求所有正整数的总和
//             else if (num > 0)
//             {
//                 sum += num;
//             }
//             // 当出现零的时候，zero加1
//             else if (0 == num)
//             {
//                 zero++;
//             }
//         }
//         while ((getchar()) != '\n')
//         {
//             continue;
//         }
//         float quotient = 0.0;
//         if ((0 == (count - nega - zero)))
//         {
//             float quotient = 0.0;
//         }
//         else
//         {
//             quotient = (sum / (float)(count - nega - zero));
//         }
//         printf("%d %.1f\n", nega, quotient);
//     }
// }

// int main()
// {
//     // int a = 0;
//     // int b = 1;
//     // printf("a + b = %d\n", a + b);

//     int c = 2;
//     printf("%d\n", c + --c);
//     return 0;
// }

// void test(int *restrict num1, int *restrict num2)
// {
//     *num1 = 2;
//     *num2 = 3;
// }

// int main()
// {
//     int num1 = 1;
//     int num2 = 0;
//     printf("num1 = %d, num2 = %d\n", num1, num2);
//     test(&num1, &num2);
//     printf("num1 = %d, num2 = %d\n", num1, num2);

//     return 0;
// }

// int test()
// {
//     return 1.2;
// }

// int main()
// {
//     printf("%d\n", test());

//     return 0;
// }

// int main()
// {
//     int a = 5, b = 0, c = 0;
//     c = ++a;
//     b = ++c, c++, ++a, a++;
//     b += a++ + c;

//     printf("a = %d, b = %d, c = %d\n", a, b, c);

//     return 0;
// }

// 不使用临时变量，交换两个值
// int main()
// {
//     int a = 2;
//     int b = 3;
//     printf("交换前：a = %d, b = %d\n", a, b);
//     // 方法一
//     // a = a - b;
//     // b = a + b;
//     // a = b - a;
//     // 方法二
//     a ^= b;
//     b ^= a;
//     a ^= b;
//     printf("交换后：a = %d, b = %d\n", a, b);

//     return 0;
// }

// #include <limits.h>

// int NumberOf1(int n)
// {
//     int count = 0;
//     int size = CHAR_BIT * sizeof(int);

//     for (int i = size - 1; i >= 0; i--, n >>= 1)
//     {
//         if (01 & n)
//         {
//             count++;
//         }
//     }
//     return (count);
// }

// int main()
// {
//     int num = 0;

//     while (~scanf("%d", &num))
//     {

//         printf("%d\n", NumberOf1(num));
//     }

//     return 0;
// }

// // 假设输入是负数，陷入死循环
// int Result(int num1, int num2)
// {
//     int count = 0;
//     // 两数中的最小数的有效比特位数
//     int max = 0;

//     // 保证num1存储的是两数的最大值
//     if (num1 < num2)
//     {
//         int temp = num1;
//         num1 = num2;
//         num2 = temp;
//     }
//     int n = num1;
//     while (n)
//     {
//         max++;
//         n >>= 1;
//     }
//     // 此时max是循环的最大次数
//     printf("max = %d\n", max);
//     for (int i = 0; i <= max; i++)
//     {
//         if ((num1 & 1) != (num2 & 1))
//         {
//             count++;
//         }
//         num1 >>= 1;
//         num2 >>= 1;
//     }
//     printf("count = %d\n", count);

//     return (count);
// }

// int main()
// {
//     int num1 = 0, num2 = 0;

//     while (2 == scanf("%d %d", &num1, &num2))
//     {
//         printf("%d\n", Result(num1, num2));
//     }

//     return 0;
// }

// 题目5
// int Result(int n)
// {
//     int tmp = n;
//     int count = 0;
//     int one = 0;
//     int zero = 0;

//     while (n)
//     {
//         count++;
//         n >>= 1;
//     }
//     while (count)
//     {
//         if (n & 1)
//         {
//             one++;
//         }
//         else
//         {
//             zero++;
//         }
//         count--;
//     }
//     for (int i = 0; i < one; i++)
//     {
//         printf("1");
//     }
//     printf(" ");
//     for (int i = 0; i < zero; i++)
//     {
//         printf("0");
//     }
// }
// int main()
// {
//     int num = 0;

//     while (1 == scanf("%d", &num))
//     {
//         Result(num);
//         printf("\n");
//     }

//     return 0;
// }

// #include <stdio.h>

// int Num(int num1, int num2);

// int main()
// {
//     int num1 = 0;
//     int num2 = 0;

//     while (2 == scanf("%d %d", &num1, &num2))
//     {
//         printf("%d\n", Num(num1, num2));
//     }

//     return 0;
// }

// int Num(int num1, int num2)
// {
//     int tmp = num1 ^ num2;
//     int count = 0;

//     while (tmp)
//     {
//         if (tmp & 1)
//         {
//             count++;
//         }
//         tmp >>= 1;
//     }

//     return (count);
// }

// // 插入排序练习
// int main()
// {
//     int arr[] = {23, 11, 90, 78, 34, 56, 22};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     Print(arr, len);
//     for (int i = 1; i < len; i++)
//     {
//         int j = 0;
//         int tmp = arr[i];
//         for (j = i - 1; j >= 0 && tmp < arr[j]; j--)
//         {
//             arr[j + 1] = arr[j];
//         }
//         arr[j + 1] = tmp;
//     }
//     Print(arr, len);

//     return 0;
// }

// // 打印菱形图案
// int main()
// {
//     int line = 0;

//     while (1 == scanf("%d", &line))
//     {
//         // 打印上三角形
//         for (int i = 0; i < line; i++)
//         {
//             // 打印空格
//             for (int j = 0; j < line - i - 1; j++)
//             {
//                 printf(" ");
//             }
//             // 打印字符*
//             for (int j = 0; j < 2 * i + 1; j++)
//             {
//                 printf("*");
//             }
//             printf("\n");
//         }
//         // 打印下三角形
//         for (int i = 0; i < line - 1; i++)
//         {
//             // 打印空格
//             for (int j = 0; j <= i; j++)
//             {
//                 printf(" ");
//             }
//             // 打印字符
//             for (int j = 0; j < 2 * (line - i - 1) - 1; j++)
//             {
//                 printf("*");
//             }
//             printf("\n");
//         }
//     }

//     return 0;
// }

// int main()
// {
//     int a[] = {23, 12, 11, 88, 90, 45};
//     int *pa = a;

//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", i[pa]);
//     }
// }

// #include <stdio.h>

// struct S
// {
//     int a;
//     int b;
// };

// int main()
// {
//     struct S a, *p = &a;
//     a.a = 99;
//     printf("%d\n", *p.a);
//     printf("%d\n", (*p).a);
// }

// // 模拟strlen函数
// #include <stdio.h>
// int my_strlen(char* str);

// int main()
// {
//     char str[24] = { 0 };

//     scanf("%s", str);
//     printf("%d\n", my_strlen(str));

//     return 0;
// }

// int my_strlen(char* str)
// {
//     char* start = str;

//     while (*str++);

//     return (str - start - 1);
// }

// // 模拟strcpy函数
// #include <stdio.h>

// char* my_strcpy(char* dest, const char* src);

// int main()
// {
//     char str[23] = {0};
//     char src[] = "abc";

//     printf("%s\n", my_strcpy(str, src));

//     return 0;
// }

// char* my_strcpy(char* dest, const char* src)
// {
//     char* start = dest;

//     while (*dest++ = *src++);

//     return start;
// }

// // 希尔排序练习
// int main()
// {
//     int arr[] = {23, 12, 11, 90, 89, 45};
//     int len = sizeof(arr) / sizeof(arr[0]);

//     Print(arr, len);
//     for (int inc = len / 3 + 1; inc > 0; inc /= 3)
//     {
//         for (int i = inc; i < len; i++)
//         {
//             int tmp = arr[i];
//             int j = 0;
//             for (j = i; j >= inc && tmp < arr[j - inc]; j -= inc)
//             {
//                 arr[j] = arr[j - inc];
//             }
//             arr[j] = tmp;
//         }
//     }
//     Print(arr, len);
// }

// // 直接插入排序练习
// int main()
// {
//     int arr[] = {23, 11, 99, 78, 33, 45,22};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     Print(arr, len);
//     for (int i = 1; i < len; i++)
//     {
//         int tmp = arr[i];
//         int j = 0;
//         for (j = i; j >= 0 && tmp < arr[j - 1]; j--)
//         {
//             arr[j] = arr[j - 1];
//         }
//         arr[j] = tmp;
//     }
//     Print(arr, len);

// }

// float类型的大小
// int main()
// {
//     printf("sizeof(float) = %d\n", sizeof(float));
//     printf("sizeof(double) = %d\n", sizeof(double));
//     printf("%f\n", 2.1234);
//     printf("%f\n", 2.12345);
//     printf("%f\n", 2.123456);
//     printf("%lf\n", 2.1234567);
//     return 0;
// }

// // 选择排序（升序）
// int main()
// {
//     int arr[] = {23, 11, 98, 10, 22, 34, 76};
//     int len = sizeof (arr) / sizeof (arr[0]);
//     Print(arr, len);
//     for (int i = 0; i < len; i++)
//     {
//         for (int j = i + 1; j < len; j++)
//         {
//             if (arr[j] < arr[i])
//             {
//                 int tmp = arr[j];
//                 arr[j] = arr[i];
//                 arr[i] = tmp;
//             }
//         }
//     }
//     Print(arr, len);

//     return 0;
// }

int main()
{
    printf("基础功能\n");
    printf("短视频\n");
    printf("约饭（修复bug）\n");

    return 0;
}
