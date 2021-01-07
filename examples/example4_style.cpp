#include <svg/SVGDocument.h>
#include <svg/BasicShapes.h>
#include <svg/Style.h>

using namespace svg;

int main()
{
    auto rectangle = new SVGRectangle("rectangle", 10, 10, 80, 80);
    auto circle    = new SVGCircle("circle", 150, 50, 40);
    auto ellipse   = new SVGEllipse("ellipse", 250, 50, 40, 20);
    auto line      = new SVGLine("line", 10, 190, 90, 110);
    auto polyline  = new SVGPolyLine("polyline", {150,110,110,130,170,190,190,150}, {190,160,130,110,110,130,160,190});
    auto polygon   = new SVGPolygon("polygon", {250,210,210,230,270,290,290,250}, {190,160,130,110,110,130,160,190});

    rectangle->style().set_filled(true);
    rectangle->style().set_fill({1,0.5,0});
    rectangle->style().set_fill_opacity(0.5);

    rectangle->style().set_stroked(true);
    rectangle->style().set_stroke({0,0.5,1});
    rectangle->style().set_stroke_opacity(1);
    rectangle->style().set_stroke_width(3);

    circle->style() = rectangle->style();
    circle->style().set_opacity(0.5);

    ellipse->style().set_fill({0.5,1,0});

    line->style().set_stroke_dashed(true);

    polyline->style().set_stroke_dashed(true);
    polyline->style().set_stroke_dasharray({10,5,1,5});

    polygon->style() = ellipse->style();
    polygon->style().set_stroked(true);
    polygon->style().set_stroke_width(10);
    polygon->style().set_stroke_opacity(0.5);

    SVGDocument svg(300,200);
    svg.add_child(rectangle);
    svg.add_child(circle);
    svg.add_child(ellipse);
    svg.add_child(line);
    svg.add_child(polyline);
    svg.add_child(polygon);

    svg.print("example4_style.svg");

    return 0;
}
