#include <vector>

using std::vector;

int KnapsackAlgorith(vector<int> elementValues, vector<int> elementWeights, int maxWeight)
{
    int value1 = 0, value2 = 0, value = 0;
    // Init our Dynamic Programming matrix of solutions.
    vector<vector<int>> optimalValues(elementValues.size() + 1, vector<int>(maxWeight + 1));

    // Fill our matrix.
    for (int item = 0; item < elementValues.size() + 1; item++) // current item will be i - 1, due to filling the first row and column with ceros.
    {
        for (int weightValue = 0; weightValue < maxWeight; weightValue++) // Iterate through each sub-problem max weight.
        {
            if (item == 0 || weightValue == 0) // Fill with cero for item 0 and weight 0.
            {
                optimalValues[item][weightValue] = 0;
            } if (elementWeights[item - 1] <= weightValue) // If our item fits, see if we use only its value or its value with the last item's value.
            {
                value1 = optimalValues[item - 1][weightValue];
                value2 = elementValues[item - 1] + optimalValues[item - 1][weightValue - elementWeights[item - 1]];
                if (value1 >= value2)
                {
                    optimalValues[item][weightValue] = value1;
                }
                else
                {
                    optimalValues[item][weightValue] = value2;
                }
            }
            else // If item has a bigger weight than our current sub-problem max weight, we use the value of the last item in that weight.
            {
                optimalValues[item][weightValue] = optimalValues[item - 1][weightValue];
            }
            // Update our max value.
            if (optimalValues[item][weightValue] >= value)
            {
                value = optimalValues[item][weightValue];
            }
        }
    }
    return value;
}