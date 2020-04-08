using namespace emscripten;

// class ExtendDraw : public b2Draw {
//  void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
//    // This is equivalent to drawing lines with the same color at each
//    // vertex
//    int elementSize = 8;
//  }

//   void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {

//   }

//   void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {

//   }

//   void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {

//   }

//   void DrawParticles(const b2Vec2 *centers, float32 radius, const b2ParticleColor *colors, int32 count) {

//   }

//   void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {

//   }

//   void DrawTransform(const b2Transform& xf) {

//   }

//   public:
//     int e_shapeBit = b2Draw::e_shapeBit;
//     int e_jointBit = b2Draw::e_jointBit;
//     int e_aabbBit = b2Draw::e_aabbBit;
//     int e_pairBit = b2Draw::e_pairBit;
//     int e_centerOfMassBit = b2Draw::e_centerOfMassBit;
//     int e_particleBit = b2Draw::e_particleBit;
// };

struct DrawWrapper : public wrapper<b2Draw> {
  EMSCRIPTEN_WRAPPER(DrawWrapper);

  // void SetFlags(uint32 flags) {
  //   return call<void>("SetFlags", flags);
  // }

  void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    return call<void>("DrawPolygon", vertices, vertexCount, color);
  }

  void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
    printf("Mama mia! Here I go again!");

    return call<void>("DrawSolidPolygon", vertices, vertexCount, color);
  }

  void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
    return call<void>("DrawCircle", center, radius, color);
  }

  void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
    return call<void>("DrawSolidCircle", center, radius, axis, color);
  }

  void DrawParticles(const b2Vec2 *centers, float32 radius, const b2ParticleColor *colors, int32 count) {
    return call<void>("DrawParticles", centers, radius, colors, count);
  }

  void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
    return call<void>("DrawSegment", p1, p2, color);
  }

  void DrawTransform(const b2Transform& xf) {
    return call<void>("DrawTransform", xf);
  }

  // int e_shapeBit = 0x0001;
  // int e_jointBit = 0x0002;
  // int e_aabbBit = 0x0004;
  // int e_pairBit = 0x0008;
  // int e_centerOfMassBit = 0x0010;
  // int e_particleBit = 0x0020;
};

EMSCRIPTEN_BINDINGS(draw_module) {
  // class_<b2Draw>("B2Draw");
  // class_<ExtendDraw, base<b2Draw>>("Draw")
  //   .constructor<>()
  //   .function("GetFlags", &ExtendDraw::GetFlags)
  //   .function("SetFlags", &ExtendDraw::SetFlags)
  //   .property("shapeBit", &ExtendDraw::e_shapeBit)
  //   .property("jointBit", &ExtendDraw::e_jointBit)
  //   .property("aabbBit", &ExtendDraw::e_aabbBit)
  //   .property("pairBit", &ExtendDraw::e_pairBit)
  //   .property("centerOfMassBit", &ExtendDraw::e_centerOfMassBit)
  //   .property("particleBit", &ExtendDraw::e_particleBit);
  class_<b2Color>("b2Color")
    .constructor<>()
    .constructor<float, float, float>()
    .function("Set", &b2Color::Set)
    .property("r", &b2Color::r)
    .property("g", &b2Color::g)
    .property("b", &b2Color::b);

  class_<b2Draw>("Draw")
    .allow_subclass<DrawWrapper>("DrawWrapper", constructor<>())
    .function("GetFlags", &b2Draw::GetFlags)
    .function("SetFlags", &b2Draw::SetFlags)
    .function("DrawPolygon", &b2Draw::DrawPolygon, allow_raw_pointers(), pure_virtual())
    .function("DrawSolidPolygon", &b2Draw::DrawSolidPolygon, allow_raw_pointers(), pure_virtual())
    .function("DrawCircle", &b2Draw::DrawCircle, pure_virtual())
    .function("DrawSolidCircle", &b2Draw::DrawSolidCircle, pure_virtual())
    .function("DrawParticles", &b2Draw::DrawParticles, allow_raw_pointers(), pure_virtual())
    .function("DrawSegment", &b2Draw::DrawSegment, pure_virtual())
    .function("DrawTransform", &b2Draw::DrawTransform, pure_virtual());
    // .property("shapeBit", 0x0001);
    // .property("jointBit", &DrawWrapper::e_jointBit)
    // .property("aabbBit", &DrawWrapper::e_aabbBit)
    // .property("pairBit", &DrawWrapper::e_pairBit)
    // .property("centerOfMassBit", &DrawWrapper::e_centerOfMassBit)
    // .property("particleBit", &DrawWrapper::e_particleBit);
}