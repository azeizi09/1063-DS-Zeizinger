/**
* @ProgramName: Program-1
* @Author: Alexander Zeizinger
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 02 06 2017
*/
/**

* TXT Image Manipulation Starter

* 

* This code is a simple way to read in color information stored in a space

* delimited txt format. The expected file format is:

*                ---------------------------

*                | width height            |

*                | R G B R G B R G B R G B |

*                | R G B R G B R G B R G B |

*                | R G B R G B R G B R G B |

*                | R G B R G B R G B R G B |

*                | R G B R G B R G B R G B |

*                | R G B R G B R G B R G B |

*                ---------------------------

* So a 10x10 img would have 11 total rows, 10 rows of data, with 30 values in row.

*/

#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

/**

Structure to hold an rgb value

*/
struct rgb
{
    int r;
    int g;
    int b;
};

/**
* @FunctionName: flipVert
* @Description: 
*     Loops through a 2D array and flips the RGB values vertically.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVert(rgb** image,int width,int height)
{
    // your code
}

/**
* @FunctionName: flipHorz
* @Description: 
*     Loops through a 2D array and flips the RGB values horizontally.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipHorz(rgb** image,int width,int height)
{
    // your code
}

/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image,int width,int height)
{
    // your code
}

/**
* @FunctionName: changeColor
* @Description: 
*     Loops through a 2D array and turns every RGB value into the new color.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    rgb newColor - a struct holding the new color for the image.
* @Returns:
*    void
*/
void changeColor(rgb** image,int width, int height, rgb newColor)
{
   // loop through image
   // assign newColor to each location in array
}

/**
* @FunctionName: readImage
* @Description: 
*     Loops through a file and reads in RGB values.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    ofstream ofile - output file
* @Returns:
*    void
*/
void readImage(rgb** image,int &width,int &height,ofstream &ofile)
{
    // Hmmm, what's up with the width and height references
}

/**
* @FunctionName: saveImage
* @Description: 
*     Loops through a file and stores the image through RGB values.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    ofstream ofile - output file
* @Returns:
*    void
*/
void saveImage(rgb** image,int width,int height,ofstream &ofile)
{
    // your code
}

int main()
{
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("bot.txt");
    ofile.open("bot2.txt");   

    int width;               //width of image
    int height;              //height of image

    rgb **imgArray;         //Pointer var for our 2D array because we         
                            //don't know how big the image will be
                            
    ifile>>width>>height;   //Read in width and height from top of input file

                            //We need this so we can make the array the right 
                            //size. After we get these two values, we can
                            //now allocate memory for our 2D array.

    imgArray = new rgb*[height];    //This array points to every row

    for(int i=0;i<height;i++)
    {
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }

    //Read the color data in from our txt file
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }

    //We could make any changes we want to the color image here

    //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }

  return 0;
}
