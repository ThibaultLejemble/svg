#include <string>

#include <svg/SVGDocument.h>
#include <svg/SVGGroup.h>
#include <svg/SVGRectangle.h>
#include <svg/SVGCircle.h>

using namespace svg;

int main(int argc, char *argv[])
{
    SVGRectangle* rect = new SVGRectangle("rectangle", 50, 50, 25, 25);
    SVGCircle*    circ = new SVGCircle("circle", 75, 75, 25);

    SVGGroup* g = new SVGGroup("layer");
    g->add_child(rect);
    g->add_child(circ);

    SVGDocument svg;
    svg.set_width(100);
    svg.set_height(100);
    svg.add_child(g);

    svg.print("output.svg");

    return 0;
}
