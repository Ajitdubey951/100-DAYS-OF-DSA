int maxProfit(int *prices, int pricesSize)
{
    if (pricesSize <= 1)
    {
        return 0;
    }

    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < min_price)
        {
            min_price = prices[i];
        }
        else if (prices[i] - min_price > max_profit)
        {
            max_profit = prices[i] - min_price;
        }
    }

    return max_profit;
}