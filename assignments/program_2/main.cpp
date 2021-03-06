/**
* @ProgramName: Program-2
* @Author: Alexander Zeizinger
* @Description: 
*     This program reads in images stored as rgb values and utilizes them as objects from a class to manipluate the image.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 15 02 2017
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

class ImageManip
{
  private:
    rgb** image;
    int width;
    int height;
    ifstream infile;
    ofstream ofile;
    string ifile_name;
    string ofile_name;
    
    /**
    * @FunctionName: readFile
    * @Description: 
    *    Reads in the values from the image file.
    * @Params:
    *    None
    * @Returns:
    *    void
    */
    void readFile()
    {
      for(int i = 0; i < height; i++)
      {
        for(int j = 0; j < width; j++)
        {
          infile>>image[i][j].r>>image[i][j].g>>image[i][j].b; 
        }
      }
    }
    
    /**
    * @FunctionName: writeFile
    * @Description: 
    *     Prints the rgb values of the image file from the pointer arrays.
    * @Params:
    *    None
    * @Returns:
    *    void
    */
    void writeFile()
    {
      ofile << width << " " << height << endl;
      for(int i = 0; i < height; i++)
      {
        for(int j = 0; j < width; j++)
          {
            ofile<<image[i][j].r<<" "<<image[i][j].g<<" "<<image[i][j].b<<" ";
          }
            
        ofile<<endl;
      }
    }
    
  public:
    ImageManip()
    {
      infile.open("bot.txt");
      ofile.open("bot2.txt");
      infile >> height >> width;
      image = new rgb*[height];

      for(int i = 0; i < height; i++)
      {
        image[i] = new rgb[width]; 
      }
      
      readFile();
    }
    
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
    void flipVert()
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
        
      writeFile();
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
    void flipHorz()
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
    ;   }
      }
      
      writeFile();
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
    void grayScale()
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
      
      writeFile();
    }
    
    ~ImageManip()
    {
      delete image;
    }
};


int main()
{
    int Option;
    ImageManip BotPic;

    cout << "Please choose an option.\n";
    cout << "1. Flip vertically.\n";
    cout << "2. Flip horizontally.\n";
    cout << "3. Grayscale image.\n";
    cin >> Option;

    if (Option == 1)
    {
      BotPic.flipVert();
    }
    
    else if (Option == 2)
    {
      BotPic.flipHorz();
    }
    
    else if (Option == 3)
    {
      BotPic.grayScale();
    }

  return 0;
}
