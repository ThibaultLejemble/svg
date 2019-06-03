#include <svg/SVGDocument.h>
#include <svg/SVGGroup.h>
#include <svg/SVGRectangle.h>
#include <svg/SVGCircle.h>
#include <svg/SVGStyle.h>

using namespace svg;

int main()
{
    SVGRectangle* rect = new SVGRectangle("rectangle", 50, 50, 25, 25);
    SVGCircle*    circ = new SVGCircle("circle", 75, 75, 25);

    rect->style().set_filled();
    rect->style().set_fill(SVGColor(1,0,0));
    rect->style().set_fill_opacity(0.5);
    rect->style().set_stroked();
    rect->style().set_stroke(SVGColor(0,0,0));
    rect->style().set_stroke_width(2);

    circ->style().set_filled();
    circ->style().set_fill(SVGColor(0,0,1));
    circ->style().set_fill_opacity(0.5);
    circ->style().set_stroked();
    circ->style().set_stroke(SVGColor(0,0.5,1));
    circ->style().set_stroke_width(1);
    circ->style().set_stroke_dashed();
    circ->style().set_stroke_dasharray({5,5});

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
