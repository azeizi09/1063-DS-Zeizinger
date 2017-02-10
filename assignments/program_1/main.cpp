/**
* @ProgramName: Program-1
* @Author: Alexander Zeizinger
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 06 02 2017
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
void flipVert(rgb** image, int width, int height)
{
    int Hold;
    for(int i = 0; i < height/2; i++)
    {
      for(int j = 0; j < width; j++)
      {
        Hold = image[i][j].r;
        image[i][j].r = image[height-1-i][j].r;
        image[height-1-i][j].r = Hold;
        Hold = image[i][j].g;
        image[i][j].g = image[height-1-i][j].g;
        image[height-1-i][j].g = Hold;
        Hold = image[i][j].b;
        image[i][j].b = image[height-1-i][j].b;
        image[height-1-i][j].b = Hold;
      }
    }
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
void flipHorz(rgb** image, int width, int height)
{
    rgb Hold;
    for(int i = 0; i < height; i++)
    {
      for(int j = 0; j < width/2; j++)
      {
        Hold.r = image[i][j].r;
        Hold.g = image[i][j].g;
        Hold.b = image[i][j].b;
        image[i][j].r = image[i][width-j-1].r;
        image[i][j].g = image[i][width-j-1].g;
        image[i][j].b = image[i][width-j-1].b;
        image[i][width-j-1].r = Hold.r;
        image[i][width-j-1].g = Hold.g;
        image[i][width-j-1].b = Hold.b;
;      }
    }
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
void grayScale(rgb** image, int width, int height)
{
    int Hold;
    for(int i = 0; i < height; i++)
    {
      for(int j = 0; j < width; j++)
      {
        Hold = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
        image[i][j].r = Hold;
        image[i][j].g = Hold;
        image[i][j].b = Hold;
      }
    }
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
void changeColor(rgb** image, int width, int height, rgb newColor)
{
   for(int i = 0; i < height; i++)
   {
     for(int j = 0; j < width; j++)
     {
       image[i][j].r = newColor.r;
       image[i][j].g = newColor.g;
       image[i][j].b = newColor.b;
     }
   }
}

int main()
{
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("bot.txt");
    ofile.open("bot2.txt");   

    int width;               //width of image
    int height;              //height of image
    int Option;
    
    rgb **imgArray;         //Pointer var for our 2D array because we         
                            //don't know how big the image will be
                            
    ifile >> width >> height;   //Read in width and height from top of input file

                            //We need this so we can make the array the right 
                            //size. After we get these two values, we can
                            //now allocate memory for our 2D array.

    imgArray = new rgb*[height];    //This array points to every row

    for(int i = 0; i < height; i++)
    {
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }

    //Read the color data in from our txt file
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }

    cout << "Please choose an option.\n";
    cout << "1. Flip vertically.\n";
    cout << "2. Flip horizontally.\n";
    cout << "3. Grayscale image.\n";
    cin >> Option;

    if (Option == 1)
    {
      flipVert(imgArray, width, height);
      
      //Write out our color data to a new file
      ofile<<width<<" "<<height<<endl;

      for(int i = 0; i < height; i++)
      {
        for(int j = 0; j < width; j++)
        {
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
      }
    }
    
    else if (Option == 2)
    {
      flipHorz(imgArray, width, height);
      
      //Write out our color data to a new file
      ofile<<width<<" "<<height<<endl;

      for(int i = 0; i < height; i++)
      {
        for(int j = 0; j < width; j++)
        {
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
      }
    }
    
    else if (Option == 3)
    {
      grayScale(imgArray, width, height);
      
      //Write out our color data to a new file
      ofile<<width<<" "<<height<<endl;

      for(int i = 0; i < height; i++)
      {
        for(int j = 0; j < width; j++)
        {
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
      }
    }

  return 0;
}
