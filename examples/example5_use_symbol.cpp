#include <svg/SVGDocument.h>
#include <svg/SVGPolygon.h>
#include <svg/Style.h>
#include <svg/SVGSymbol.h>
#include <svg/SVGUse.h>

using namespace svg;

int main()
{
    auto polygon1 = new SVGPolygon(
        "polygon1",
        {1,1,0,0},
        {3,2,1,2});
    auto polygon2 = new SVGPolygon(
        "polygon2",
        {1,1,2,2},
        {3,2,1,2});
    auto polygon3 = new SVGPolygon(
        "polygon3",
        {1,2,1,0},
        {2,1,0,1});

    polygon1->style().set_filled(true);
    polygon1->style().set_stroked(false);

    polygon2->style() = polygon1->style();
    polygon3->style() = polygon1->style();

    polygon1->style().set_fill({0.25,0.25,0.25});
    polygon2->style().set_fill({0.75,0.75,0.75});
    polygon3->style().set_fill({0.50,0.50,0.50});

    auto symbol = new SVGSymbol("cube", 2, 3);
    symbol->add_child(polygon1);
    symbol->add_child(polygon2);
    symbol->add_child(polygon3);

    SVGDocument svg(60,70);
    svg.add_child(symbol);

    svg.add_child(new SVGUse("cube",  0, 40, 20, 30));
    svg.add_child(new SVGUse("cube", 20, 40, 20, 30));
    svg.add_child(new SVGUse("cube", 40, 40, 20, 30));
    svg.add_child(new SVGUse("cube", 10, 20, 20, 30));
    svg.add_child(new SVGUse("cube", 30, 20, 20, 30));
    svg.add_child(new SVGUse("cube", 20,  0, 20, 30));

    svg.print("example5_use_symbol.svg");

    return 0;
}
