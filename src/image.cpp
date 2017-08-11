Image::Image(unsigned int width_ = 0, unsigned int height_ = 0) :
    width(width_), height(height_) {
    // Allocate pixel vector of image
    pixels = new rgb[width * height];
}

Image::~Image(){
    delete[] this->pixels;
}