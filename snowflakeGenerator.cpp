#include <iostream>

void displayStar(bool** star,int length)
{
    for(int j = 0; j < length;j++)
    {
        for(int i = 0; i < length;i++)
        {
            if (star[i][j])
                std::cout<< "*";
            else
                std::cout<< " ";

        }
        std::cout<<std::endl;
    }

}



bool** setupStar(int length)
{
    bool **star = new bool*[length];



    for(int i=0;i<length;i++)
    {
        star[i]=new bool[length];
        for(int j=0;j<length;j++)
        {
            if (i == j || j == length/2 || i+j == length - 1)
            {
                star[i][j] = true;
                //1. right diagonal
                //2. left diagonal
                //3.horizontal line
            }
            else
                star[i][j] = false;

            int counter = 0;
            for (int p = 9; p <= length; p += 2,counter++)
            {
                if ((p+1) % 4 != 0)
                {
                    int small = 1 + counter;
                    int med = 2 + counter;
                    int large = 3 + counter;
                    if (i == length - med && j == length - large)
                    {
                        star[i][j] = true;
                    }
                    else if (i == length - large && j == length - med)
                    {
                        star[i][j] = true;
                    }
                    else if (i == small && j == med)
                    {
                        star[i][j] = true;
                    }
                    else if (i == med && j == small)
                    {
                        star[i][j] = true;
                    }
                    else if (i == med && j == length - med)
                    {
                        star[i][j] = true;
                    }
                    else if (i == length - med && j == med)
                    {
                        star[i][j] = true;
                    }
                    else if (i == small && j == length - large)
                    {
                        star[i][j] = true;
                    }
                    else if (i == length - large && j == small)
                    {
                        star[i][j] = true;
                    }
                }
            }
        }
    }
    return star;
}

void destroyStar(bool** star,int length)
{
    for(int i=0;i<length;i++)
        delete [] star[i];
    delete [] star;
}

//int MIN_STARS = 9;
//int MAX_STARS = 25;


int main()
{
    /*for(int k = MIN_STARS; k <= MAX_STARS; k += 2)
    {
         bool** ptr = setupStar(k);

         displayStar(ptr,k);
        std::cout<< std::endl<<std::endl;
        destroyStar(ptr,k);
    }*/
    int starsize;
     std::cout<< "Snowflake Generator\n";
    std::cout<< "How big snowflake do you want to make? (Recommended size at least 5 and no greater than 25)";
    std::cin >> starsize;

    bool** ptr = setupStar(starsize);
    displayStar(ptr,starsize);
    destroyStar(ptr,starsize);

    return 0;
}
