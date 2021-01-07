#include <svg/SVGDocument.h>
#include <svg/SVGRectangle.h>

using namespace svg;

int main()
{
    auto rect = new SVGRectangle("rectangle", 10, 10, 80, 80);

    SVGDocument svg(100,100);
    svg.add_child(rect);
    svg.add_background_white();

    svg.print("example1_hello_word.svg");

    return 0;
}
