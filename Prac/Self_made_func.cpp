#include <string.h>
#include <string>

using namespace std;

int Strcmp_equal(char *s1, char *s2){
    int len1, len2;

    len1 = strlen(s1);
    len2 = strlen(s2);

    if(len1 != len2){
        return 0;
    }

    for(int i = 0; i < len1; i++){
        if(s1[i] != s2[i]){
            return 0;
        }
    }

    return 1;
}

void ToUpper(char *s){
    for(int i = 0; i < strlen(s); i++){
        if(s[i] >= 97){
            s[i] -= 32;
        }
    }
}

int Power(int n, int k){
    int rtn = 1;

    for(int i = 0; i < k; i++){
        rtn *= n;
    }

    return rtn;
}

int Str2Int(char *s){
    int rtn = 0;
    int len = (int)strlen(s);

    for(int i = len; i > 0; i--){
        rtn += Power(10, i - 1) * (s[len - i] - 48);
    }

    return rtn;
}

string CString(const char *s){
    string str = s;
    return s;
}

void Substr(const char *src, char *dst, int st, int end){
    for(int i = st, j = 0; i <= end; i++, j++){
        dst[j] = src[i];
    }
    dst[end + 1] = '\0';
}

int GCD(int a, int b){
    int t;

    if(a < b){
        t = a;
        a = b;
        b = t;
    }

    while(a % b){
        t = a % b;
        a = b;
        b = t;
    }

    return b;
}

int IsPrime(long long int n){
    if(n < 2){
        return 0;
    }
    else if(n == 2 || n == 3){
        return 1;
    }
    else if(n % 2 == 0 || n % 3 == 0){
        return 0;
    }
    for(long long int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int BinarySearch(const int *arr, int len, int tgt){
    int st, mid;

    st = 0;
    len--;

    while(st <= len){
        mid = (st + len) / 2;

        if(arr[mid] == tgt){
            return mid;
        }
        else if(arr[mid] < tgt){
            st = mid + 1;
        }
        else{
            len = mid - 1;
        }
    }

    return -1;
}

int Cmp(const void *x, const void *y){
    int a = *(int*)x;
    int b = *(int*)y;

    if(a > b){
        return 1;
    }
    else if(a < b){
        return -1;
    }
    else{
        return 0;
    }
}