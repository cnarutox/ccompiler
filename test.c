// int main()
// {
//     int i = 10 * 1;
//     for (i = 0; i < 3; i = i + 1) {
//         print(i);
//     }
//     while(i > 0) {
//         print(i);
//         i = i - 1;
//     }
//     if (i < 9){
//         print(99);
//     }
//     else {
//         print(88);
//     }
//     return i;
// }
int func(int i)
{
    while(i > 0){
      i = i - 1;
      print(i);
    }
    return 0;
}

int main()
{
    int j = 5;
    func(j);
    // do
    // {
    //     j = j - 1;
    //     print(j);
    // } while (j > 0);
    return 0;
}

// int main(){
// int a[3];
// a[0] = 5;
// print(a[0]);
// return 0;
// }