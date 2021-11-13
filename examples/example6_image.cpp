#include <svg/SVGDocument.h>
#include <svg/SVGImage.h>

using namespace svg;

int main()
{
    auto img = new SVGImage("../tux.png", 320, 0, 640, 768);

    SVGDocument svg(1280,768);
    svg.add_child(img);
    svg.print("example6_image.svg");

    return 0;
}
