#include "modules/image.hpp"

/* Write a screenshot to the specified filename */
namespace image {

  void saveScreenshot (char * filename) {

    int x, y;
    Pic * image = NULL;

    // ensure that our filename is given
    if (filename == NULL) return;

    // create a picture buffer -- for storing the image pixels etc
    // allocate a picture object the size of our screen
    // pic_alloc(int nx, int ny, int bpp, pic) -- will then return our image that we need
    image = pic_alloc(640, 480, 3, NULL);

    printf("File to save to: %s\n", filename);
    // now loop through the entire elements

    // loop from the top left down to the bottom right for creating the pixels 
    // we want to only grab one row at at time starting from the top
    for (y = 479; y >= 0; y--) {

      // grab the image data, one row at a time from top to bottom
      // glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
      // draw a row at a time
      glReadPixels(0, 479-y, 640, 1, GL_RGB, GL_UNSIGNED_BYTE, &image->pix[y*image->nx*image->bpp]);

    }

    if (jpeg_write(filename, image))
      printf("File %s saved successfully.", filename);

    else
      printf("Could not save image");

    pic_free(image);

  }

  void draw() {

    // will be responsible for applying texture maps etc in the future
    // will want to center the image when we do this from our other application because this may be scaled else where right?
    glDrawPixels(currentImage->nx, currentImage->ny, GL_RGBA, GL_UNSIGNED_BYTE, currentImage->pix); 


  }

}
