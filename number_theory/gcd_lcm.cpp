typedef long long ll;

ll gcd(ll num, ll num2) {
    ll tmp;
    while (num2) {
        tmp = num2;
        num2 = num % num2;
        num = tmp;
    }
    return num;
}

ll lcm(ll num, ll num2) {
    return num / gcd(num, num2) * num2;
}
