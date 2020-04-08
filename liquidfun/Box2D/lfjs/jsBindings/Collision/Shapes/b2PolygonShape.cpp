using namespace emscripten;

EMSCRIPTEN_BINDINGS(polygon_shape_module) {
  // class_<b2PolygonShape>("PolygonShape")
  //   .constructor<>()
  //   .function("SetAsBox", select_overload<void(float, float)>(&b2PolygonShape::SetAsBox))
  //   .function("SetAsBox", select_overload<void(float, float, const b2Vec2&, float)>(&b2PolygonShape::SetAsBox));


  class_<b2PolygonShape, base<b2Shape>>("PolygonShape")
    .constructor<>()
    .function("SetAsBox", select_overload<void(float, float)>(&b2PolygonShape::SetAsBox))
    .function("SetAsBox", select_overload<void(float, float, const b2Vec2&, float)>(&b2PolygonShape::SetAsBox));
}
