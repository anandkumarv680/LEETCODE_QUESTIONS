int findTheWinner(int n, int k) {

    if (n == 1)
        return 1;

    int winner = findTheWinner(n - 1, k);
    return (winner + k - 1) % n + 1;
}
