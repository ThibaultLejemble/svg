#include <svg/SVGDocument.h>
#include <svg/BasicShapes.h>

using namespace svg;

int main()
{
    auto rectangle = new SVGRectangle("rectangle", 10, 10, 80, 80);
    auto circle    = new SVGCircle("circle", 150, 50, 40);
    auto ellipse   = new SVGEllipse("ellipse", 250, 50, 40, 20);
    auto line      = new SVGLine("line", 10, 190, 90, 110);
    auto polyline  = new SVGPolyLine("polyline", {150,110,110,130,170,190,190,150}, {190,160,130,110,110,130,160,190});
    auto polygon   = new SVGPolygon("polygon", {250,210,210,230,270,290,290,250}, {190,160,130,110,110,130,160,190});

    SVGDocument svg(300,200);
    svg.add_child(rectangle);
    svg.add_child(circle);
    svg.add_child(ellipse);
    svg.add_child(line);
    svg.add_child(polyline);
    svg.add_child(polygon);

    svg.print("example2_basic_shapes.svg");

    return 0;
}
