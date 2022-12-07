#include <stdio.h>
#include <stdlib.h>
void plotPointsInBoardOf80per24(int pointsX[], int pointsY[], int length);

int main(int argc, char **argv) {

    int x[] = {2, 1, 10, 20, 60, 17};
    int y[] = {4, 1,20,3,5,8};
    int len = (int) (sizeof(x)/sizeof(* x));
    // https://stackoverflow.com/a/25680141/8567062

    plotPointsInBoardOf80per24(x,y,len);
}

/**
 * This function prints a board of 80x24 and prints the points inside
 * @param pointsX
 * @param pointsY
 * @param length
 */
void plotPointsInBoardOf80per24(int pointsX[], int pointsY[], int length) {

    const int LIMIT_X = 23;
    const int LIMIT_Y = 79;

    // Define limit to simplify things
    int *inverse_y = malloc(sizeof(int) * (length + 1));

    for (int k = 0; k < length; k++)
    {
        inverse_y[k] = LIMIT_X - pointsY[k] + 1;
        // printf("(%d,%d)", pointsX[k], inverse_y[k]); // Just o make sure that everything is ok
    }

    // At this point you have your array clean and inverse
    int counterTemp = 0;
    int isPlotable = 0;

    printf("(y)\n");
    for (int i = 0; i <= LIMIT_X; i++) // Y
    {
        printf("%2d ", LIMIT_X + 1 - i);
        for (int j = 0; j <= LIMIT_Y; j++) // X
        {

            for (int k = 0; k < length; k++) {
                if (pointsX[k] - 1 == j && inverse_y[k] == i) {
                    printf("*");
                    isPlotable = 1;
                    counterTemp++;
                }
            }

            if (isPlotable == 0) {
                printf("_");
            }

            isPlotable = 0;

            if (i == LIMIT_X && j == LIMIT_Y) {
                printf(" > (x)");
            }
        }
        
        printf("\n");
    }

    printf("   ");
    for (int i = 0; i <= LIMIT_Y; ++i) {
        if ((i + 1) % 2 == 0) {
            if (i+1 < 10) {
                printf("%2d", i + 1);
            }
            else {
                printf("%2d", i + 1);
            }
        }
    }
    printf("\n");

    free(inverse_y);
}