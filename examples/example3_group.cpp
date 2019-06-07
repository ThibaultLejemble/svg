#include <svg/SVGDocument.h>
#include <svg/BasicShapes.h>
#include <svg/SVGGroup.h>

using namespace svg;

int main()
{
    SVGRectangle* rectangle = new SVGRectangle("rectangle", 10, 10, 80, 80);
    SVGCircle*    circle    = new SVGCircle("circle", 150, 50, 40);
    SVGEllipse*   ellipse   = new SVGEllipse("ellipse", 250, 50, 40, 20);
    SVGLine*      line      = new SVGLine("line", 10, 190, 90, 110);
    SVGPolyLine*  polyline  = new SVGPolyLine("polyline", {150,110,110,130,170,190,190,150}, {190,160,130,110,110,130,160,190});
    SVGPolygon*   polygon   = new SVGPolygon("polygon", {250,210,210,230,270,290,290,250}, {190,160,130,110,110,130,160,190});

    SVGGroup* layer1 = new SVGGroup("Layer 1");
    layer1->add_child(rectangle);
    layer1->add_child(circle);
    layer1->add_child(ellipse);

    SVGGroup* layer2 = new SVGGroup("Layer 2");
    layer2->add_child(line);
    layer2->add_child(polyline);
    layer2->add_child(polygon);

    SVGGroup* main = new SVGGroup("Main layer");
    main->add_child(layer1);
    main->add_child(layer2);

    SVGDocument svg(300,200);
    svg.add_child(main);

    svg.print("example3_group.svg");

    return 0;
}
