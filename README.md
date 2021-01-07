# svg: Simple C++ SVG library

**svg** is a C++ library without dependencies that focuses on the production of basic SVG file. 

## Features

- styles
- transforms
- groups (seen as layers in [Inkscape](https://inkscape.org/))
- symbols
- basic shapes
  - rectangle
  - circle
  - ellipse
  - line
  - polyLine
  - polygon

## Examples

To download, compile, and run the examples run these commands 
```
git clone git@github.com:ThibaultLejemble/svg.git
cd svg
mkdir build
cd build
cmake .. 
make -j
./example1_hello_word
./example2_basic_shapes
./example3_group
./example4_style
./example5_use_symbol
```

## Missing features

- image
- text
- gradient
- clipping, masking and compositing
- path
- loading svg file
- ...
