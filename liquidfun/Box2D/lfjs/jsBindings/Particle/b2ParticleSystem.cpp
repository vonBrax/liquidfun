

namespace emscripten {

  namespace internal {
    template<> void raw_destructor<b2ParticleSystem>(b2ParticleSystem* ptr) {
      // Do nothing.
    }
  }

  EMSCRIPTEN_BINDINGS(particle_system_module) {

    class_<b2ParticleSystemDef>("ParticleSystemDef")
      .constructor<>()
      // .property("strictContactCheck", &b2ParticleSystemDef::strictContactCheck)
      // .property("density", &b2ParticleSystemDef::density)
      // .property("gravityScale", &b2ParticleSystemDef::gravityScale)
      .property("radius", &b2ParticleSystemDef::radius)
      .property("maxCount", &b2ParticleSystemDef::maxCount)
      // .property("pressureStrength", &b2ParticleSystemDef::pressureStrength)
      // .property("dampingStrength", &b2ParticleSystemDef::dampingStrength)
      // .property("elasticStrength", &b2ParticleSystemDef::elasticStrength)
      // .property("springStrength", &b2ParticleSystemDef::springStrength)
      // .property("viscousStrength", &b2ParticleSystemDef::viscousStrength)
      // .property("surfaceTensionPressureStrength", &b2ParticleSystemDef::surfaceTensionPressureStrength)
      // .property("surfaceTensionNormalStrength", &b2ParticleSystemDef::surfaceTensionNormalStrength)
      .property("repulsiveStrength", &b2ParticleSystemDef::repulsiveStrength);
      // .property("powderStrength", &b2ParticleSystemDef::powderStrength)
      // .property("ejectionStrength", &b2ParticleSystemDef::ejectionStrength)
      // .property("staticPressureStrength", &b2ParticleSystemDef::staticPressureStrength)
      // .property("staticPressureRelaxation", &b2ParticleSystemDef::staticPressureRelaxation)
      // .property("staticPressureIterations", &b2ParticleSystemDef::staticPressureIterations)
      // .property("colorMixingStrength", &b2ParticleSystemDef::colorMixingStrength)
      // .property("destroyByAge", &b2ParticleSystemDef::destroyByAge)
      // .property("lifetimeGranularity", &b2ParticleSystemDef::lifetimeGranularity);

    class_<b2ParticleSystem>("ParticleSystem")
      .function("GetParticleCount", &b2ParticleSystem::GetParticleCount)
      .function("GetParticleGroupList", select_overload<b2ParticleGroup*()>(&b2ParticleSystem::GetParticleGroupList), allow_raw_pointers())
      .function("SetMaxParticleCount", &b2ParticleSystem::SetMaxParticleCount)
      .function("CreateParticleGroup", &b2ParticleSystem::CreateParticleGroup, allow_raw_pointers())
      .function("GetParticleGroupCount", &b2ParticleSystem::GetParticleGroupCount)
      .function("DestroyParticlesInShape", select_overload<int(const b2Shape&, const b2Transform&)>(&b2ParticleSystem::DestroyParticlesInShape))
      .function("DestroyParticlesInShape", select_overload<int(const b2Shape&, const b2Transform&, bool)>(&b2ParticleSystem::DestroyParticlesInShape))
      .function("JoinParticleGroups", &b2ParticleSystem::JoinParticleGroups, allow_raw_pointers())
      // .function("GetDensity", &b2ParticleSystem::GetDensity)
      // .function("GetRadius", &b2ParticleSystem::GetRadius)
      // .function("GetStaticPressureIterations", &b2ParticleSystem::GetStaticPressureIterations)
      // .function("GetPositionBuffer", select_overload<b2Vec2*()>(&b2ParticleSystem::GetPositionBuffer), allow_raw_pointers())
      // .function("GetPositionBuffer", select_overload<const b2Vec2*() const>(&b2ParticleSystem::GetPositionBuffer), allow_raw_pointers())
      // .function("CopyPositionBuffer", &b2ParticleSystem::CopyPositionBuffer, allow_raw_pointers())
      .function("CopyPositionBuffer", optional_override(
        [](b2ParticleSystem& self, int startIndex, int numParticles, uintptr_t buffPtr, int size) {
          int* ptr = reinterpret_cast<int*>(buffPtr);
          return self.CopyPositionBuffer(startIndex, numParticles, ptr, size);
        }
      ))
      // .function("CopyColorBuffer", &b2ParticleSystem::CopyColorBuffer, allow_raw_pointers())
      .function("CopyColorBuffer", optional_override(
        [](b2ParticleSystem& self, int startIndex, int numParticles, uintptr_t buffPtr, int size) {
          int* ptr = reinterpret_cast<int*>(buffPtr);
          return self.CopyColorBuffer(startIndex, numParticles, ptr, size);
        }
      ))
      // .function("CopyWeightBuffer", &b2ParticleSystem::CopyWeightBuffer, allow_raw_pointers());
      .function("CopyWeightBuffer", optional_override(
        [](b2ParticleSystem& self, int startIndex, int numParticles, uintptr_t buffPtr, int size) {
          int* ptr = reinterpret_cast<int*>(buffPtr);
          return self.CopyWeightBuffer(startIndex, numParticles, ptr, size);
        }
      ));
  }
}