using namespace emscripten;

EMSCRIPTEN_BINDINGS(particle_module) {
  // class_<b2Particle>("Particle")
  //   //.constructor<b2Vec2>()
  //   .property("r", &b2Particle::r)
  //   .property("g", &b2Particle::g)
  //   .property("b", &b2Particle::b)
  //   .property("a", &b2Particle::a);

  class_<b2ParticleColor>("ParticleColor")
    .constructor<>()
    .constructor<uint8, uint8, uint8, uint8>()
    .constructor<b2Color&>()
    .function("Set", select_overload<void(uint8, uint8, uint8, uint8)>(&b2ParticleColor::Set))
    .function("Set", select_overload<void(const b2Color&)>(&b2ParticleColor::Set))
    .property("r", &b2ParticleColor::r)
    .property("g", &b2ParticleColor::g)
    .property("b", &b2ParticleColor::b)
    .property("a", &b2ParticleColor::a);

    // enum_<b2ParticleFlag>("ParticleFlag")
    //   .value("waterParticle", b2ParticleFlag::b2_waterParticle)
    //   .value("zombieParticle", b2ParticleFlag::b2_zombieParticle)
    //   .value("wallParticle", b2ParticleFlag::b2_wallParticle)
    //   .value("springParticle", b2ParticleFlag::b2_springParticle)
    //   .value("elasticParticle", b2ParticleFlag::b2_elasticParticle)
    //   .value("viscousParticle", b2ParticleFlag::b2_viscousParticle)
    //   .value("powderParticle", b2ParticleFlag::b2_powderParticle)
    //   .value("tensileParticle", b2ParticleFlag::b2_tensileParticle)
    //   .value("colorMixingParticle", b2ParticleFlag::b2_colorMixingParticle)
    //   .value("destructionListenerParticle", b2ParticleFlag::b2_destructionListenerParticle)
    //   .value("barrierParticle", b2ParticleFlag::b2_barrierParticle)
    //   .value("staticPressureParticle", b2ParticleFlag::b2_staticPressureParticle)
    //   .value("reactiveParticle", b2ParticleFlag::b2_reactiveParticle)
    //   .value("repulsiveParticle", b2ParticleFlag::b2_repulsiveParticle)
    //   .value("fixtureContactListenerParticle", b2ParticleFlag::b2_fixtureContactListenerParticle)
    //   .value("particleContactListenerParticle", b2ParticleFlag::b2_particleContactListenerParticle)
    //   .value("fixtureContactFilterParticle", b2ParticleFlag::b2_fixtureContactFilterParticle)
    //   .value("particleContactFilterParticle", b2ParticleFlag::b2_particleContactFilterParticle);
}
