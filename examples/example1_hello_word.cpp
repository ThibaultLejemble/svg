#include <svg/SVGDocument.h>
#include <svg/SVGRectangle.h>

using namespace svg;

int main()
{
    SVGRectangle* rect = new SVGRectangle("rectangle", 50, 50, 25, 25);

    SVGDocument svg;
    svg.set_width(100);
    svg.set_height(100);
    svg.add_child(rect);

    svg.print("example1.svg");

    return 0;
}
